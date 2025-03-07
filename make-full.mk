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
	delay.c delay.h \
	mathCalc.c mathCalc.h \
	PolarCartConv.c PolarCartConv.h

OBJ = 	mathCalc.o mathCalc.i mathCalc.s mathCalc.pie mathCalc.hex \
	complexCalc.o complexCalc.i complexCalc.s complexCalc.pie complexCalc.hex \
	delay.o delay.i delay.s delay.pie delay.hex \
	PolarCartConv PolarCartConv.o PolarCartConv.i PolarCartConv.s PolarCartConv.pie PolarCartConv.hex

all: complexCalc delay mathCalc PolarCartConv

complexCalc: complexCalc.o
	$(CC) -o complexCalc complexCalc.o $(LIBS)

complexCalc.o: $(DEPS)
	$(CC) $(CFLAGS) -c complexCalc.c $(LIBS)
	$(CC) -E complexCalc.c -o complexCalc.i $(LIBS)
	$(CC) -S complexCalc.c -fverbose-asm -o complexCalc.s $(LIBS)
	$(CC) -pie complexCalc.c -o complexCalc.pie $(LIBS)
	objcopy -O ihex complexCalc complexCalc.hex

delay: delay.o
	$(CC) -o delay delay.o

delay.o: $(DEPS)
	$(CC) $(CFLAGS) -c delay.c
	$(CC) -E delay.c -o delay.i
	$(CC) -S delay.c -fverbose-asm -o delay.s
	$(CC) -pie delay.c -o delay.pie
	objcopy -O ihex delay delay.hex

mathCalc: mathCalc.o
	$(CC) -o mathCalc mathCalc.o $(LIBS)

mathCalc.o: $(DEPS)
	$(CC) $(CFLAGS) -c mathCalc.c $(LIBS)
	$(CC) -E mathCalc.c -o mathCalc.i $(LIBS)
	$(CC) -S mathCalc.c -fverbose-asm -o mathCalc.s $(LIBS)
	$(CC) -pie mathCalc.c -o mathCalc.pie $(LIBS)
	objcopy -O ihex mathCalc mathCalc.hex

PolarCartConv: PolarCartConv.o
	$(CC) -o PolarCartConv PolarCartConv.o $(LIBS)

PolarCartConv.o: $(DEPS)
	$(CC) $(CFLAGS) -c PolarCartConv.c $(LIBS)
#~ 	$(CC) -E PolarCartConv.c -o PolarCartConv.i $(LIBS)
#~ 	$(CC) -S PolarCartConv.c -fverbose-asm -o PolarCartConv.s $(LIBS)
#~ 	$(CC) -pie PolarCartConv.c -o PolarCartConv.pie $(LIBS)
#~ 	objcopy -O ihex PolarCartConv PolarCartConv.hex

clean:
	rm -f $(OBJ) 
