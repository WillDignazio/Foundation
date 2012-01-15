# Device driver makefile for the kernel, 
# builds the c files. The resulting object
# files will be dumped intot the OUTPUT 
# folder provided by the parent makefile. 
DEVTREE := $(CURDIR)/keyboard $(CURDIR)/video

build:
	@mkdir -p $(OUTPUT)/device
	@for dir in $(DEVTREE) ; do $(MAKE) -C $$dir -s; done

