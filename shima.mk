# Compiler

CC = g++

# Flags to the compiler

CFLAGS = -Wall

all: H2

H2: H2.cpp 
	$(CC) $(CFLAGS) H2.cpp -o run_H2

clean:
	rm -rf H2
