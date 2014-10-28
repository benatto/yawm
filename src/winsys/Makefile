CC=gcc

LD_FLAGS=`pkg-config gtk+-3.0 --libs`
LD_FLAGS+=`pkg-config glib-2.0 --libs`
C_FLAGS=`pkg-config gtk+-3.0 --cflags`
C_FLAGS+=`pkg-config glib-2.0 --cflags`

LIBS_PATH=$(PWD)

all: window
	#gcc -o test main.c window.c `pkg-config gtk+-3.0 --cflags --libs` `pkg-config glib-2.0 --cflags --libs`
	$(CC) -L$(LIBS_PATH) -o test main.c $(LD_FLAGS) $(C_FLAGS) -lyawm

window: window.h
	echo $(LD_FLAGS)
	gcc -c -Wall -fpic -g window.c $(LD_FLAGS) $(C_FLAGS)
	gcc -L$(LIBS_PATH) -shared -o libyawm.so window.o
