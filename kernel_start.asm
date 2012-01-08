;; Kernel Starter 
;; Author: Will Dignazio 
;; Description: 
;;	Stublet app to start the kernel after being called by the bootloader. 
;; Also sets up a simple 8 kilobyte stack for use by the kernel. Functions
;; once resided here for setting up the GDT and IDT, those were moved to
;; the core.asm file in kernel/system/core.asm.
[BITS 32]
[global start]
[extern halt]
[extern kernel_main]

[SECTION .text]
start:						; Called by the bootloader, must be start
  mov esp, sys_stack 
  call kernel_main
  call halt

[SECTION .bss]
  resb 8192			; 8Kbytes of memory for stack 
 sys_stack:
