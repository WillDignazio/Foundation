;; Core Assembly Functions
;; Author: Will Dignazio 
;; Description: 
;; 	Core assembly functions for the kernel, used for a variety of functions
;; including debugging and manual register setting. Among vital system
;; functions, the gdt and idt register loading functions are here, which 
;; provide the kernel the ability to set new tables. 
[BITS 32] 

[global set_eax]
[global gdt_flush]
[global idt_load]
[global halt]
[extern gp]
[extern idtp]

;; Set EAX 
;;	- Primarily a debug function to set eax
;;	- Contains a magic breakpoint after setting eax 
;;	- Will also return the value you pass in 
set_eax: 
  push ebp		; Save stack frame
  mov ebp, esp	; Setup new stack frame
  mov eax, [ebp+8]
  xchg bx, bx	; This is a debug function, MAGIC BREAKPOINT
  pop ebp		; restore stack frame
  ret 			; This function also return eax

;; Load GDT 
gdt_flush:
  lgdt[gp]
  mov ax, 0x10		; 0x10 is the offset in the GDT to data segment
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov ss, ax
  jmp 0x08:flush2	; 0x08 is code segment descriptor, far jump to that shit
flush2: 
  ret

; Load IDT Table 
;	- Loads the table into the memory
;	- Should be called only once by the kernel init
idt_load:
  lidt [idtp]
  ret

; Halt The Kernel 
;	- Completely stops the sytem
;	- No way to return 
halt:
  cli
  mov eax, 0x99999
  hlt 


