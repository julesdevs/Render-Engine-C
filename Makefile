CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -O3 -march=native -flto -I./include
SRC = src/main.c src/image.c
OBJ = $(SRC:.c=.o)
EXEC = Render-Engine-C

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
