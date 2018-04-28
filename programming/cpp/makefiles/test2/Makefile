# None of this will actually work; there are no files
# see https://www.youtube.com/watch?time_continue=293&v=aw9wHbFTnAQ

# These are pretty self-explanatory. They're just variables
CC=g++
CFLAGS=-c -Wall

all: hello

# 'hello' is the target, the *.o files are the dependencies, and the
# next line is the command

# The command is executing all the *.o files. The rules for making
# those are listed below it. Similarly, the 'all' target depends on
# 'hello' which is outlined here

hello: main.o function1.o function2.o
	$(CC) main.o function1.o function2.o -o hello

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

function1.o: function1.cpp
	$(CC) $(CFLAGS) function1.cpp

function2.o: function2.cpp
	$(CC) $(CFLAGS) function2.cpp

clean:
	rm -rf *o hello
