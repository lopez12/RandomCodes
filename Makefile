CC = gcc
CFLAGS = -Wall -Werror
OUTPUT = Cliente.out
DEBUG = -g
SOURCES = cliente.c 

all:
	$(CC) $(SOURCES) $(CFLAGS) -o $(OUTPUT)

debug:
	$(CC) $(SOURCES) $(CFLAGS) $(DEBUG) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

fresh:
	make clean
	make all
