; Compile with FASM
section .data
    buffer db 8192 dup(0)

section .text

global __readfile

__readfile:
    mov ah, 3Fh
    mov bx, rcx
    mov dx, [buffer]
    mov cx, r8
    int 21h
    lea rax, [buffer]
    ret