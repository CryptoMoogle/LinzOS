
PROJDIR := $(HOME)/LinzOS

SRCDIR = $(PROJDIR)/$(TEMPDIR)/src
BUILDIR = $(PROJDIR)/build/$(TEMPDIR)

ASMFILES := $(shell find $(SRCDIR)/ -name \*.S)
SRCFILES := $(shell find $(SRCDIR)/ -name \*.c)
objects := $(patsubst %.c,%.o, $(notdir $(SRCFILES))) $(patsubst %.S,%.o, $(notdir $(ASMFILES)))

CC := gcc
AR := ar

PREFIX	:= /home/Lindsay/.toolchains/LinzOS/bin/i686-LinzOS-
CC 		:= $(addprefix $(PREFIX),$(CC))
AR		:= $(addprefix $(PREFIX),$(AR))

CFLAGS := -std=gnu99 -O0 -Wall -Wextra

CPPFLAGS := 

VPATH = $(dir $(SRCFILES) $(ASMFILES) :$(SRCDIR)/%=%)

all:

%.o: %.c
	$(COMPILE.c) -o $(BUILDIR)/$@ $<

%.o: %.S
	$(COMPILE.S) -o $(BUILDIR)/$@ $<
	
$(BUILDIR):
	mkdir -p $(BUILDIR)

