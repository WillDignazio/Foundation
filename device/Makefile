# Device driver makefile for the kernel, 
# builds the c files. The resulting object
# files will be dumped intot the OUTPUT 
# folder provided by the parent makefile. 

# Tree of folders for which to search 
# through. The files within will be compiled
# and put in the output var. 
DEVTREE= keyboard video

build:
	@mkdir -p $(OUTPUT)/device 
# We have to create the folder where 
# the files will go to. This allows for very specific 
# debugging on any file that is in the kernel. 
	@for folder in $(DEVTREE); do for child in $$folder; do mkdir -p $(OUTPUT)/device/$$child ; done ; done
# Go through the device tree list, 
# and build the files within them. 
	@for folder in $(DEVTREE); do for file in $$folder/*.c ; do $(CC) $(CLFAGS) $$file -o $(OUTPUT)/$$file ; done ; done 
	@for file in $(OUTPUT)/device; do rename .c .o $(OUTPUT)/*; done; 
