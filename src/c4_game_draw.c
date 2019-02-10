/*
 * c4_game_draw.c
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#include <c4_game_draw.h>
#include <ma_types.h>
#include <c4_err.h>

_t_c4_err c4_game_draw_init(_t_c4_hal_graphics_key_callback cb, _t_c4_hal_graphics_special_key_callback sp_cb){
	_t_c4_err ret = C4_ERR_NOT_OK;
	c4_hal_graphics_init(cb, sp_cb);
	return ret;
}
