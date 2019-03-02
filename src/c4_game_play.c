/*
 * c4_game_play.c
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#include <c4_game_play.h>

#include <c4_game_draw.h>
#include <c4_hal_graphics.h>

static _t_ma_u8 g_coing_location = 0;
static _t_ma_u8 g_curr_player = 0;


static void keyCB(_t_ma_char key, _t_str_c4_hal_graphics_point pt){
}

static void SpkeyCB(_t_ma_int key, _t_str_c4_hal_graphics_point pt){
	switch(key){
	case C4_HAL_GRAPHICS_SF_KEY_RIGHT:
		g_coing_location++;
		break;
	case C4_HAL_GRAPHICS_SF_KEY_LEFT:
		g_coing_location--;
		break;
	}
	if(g_coing_location == 7) g_coing_location = 0;
	if(g_coing_location == 0xff) g_coing_location = 6;
	c4_game_draw_coin(g_coing_location,g_curr_player);
}

int c4_game_play_init(void){
	int ret = -1;
	_t_str_c4_game_draw_init inp= {
			.pf_kcb = keyCB,
			.pf_skcb = SpkeyCB,
			.player_color[0] = {1,0,0,0},
			.player_color[1] = {1,1,0,0}
	};
	c4_game_draw_init(inp);
	return ret;
}
