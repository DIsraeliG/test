SRCS:=$(wildcard *.c)
OUTS:=$(patsubst %.c, %, $(SRCS))
CC:=gcc

.PHONY: all clean rebuild
all: hw1 hw2 hw3

%: %.c
	$(CC) $^ -o $@

clean:
	$(RM) $(OUTS)

rebuild: clean all
