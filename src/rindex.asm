;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so rindex
;;

bits 64                         ; 64 bits prgm
global rindex                   ; char *rindex(const char *s, int c)

section .text

rindex:                         ; rax rindex(rdi, rsi)
    xor rax, rax                ; set output to NULL
    xor rcx, rcx                ; set iterator to 0

loop:                           ; while

if:
    cmp byte [rdi + rcx], sil   ; if s[it] == c
    jne endif                   ; if s[it] != c then jmp to else

then:
    mov rax, rdi                ; set output to s
    add rax, rcx                ; set output to s[it]

endif:
    cmp byte [rdi + rcx], 0     ; if s[it] == 0
    jz end                      ; then end
    inc rcx                     ; it++
    jmp loop                    ; restart loop

end:
    ret                         ; return
