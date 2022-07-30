SRCS:=$(wildcard *.c)
OUTS:=$(patsubst %.c, %, $(SRCS))
CC:=gcc

.PHONY: all clean rebuild

all: $(OUTS)
	$(CC) $^ -o $@

clean:
	$(RM) $(OUTS)

rebuild: clean all
