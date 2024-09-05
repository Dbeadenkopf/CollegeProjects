;; File: textSearch.asm
	;; 136;0c

; This program demonstrates the use of an indexed addressing mode
; to access data within a record
;
; Assemble using NASM:  nasm -f elf64 textSearch.asm
; Link with ld:  ld textSearch.o -o textSearch
;

%define STDIN         0
%define STDOUT        1
%define SYSCALL_EXIT  60
%define SYSCALL_READ  0
%define SYSCALL_WRITE 1
%define BUFLEN        100

        SECTION .data                                   ; Data section
msg1:   db "Enter search string: "                      ; user prompt
len1:   equ $-msg1                                      ; length of message

msg2:   db 10, "Read error", 10                         ; error message
len2:   equ $-msg2                                      ; length of error message

msg3a:  db "Text you searched appears at  "               ; String found message
len3a:  equ $-msg3a                                     ; length of message

msg3b:	db " characters after the first."               ; Remainder of string found message
len3b:	equ $-msg3b					; length of message

msg4:   db "String not found!", 10                      ; string not found message
len4:   equ $-msg4                                      ; length of message

endl:	db 10						; Linefeed

                                                        ; simulates a text file (record)
record:                                                 ; An excerpt from the intro to Knight Rider (a cool TV series ;-) )
row1:   db "Knight Rider a shadowy flight"
row2:   db "into the dangerous world of a"
        db " man who does not exist. Mich"
        db "ael Knight, a young loner on "
        db "a crusade to champion the cau"
        db "se of the innocent, the innoc"
        db "ent, the helpless in a world "
        db "of criminals who operate abov"
        db "e the law. Knight Rider, Keep"
        db " riding brave into the night."
rlen:   equ $-record
rowlen: equ row2 - row1

        SECTION .bss                                    ; uninitialized data section
buf:    resb BUFLEN                                     ; buffer for read
loc:    resb BUFLEN                                     ; buffer to store found location string
count:  resb 4                                          ; reserve storage for user input bytes

        SECTION .text                                   ; Code section.
        global _start
_start: nop                                             ; Entry point.

                                                        ; prompt user for input
                                                        ;
        mov     rax, SYSCALL_WRITE                      ; write function
        mov     rdi, STDOUT                             ; Arg1: file descriptor
        mov     rsi, msg1                               ; Arg2: addr of message
        mov     rdx, len1                               ; Arg3: length of message
        syscall                                         ; 64-bit system call

                                                        ; read user input
                                                        ;
        mov     rax, SYSCALL_READ                       ; read function
        mov     rdi, STDIN                              ; Arg1: file descriptor
        mov     rsi, buf                                ; Arg2: addr of message
        mov     rdx, BUFLEN                             ; Arg3: length of message
        syscall                                         ; 64-bit system call

                                                        ; error check
                                                        ;
        mov     [count], rax                            ; save length of string read
        cmp     rax, 0                                  ; check if any chars read
        jg      read_OK                                 ; >0 chars read = OK
        mov     rax, SYSCALL_WRITE                      ; Or Print Error Message
        mov     rdi, STDOUT                             ; Arg1: file descriptor
        mov     rsi, msg2                               ; Arg2: addr of message
        mov     rdx, len2                               ; Arg3: length of message
        syscall                                         ; 64-bit system call
        jmp     exit                                    ; skip over rest

read_OK:
				; Input was accepted we can intilize now
Initialize_Main:
	mov     rdx, 0                                	; rdx acts as an iterator so we can now go over the record
        mov     rsi, record                             ; point to the record's address
        mov     rdi, buf                                ; point to the user string's address
        mov     r8, [count]                             ; length of user string, so we can tell the computer in assembly how long it is
        dec     r8                                      ; reduce one to ignore the linefeed character, we dont wont want the \n because that is not the string we want
        xor     r9, r9                                  ; r9 will be used to restore/ reset the record index iterator or basically reset the iterator to 0

Reset_Offset:  xor     rcx, rcx                                ; rcx is our string iterator, helpful for iterator over just the string
        mov     rdx, r9                                 ; Restore value of rdx when search was not successful, keeps rdx to the beggining of the record
        mov     al, [rdi]                               ; Copy first character in search string or saving rdi into al and at this point rdi is the address of the character,
							; The rdi can now be used later for operations like comparison
                                                        
                                                        ; A main loop that will go one-by-one over characters in the record 
Loop_chars: mov     bl, [rsi+rdx]                           ; Copy character in record to bl, the [rsi+rdx] adding the rdx iterator to the record so we can use the iterator
        cmp     rdx, rlen                               ; End of record , so checking if we are at the end of the record
        jge     nope                                    ; here we have a jump and so basically jump to nope
        inc     rdx                                     ; Update r9 so restore/reset that, rdx points to next offset or 0 when restored
        mov     r9, rdx                                 ; Save the value in rdx, to restore later 
        cmp     al, bl                                  ; Compare first character from the user with character in record, basically the premiss of the project
        jne     Loop_chars                                  ; Now take that user character and search for a match but if not equal then loop back around
                                                         
