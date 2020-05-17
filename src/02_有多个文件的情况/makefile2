CC ?= gcc

W_DIR ?= $(shell pwd)

CFLAGS ?= -O3 -g0 -I$(W_DIR)\
		  -I$(W_DIR)/single

BIN = main
MAINSRC = main.c

CSRCS +=$(W_DIR)/single/single.c

OBJEXT ?= .o
COBJS = $(CSRCS:.c=$(OBJEXT))
MAINOBJ = $(MAINSRC:.c=$(OBJEXT))

all:default

%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"

default: $(COBJS) $(MAINOBJ)
	$(CC) -o $(BIN) $(MAINOBJ) $(COBJS)

.PHONY:
	clean

clean:
	rm -rf *.o
	rm -rf main 
