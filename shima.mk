# Compiler

CC = g++

# Flags to the compiler

CFLAGS = -Wall

all: H3

H3: shima.cpp 
	$(CC) $(CFLAGS) shima.cpp -o run_shimaH3

clean:
	rm -rf H3
