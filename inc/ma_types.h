/**
@file		ma_types.h
@brief		This module contains common data types definitions
@author		M. Abdelmawla
@date		22 DEC 2017
@version	1.0

ma_clib is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ma_clib is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ma_clib.  If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef _MA_TYPES_H_
#define _MA_TYPES_H_

typedef char				_t_ma_char;
typedef unsigned char		_t_ma_u8;
typedef unsigned short		_t_ma_u16;
#ifndef __linux__
	typedef unsigned long		_t_ma_u32;
#else
	typedef unsigned int		_t_ma_u32;
#endif

typedef void				_t_ma_void;
typedef int					_t_ma_int;

typedef signed char			_t_ma_s8;
typedef signed short		_t_ma_s16;
typedef signed long			_t_ma_s32;

typedef unsigned char 		_t_ma_bool;

#define MA_NULL		((void*)0)

#define TRUE 					1
#define FALSE 					0

#endif //_MA_TYPES_H_
