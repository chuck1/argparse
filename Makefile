
inc_dir = -I/home/chuck/git/stdc/include -Iinclude
lib_dir = -L/home/chuck/git/stdc/build

src = $(shell find src -name "*.c")

obj = $(patsubst %.c,%.o,$(src))

bin = build/libargparse.a

test = build/test

GCC = gcc

.PHONY: all

all: $(test)

%.o: %.c
	@$(GCC) -c $^ -o $@ $(inc_dir)

$(bin): $(obj)
	@echo build $@
	@mkdir -p $(dir $@)
	@ar rcs $@ $(obj)
	@ranlib $@

$(test): $(bin)
	@mkdir -p $(dir $@)
	@$(GCC) test/main.c -Lbuild -largparse -lstdc -o $@ $(inc_dir) $(lib_dir)

clean:
	@rm -rf build

help:
	@echo $(src)
	@echo $(obj)


