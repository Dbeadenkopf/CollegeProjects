; Convert user input to hexadecimal number.
;
; Assemble using NASM:  nasm -f elf64 hexConverter.asm
; Compile with gcc:     gcc hexConverter.o cfunc.c -o converter.out
;

%define STDIN         0
%define STDOUT        1
%define SYSCALL_EXIT  60
%define SYSCALL_READ  0
%define SYSCALL_WRITE 1
%define BUFLEN 		  21


        SECTION .data                   ; initialized data section

msg1:   db "Enter Number: "             ; user prompt
len1:   equ $-msg1                      ; length of first message

msg2:   db "Invalid Input!", 10         ; error message
len2:   equ $-msg2

msg3:   db "Hexadecimal value is: "     ; Feedback
len3:   equ $-msg3

msg4:   db 10      						; Linefeed
len4:   equ $-msg4

        SECTION .bss                 ; uninitialized data section
buf:    resb BUFLEN                  ; buffer for read
newstr: resb BUFLEN                  ; converted string
count:  resb 4                       ; reserve storage for user input bytes

        SECTION .text                ; Code section.
        global  main                 ; let gcc see entry point        
        extern printhex				 ; This routine is defined in the c function
        extern printf				 ; This routine will be utilized in the c function

main:	nop                          ; Entry point.
start:                               ; address for gdb

        ; prompt user for input
        ;
        mov rax, SYSCALL_WRITE       ; write function
        mov rdi, STDOUT              ; Arg1: file descriptor
        mov rsi, msg1                ; Arg2: addr of message
        mov rdx, len1                ; Arg3: length of message
        syscall                      ; 64-bit system call

        ; read user input
        ;
        mov rax, SYSCALL_READ        ; read function
        mov rdi, STDIN               ; Arg1: file descriptor
        mov rsi, buf                 ; Arg2: addr of message
        mov rdx, BUFLEN              ; Arg3: length of message
        syscall                      ; 64-bit system call

        ; error check
        ;
        mov [count], rax             ; save length of string read so checking wether the user gave the correct input
        cmp rax, 0                   ; checking for more characters here 
        jle invalid                  ; if rax <=0 then chars read are invalid

	cmp rax, 21					 ; check if 21 characters were read
	je	read_OK					 ; if so then we are ok
	cmp rax, 20					 ; check if 20 characters were read
	je	read_OK					 ; if so then we are ok

invalid:mov rax, SYSCALL_WRITE       ; Or Print Error Message
        mov rdi, STDOUT              ; Arg1: file descriptor
        mov rsi, msg2                ; Arg2: addr of message
        mov rdx, len2                ; Arg3: length of message
        syscall                      ; 64-bit system call
        jmp     exit                 ; skip over rest

read_OK:

        
init:

									 ; printout the precursor message
	mov rax, SYSCALL_WRITE       ; Print Message
        mov rdi, STDOUT              ; Arg1: file descriptor
        mov rsi, msg3                ; Arg2: addr of message
        mov rdx, len3                ; Arg3: length of message
        syscall                      ; 64-bit system call

									 ; printout the linefeed
		mov rax, SYSCALL_WRITE       ; Print Message
        mov rdi, STDOUT              ; Arg1: file descriptor
        mov rsi, msg4                ; Arg2: addr of message
        mov rdx, len4                ; Arg3: length of message
        syscall                      ; 64-bit system call


        ; final exit
        ;
exit:   mov 	rax, SYSCALL_EXIT
        mov 	rdi, 0               ; exit to shell
        syscall
