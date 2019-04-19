;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so strpbrk
;;

bits 64
global strpbrk                  ; char *strpbrk(const char *s, const char *accept)

section .text

strpbrk:                        ; rax strpbrk(rdi, rsi)
    xor rax, rax                ; set output to 0
    xor rdx, rdx                  ; set 2nd it to 0
    xor r8, r8                  ; set r8 to 0

take_char:
    cmp byte [rsi + rdx], 0      ; if accept[it] == 0
    jz end                      ; then jmp to end
    mov r8b, [rsi + rdx]         ; else get next char
    xor rcx, rcx                ; reset rcx to 0

loop:                           ; while
    cmp byte [rdi + rcx], 0     ; if s[it] = 0
    jz next_char                ; then jmp to next_char
    cmp byte [rdi + rcx], r8b   ; if s[it] == accept[it2]
    je found                    ; then found
    inc rcx                     ; it++
    jmp loop                    ; restart loop

next_char:
    inc rdx                      ; it2++
    jmp take_char               ; jmp to take_char

found:
    mov rax, rdi                ; set output
    add rax, rcx
    ret                         ; return

end:
    xor rax, rax                ; set output to null
    ret                         ; return
