CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c11

SRC = main.c src/server.c src/file-handler.c
OBJ = $(SRC:.c=.o)

app: $(OBJ)
	$(CC) $(OBJ) -o app

clean:
	rm -f $(OBJ) app
