CC = clang
CFLAGS = -Wall -Wextra -I. -std=gnu2x

SRCS = main.c

OBJS = $(SRCS:.c=.o)

TARGET = sambadc-tool-cli

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.0: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
