# Makefile for building the standard
# applications available within the 
# kernel. The standard applications should
# generally have their own make files. These
# make files should pipe their output to the 
# OUTPUT folder provided. 

# Current directory makefile file 
# procession tree. 
APPTREE := $(CURDIR)/terminus 

build: 
	@for dir in $(APPTREE) ; do $(MAKE) -C $$dir -s ; done
