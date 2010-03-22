o/%.o: src/%.c
	-mkdir o b
	$(CC) $(CFLAGS) -I ./h -c $< -o $@
	-rm b/$(@F).bfl
	for i in $^ ; do \
		echo -n "$$i " >> b/$(@F).bfl ; git hash-object $$i >> b/$(@F).bfl ;\
	done
	git add b/$(@F).bfl

d/%.d: src/%.c
	-mkdir d
	$(CC) $(CLAGS) -I ./h -MM -MG -MT o/$*.o -MT d/$*.d -MF $@ $<

SRCS :=	src/main.c \
	src/a.c \
	src/b.c

OBJS := ${patsubst src/%, o/%, ${patsubst %.c, %.o, ${filter %.c, $(SRCS)}}}

all: bin/main

clean:
	rm -rf bin o b

bin/main: $(OBJS)
	-mkdir bin  b
	$(CC) $(CFLAGS) -o $@  $^
	-rm b/$(@F).bfl
	for i in $^ ; do \
		echo -n "$$i " >> b/$(@F).bfl ; git hash-object $$i >> b/$(@F).bfl ;\
	done
	git add b/$(@F).bfl

include ${patsubst o/%, d/%, ${patsubst %.o, %.d, $(OBJS)}}
