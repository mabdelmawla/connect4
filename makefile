#Application name
APP=connect4

#Tools
CC=gcc

#CFLAGS
CFLAGS=-Iinc -I. -g

#Source root
SRC_ROOT=src
TST_ROOT=tst

#Components
SRC=$(wildcard $(TST_ROOT)/*.c) $(wildcard $(SRC_ROOT)/ma_aes/*.c)

all: $(SRC)
	$(CC) $(SRC) $(CFLAGS) -o $(APP)

clean: 
	rm $(APP) *.o


