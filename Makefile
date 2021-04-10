CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -fopenmp
RM = rm

EXE = out.exe
COMPILE = main.o filter.o image.o
HEADER = image.h filter.h stblib.h

.PHONY: compile build clean

build: $(EXE)

$(EXE): $(COMPILE)
	$(CC) -o $@ $^ $(LDFLAGS)

compile: $(COMPILE)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

clean:
	$(RM) $(EXE) *.o
