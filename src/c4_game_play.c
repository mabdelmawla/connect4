/*
 * c4_game_play.c
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#include <c4_game_play.h>

#include <c4_game_draw.h>
#include <c4_hal_graphics.h>

static _t_ma_u8 g_curr_coin_location = 0;
static _t_ma_u8 g_curr_player = 0;
static _t_ma_u8 g_board[7][6] = { 0xff };
static _t_ma_u8 g_slots[7] = { 0 };
static _t_ma_u8 g_declare_win = 0;

static void check_win(void) {
	_t_ma_u8 loc = g_curr_coin_location;
	_t_ma_u8 player = 1 - g_curr_player;
	int cnt;
	int h = g_slots[loc]-1;
	int win = 1;
	//vertical check;
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

	//horizontal check
#if 0
	win = 1;
	cnt = loc;
	do {
		if (g_board[cnt--][h] == player) {
			win++;
		} else {
			break;
		}
	} while (cnt > 0);
	cnt = loc;
	do {
		if (g_board[cnt++][h] == player) {
			win++;
		} else {
			break;
		}
	} while (cnt < 7);
	if (win == 4) { // declare win
		g_declare_win = 1;
		c4_set_winning_coin(player);
		return;
	}
#endif
}
static void clear_all(void) {
	//g_curr_coin_location = 0;
	//g_curr_player = 0;
	g_declare_win = 0;

	for (int i = 0; i < 7; i++) {
		g_slots[i] = 0;
		for (int j = 0; j < 6; j++) {
			g_board[i][j] = 0xff;
			c4_game_board_update(i, j, 0xff);
		}
	}
	c4_set_winning_coin(0xff);
}

static void keyCB(_t_ma_char key, _t_str_c4_hal_graphics_point pt) {
	if (1 == g_declare_win) {
		clear_all();
	} else {
		if (('\r' == key) && (g_slots[g_curr_coin_location] < 6)) {
			c4_game_board_update(g_curr_coin_location,
					g_slots[g_curr_coin_location], g_curr_player);
			g_board[g_curr_coin_location][g_slots[g_curr_coin_location]] =
					g_curr_player;
			g_curr_player = 1 - g_curr_player;
			c4_game_draw_coin(g_curr_coin_location, g_curr_player);
			g_slots[g_curr_coin_location]++;
			check_win();
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
	_t_str_c4_game_draw_init inp =
			{ .pf_kcb = keyCB, .pf_skcb = SpkeyCB, .player_color[0] = { 1, 0, 0,
					0 }, .player_color[1] = { 1, 1, 0, 0 } };
	c4_game_draw_init(inp);
	return ret;
}
