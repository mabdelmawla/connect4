/*
 * c4_game_draw.h
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#ifndef INC_C4_GAME_DRAW_H_
#define INC_C4_GAME_DRAW_H_

#include <c4_hal_graphics.h>

typedef enum _enu_c4_game_draw_players {
	C4_GAME_DRAW_PLAYER_1 = 0,
	C4_GAME_DRAW_PLAYER_2 = 1,
} _t_enu_c4_game_draw_players;

typedef struct _str_c4_game_draw_init {
	_t_c4_hal_graphics_key_callback pf_kcb;
	_t_c4_hal_graphics_special_key_callback pf_skcb;
	_t_str_c4_hal_graphics_color player_1_color;
	_t_str_c4_hal_graphics_color player_2_color;
} _t_str_c4_game_draw_init;

int c4_game_draw_init(_t_str_c4_game_draw_init);

#endif /* INC_C4_GAME_DRAW_H_ */
