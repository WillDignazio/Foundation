# Makefile for the terminus shell. 
# Builds the program and pipes the 
# object file to the OUTPUT directory 
# provided. 

CSRC := *.c

build: 
	@mkdir $(OUTPUT)/terminus
	@for file in $(CSRC); do $(CC) $(CFLAGS) $$file -o $(OUTPUT)/terminus/$$file; done
	@for file in $(OUTPUT)/terminus/*.*; do rename .c .o $(OUTPUT)/terminus/*; done
