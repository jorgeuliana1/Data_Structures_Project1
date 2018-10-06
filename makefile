CC = gcc
CFLAGS =
SOURCES = source/main.c source/libs/*.c
OBJECTS = $(SOURCES)
LDFLAGS =
PARAM =
EXE = NetMap

all: $(EXE)

$(EXE): $(OBJECTS)
		$(CC) $^ -o $@ $(LDFLAGS)
clean:
		rm $(EXE)
run: $(EXE)
		./$^ $(ARGS)
