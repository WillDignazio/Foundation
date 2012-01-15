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
maketree := $(CURDIR)/system/ $(CURDIR)/device/
linktree := $(OUTPUT)/system/ $(OUTPUT)/device/

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

# Link the subfolders of the link tree into 
# usable object files within the parent 
# directory of OUTPUT. 
link: build 
	@for folder in $(linktree) ; do $(LD) $(LFLAGS) $$folder/*.o -o $$folder/a.out; done 

# The object building file process, 
# it iterates through the maketree list, 
# running the makefiles within. 
# This allows each section of the kernel and its
# subsections to build in specific ways. 
build: 
	@mkdir -p $(OUTPUT)
	@for dir in $(maketree) ; do \
		$(MAKE) -C $$dir -s ; \
	done

clean: 
	@echo "Cleaning..."
	@echo "Removing Bin Folder..."
	@rm -rf ./bin
