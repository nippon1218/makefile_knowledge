CC ?= gcc
W_DIR ?= $(shell pwd)
MAINSRC = main.c
PROM = main 
CFLAGS ?= -O3 -g0
OBJEXT ?= .o

include main.mk

MAINOBJ = $(MAINSRC:.c=$(OBJEXT))
COBJS = $(CSRCS:.c=$(OBJEXT))



%.o: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@
	@echo "CC $<"

all:default

default: $(COBJS) $(MAINOBJ)
	$(CC) -o $(PROM) $(MAINOBJ) $(COBJS)

.PHONY:
	clean

clean:
	rm -rf *.o
	rm -rf main 
	rm -rf $(W_DIR)/single/*.o 
