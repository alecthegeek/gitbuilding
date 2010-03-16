o/%.o: src/%.c
	-mkdir o
	gcc -I ./h -c $< -o $@

OBJS:=	o/main.o \
	o/a.o \
	o/b.o

all: bin/main

clean:
	rm -rf bin o

bin/main: $(OBJS)
	-mkdir bin
	gcc  -o $@  $^

o/main.o: src/main.c h/a.h h/b.h

o/a.o: src/a.c h/a.h

o/b.o: src/b.c h/b.h
