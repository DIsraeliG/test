SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c, %.o, $(SRCS))
OUT:=main
CC:=gcc

${OUT}: ${OBJS}
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $^
.PHONY: clean rebuild print
clean:
	$(RM) ${OBJS} 

rebuild: clean ${OUT}

print:
	echo $(OBJS)
