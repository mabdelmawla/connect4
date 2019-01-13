#Application name
APP=connect4

#Tools
CC=gcc

#CFLAGS
CFLAGS=-Iinc -I. -g

#Source root
SRC_ROOT=src
TST_ROOT=tst

#libs
LIBS=glut

#Components
SRC=$(wildcard $(TST_ROOT)/*.c) $(wildcard $(SRC_ROOT)/*.c)

all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -l$(LIBS) -o $(APP)

clean: 
	rm $(APP) *.o


