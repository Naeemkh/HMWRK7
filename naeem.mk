# -------- makefile --------------

CC = g++

# Flags to the compiler

CFLAGS = -Wall

all: prime

prime: naeem.cpp
	$(CC) $(CFLAGS) io_print_handler.cpp input_validate.cpp earthquake.cpp station.cpp  naeem.cpp -o naeem 

clean:
	rm -rf naeem

