;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so strcmp
;;

bits 64                                             ; 64 bits prgm
global strcmp                                       ; int strcmp(const char *s1, const char *s2)

section .text

strcmp:
    xor rcx, rcx
    xor r8, r8

loop:
    cmp byte [rdi + rcx], 0
    jz end
    cmp byte [rsi + rcx], 0
    jz end
    mov r8b, byte [rsi + rcx]
    cmp byte [rdi + rcx], r8b
    jne end
    inc rcx
    jmp loop

end:
    movzx rax, byte [rdi + rcx]
    movzx r8, byte [rsi + rcx]
    sub rax, r8
    ret
