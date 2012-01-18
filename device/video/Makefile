# Makefile for the video driver folder. 
# This file will build all the video 
# drivers for the system. The output object
# files will be put in the OUTPUT directory 
# in the video subdirectory. 
CSRC := *.c

#TODO: If there is going to be subdirectories, 
# make sure to add the standard descend and make 
# files.

build: 
	@for file in $(CSRC) ; do echo "Compiling "$$file"..." ; $(CC) $(CFLAGS) $$file -o $(OUTPUT)/$$file ; done
	@for file in $(OUTPUT)/* ; do rename .c .o $(OUTPUT)/* ; done 
