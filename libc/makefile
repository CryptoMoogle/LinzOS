
TEMPDIR = libc

include ../common.mk

OBJS := $(filter-out crt0.o,$(objects))

#CRT := crt0.o

CFLAGS  += -nostdinc -nostdlib -ffreestanding
CPPFLAGS += -I../libc/include

library := $(BUILDIR)/libc.a

#all: $(BUILDIR) $(library) $(CRT) Sysroot
all: $(BUILDIR) $(library)

$(library): $(OBJS)
	$(AR) $(ARFLAGS) $@ $(addprefix $(BUILDIR)/,$?)
	
#Sysroot:
#	mkdir -p $(PROJDIR)/sysroot/usr/lib
#	
#	cp -R $(PROJDIR)/$(TEMPDIR)/include $(PROJDIR)/sysroot/usr
#	cp -R $(BUILDIR)/libc.a $(PROJDIR)/sysroot/usr/lib
#	cp -R $(BUILDIR)/crt0.o $(PROJDIR)/sysroot/usr/lib
