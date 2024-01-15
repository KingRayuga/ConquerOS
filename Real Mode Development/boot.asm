ORG 0
BITS 16
_start:
    jmp short start
    nop

times 33 db 0

start:
    jmp 0x7C0:step

handle_one:
    mov ah,0eh
    mov al,'#'
    int 0x10
    iret

step:
    cli
    mov ax, 07C0
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00
    sli

    mov word[ss:0x04], handle_one
    mov word[ss:0x06], 0x7C0

    int 1

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
    mov ah,0eh
    int 0x10
    ret

message: db 'Welcome to ConquerOS', 0

times 510 - ($ - $$) db 0
dw 0xAA55

    