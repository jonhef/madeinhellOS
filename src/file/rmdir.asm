; Compile with FASM
section .text

global __rmdir

__rmdir:
    mov ah, 3Ah
    mov dx, [rcx]
    int 21h
    mov rax, cf
    ret