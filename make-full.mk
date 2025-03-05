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
DEPS =  complexCalc.c complexCalc.h \
	mathCalc.c mathCalc.h
OBJ = 	mathCalc.o mathCalc.i mathCalc.s mathCalc.pie mathCalc.hex \
	complexCalc.o complexCalc.i complexCalc.s complexCalc.pie complexCalc.hex

all: complexCalc mathCalc

complexCalc: complexCalc.o
	$(CC) -o complexCalc complexCalc.o $(LIBS)

complexCalc.o: $(DEPS)
	$(CC) $(CFLAGS) -c complexCalc.c $(LIBS)
	$(CC) -E complexCalc.c -o complexCalc.i $(LIBS)
	$(CC) -S complexCalc.c -fverbose-asm -o complexCalc.s $(LIBS)
	$(CC) -pie complexCalc.c -o complexCalc.pie $(LIBS)
	objcopy -O ihex complexCalc complexCalc.hex

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
