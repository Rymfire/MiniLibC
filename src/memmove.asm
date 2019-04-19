;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so memmove
;;

bits 64                                     ; 64 bits prgm
global memmove                              ; void *memmove(void *dest, const void *src, size_t n)

section .text

memmove:                                    ; rax memmove(rdi, rsi, rdx)
    xor rcx, rcx                            ; set counter to 0
    xor rax, rax                            ; set output to 0

push_stack:
    cmp rcx, rdx
    je pop_stack
    mov r8b, byte [rsi + rcx]
    push r8
    inc rcx
    jmp push_stack

pop_stack:
    cmp rcx, 0
    jz end
    dec rcx
    pop r8
    mov byte [rdi + rcx], r8b
    jmp pop_stack

end:
    mov rax, rdi                            ; set output
    ret                                     ; return
