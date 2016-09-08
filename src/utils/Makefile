.PHONY :none
sources = utils.c nettools.c
CFLAGS += -O2 -fPIC
#CFLAGS := $(CFLAGS)   
#include $(sources:.c=.d)
LD := gcc
objects = utils.o nettools.o
target = libutils.so
ifeq (0,${MAKELEVEL})
	cur-dir := $(shell pwd)
	whoami := $(shell whoami)
	host-type := $(shell arch)
	MAKE := ${MAKE} host-type=${host-type} whoami=${whoami}
else

	inlcude $(sources:.c=.d)
endif 
$(filter %.o,$(objects)): %.o: %.c
	@echo "CFLAGS:"$(CFLAGS)",cc source files:" $< 
	$(CC) -c $(CFLAGS) $< -o $@
%.d: %.c
	@set -e; rm -f $@; \
	$(CC) -M $(CFLAGS) $< > $@; \
	sed 's,$∗\.o[:]*,\1.o $@:,g' < $@ > $@; \
	rm -f $@

$(target):$(objects)
	$(LD) $(LDFLAGS) -shared -fPIC  -v  -o $@ $^ 
.PHONY: all
all:$(target)
	@echo $(VPATH) $(MAKEFLAGS)
	@echo "all build"

.PHONY: clean
clean:
	-rm -f *.o
