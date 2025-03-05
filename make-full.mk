#************************************************************************
# 	Makefile for complexCalc.c - Complex Number Functions
#************************************************************************

# Compiler flags
CC=gcc
CFLAGS=-Wall -g

# Debug build settings
DEBUG=-g

# Libraries
LIBS=-lm -lcheck -lpthread -lrt -lsubunit -lcheck_pic 
## `pkg-config --cflags gtk+-2.0`

# Dependencies
DEPS = complexCalc.c complexCalc.h
OBJ = complexCalc.o complexCalc.i complexCalc.s complexCalc.pie complexCalc.hex

all: complexCalc

complexCalc: complexCalc.o
	$(CC) -o complexCalc complexCalc.o $(LIBS)

complexCalc.o: $(DEPS)
	$(CC) $(CFLAGS) -c complexCalc.c $(LIBS)
	$(CC) -E complexCalc.c -o complexCalc.i $(LIBS)
	$(CC) -S complexCalc.c -fverbose-asm -o complexCalc.s $(LIBS)
	$(CC) -pie complexCalc.c -o complexCalc.pie $(LIBS)
	objcopy -O ihex complexCalc complexCalc.hex

clean:
	rm -f $(OBJ) 
