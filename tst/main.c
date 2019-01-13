#include <stdlib.h>
#include <c4_hal_graphics.h>

void keyCB(_t_ma_char key, _t_str_c4_hal_graphics_point pt){
	if('q' == key) exit(0);
}

int main(int argc, char**argv) {
	c4_hal_graphics_init(&argc, &argv, keyCB);
	return 0;
}
