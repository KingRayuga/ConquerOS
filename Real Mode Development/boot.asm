ORG 0
BITS 16

jmp 0x7C0:start

start:
    cli
    mov ax, 07C0
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    sli

    mov si, message
    call print
    jmp $

print:
    mov bx, 0
.loop:
    lodsb
    cmp al,0
    je .done
    call print_char
    jmp .loop
.done:
    ret

print_char:
    move ah,0eh
    int 0x10
    ret

message: db 'Welcome to ConquerOS', 0

times 510 - ($ - $$) db 0
dw 0xAA55

    