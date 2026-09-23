CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRCS = src/main.c
OBJS = $(SRCS:.c=.o)
TARGET = render-engine

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
