;;
;; EPITECH PROJECT, 2018
;; ASM_minilibc_2018
;; File description:
;; libc.so strcspn
;;

bits 64                         ; 64 bits prgm
global strcspn                  ; size_t strcspn(const char *s, const char *reject)

section .text

strcspn:                        ; rax strcspn(rdi, rsi)
    xor rax, rax                ; set it2 to 0
    xor rcx, rcx                ; set it to 0

take_char:
    cmp byte [rsi + rax], 0     ; if s[it2] == 0
    jz end                      ; then jmp to end
    mov r8b, [rdi + rax]
    xor rcx, rcx                ; reset it to 0

loop:                           ; while
    cmp byte [rsi + rcx], 0     ; if reject[it] == 0
    jz end                      ; then jump to end
    cmp byte [rsi + rcx], r8b   ; if reject[it] == s[it2]
    je next_char                ; then jump to next_char
    inc rcx                     ; it++
    jmp loop                    ; restart loop

next_char:
    inc rax                      ; it2++
    jmp take_char               ; jump to take_char

end:
    sub rax, 1
    ret                         ; return