Search_user_string:                                                 ; The rcx iterator will increment over the user string
        inc     rcx                                     ; increment user string index 
        cmp     rcx, r8                                 ; End of user string, another jump so if string was found then jump to found
        je      Found_str_match                                   ; If yes, then proceed, the user string was found at rdx-r8
        mov     bl, [rsi+rdx]                           ; iterate to the next character in the record
        mov     al, [rdi+rcx]                           ; next character in search string to see if there is another match to user string
        inc     rdx                                     ; increment record string, move through records again
        cmp     al, bl                                  ; compare record's current character with user string's current character
        je      Search_user_string                                  ; if they are equal, proceed to the next iteration of the nested loop 
        jmp     Reset_Offset                                   ; if not, then go back to reset state and then over to the main loop, so doing a wrap around if strings are not eqaul
							; so same as in Loop_m where we did the cmp operation with al, bl before 

Found_str_match:                                                  ; If string was found print location which is where the string first occured
        sub     rdx, r8
                                                        
                                                        
        mov     r10, 1                                  ; acts as an inventory to keep track of the number of digits for printing
        mov     rdi, loc                                ; Store the address of location buffer if the location exist
        mov     rax, rdx                                
                                                        ; was 212 characters from the first character
        mov     cl, 10                                  ; Print out its digits using a loop
        cmp     ax, 9                                   ; Is the number larger than a single digit?
        jg      Store_digits                                  ; if so, jump to store the digits routine
        mov     rbx, rax                                ; Copy the value into rbx (Used later by a shifting out routine)
        add     bl, '0'                                 ; Add the ASCII character offset for numbers or the char '0'
        jmp     shOut                                   ; Shift out routine using the jump to shOut

Store_digits: div     cl                                      ; Divide by 10  and so that using the 212 characters we can perform basic math thus 212/10 gives a Q							    ; Quetient of 21 with a remainder of 2
                                                        ; ... On the first iteration of this loop                          
        mov     bl, ah                                  ; Store the remainder so 2 goes in bl for instance
        add     bl, '0'                                 ; Add the ASCII character offset or '0' for numbers
        shl     rbx, 8                                  ; Shift left by 8 to the character, so that they can be shifted out in reverse 
        and     ax, 0x00FF                              ; Clear the result remainder
        inc     r10                                     ; R10 has inventory on the number of digits
        cmp     al, 0                                   ; check for other digits to convert
        jnz     Store_digits                                  ; If more digits are found then just keep looping to continously look for more

shOut:
        mov     [rdi], bl                               ; we have the first digit which is the character to be moved
        inc     rdi                                     ; update to next character position
        shr     rbx, 8                                  ; Shift out the next digit
        cmp     bl, 0                                   ; making sure we have shifted out all the digits
        jnz     shOut                                   ; as with line 135, keep looping to find more digits

        mov     rax, SYSCALL_WRITE                      ; running a SYSCALL_WRITE to display message
        mov     rdi, STDOUT                             ; Arg1: file descriptor
        mov     rsi, msg3a                              ; Arg2: addr of message
        mov     rdx, len3a                              ; Arg3: length of message
        syscall                                         ; 64-bit system call


        mov     rax, SYSCALL_WRITE                      ; Write out location information
        mov     rdi, STDOUT                             ; Arg1: file descriptor
        mov     rsi, loc                                ; Arg2: addr of message
        mov     rdx, r10                                ; Arg3: length of message
        syscall                                         ; 64-bit system call

        mov     rax, SYSCALL_WRITE                      ; Print remainder of Message
        mov     rdi, STDOUT                             ; Arg1: file descriptor
        mov     rsi, msg3b                              ; Arg2: addr of message
        mov     rdx, len3b                              ; Arg3: length of message
        syscall                                         ; 64-bit system call

        mov     rax, SYSCALL_WRITE                      ; Write out string
        mov     rdi, STDOUT                             ; Arg1: file descriptor
        mov     rsi, endl                               ; Arg2: addr of message
        mov     rdx, 1                                  ; Arg3: length of message
        syscall                                         ; 64-bit system call

        jmp     exit

nope:                                                   ; String not found message
                                                        ;
        mov     rax, SYSCALL_WRITE                      ; Print Message
        mov     rdi, STDOUT                             ; Arg1: file descriptor
        mov     rsi, msg4                               ; Arg2: addr of message
        mov     rdx, len4                               ; Arg3: length of message
        syscall                                         ; 64-bit system call


exit:   mov     rax, SYSCALL_EXIT                       ; exit system call id
        mov     rdi, 0                                  ; exit to shell
        syscall

