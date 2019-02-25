/*
 * c4_game_draw.c
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#include <c4_game_draw.h>
#include <ma_types.h>
#include <c4_err.h>

static _t_str_c4_hal_graphics_window gstr_main_win_cfg = {
		.height =800,
		.width = 800,
		.bg_color = {0,0,0,0},
		.pt_window_start = {0,0},
		.win_name = "Connect 4"
};

static _t_str_c4_hal_object objs[50];

_t_c4_err c4_game_draw_init(_t_c4_hal_graphics_key_callback cb, _t_c4_hal_graphics_special_key_callback sp_cb){
	_t_c4_err ret = C4_ERR_NOT_OK;
	objs[0].type = C4_HAL_GRAPHICS_LINE;
	objs[0].color.alfa = 0;
	objs[0].color.r = 255.0;
	objs[0].color.g = 0;
	objs[0].color.b = 0;
	objs[0].uni_obj.line.start.x = 100;
	objs[0].uni_obj.line.start.y = 200;
	objs[0].uni_obj.line.end.x = 200;
	objs[0].uni_obj.line.end.y = 200;

	objs[0].type = C4_HAL_GRAPHICS_RECTANGLE;
	objs[0].color.alfa = 0;
	objs[0].color.r = 0;
	objs[0].color.g = 255;
	objs[0].color.b = 0;
	objs[0].uni_obj.rectangle.bottom_left.x = 120;
	objs[0].uni_obj.rectangle.bottom_left.y = 120;
	objs[0].uni_obj.rectangle.top_right.x = 240;
	objs[0].uni_obj.rectangle.top_right.y = 240;

	objs[1].type = C4_HAL_GRAPHICS_LINE;
	objs[1].color.alfa = 0;
	objs[1].color.r = 255.0;
	objs[1].color.g = 0;
	objs[1].color.b = 0;
	objs[1].uni_obj.line.start.x = 100;
	objs[1].uni_obj.line.start.y = 200;
	objs[1].uni_obj.line.end.x = 200;
	objs[1].uni_obj.line.end.y = 200;

	objs[2].type = C4_HAL_GRAPHICS_CIRCLE;
	objs[2].color.alfa = 0;
	objs[2].color.r = 0;
	objs[2].color.g = 0;
	objs[2].color.b = 255;
	objs[2].uni_obj.circle.center.x = 300;
	objs[2].uni_obj.circle.center.y = 300;
	objs[2].uni_obj.circle.radius = 100;
	objs[2].uni_obj.circle.finess = 180;
	c4_hal_graphics_draw_objects(3,objs);

	c4_hal_graphics_init(&gstr_main_win_cfg, cb, sp_cb);
#if 0
	_t_str_c4_hal_graphics_line l;
	l.start.x = 100;
	l.start.y = 200;
	l.end.x = 200;
	l.end.y = 200;
	l.thickness = 10;
	_t_str_c4_hal_graphics_rectanble r;
	r.bottom_left.x = 0;
	r.bottom_left.y = 0;
	r.top_right.x = 200;
	r.top_right.y = 200;
	_t_str_c4_hal_graphics_color c = {0};
	c.r = 255;
	draw_line(l, c);
	c.g = 255;
	draw_rectangle(r, c);
	_t_str_c4_hal_graphics_point p;
	p.x = 120;
	p.y = 120;
	c.r = 0;
	c.g = 0;
	c.b = 255;
	draw_point(p, c);
	_t_str_c4_hal_graphics_circle circle;
	circle.center.x = 100;
	circle.center.y = 200;
	circle.radius = 75;
	circle.finess = 360;
	draw_circle(circle, c);
#endif
	return ret;
}
