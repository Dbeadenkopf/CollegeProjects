; File: bookcmp.asm
;
;Defines the bookcmp subroutine for use by the sort algorithm in sort_books.c
;
	;;  found the offsets through gdb
%define TITLE_OFFSET 0
%define AUTHOR_OFFSET 41
%define YEAR_OFFSET 64

        SECTION .text                ; Code section.
        global  bookcmp              ; let loader see entry point

bookcmp:
    push   rbp                       ; push the base pointer
    mov    rbp, rsp                  ; move stack pointer onto rbp (Prologue)

    push   rdi                       ; push registers we want to use
    push   rsi
        
    mov    	rdi, [rbp - 8]            ; move first book into rdi
    mov    	rsi, [rbp - 16]           ; move second book into rsi
    push 	rbx                                 ; fetch the year field
    mov 	eax, dword[RSI+YEAR_OFFSET]; and compare the year field to book1's
    mov		ebx, dword[RDI+YEAR_OFFSET]; If they're different, do not sort, treat the titles as lexicographically equivalent
    cmp 	eax, ebx
    jne 	L_eq
cmpTitles:                           ; Fall through to here if years same
                                ; Compare the book title strings
retrieveLetter:
	mov al, [rdi]	     ;get a letter out of rdi(book1)
	mov ah, [rsi]	     ;get a letter out of rsi(book2)
	cmp al, ah
	jg L_gt			;if al(book1letter) > ah(book2letter) b1>b2
	jl L_lt			;if al(book1letter) < ah(book2letter) b1<b2
	cmp al,0
	je L_eq
	cmp ah,0
	je L_eq
	;; al =  ah
	inc rdi			;they the same & we havent hit a nullterminator
	inc rsi
	jmp retrieveLetter	      ;ah and al are the same char & are not null

cmpDone:                             ; Things to do after titles are compared

L_lt:
    mov    rax, -1                   ; book1 is strictly less than book2
    jmp    end
    
L_eq:    
    mov    rax, 0                    ; book1 equals book2
    jmp    end
    
L_gt:    
    mov    rax, 1                    ; book1 is strictly greater than book2

    ;; Clean up and finish
end:    
	pop    rsi
	pop rsi; clean up
	pop    rdi
	leave                            ; Sets RSP to RBP and pops off RBP (Epilogue)
	ret
