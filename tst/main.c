#include <stdlib.h>
#include <c4_game_play.h>
#include <ma_debug.h>
#include <stdio.h>

FILE *ma_dbg_fp;

int main(void) {
	MA_DBG_START();
	c4_game_play_init();
	MA_DBG_END();
	return 0;
}
