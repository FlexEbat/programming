include 'emu8086.inc'

ORG 100h

.DATA
    num1 dw ?
    num2 dw ?
    sum  dw ?
    diff dw ?
    prod dw ?
    quot dw ?
    rem  dw ?

.CODE

start:
    ; Ввод первого числа
    print 'Enter the first number: $'
    lea dx, num1
    call scan_num

    ; Ввод второго числа
    printn
    print 'Enter the second number: $'
    lea dx, num2
    call scan_num

    ; Сумма
    mov ax, num1
    add ax, num2
    mov sum, ax

    ; Разность
    mov ax, num1
    sub ax, num2
    mov diff, ax

    ; Произведение
    mov ax, num1
    mov bx, num2
    mul bx
    mov prod, ax

    ; Частное и остаток
    mov ax, num1
    mov dx, 0
    mov bx, num2
    cmp bx, 0
    je  division_by_zero
    div bx
    mov quot, ax
    mov rem, dx

    ; Вывод результатов
    printn
    print 'Sum:         '
    mov ax, sum
    call print_num
    printn

    print 'Difference:      '
    mov ax, diff
    call print_num
    printn

    print 'Work:  '
    mov ax, prod
    call print_num
    printn

    print 'Private:       '
    mov ax, quot
    call print_num
    printn

    print 'Remainder:       '
    mov ax, rem
    call print_num
    printn

    jmp exit

division_by_zero:
    printn
    print 'Error: division by zero!$'

exit:
    ret

END start