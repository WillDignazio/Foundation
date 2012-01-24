CC=gcc
LD=ld
AS=nasm 
BITS=32
OUTPUT	:=	$(CURDIR)/bin
INCLUDE	:=	-I $(CURDIR)/include/  
AINCLUDE:= 	-I $(CURDIR)/include/foundation/inc
OUTPUT 	:=	$(CURDIR)/bin
CFLAGS := -m32 -c $(INCLUDE)
AFLAGS := -f elf32 $(AINCLUDE) 
LFLAGS := -melf_i386 -r 

# These folder contain the top level make 
# files for that portion of the kernel. 
# Each of these has a makefile in them, which 
# may or may not point to other Makefiles in sub-
# directories. 
maketree := $(CURDIR)/system/ $(CURDIR)/device/ $(CURDIR)/app/

# The make process for the kernel is started here, 
# the default bit setting is 32, and for now there is
# no alternative. The kernel will reach through the 
# directory's building the appropriate files, and alloting
# the correct include directory, bit build type, and other
# various aspect of the build process. 
export CC
export LD
export AS
export BITS
export FINCLUDE
export AINCLUDE
export OUTPUT
export CFLAGS
export AFLAGS
export OUTPORT
export srctree

all: link
	@echo "Building Image..."
	$(LD) -melf_i386 -r -T ./script/liveimg.ld $(shell find $(OUTPUT)/ -name a.out) -o $(OUTPUT)/foundation.o

# Link the subfolders of the link tree into 
# usable object files within the parent 
# directory of OUTPUT. 
link: build 
	@echo "Linking Files..."
	@for folder in $(shell find $(OUTPUT) -type d); do echo $(LD) $(LFLAGS) $$folder/*.o -o $$folder/a.out; $(LD) $(LFLAGS) $$folder/*.o -o $$folder/a.out; done 

# The object building file process, 
# it iterates through the maketree list, 
# running the makefiles within. 
# This allows each section of the kernel and its
# subsections to build in specific ways. 
build: 
	@mkdir -p $(OUTPUT)
# We have to build the start and main files
# as they are technically outside the recursive reach. 
	$(CC) $(CFLAGS) ./kernel_main.c -o $(OUTPUT)/kmain.o
	$(AS) $(AFLAGS) ./kernel_start.asm -o $(OUTPUT)/kstart.o
	@for dir in $(maketree) ; do \
		$(MAKE) -C $$dir -s ; \
	done

bind-atlas: link 
	@mkdir -p $(OUTPUT)/images/
	@echo "Binding Atlas..."
	$(LD) -melf_i386 -r $(shell find $(OUTPUT)/ -name a.out) -o $(OUTPUT)/foundation.o
	dd if=/dev/zero of=$(OUTPUT)/fluff.bin bs=1M count=10
	$(LD) -melf_i386 -T ./script/atlas.ld $(OUTPUT)/foundation.o -o $(OUTPUT)/fbounda.o
	cat $(OUTPUT)/fbounda.o $(OUTPUT)/fluff.bin > $(OUTPUT)/images/fnlive.img

clean: 
	@echo "Cleaning..."
	@echo "Removing Bin Folder..."
	@rm -rf ./bin
