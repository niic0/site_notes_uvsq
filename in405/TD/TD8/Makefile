CC=gcc

.PHONY: all

all: client server

server: server.c
	$(CC) -Wall -o $@ $^

client: client.c
	$(CC) -Wall -o $@ $^
