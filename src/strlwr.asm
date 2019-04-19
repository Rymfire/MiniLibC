;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; strlwr
;;

bits 64
global strlwr                   ; char *strlwr(const char *)

section .text

strlwr:                         ; rax strlwr(rdi)
    mov rax, rdi                ; set rax to NULL
    xor rcx, rcx                ; set rcx to 0

loop:
    cmp byte [rax + rcx], 0
    jz end

if_greater_equal:
    cmp byte [rax + rcx], 65
    jge if_lesser_equal
    jmp next

if_lesser_equal:
    cmp byte [rax + rcx], 90
    jle make_lower
    jmp next

next:
    inc rcx
    jmp loop

make_lower:
    mov r8b, byte [rax + rcx]
    add r8b, 32
    mov byte [rax + rcx], r8b
    jmp next

end:
    ret
