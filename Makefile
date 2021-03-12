
# CC=arm-linux-gnueabihf-gcc
CC=gcc

SRC += ./src
INC += -I./src
CFLAG += -lpthread

obj += $(SRC)/main.c
obj += $(SRC)/fbmap.c

target:
	$(CC) -Wall -o app $(obj) $(INC) $(CFLAG)

clean:
	rm app -rf
