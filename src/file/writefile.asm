; Compile with FASM
section .text

global __writefile

__writefile:
    mov ah, 40h
    mov bx, rcx
    mov cx, r8
    lea dx, [rdx]
    int 21h
    mov rax, cf
    ret