/*
 * ma_debug.h
 *
 *  Created on: Mar 9, 2019
 *      Author: mabdelmawla
 */

#ifndef TST_MA_DEBUG_H_
#define TST_MA_DEBUG_H_


#ifdef MA_DEBUG
#include <stdio.h>
static FILE *ma_dbg_fp;
#define MA_DBG_START() \
	do { \
		char name[64] = {0}; \
		sprintf(name, "%s_%s.txt", __DATE__, __TIME__); \
		ma_dbg_fp = fopen(name, "w"); \
	} while(0)
#define MA_DBG_FPRINT(...) fprintf(ma_dbg_fp,__VA_ARGS__)
#define MA_DBG_PRINT(...) printf(__VA_ARGS__)
#define MA_DBG_END() fclose(ma_dbg_fp)
#else
#define MA_DBG_START()
#define MA_DBG_PRING(s)
#define MA_DBG_END()
#endif


#endif /* TST_MA_DEBUG_H_ */
