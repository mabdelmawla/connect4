/*
 * c4_game_play.c
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#include <c4_game_play.h>

#include <c4_game_draw.h>
#include <c4_hal_graphics.h>


static void keyCB(_t_ma_char key, _t_str_c4_hal_graphics_point pt){
}

static void SpkeyCB(_t_ma_int key, _t_str_c4_hal_graphics_point pt){
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
