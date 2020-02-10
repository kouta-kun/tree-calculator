WCXX := em++
iflags := -I../headers
cflags := -std=c++17 -fno-exceptions -c
ldflags := --bind -s WASM=1 -s ERROR_ON_UNDEFINED_SYMBOLS=0 --shell-file template.html

main.html: AddOp.o Constant.o DivOp.o MulOp.o Parser.o StringUtils.o SubOp.o emscripten_bindings.o template.html
	$(WCXX) $(ldflags) *.o -o $@


%.o: ../%.cpp
	$(WCXX) $(cflags) $(iflags) $^ -o $@

.PHONY: clean

clean:
	rm *.o main.html main.js main.wasm
