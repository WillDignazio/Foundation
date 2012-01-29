;; End stublet 
;; 	- Marks the end of the kernel
;; 	- Allows for quick malloc 
[BITS 32] 
[SECTION .endstub]
[global endstub]

endsign	db	'KERNEL_END'
;; End mark variable 
endstub db 0 
