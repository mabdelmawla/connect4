/*
 * c4_game_draw.c
 *
 *  Created on: Feb 7, 2019
 *      Author: mabdelmawla
 */

#include <c4_game_draw.h>
#include <ma_types.h>
#include <c4_err.h>

#define C4_GAME_DRAW_UNIT			120
#define C4_CIRCLE_R					(C4_GAME_DRAW_UNIT * 8 / 20)
#define C4_GAME_DRAW_NUM_H_UNIT		8
#define C4_GAME_DRAW_NUM_W_UNIT		9
#define C4_GAME_DRAW_WINDOW_HIGHT 	(C4_GAME_DRAW_NUM_H_UNIT * C4_GAME_DRAW_UNIT)
#define C4_GAME_DRAW_WINDOW_WIDTH	(C4_GAME_DRAW_NUM_W_UNIT * C4_GAME_DRAW_UNIT)

static _t_str_c4_hal_graphics_window gstr_main_win_cfg = { .height =
C4_GAME_DRAW_WINDOW_HIGHT, .width = C4_GAME_DRAW_WINDOW_WIDTH, .bg_color = { 0,
		0, 0, 0 }, .pt_window_start = { 0, 0 }, .win_name = "Connect 4" };

static _t_str_c4_hal_object objs[50] = { 0 };
static _t_str_c4_hal_object *g_slot_array[7];
static _t_str_c4_hal_object *g_coin_pointer_array;
static _t_str_c4_game_draw_init gstr_inp;
static int g_num_objs = 0;

static void initialize_objects(void) {
	int cnt = 0;
	//draw the game frame
	objs[cnt].type = C4_HAL_GRAPHICS_RECTANGLE;
	objs[cnt].color.b = 1;
	objs[cnt].uni_obj.rectangle.bottom_left.x = C4_GAME_DRAW_UNIT;
	objs[cnt].uni_obj.rectangle.bottom_left.y = C4_GAME_DRAW_UNIT;
	objs[cnt].uni_obj.rectangle.top_right.x = C4_GAME_DRAW_WINDOW_WIDTH
			- C4_GAME_DRAW_UNIT;
	objs[cnt].uni_obj.rectangle.top_right.y = C4_GAME_DRAW_WINDOW_HIGHT
			- C4_GAME_DRAW_UNIT;
	cnt++;

	//draw coin pointers
	g_coin_pointer_array = &objs[cnt];
	for (int i = 0; i < 7; i++) {
		g_coin_pointer_array[i].type = C4_HAL_GRAPHICS_CIRCLE;
		g_coin_pointer_array[i].uni_obj.circle.center.x = C4_GAME_DRAW_UNIT
				* (3 + 2 * i) / 2;
		g_coin_pointer_array[i].uni_obj.circle.center.y =
				C4_GAME_DRAW_WINDOW_HIGHT - C4_GAME_DRAW_UNIT / 2;
		g_coin_pointer_array[i].uni_obj.circle.radius = C4_CIRCLE_R;
		g_coin_pointer_array[i].uni_obj.circle.finess = 120;
		cnt++;
	}
	g_coin_pointer_array[0].color = gstr_inp.player_color[0];

	//draw circles array
	for (int i = 0; i < 7; i++) {
		g_slot_array[i] = &objs[cnt];
		for (int j = 0; j < 6; j++) {
			g_slot_array[i][j].type = C4_HAL_GRAPHICS_CIRCLE;
			g_slot_array[i][j].uni_obj.circle.center.x = C4_GAME_DRAW_UNIT
					* (3 + 2 * i) / 2;
			g_slot_array[i][j].uni_obj.circle.center.y = C4_GAME_DRAW_UNIT
					* (3 + 2 * j) / 2;
			g_slot_array[i][j].uni_obj.circle.radius = C4_CIRCLE_R;
			g_slot_array[i][j].uni_obj.circle.finess = 120;
			cnt++;
		}
	}
	g_num_objs = cnt;
}

_t_c4_err c4_game_draw_coin(_t_ma_u8 coin_location, _t_ma_u8 player){
	g_coin_pointer_array[coin_location%7].color = gstr_inp.player_color[player];
}

_t_c4_err c4_game_draw_init(_t_str_c4_game_draw_init inp) {
	_t_c4_err ret = C4_ERR_NOT_OK;
	gstr_inp = inp;
	initialize_objects();
	c4_hal_graphics_draw_objects(g_num_objs, objs);
	c4_hal_graphics_init(&gstr_main_win_cfg, inp.pf_kcb, inp.pf_skcb);
	return ret;
}
