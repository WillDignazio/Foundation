# Makefile for the keyboard driver
# that build the source files within 
# this directory. The ouput of the 
# files will go into OUTPUT path. 

CSRC = *.c

build: 
	@for file in $(CSRC) ; do echo "Compiling " $$file"..." ; $(CC) $(CFLAGS) $$file -o $(OUTPUT)/device/$$file ; done
	@for file in $(OUTPUT)/device/*.c ; do rename .c .o $(OUTPUT)/device/* ; done
