#************************************************************************
# 	Makefile for mathCalc.c - Integrals and Derivatives of Fucntions
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
DEPS = mathCalc.c mathCalc.h
OBJ = mathCalc.o mathCalc.i mathCalc.s mathCalc.pie mathCalc.hex

all: mathCalc

mathCalc: mathCalc.o
	$(CC) -o mathCalc mathCalc.o $(LIBS)

mathCalc.o: $(DEPS)
	$(CC) $(CFLAGS) -c mathCalc.c $(LIBS)
	$(CC) -E mathCalc.c -o mathCalc.i $(LIBS)
	$(CC) -S mathCalc.c -fverbose-asm -o mathCalc.s $(LIBS)
	$(CC) -pie mathCalc.c -o mathCalc.pie $(LIBS)
	objcopy -O ihex mathCalc mathCalc.hex

clean:
	rm -f $(OBJ) 
