;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so strchr
;;

bits 64
global strchr                               ; rax strchr(rdi, rsi)

section .text

strchr:
    xor rcx, rcx                            ; init counter to 0
    xor rax, rax                            ; init output to NULL

loop:
    cmp byte [rdi + rcx], sil               ; compare string[rax] with rsi
    je found                                ; if rsi is found jmp to found
    cmp byte [rdi + rcx], 0                 ; check end string
    jz end                                  ; if yes, jump to end
    inc rcx                                 ; else iterator++
    jmp loop                                ; restart loop

found:
    mov rax, rdi
    add rax, rcx
    ret                                     ; end ft with result in rax

end:
    xor rax, rax                            ; reset rax to NULL
    ret                                     ; return NULL;
