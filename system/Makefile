# Makefile for the system directory, 
# it adds all the relevant material to the 
# srctree for building.  
# After the subdirectory's make files have 
# been called, this one simply exits, and 
# returns to the makefile of the parent 
# directory. 

# C source files within the current directory
CSRC := *.c 
# ASM object files within the current directory
# TODO: *.asm doesn't work for whatever god-aweful reason. 
ASRC := core.asm irq.asm isrs.asm 

# The system makefile tree, while you do have 
# manually input the makefile directorys you want
# to run, this allows for fairly modularized system 
# building. 
SYSTEMTREE := $(CURDIR)/asm/

# Main function for the Makefile, simply runs
# any of the system tree makefiles first 
# then adds any directories to the srctree after it's 
# finished. 
#TODO: Add handler for SYSTEMTREE makefile calling
system:
	@mkdir -p $(OUTPUT)/system/
	@mkdir -p $(OUTPUT)/system/asm
	@echo $(ASRC)
	@echo $(CSRC)
# Since we are in a child of the parent makefile, 
# we can't export an updated list of files to compile
# back up. So we have to compile the files here, 
# and leave it up to the main Makefile later. 
	@for file in $(CSRC) ; do echo "Compiling "$$file"..." ; $(CC) $(CFLAGS) $$file -o $(OUTPUT)/system/$$file ; done
	@for file in $(ASRC) ; do echo "Assembling "$$file".." ; $(AS) $(AFLAGS) $(CURDIR)/asm/$$file -o $(OUTPUT)/system/asm/$$file ; done
# Because the for loop only lets you do simple commands
# we have to rename the extension on the object files 
# that were just created from .c and .asm to .o
	@for file in $(OUTPUT)/system/ ; do rename .c .o $(OUTPUT)/system/* ; done
	@for file in $(OUTPUT)/system/asm/ ; do rename .asm .o $(OUTPUT)/system/asm/* ; done
