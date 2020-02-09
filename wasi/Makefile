WCXX := wasic++
iflags := -I../headers
cflags := -fno-exceptions -c

main.wasm: AddOp.o Constant.o DivOp.o MulOp.o Parser.o StringUtils.o SubOp.o main.o
	$(WCXX) $^ -o $@


%.o: ../%.cpp
	$(WCXX) $(cflags) $(iflags) $^ -o $@