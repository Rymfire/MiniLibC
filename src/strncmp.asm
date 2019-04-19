;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so strncmp
;;

bits 64                                 ; 64 bits prgm
global strncmp                          ; int strncmp(const char *s1, const char *s2, size_t n)

section .text

strncmp:
    xor rcx, rcx
    xor r8, r8
    sub rdx, 1

loop:
    cmp rcx, rdx
    je end
    cmp byte [rdi + rcx], 0
    jz end
    cmp byte [rsi + rcx], 0
    jz end
    mov r8b, byte [rsi, rcx]
    cmp byte [rdi + rcx], r8b
    jne end
    inc rcx
    jmp loop

end:
    movzx rax, byte [rdi + rcx]
    movzx r8, byte [rsi + rcx]
    sub rax, r8
    ret
