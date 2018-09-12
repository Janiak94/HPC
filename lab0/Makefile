CC=gcc
HEADERS=-I/home/hpcuser122/local_flint/include -I/home/hpcuser122/local_arb/include
LIBS=-L/home/hpcuser122/local_flint/lib -L/home/hpcuser122/local_arb/lib
STD=c99
PROGRAMS=stack heap poly_roots fragment reduced_fragment file printargs

.PHONY: all
all: $(PROGRAMS)

printargs: src/printargs.c
	$(CC) -std=$(STD) -o $@ $<

file: src/file.c
	$(CC) -std=$(STD) -o $@ $<

fragment: src/fragment.c
	$(CC) -std=$(STD) -o $@ $<

reduced_fragment: src/reduced_fragment.c
	$(CC) -std=$(STD) -o $@ $<

stack: src/stack.c
	$(CC) -std=$(STD) -o $@ $<

heap: src/heap.c
	$(CC) -std=$(STD) -o $@ $<

poly_roots: src/poly_roots.c
	$(CC) -o $@ $< -larb -lflint $(HEADERS) $(LIBS)
