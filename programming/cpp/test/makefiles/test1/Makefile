# Variables
CC=gcc
# This flag tells gcc to look for the files in the current directory
CFLAGS=-I.
DEPS = hellomake.h
OBJ = hellomake.o hellofunc.o

# With no arguments, make executes the first rule in the file

# The files listed after the ':' are what the command depends on. It
# lets make know that the rule needs to be executed if any of the
# files change.

# Note: you must tab for anything after the first line otherwise make
# won't work

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


hellomake: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)
