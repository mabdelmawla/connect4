/*
 * c4_game_play.c
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#include <c4_game_play.h>

#include <c4_game_draw.h>
#include <c4_hal_graphics.h>

static _t_ma_u8 g_curr_coin_location;
static _t_ma_u8 g_curr_player;
static _t_ma_u8 g_board[7][6];
static _t_ma_u8 g_slots[7];
static _t_ma_u8 g_declare_win;

static void check_win(void) {	// TODO: Improve this implementation
	_t_ma_u8 loc = g_curr_coin_location;
	_t_ma_u8 player = g_curr_player;
	int cnt;
	int h = g_slots[loc];
	int win = 1;
	//############# vertical check;
	cnt = h;
	while(cnt > 0){
		if(g_board[loc][--cnt] == player){
			win++;
		} else {
			break;
		}
	}

	if (win == 4) { // declare win
		g_declare_win = 1;
		c4_set_winning_coin(player);
		return;
	}

	//############# horizontal check
	win = 1;
	cnt = loc;
	//right side check
	while(cnt > 0){
		if(g_board[--cnt][h] == player){
			win++;
		} else {
			break;
		}
	}
	cnt = loc;
	//left side check
	while(cnt < 6){
		if(g_board[++cnt][h] == player){
			win++;
		} else {
			break;
		}
	}

	if (win == 4) { // declare win
		g_declare_win = 1;
		c4_set_winning_coin(player);
		return;
	}

	//######### diagonal check
	int hh;
	// ### left inclining slope
	win = 1;
	hh = h;
	cnt = loc;
	//right side check
	while((cnt > 0) && (hh > 0)){
		if(g_board[--cnt][--hh] == player){
			win++;
		} else {
			break;
		}
	}
	cnt = loc;
	hh = h;
	//left side check
	while((cnt < 6) && (hh < 5)){
		if(g_board[++cnt][+hh] == player){
			win++;
		} else {
			break;
		}
	}

	if (win == 4) { // declare win
		g_declare_win = 1;
		c4_set_winning_coin(player);
		return;
	}
	// ### left inclining slope
	win = 1;
	hh = h;
	cnt = loc;
	//right side check
	while((cnt > 0) && (hh < 5)){
		if(g_board[--cnt][++hh] == player){
			win++;
		} else {
			break;
		}
	}
	cnt = loc;
	hh = h;
	//left side check
	while((cnt < 6) && (hh > 0)){
		if(g_board[++cnt][--hh] == player){
			win++;
		} else {
			break;
		}
	}

	if (win == 4) { // declare win
		g_declare_win = 1;
		c4_set_winning_coin(player);
		return;
	}

}
static void clear_all(_t_ma_bool update_draw) {
	//g_curr_coin_location = 0;
	//g_curr_player = 0;
	g_declare_win = 0;

	for (int i = 0; i < 7; i++) {
		g_slots[i] = 0;
		for (int j = 0; j < 6; j++) {
			g_board[i][j] = 0xff;
			if (update_draw) {
				c4_game_board_update(i, j, 0xff);
			}
		}
	}
	if (update_draw) {
		c4_set_winning_coin(0xff);
	}
}

static void keyCB(_t_ma_char key, _t_str_c4_hal_graphics_point pt) {
	if ((1 == g_declare_win) || ('n' == key) || ('N' == key)) {
		clear_all(1);
	} else {
		if (('\r' == key) && (g_slots[g_curr_coin_location] < 6)) {
			c4_game_board_update(g_curr_coin_location,
					g_slots[g_curr_coin_location], g_curr_player);
			g_board[g_curr_coin_location][g_slots[g_curr_coin_location]] =
					g_curr_player;
			check_win();
			g_curr_player = 1 - g_curr_player;
			c4_game_draw_coin(g_curr_coin_location, g_curr_player);
			g_slots[g_curr_coin_location]++;
		}
	}
}

static void SpkeyCB(_t_ma_int key, _t_str_c4_hal_graphics_point pt) {
	switch (key) {
	case C4_HAL_GRAPHICS_SF_KEY_RIGHT:
		g_curr_coin_location++;
		break;
	case C4_HAL_GRAPHICS_SF_KEY_LEFT:
		g_curr_coin_location--;
		break;
	}
	if (g_curr_coin_location == 7)
		g_curr_coin_location = 0;
	if (g_curr_coin_location == 0xff)
		g_curr_coin_location = 6;
	c4_game_draw_coin(g_curr_coin_location, g_curr_player);
}

int c4_game_play_init(void) {
	int ret = -1;
	g_curr_coin_location = 0;
	g_curr_player = 0;
	clear_all(0);
	_t_str_c4_game_draw_init inp =
			{ .pf_kcb = keyCB, .pf_skcb = SpkeyCB, .player_color[0] = { 1, 0, 0,
					0 }, .player_color[1] = { 1, 1, 0, 0 } };
	c4_game_draw_init(inp);
	return ret;
}
