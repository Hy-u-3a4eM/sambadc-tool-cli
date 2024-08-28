CC = clang
CFLAGS = -Wall -Wextra -I. -std=gnu2x

SRCS = main.c system.c user/user_create.c menu_system.c

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
