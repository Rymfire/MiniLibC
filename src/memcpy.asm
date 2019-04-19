;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so memcpy
;;

bits 64                                     ; 64 bits prgm
global memcpy                               ; void *memcpy(void *dest, const void *src, size_t n)

section .text

memcpy:                                     ; rax memcpy(rdi, rsi, rdx)
    xor rcx, rcx                            ; set counter to 0
    xor rax, rax                            ; set output to 0

loop:                                       ; while
    cmp rcx, rdx                            ; if iterator == n
    je end                                  ; then do end
    mov r8b, byte [rsi + rcx]
    mov byte [rdi + rcx], r8b
    inc rcx                                 ; iterator++
    jmp loop                                ; restart loop

end:
    mov rax, rdi                            ; set output
    ret                                     ; return