# System Makefile for the kernel, 
# it appends the systme object file folder
# to the lnktree list of the make process. 
# It compiles the files within this folder to 
# the specified forrmat in CFLAGS, which was exported 
# in the makefile above. Note that there may be folders
# below which require seperate attributes. 
CSOURCE:= ./*.c
ASOURCE:= ./asm/*.asm 
OUT:=./bin/

# After the list of c file and assembly files 
# have been put into object files, the output folder 
# needs to be added to the lnklist
system: build
	
COBJ:= $(OUT)*.o 

# Build 
build: 
	mkdir -p $(OUT)
	@echo $(COBJ)
	@for file in $(CSOURCE) ; do \
		$(CC) $(CFLAGS) -o $(OUT)/$${CSOURCE:%.c=%.o} $$file ; \
	done

