CC=gcc
CFLAGS=-I./src
STD=c11
ODIR=obj
SDIR=src
OFLAGS=-O0 -O1 -O2 -O3 -Os -Og
PROGRAMS=mainfile separatefile inline
_OBJ=separateheader.o separatefile.o
OBJ=$(patsubst %,$(ODIR)/%,$(_OBJ))
_DEPS=separateheader.h
DEPS=$(patsubst %,$(SDIR)/%,$(_DEPS))
OTIME=$(addprefix out/time_meas,$(OFLAGS))

.PHONY: all

all: $(PROGRAMS) $(OTIME)

mainfile: src/mainfile.c
	$(CC) -O2 -std=$(STD) -o $@ $< $(CFLAGS)

inline: src/inline.c
	$(CC) -std=$(STD) -O2 -o $@ $<

separatefile: obj/separateheader.o obj/separatefile.o
	$(CC) -O2 -std=$(STD) -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -O2 -c -o $@ $< $(CFLAGS)

$(OTIME): src/time_meas.c
	$(CC) $(patsubst out/time_meas%,%,$@) -o $@ $^
	$(CC) -S $(patsubst out/time_meas%,%,$@) -o $(patsubst out/%,as/%.s,$@) $^

.PHONY: clean

clean:
	rm -rf $(ODIR)/*
