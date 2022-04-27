# See https://cs.colby.edu/maxwell/courses/tutorials/maketutor
# The compiler: gcc for C programs, g++ for C++ progams
CC=gcc

# Compiler flags:
#  -g    Include debugger information
#  -Wall Turns on, but not all, compiler warnings
#  -I.   Include files in the current directory
CFLAGS=-g -Wall -I.

# The build target executable
TARGET=gpw
# The include (header) files
DEPS=gen.h
# All object files
OBJ=gpw.o gen.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

gpw: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o $(TARGET)

# $(TARGET): $(TARGET).c
#	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c 

