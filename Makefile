PROGRAM = iniparser
CC = g++
CFLAGS = -Wall
SRCS = main.cpp ini_parse.cpp

all:
	$(CC) $(CFLAGS) -o $(PROGRAM) $(SRCS)

clean:
	rm $(PROGRAM)

