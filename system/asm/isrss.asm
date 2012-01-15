;; Interrupt Service Routines
;; Author: Will Dignazio 
;; Description: 
;;	Routines for interrupt handlers, these routines are essential for 
;; vital system functions. Some of these functions include keyboard input, 
;; page fault, segfault, and divide by zero exceptions. 
[BITS 32]
[global isr0]
[global isr1]
[global isr8]
[global isr13]
[extern fault_handler]

;;Divide By Zero Exception Handler
isr0:
  cli 
  push byte 0
  push byte 0
  jmp isr_common_stub

;;Debug Exception Handler
isr1: 
  cli 
  push byte 0
  push byte 1
  jmp isr_common_stub

;; Double Fault Handler
isr8: 
  cli 
  push byte 8
  jmp isr_common_stub

isr13: 
  cli 
  push byte 0x0D
  jmp isr_common_stub

;; Interrupt Service Common Stub
;;	- Saves processor state
;;	- Sets up for kernel mode segments 
;;	- Calls C fault handler 
;;	- Restores stack frame
isr_common_stub: 
  pusha 
  push ds
  push es
  push fs
  push gs
  mov ax, 0x10		; Kernel data segment descriptor
  mov ds, ax 
  mov es, ax
  mov fs, ax 
  mov gs, ax
  mov eax, esp		; Push the stack
  push eax 
  mov eax, fault_handler
  call eax 		; Special thingy, preserves eip register
  pop eax
  pop gs
  pop fs
  pop es
  pop ds
  popa
  add esp, 8		; Clean pushed error code and push ISR num
  iret			; pops 5 things at once 
