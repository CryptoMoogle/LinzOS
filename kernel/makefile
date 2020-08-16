
TEMPDIR = kernel

include ../common.mk

CFLAGS  += -ffreestanding

LDFLAGS  += -nostartfiles -lgcc

kern := $(BUILDIR)/KERNEL.SYS

all: $(BUILDIR) $(kern)	

$(kern):  $(objects)
	$(LINK.o) -T $(SRCDIR)/linker.ld $(CFLAGS) $(addprefix $(BUILDIR)/,$^) -o $@
	
