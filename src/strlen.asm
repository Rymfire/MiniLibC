;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so strchr
;;

bits 64                         ; 64 bit
global strlen                   ; ft is strlen

section .text                   ; Code section

strlen:                         ; rax strlen(rdi)
    xor rax, rax                ; set rax to 0

loop:
    cmp byte [rdi + rax], 0     ; compare each char to 0
    jz end                      ; if char is 0 jump to end
    inc rax                     ; else length++
    jmp loop                    ; restart loop

end: 
    ret                         ; return
