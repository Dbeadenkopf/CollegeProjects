	
				; so we are practing changing from
	;;  paractiing changing from 32 to 64 bit
; Assemble using NASM
				;
	;;homework 2 practice, changing from 32-bit to 64- bit
        SECTION .data                   ; Data section

msg:    db "Hello, world$", 10           ; The string to print.
len:    equ $-msg

        SECTION .text                   ; Code section.
        global _start
_start: nop                             ; Entry point.
        mov     eax, msg                ; Arg 3: length of string.
        mov     esi, len              ; Arg 2: pointer to string.
        mov     edi, 1                  ; Arg 1: file descriptor.
        mov     eax, 1                  ; Write.
        syscall				; to show new adjustments

        mov     edi, 0                  ; exit code, 0=normal
        mov     eax, 60                  ; Exit.
        syscall                    ; Call kernel.
