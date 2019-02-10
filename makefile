#Application name
APP=connect4

#select graphics lib
#available options: GL_GLUT
GRAPHICS_LIB=GL_GLUT

#Tools
CC=gcc

#CFLAGS
ifeq ($(GRAPHICS_LIB),GL_GLUT)
	#CFLAGS=-Iinc -I. -g -lglut -lGLU -lGL -lXmu -lXi -lXext -lX11 -lm
	CFLAGS=-Iinc -I. -g -lglut -lGL -lGLU -D$(GRAPHICS_LIB)
else
	CFLAGS=-Iinc -I. -g
endif

#Source root
SRC_ROOT=src
TST_ROOT=tst

#Components
SRC=$(wildcard $(TST_ROOT)/*.c) $(wildcard $(SRC_ROOT)/*.c)

all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(APP)

clean: 
	rm $(APP)


