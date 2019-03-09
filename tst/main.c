#include <stdlib.h>
#include <c4_game_play.h>
#include <ma_debug.h>
#include <stdio.h>


int main(int argc, char**argv) {
	MA_DBG_START();
	c4_game_play_init();
	MA_DBG_END();
	return 0;
}
