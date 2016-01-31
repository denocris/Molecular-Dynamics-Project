# -*- Makefile -*-
SHELL=/bin/sh
############################################
# derived makefile variables
OBJ_SERIAL=$(SRC:src/%.f90=Obj-serial/%.o)
############################################

default: serial

serial:
	$(MAKE) $(MFLAGS) -C Obj-$@

clean:
	$(MAKE) $(MFLAGS) -C Obj-serial clean

