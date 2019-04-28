# Flags
CC = gcc
OBJ = gcc -c
CFLAGS = -I ./inc -Wall -lm -g 

all: main clean

# Main file
main: algraph.o util.o
	$(CC) src/main.c algraph.o util.o -o ./bin/tp2 $(CFLAGS)

# Compile object files
algraph.o:
	$(OBJ) src/algraph.c $(CFLAGS)

util.o:
	$(OBJ) src/util.c $(CFLAGS)

# Clean object files
clean:	
	rm algraph.o util.o
