CC=gcc
LD=ld
AS=nasm 
BITS=32
INCLUDE	:=	-I $(CURDIR)/include/foundation  

srctree = $(CURDIR)/Atlas $(CURDIR)/device $(CURDIR)/system

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
	@echo "test"
