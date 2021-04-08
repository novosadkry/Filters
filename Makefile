CC = gcc
CFLAGS = -g -Wall
RM = rm

EXE = image.exe
COMPILE = main.o filter.o image.o
HEADER = image.h filter.h stblib.h

.PHONY: compile build clean

build: $(EXE)

$(EXE): $(COMPILE)
	$(CC) -o $@ $^

compile: $(COMPILE)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(EXE) *.o
