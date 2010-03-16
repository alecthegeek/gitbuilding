o/%.o: src/%.c
	-mkdir o
	$(CC) $(CFLAGS) -I ./h -c $< -o $@

d/%.d: src/%.c
	-mkdir d
	$(CC) $(CLAGS) -I ./h -MM -MG -MT o/$*.o -MT d/$*.d -MF $@ $<

SRCS :=	src/main.c \
	src/a.c \
	src/b.c

OBJS := ${patsubst src/%, o/%, ${patsubst %.c, %.o, ${filter %.c, $(SRCS)}}}

all: bin/main

clean:
	rm -rf bin o

bin/main: $(OBJS)
	-mkdir bin
	$(CC) $(CFLAGS) -o $@  $^

include ${patsubst o/%, d/%, ${patsubst %.o, %.d, $(OBJS)}}
