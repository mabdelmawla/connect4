/*
 * c4_hal_graphics_opengl.c
 *
 *  Created on: Jan 13, 2019
 *      Author: mabdelmawla
 */
#include <GL/glut.h>
#include <GL/gl.h>

#include <c4_hal_graphics.h>

static _t_c4_hal_graphics_key_callback gpf_key_cb;

int xx, yy, cc;

static void displayCB(void) {
	glClear(GL_COLOR_BUFFER_BIT); /* clear the display */
	glColor3f(1.0, 1.0, cc); /* set current color to white */
	glBegin(GL_POLYGON); /* draw filled triangle */
	glVertex2i(xx, yy); /* specify each vertex of triangle */
	glVertex2i(100, 375);
	glVertex2i(300, 375);
	glEnd(); /* OpenGL draws the filled triangle */
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

_t_c4_err c4_hal_graphics_init(int *argc, char***argv, _t_c4_hal_graphics_key_callback cb) {
	_t_c4_err ret = C4_ERR_OK;
	int win;
	xx = 200;
	yy = 125;
	cc = 1;

	gpf_key_cb = cb;
	glutInit(argc, *argv); /* initialize GLUT system */

	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400, 500); /* width=400pixels height=500pixels */
	win = glutCreateWindow("Triangle"); /* create window */

	/* from this point on the current window is win */

	glClearColor(0.0, 0.0, 0.0, 0.0); /* set background to black */
	gluOrtho2D(0, 400, 0, 500); /* how object is mapped to window */
	glutDisplayFunc(displayCB); /* set window's display callback */
	glutKeyboardFunc(keyCB); /* set window's key callback */

	glutMainLoop(); /* start processing events... */

	/* execution never reaches this point */
	return ret;
}

_t_c4_err c4_hal_graphics_deinit(void) {
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

_t_c4_err c4_hal_graphics_line(_t_str_c4_hal_graphics_point ptStart,
		_t_str_c4_hal_graphics_point ptEnd, _t_str_c4_hal_graphics_color color) {
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

_t_c4_err c4_hal_graphics_circle(_t_str_c4_hal_graphics_point ptCenter,
		_t_ma_u16 radius, _t_str_c4_hal_graphics_color Color,
		_t_ma_bool isFilled) {
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

_t_c4_err c4_hal_graphics_rectangle(_t_str_c4_hal_graphics_point ptStart,
		_t_str_c4_hal_graphics_point ptEnd, _t_str_c4_hal_graphics_color color,
		_t_ma_bool isFilled) {
	_t_c4_err ret = C4_ERR_OK;
	return ret;
}

