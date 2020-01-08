# The compiler: gcc for C programs, g++ for C++ progams
CC = gcc

# Compiler flags:
#  -g    Include debugger information
#  -Wall Turns on, but not all, compiler warnings 
CFLAGS = -g -Wall

# The build target executable
TARGET = gpw  

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c 

