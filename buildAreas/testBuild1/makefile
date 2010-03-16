o/%.o: src/%.c
	-mkdir o b
	$(CC) $(CFLAGS) -I ./h -c $< -o $@
	for i in $^ ; do echo -n "$$i " ; git hash-object $$i ; done > b/$(@F).bfl
	echo -n $(BLDCONFIG) >> b/$*.bfl
	echo $(BLDCONFIG) | git hash-object --stdin > b/$(@F).b

d/%.d : src/%.c
	-mkdir d
	$(CC) $(CLAGS) -I ./h -MM -MG -MT o/$*.o -MT d/$*.d -MT b/$@.bfl \
		-MF $@ $<

SRCS :=	src/main.c \
	src/a.c \
	src/b.c

OBJS := ${patsubst src/%, o/%, ${patsubst %.c, %.o, ${filter %.c, $(SRCS)}}}

all: bin/main

clean:
	rm -rf bin o b

bin/main: $(OBJS)
	-mkdir bin
	$(CC) $(CFLAGS) -o $@  $^

include ${patsubst o/%, d/%, ${patsubst %.o, %.d, $(OBJS)}}
