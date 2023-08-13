; Compile with FASM
section .text

global __mkdir

__mkdir:
    mov ah, 39h
    mov dx, [rcx]
    int 21h
    mov rax, cf
    ret