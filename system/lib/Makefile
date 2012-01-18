# Makefile for the system libraries 
# builds all the source files within the 
# directory and outputs them to their 
# appropriate output directory. 

CSRC += *.c
OUTPUT:=$(OUTPUT)lib/
export OUTPUT

build: 
	@mkdir -p $(OUTPUT)
	@for file in $(CSRC); do echo "Compiling "$$file"..."; $(CC) $(CFLAGS) $$file -o $(OUTPUT)$$file; done
	@for file in $(CSRC); do rename .c .o $(OUTPUT)*; done 
