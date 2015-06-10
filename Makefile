
src = $(shell find src -name "*.c")

obj = $(patsubst %.c,%.o,$(src))

bin = build/libargparse.a

test = build/test

GCC = gcc

.PHONY: all

all: $(test)

%.o: %.c
	@$(GCC) -c $^ -o $@ -Iinclude

$(bin): $(obj)
	@echo build $@
	@mkdir -p $(dir $@)
	@ar rcs $@ $(obj)
	@ranlib $@

$(test): $(bin)
	@mkdir -p $(dir $@)
	@$(GCC) test/main.c -Lbuild -largparse -Iinclude -o $@

clean:
	@rm -rf build

help:
	@echo $(src)
	@echo $(obj)


