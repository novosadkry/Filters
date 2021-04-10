CC = gcc
CFLAGS = -g -Wall -Istb
LDFLAGS = -fopenmp

RM = rm -rf
MKDIR = mkdir -p

ODIR = obj
SDIR = src

EXE = out.exe
SOURCE = $(wildcard $(SDIR)/*.c)
HEADER = $(wildcard $(SDIR)/*.h)
OBJECT = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SOURCE))

.PHONY: compile build clean

build: $(EXE)

$(EXE): $(OBJECT)
	$(CC) -o $@ $^ $(LDFLAGS)

compile: $(OBJECT)

$(ODIR)/%.o: $(SDIR)/%.c $(HEADER)
	@ $(MKDIR) obj
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	$(RM) $(EXE) $(ODIR)
