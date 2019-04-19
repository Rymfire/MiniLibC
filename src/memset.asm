;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so memset
;;

bits 64                                     ; 64 bits program
global memset                               ; void *memset(void *s, int c, size_t n)

section .text

memset:                                     ; rax memset(rdi, rsi, rdx)
    xor rcx, rcx                            ; set counter to 0
    xor rax, rax                            ; set output to 0

loop:
    cmp rcx, rdx                            ; check if counter is equal to n
    je end                                  ; if counter == n then jump to end
    mov byte [rdi + rcx], sil               ; set s[cnt] to c
    inc rcx                                 ; cnt++
    jmp loop                                ; restart loop

end:
    mov rax, rdi                            ; set output with new pointer
    ret                                     ; return
