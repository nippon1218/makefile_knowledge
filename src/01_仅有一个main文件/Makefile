CC ?= gcc

W_DIR ?= $(shell pwd)

CFLAGS ?= -O3 -g0 -I$(W_DIR)

BIN = main
MAINSRC = main.c

OBJEXT ?= .o
MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

all:default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"

default: $(MAINOBJ)
	$(CC) -o $(BIN) $(MAINOBJ)

.PHONY:
	clean

clean:
	rm -rf *.o
	rm -rf main 
