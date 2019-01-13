/*
 * c4_hal_graphics_opengl.c
 *
 *  Created on: Jan 13, 2019
 *      Author: mabdelmawla
 */
#include <GL/glut.h>

#include <c4_hal_graphics.h>

_t_c4_err c4_hal_graphics_init(int argc, char**argv){
	_t_c4_err ret = C4_ERR_OK;
    glutInit(&argc, argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Hello World");
    glutMainLoop();
	return ret;
}

_t_c4_err c4_hal_graphics_deinit(void){
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

_t_c4_err c4_hal_graphics_line(
		_t_str_c4_hal_graphics_point ptStart,
		_t_str_c4_hal_graphics_point ptEnd,
		_t_str_c4_hal_graphics_color color
		){
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

_t_c4_err c4_hal_graphics_circle(
		_t_str_c4_hal_graphics_point ptCenter,
		_t_ma_u16 radius,
		_t_str_c4_hal_graphics_color Color,
		_t_ma_bool isFilled
		){
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

_t_c4_err c4_hal_graphics_rectangle(
		_t_str_c4_hal_graphics_point ptStart,
		_t_str_c4_hal_graphics_point ptEnd,
		_t_str_c4_hal_graphics_color color,
		_t_ma_bool isFilled
		){
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

