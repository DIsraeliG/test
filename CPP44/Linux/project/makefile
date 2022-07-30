SRCS:=filetransfer.o io.o print.o token.o main.o
OUT:=main

.PHONY: clean rebuild

$(OUT): $(SRCS)
	gcc $(SRCS) -o main

%.o: %.c
	gcc -c $^
clean:
	$(RM) $(SRCS)

rebuild: clean $(OUT)