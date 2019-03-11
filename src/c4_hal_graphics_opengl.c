/*
 * c4_hal_graphics_opengl.c
 *
 *  Created on: Jan 13, 2019
 *      Author: mabdelmawla
 */
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

#include <c4_hal_graphics.h>

/** static declarations **/
static _t_c4_hal_graphics_key_callback gpf_key_cb;
static _t_c4_hal_graphics_special_key_callback gpf_sp_key_cb;
static _t_str_c4_hal_graphics_window *g_win;

static _t_str_c4_hal_object* gp_obj_array = NULL;
static _t_ma_u32 gu32_num_objs = 0;

/** internal functionality **/
static void draw_point(_t_str_c4_hal_graphics_point p,
		_t_str_c4_hal_graphics_color c) {
	glColor3f(c.r, c.g, c.b);
	glPointSize(3.0f);
	glBegin(GL_POINTS);
	glVertex2i(p.x, p.y);
	glEnd();
}

static void draw_line(_t_str_c4_hal_graphics_line l,
		_t_str_c4_hal_graphics_color c) {
	glColor3f(c.r, c.g, c.b);

	//glPointSize(l.thickness); // TODO: fine a solution for this point to work;

	glBegin(GL_LINES); /* draw filled triangle */
	glVertex2i(l.start.x, l.start.y);
	glVertex2i(l.end.x, l.end.y);
	glEnd(); /* OpenGL draws the filled triangle */
}

static void draw_rectangle(_t_str_c4_hal_graphics_rectanble r,
		_t_str_c4_hal_graphics_color c) {
	glColor3f(c.r, c.g, c.b);

	glBegin(GL_POLYGON); /* draw filled rectangle */
	glVertex2i(r.bottom_left.x, r.bottom_left.y);
	glVertex2i(r.top_right.x, r.bottom_left.y);
	glVertex2i(r.top_right.x, r.top_right.y);
	glVertex2i(r.bottom_left.x, r.top_right.y);
	glEnd();
}

static void draw_circle(_t_str_c4_hal_graphics_circle circle,
		_t_str_c4_hal_graphics_color c) {
	int i;
	const float pi = 3.14159265358979323846;
	glColor3f(c.r, c.g, c.b);

	glBegin(GL_POLYGON); /* draw filled circle */
	for (i = 0; i < circle.finess; i++) {
		float x, y;
		x = circle.center.x
				+ circle.radius * cosf((i * 2 * pi) / circle.finess);
		y = circle.center.y
				+ circle.radius * sinf((i * 2 * pi) / circle.finess);
		glVertex2i(x, y);
	}
	glEnd();
}

static void c4_hal_graphics_write_string(_t_str_c4_hal_graphics_string s,
		_t_str_c4_hal_graphics_color c) {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, g_win->width, 0.0, g_win->height);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
    glColor3f(c.r, c.g, c.b);
	glRasterPos2i(s.pt.x, s.pt.y);
	for (int i = 0; s.s[i] != '\0'; i++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s.s[i]);
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

    //glutSwapBuffers();
}

static void displayCB(void) {
	glClear(GL_COLOR_BUFFER_BIT); /* clear the display */
	for (unsigned int i = 0; i < gu32_num_objs; i++) {
		switch (gp_obj_array[i].type) {
		case C4_HAL_GRAPHICS_PT:
			draw_point(gp_obj_array[i].uni_obj.pt, gp_obj_array[i].color);
			break;
		case C4_HAL_GRAPHICS_LINE:
			draw_line(gp_obj_array[i].uni_obj.line, gp_obj_array[i].color);
			break;
		case C4_HAL_GRAPHICS_RECTANGLE:
			draw_rectangle(gp_obj_array[i].uni_obj.rectangle,
					gp_obj_array[i].color);
			break;
		case C4_HAL_GRAPHICS_CIRCLE:
			draw_circle(gp_obj_array[i].uni_obj.circle, gp_obj_array[i].color);
			break;
		case C4_HAL_GRAPHICS_STRING:
			c4_hal_graphics_write_string(gp_obj_array[i].uni_obj.string, gp_obj_array[i].color);
			break;
		default:
			break;
		}
	}
	glFlush(); /* Complete any pending operations */
}

static void keyCB(unsigned char key, int x, int y) /* called on key press */
{
	_t_str_c4_hal_graphics_point pt = { x, y , 1};
	glutPostRedisplay();
	gpf_key_cb((_t_ma_char) key, pt);
}

static void SpecialKeyCb(int key, int x, int y) {
	_t_str_c4_hal_graphics_point pt = { x, y, 1 };
	glutPostRedisplay();
	gpf_sp_key_cb((_t_ma_int) key, pt);
}

/**
 * APIs
 */

_t_c4_err c4_hal_graphics_init(_t_str_c4_hal_graphics_window* pwin,
		_t_c4_hal_graphics_key_callback cb,
		_t_c4_hal_graphics_special_key_callback sp_cb) {
	_t_c4_err ret = C4_ERR_OK;
	int dummy = 1;
	gpf_key_cb = cb;
	gpf_sp_key_cb = sp_cb;
	g_win = pwin;
	glutInit(&dummy, NULL); /* initialize GLUT system */

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(pwin->width, pwin->height); /* width=400pixels height=500pixels */
	pwin->win_handle = glutCreateWindow(pwin->win_name); /* create window */

	/* from this point on the current window is win */

	glClearColor(pwin->bg_color.r, pwin->bg_color.g, pwin->bg_color.b,
			pwin->bg_color.alfa); /* set background to black */
	gluOrtho2D(0, pwin->width, 0, pwin->height); /* how object is mapped to window */
	glutDisplayFunc(displayCB); /* set window's display callback */
	glutKeyboardFunc(keyCB); /* set window's key callback */
	glutSpecialFunc(SpecialKeyCb);

	glutMainLoop(); /* start processing events... */

	/* execution never reaches this point */
	return ret;
}

_t_c4_err c4_hal_graphics_deinit(void) {
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

_t_c4_err c4_hal_graphics_draw_objects(_t_ma_u32 num_objects,
		_t_str_c4_hal_object *objects_array) {
	_t_c4_err ret = C4_ERR_OK;
	gp_obj_array = objects_array;
	gu32_num_objs = num_objects;
	return ret;
}

