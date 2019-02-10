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

// Special keys defines
#define C4_HAL_GRAPHICS_SF_KEY_F_BASE	0xA500
#define C4_HAL_GRAPHICS_SF_KEY_F1	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 1)
#define C4_HAL_GRAPHICS_SF_KEY_F2	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 2)
#define C4_HAL_GRAPHICS_SF_KEY_F3	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 3)
#define C4_HAL_GRAPHICS_SF_KEY_F4	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 4)
#define C4_HAL_GRAPHICS_SF_KEY_F5	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 5)
#define C4_HAL_GRAPHICS_SF_KEY_F6	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 6)
#define C4_HAL_GRAPHICS_SF_KEY_F7	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 7)
#define C4_HAL_GRAPHICS_SF_KEY_F8	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 8)
#define C4_HAL_GRAPHICS_SF_KEY_F9	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 9)
#define C4_HAL_GRAPHICS_SF_KEY_F10	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 10)
#define C4_HAL_GRAPHICS_SF_KEY_F11	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 11)
#define C4_HAL_GRAPHICS_SF_KEY_F12	(C4_HAL_GRAPHICS_SF_KEY_F_BASE + 12)

#define C4_HAL_GRAPHICS_SF_KEY_DIR_BASE	0xB500
#define C4_HAL_GRAPHICS_SF_KEY_LEFT		(C4_HAL_GRAPHICS_SF_KEY_DIR_BASE + 1)
#define C4_HAL_GRAPHICS_SF_KEY_UP		(C4_HAL_GRAPHICS_SF_KEY_DIR_BASE + 2)
#define C4_HAL_GRAPHICS_SF_KEY_RIGHT	(C4_HAL_GRAPHICS_SF_KEY_DIR_BASE + 3)
#define C4_HAL_GRAPHICS_SF_KEY_DOWN		(C4_HAL_GRAPHICS_SF_KEY_DIR_BASE + 4)

#define C4_HAL_GRAPHICS_SF_KEY_OTHER_BASE	0xC500
#define C4_HAL_GRAPHICS_SF_KEY_PAGE_UP		(C4_HAL_GRAPHICS_SF_KEY_OTHER_BASE + 1)
#define C4_HAL_GRAPHICS_SF_KEY_PAGE_DOWN	(C4_HAL_GRAPHICS_SF_KEY_OTHER_BASE + 2)
#define C4_HAL_GRAPHICS_SF_KEY_PAGE_HOME	(C4_HAL_GRAPHICS_SF_KEY_OTHER_BASE + 3)
#define C4_HAL_GRAPHICS_SF_KEY_PAGE_END		(C4_HAL_GRAPHICS_SF_KEY_OTHER_BASE + 4)
#define C4_HAL_GRAPHICS_SF_KEY_PAGE_INS		(C4_HAL_GRAPHICS_SF_KEY_OTHER_BASE + 5)

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



typedef void (*_t_c4_hal_graphics_key_callback)(_t_ma_char, _t_str_c4_hal_graphics_point); /* called on key press */

_t_c4_err c4_hal_graphics_init(int *argc, char***argv, _t_c4_hal_graphics_key_callback);
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
