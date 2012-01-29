;; End stublet 
;; 	- Marks the end of the kernel
;; 	- Allows for quick malloc 
[BITS 32] 
[SECTION .endstub]
[global end]

endsign	db	'KERNEL_END'
;; End mark label
end: 
