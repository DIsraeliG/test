SRCS:=$(wildcard *.cc)
OBJECTS:=$(patsubst %.cc, %, $(SRCS))
CC:=g++
LIBS:=
# FLAGS:= -g -fno-elide-constructors
FLAGS:= -g

all:$(OBJECTS)

%:%.cc
	$(CC) $^ -o $@ $(LIBS) $(FLAGS)
print:
	echo $(OBJECTS)
clean:
	rm -rf $(OBJECTS)