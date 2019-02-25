/*
 * c4_hal_graphics_opengl.c
 *
 *  Created on: Jan 13, 2019
 *      Author: mabdelmawla
 */
#include <GL/glut.h>
#include <GL/gl.h>

#include <c4_hal_graphics.h>

/** static declarations **/
static _t_c4_hal_graphics_key_callback gpf_key_cb;
static _t_c4_hal_graphics_special_key_callback gpf_sp_key_cb;

int xx, yy, cc;

/** internal functionality **/
static void draw_point(_t_str_c4_hal_graphics_point p, _t_str_c4_hal_graphics_color c){
    glColor3f(c.r,c.g,c.b);
    glPointSize(3.0f);
    glBegin(GL_POINTS);
        glVertex2i(p.x, p.y);
    glEnd();


}

static void draw_line(_t_str_c4_hal_graphics_line l, _t_str_c4_hal_graphics_color c){
    glColor3f(c.r,c.g,c.b);

	//glPointSize(l.thickness); // TODO: fine a solution for this point to work;

	glBegin(GL_LINES); /* draw filled triangle */
		glVertex2i(l.start.x, l.start.y);
		glVertex2i(l.end.x, l.end.y);
	glEnd(); /* OpenGL draws the filled triangle */
}

static void draw_rectangle(_t_str_c4_hal_graphics_rectanble r, _t_str_c4_hal_graphics_color c){
    glColor3f(c.r,c.g,c.b);

	glBegin(GL_POLYGON); /* draw filled triangle */
		glVertex2i(r.bottom_left.x, r.bottom_left.y);
		glVertex2i(r.top_right.x, r.bottom_left.y);
		glVertex2i(r.top_right.x, r.top_right.y);
		glVertex2i(r.bottom_left.x, r.top_right.y);
	glEnd();
}

static void displayCB(void) {
	glClear(GL_COLOR_BUFFER_BIT); /* clear the display */
	glColor3f(1.0, 1.0, cc); /* set current color to white */
	glBegin(GL_POLYGON); /* draw filled triangle */
	glVertex2i(xx, yy); /* specify each vertex of triangle */
	glVertex2i(100, 375);
	glVertex2i(300, 375);
	glEnd(); /* OpenGL draws the filled triangle */
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
	glFlush(); /* Complete any pending operations */
}

static void keyCB(unsigned char key, int x, int y) /* called on key press */
{
	_t_str_c4_hal_graphics_point pt = {x, y};
	xx += 20;
	yy += 20;
	cc++;
	glutPostRedisplay();
	gpf_key_cb((_t_ma_char)key, pt);
}

static void SpecialKeyCb(int key, int x, int y){
	_t_str_c4_hal_graphics_point pt = {x, y};
	xx += 20;
	yy += 20;
	cc++;
	glutPostRedisplay();
	gpf_sp_key_cb((_t_ma_int)key, pt);
}


/**
 * APIs
 */

_t_c4_err c4_hal_graphics_init(
		_t_str_c4_hal_graphics_window* pwin,
		_t_c4_hal_graphics_key_callback cb,
		_t_c4_hal_graphics_special_key_callback sp_cb) {
	_t_c4_err ret = C4_ERR_OK;
	int dummy = 1;
	xx = 200;
	yy = 125;
	cc = 1;

	gpf_key_cb = cb;
	gpf_sp_key_cb = sp_cb;
	glutInit(&dummy, NULL); /* initialize GLUT system */

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(pwin->width, pwin->height); /* width=400pixels height=500pixels */
	pwin->win_handle = glutCreateWindow(pwin->win_name); /* create window */

	/* from this point on the current window is win */

	glClearColor(
			pwin->bg_color.r,
			pwin->bg_color.g,
			pwin->bg_color.b,
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

_t_c4_err c4_hal_graphics_draw_objects(
		_t_ma_u32	num_objects,
		_t_str_c4_hal_object *objects_array
		){
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}


