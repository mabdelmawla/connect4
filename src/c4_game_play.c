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
	c4_game_draw_init(keyCB, SpkeyCB);
	return ret;
}
