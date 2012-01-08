CC=gcc
LD=ld
AS=nasm 
BITS=32
INCLUDE	:=	-I $(CURDIR)/include/foundation  
AINCLUDE:= 	-I $(CURDIR)/include/foundation/inc

# These folder contain the top level make 
# files for that portion of the kernel. 
# Each of these has a makefile in them, which 
# may or may not point to other Makefiles in sub-
# directories. 
maketree = $(CURDIR)/Atlas $(CURDIR)/device $(CURDIR)/system

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

build: 
	@for src in $(maketree) ; do \
		$(MAKE) -f $(src)/Makefile; \
	done 
