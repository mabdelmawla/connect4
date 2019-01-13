/*
 * c4_hal_graphics.h
 *
 *  Created on: Jan 13, 2019
 *      Author: mabdelmawla
 */

#ifndef INC_C4_HAL_GRAPHICS_H_
#define INC_C4_HAL_GRAPHICS_H_

#include <ma_types.h>
#include <c4_err.h>

typedef struct _str_c4_hal_graphics_point{
	_t_ma_u16	x;
	_t_ma_u16	y;
} _t_str_c4_hal_graphics_point;

typedef struct _str_c4_hal_graphics_color{
	_t_ma_u8	r;
	_t_ma_u8	g;
	_t_ma_u8	b;
	_t_ma_u8	alfa;
} _t_str_c4_hal_graphics_color;

_t_c4_err c4_hal_graphics_init(void);
_t_c4_err c4_hal_graphics_deinit(void);
_t_c4_err c4_hal_graphics_line(
		_t_str_c4_hal_graphics_point ptStart,
		_t_str_c4_hal_graphics_point ptEnd,
		_t_str_c4_hal_graphics_color color
		);
_t_c4_err c4_hal_graphics_circle(
		_t_str_c4_hal_graphics_point ptCenter,
		_t_ma_u16 radius,
		_t_str_c4_hal_graphics_color Color,
		_t_ma_bool isFilled
		);
_t_c4_err c4_hal_graphics_rectangle(
		_t_str_c4_hal_graphics_point ptStart,
		_t_str_c4_hal_graphics_point ptEnd,
		_t_str_c4_hal_graphics_color color,
		_t_ma_bool isFilled
		);
#endif /* INC_C4_HAL_GRAPHICS_H_ */
