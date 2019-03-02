/*
 * c4_game_draw.h
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#ifndef INC_C4_GAME_DRAW_H_
#define INC_C4_GAME_DRAW_H_

#include <c4_hal_graphics.h>

typedef struct _str_c4_game_draw_init {
	_t_c4_hal_graphics_key_callback pf_kcb;
	_t_c4_hal_graphics_special_key_callback pf_skcb;
	_t_str_c4_hal_graphics_color player_color[2];
} _t_str_c4_game_draw_init;

_t_c4_err c4_game_draw_init(_t_str_c4_game_draw_init);
void c4_game_draw_coin(_t_ma_u8, _t_ma_u8);
void c4_game_board_update(_t_ma_u8, _t_ma_u8, _t_ma_u8);

#endif /* INC_C4_GAME_DRAW_H_ */
