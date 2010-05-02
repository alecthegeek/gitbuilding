o/%.o: src/%.c
	-mkdir o b
	$(CC) $(CFLAGS) -I ./h -c $< -o $@
	echo -n "BLD_FLAGS [$(CC) $(CFLAGS)]:" > b/$(@F).bfl 
	echo $(CC) $(CFLAGS)  | git hash-object --stdin >> b/$(@F).bfl 
	echo -n "BLD_ENV:" >> b/$(@F).bfl 
	echo $(BLD_ENV)  | git hash-object --stdin >> b/$(@F).bfl 
	for i in $^ $(MAKEFILE_LIST); do \
		echo -n "$$i:" >> b/$(@F).bfl ; git hash-object $$i >> b/$(@F).bfl ;\
	done
	git add b/$(@F).bfl
	git add $@

d/%.d: src/%.c
	-mkdir d
	$(CC) $(CLAGS) -I ./h -MM -MG -MT o/$*.o -MT d/$*.d -MF $@ $<
	git add $@

SRCS:=src/main.c \
	src/a.c \
	src/b.c

OBJS:=${patsubst src/%, o/%, ${patsubst %.c, %.o, ${filter %.c, $(SRCS)}}}

CFLAGS:=-ansi

.PHONY: clean all

.SUFFIXES:

.SUFFIXES: .o .d

all: bin/main

clean:
	rm -rf bin o b *.log buildConfigData

bin/main: $(OBJS)
	-mkdir bin  b
	$(CC) $(CFLAGS) -o $@  $^
	-rm b/$(@F).bfl
	echo -n "BLD_FLAGS [$(CC) $(CFLAGS)]:" > b/$(@F).bfl 
	echo $(CC) $(CFLAGS)  | git hash-object --stdin >> b/$(@F).bfl 
	echo -n "BLD_ENV:" >> b/$(@F).bfl 
	echo $(BLD_ENV)  | git hash-object --stdin >> b/$(@F).bfl 
	for i in $^ $(MAKEFILE_LIST); do \
		echo -n "$$i:" >> b/$(@F).bfl ; git hash-object $$i >> b/$(@F).bfl ;\
	done
	git add b/$(@F).bfl
	git add $(@)

include ${patsubst o/%, d/%, ${patsubst %.o, %.d, $(OBJS)}}
