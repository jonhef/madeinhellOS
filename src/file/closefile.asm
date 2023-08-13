; Compile with FASM
section .text

global __CloseFile

__CloseFile:
    mov rax, rcx
    mov ah,3Eh
    mov bx,rax
    int 21h
    jnc exit
    jc error_msg

exit:
    ret

error_msg:
    mov rax, s_error        ;Return error
    ret