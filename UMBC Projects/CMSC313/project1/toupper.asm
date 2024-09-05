; File: atbash.asm last updated 09/18/2018
;
; Convert user input to encrypted string using the ATBASH cipher.
;
; Assemble using NASM:  nasm -f elf64 atbash.asm
; Link with ld:         ld atbash.o -o atbash
;
; Just one of the many ways to do this!

%define STDIN         0
%define STDOUT        1
%define SYSCALL_EXIT  60
%define SYSCALL_READ  0
%define SYSCALL_WRITE 1
%define BUFLEN 256


        SECTION .data                   ; initialized data section

msg1:   db "Enter string: "             ; user prompt
len1:   equ $-msg1                      ; length of first message

msg2:   db "Original: "                 ; original string label
len2:   equ $-msg2                      ; length of second message

msg3:   db "Convert:  "                 ; converted string label
len3:   equ $-msg3

msg4:   db 10, "Read error", 10         ; error message
len4:   equ $-msg4

; Store upper and lower case into lookup table
;          'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'
atbash: db 'ZYXWVUTSRQPONMLKJIHGFEDCBAzyxwvutsrqponmlkjihgfedcba'

        SECTION .bss                    ; uninitialized data section
buf:    resb BUFLEN                     ; buffer for read
newstr: resb BUFLEN                     ; converted string
count:  resb 4                          ; reserve storage for user input bytes


        SECTION .text                   ; Code section.
        global  _start                  ; let loader see entry point

_start: nop                             ; Entry point.
start:                                  ; address for gdb

        ; prompt user for input
        ;
        mov rax, SYSCALL_WRITE         ; write function
        mov rdi, STDOUT                ; Arg1: file descriptor
        mov rsi, msg1                  ; Arg2: addr of message
        mov rdx, len1                  ; Arg3: length of message
        syscall                        ; 64-bit system call

        ; read user input
        ;
        mov rax, SYSCALL_READ          ; read function
        mov rdi, STDIN                 ; Arg1: file descriptor
        mov rsi, buf                   ; Arg2: addr of message
        mov rdx, BUFLEN                ; Arg3: length of message
        syscall                        ; 64-bit system call

        ; error check
        ;
        mov [count], rax               ; save length of string read
        cmp rax, 0                     ; check if any chars read
        jg  read_OK                    ; >0 chars read = OK
        mov rax, SYSCALL_WRITE         ; Or Print Error Message
        mov rdi, STDOUT                ; Arg1: file descriptor
        mov rsi, msg4                  ; Arg2: addr of message
        mov rdx, len4                  ; Arg3: length of message
        syscall                        ; 64-bit system call
        jmp     exit                   ; skip over rest
read_OK:

        ; Loop for conversion
        ; assuming count > 0
       
Register_init:
        mov     rcx, [count]           ; initialize count
        mov     rsi, buf               ; point to start of buffer
        mov     rdi, newstr            ; point to start of new string

Initialize_main:
        mov     rax, 0               ; Initialize rax, xor generates machine code that's much shorter than a MOV to reset instruction (see below)
        mov     al, [rsi]              ; get a character
        inc     rsi                    ; update source pointer

        ; Check if a character is in [A-Z]
        ;
        cmp     al, 'A'                ; less than 'A'?
        jb      Mov_next_char           ; Move onto next char, no converting
        cmp     al, 'Z'                ; Same as 'A' checking if less than Z
        jbe     Upper_To_Lower                  ; access the atbash lookup table

        ; Check if a character is in [a-z]
        ;
        cmp     al, 'a'                ; comparing 'a' now to see if less than
        jb      Mov_next_char           ; Move onto next char, no converting 
        cmp     al, 'z'                ; again like 'Z' checking to see if 'z' is less than
        jbe     Lower_To_Upper                  ; access the atbash lookup table

        jmp     Mov_next_char           ; jump down to Mov_next_char if the line 99 and line 101 are true 


Upper_To_Lower:
        add     rax, atbash            ; adding offset to see how far the char is from the start
        sub     rax, 41h               ; 41h = 65 in ASCII, basically subtracting rax from 41  
        mov     al, byte [rax]         ; moving the results into al
        jmp     Mov_next_char           ; jump down again to Mov_next_char

Lower_To_Upper:
        add     rax, atbash            ; Add the offset to character in look up table
        sub     rax, 47h               ; shifting from right to left (formula:(61h = 97)-(1Ah = 26))
        mov     al, byte [rax]         ; Access atbash lookup table
        jmp     Mov_next_char           ; jump down again to the next character

Mov_next_char:
        mov     [rdi], al              ; put character in al into a new string 
        inc     rdi                    ; update dest pointer
        dec     rcx                    ; update char count
        jnz     Initialize_main         ; loop back to the main of the program

Conclusion:

        ; print out user input for feedback
        ;
        mov rax, SYSCALL_WRITE         ; Print Message
        mov rdi, STDOUT                ; Arg1: file descriptor
        mov rsi, msg2                  ; Arg2: addr of message
        mov rdx, len2                  ; Arg3: length of message
        syscall                        ; 64-bit system call

        mov rax, SYSCALL_WRITE         ; Write user input
        mov rdi, STDOUT                ; Arg1: file descriptor
        mov rsi, buf                   ; Arg2: addr of message
        mov rdx, [count]               ; Arg3: length of message
        syscall                        ; 64-bit system call

        ; print out converted string
        ;
        mov rax, SYSCALL_WRITE         ; Print Message
        mov rdi, STDOUT                ; Arg1: file descriptor
        mov rsi, msg3                  ; Arg2: addr of message
        mov rdx, len3                  ; Arg3: length of message
        syscall                        ; 64-bit system call


        mov rax, SYSCALL_WRITE         ; Write out garbled string!
        mov rdi, STDOUT                ; Arg1: file descriptor
        mov rsi, newstr                ; Arg2: addr of message
        mov rdx, [count]               ; Arg3: length of message
        syscall                        ; 64-bit system call


        ; final exit
        ;
exit:   mov rax, SYSCALL_EXIT          ; Setup exit system call
        mov rdi, 0                     ; no errors
        syscall                        ; call kernel
