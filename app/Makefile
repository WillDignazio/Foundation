# Makefile for building the standard
# applications available within the 
# kernel. The standard applications should
# generally have their own make files. These
# make files should pipe their output to the 
# OUTPUT folder provided. 

# Current directory makefile file 
# procession tree. 
APPTREE := $(CURDIR)/terminus 
OUTPUT :=$(OUTPUT)/app/
export OUTPUT

build: 
	@mkdir $(OUTPUT)
	@for dir in $(APPTREE) ; do $(MAKE) -C $$dir -s ; done
