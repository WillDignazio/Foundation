;; Interrupt Request Handlers
;; Author: Will Dignazio
;; Description: 
;; 	Interupt handlers for non-exception interrupts. After remapping the 
;; PIC, these will be the IDT entries from 32-47. 
[BITS 32]
[global irq0]
[global irq1]
[global irq15]

;; 32: IRQ 0
irq0: 
  cli 
  push byte 0 
  push byte 32
  jmp irq_common_stub

;; 33: IRQ
;;	- Keyboard interrupt
irq1: 
  cli
  push byte 0
  push byte 33
  jmp irq_common_stub

;; 47: IRQ 15
irq15: 
  cli 
  push byte 0 
  push byte 47
  jmp irq_common_stub

[extern irq_handler]

irq_common_stub: 
  pusha
  push ds
  push es
  push fs
  push gs
  mov ax, 0x10
  mov ds, ax
  mov es, ax
  mov fs, ax
  mov gs, ax
  mov eax, esp
  push eax
  mov eax, irq_handler
  call eax
  pop eax
  pop gs
  pop fs
  pop es
  pop ds
  popa 
  add esp, 8
  iret 
