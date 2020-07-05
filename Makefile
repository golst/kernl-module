obj-m := work_queue.o

KERNELDIR ?= /lib/modules/$(shell uname -r)/build

all default: modules
install: modules_install

modules modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(shell pwd) $@