# Makefile for the terminus shell. 
# Builds the program and pipes the 
# object file to the OUTPUT directory 
# provided. 

CSRC := *.c
OUTPUT := $(OUTPUT)/terminus
export OUTPUT

build: 
	@mkdir $(OUTPUT)
	@for file in $(CSRC); do echo "Compiling "$$file"..."; $(CC) $(CFLAGS) $$file -o $(OUTPUT)/$$file; done
	@for file in $(OUTPUT)/*.*; do rename .c .o $(OUTPUT)/*; done
