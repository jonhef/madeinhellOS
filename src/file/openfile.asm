; Compile with FASM
section .text

global __openfile

__openfile:
    mov ah, 3Dh
    mov dx, [rcx]
    int 21h
    mov rax, ax
    ret