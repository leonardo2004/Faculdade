Atividade da matéria "**Arquitetura e organização de computadores**", feita utilizando **NASM**.

---

### Enunciado:
Implemente um programa em **assembly para x86** conforme as instruções especificadas:

1. O programa deve ler como entrada, nesta ordem, a hora (entre 0 e 23) de um compromisso e o minuto (entre 0 e 59).
2. Após isso, o programa deve ler a hora e o minuto em que a pessoa chegou ao compromisso.
3. O programa deve verificar se os valores digitados para horas e minutos estão dentro do intervalo esperado. Caso contrário, ele deve imprimir uma mensagem de erro e repetir a operação. (Não precisa validar se a entrada é numérica. Assuma que foram entrados números).
4. Após lidos os dados, o programa deve dizer se a pessoa chegou adiantada, atrasada ou pontualmente e quanto tempo de atraso ou adiantada chegou.

Use as mensagens abaixo para a interação com o usuário:
- Entre com a hora do compromisso: 
- Entre com os minutos do compromisso: 
- Entre com a hora de chegada:
- Entre com os minutos de chegada: 
- Hora invalida!
- Minutos inválidos!
- A pessoa chegou HH:MM adiantada. 
- A pessoa chegou HH:MM atrasada. 
- A pessoa chegou pontualmente.

Nas mensagens acima, HH e MM são a quantidade de horas e minutos que a pessoa chegou atrasada ou adiantada.
Use sempre dois dígitos para a mensagem de saída. Exemplo 01:32. Para a leitura de entrada pode ser lido com apenas um dígito.

---

### Solução:
```
section .data
    printHoraCompromisso db "Entre com a hora do compromisso:", 10
    printMinCompromisso db "Entre com os minutos do compromisso:", 10
    printHoraChegada db "Entre com a hora de chegada:", 10
    printMinChegada db "Entre com os minutos de chegada:", 10
    invalidHour db "Hora invalida!", 10
    invalidMin db "Minutos invalidos!", 10
    pontualmente db "A pessoa chegou pontualmente.", 10
    chegou db "A pessoa chegou "
    adiantada db " adiantada.", 10
    atrasada db " atrasada.", 10
    dotdot db ":"
    strZero db "0"
section .bss
    valorHoraCompromisso resb 8
    valorMinCompromisso resb 8
    valorHoraChegada resb 8
    valorMinChegada resb 8

section .text
    global _start

_start:
    ;Scaneia o valor das horas do compromisso
    mov rdx, 33         ;Tamanho da string + 1 para incluir a newline
    mov rsi, printHoraCompromisso
    call printf
    mov rdx, 2
    mov rsi, valorHoraCompromisso
    call scanf
    ;Verifica se o primeiro digito das horas do compromisso é válido
    mov dl, [valorHoraCompromisso] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '2'           ;Move o valor 2 para dh (para comparar)
    cmp dl, dh          ;Compara dl com dh (se o valor em dl for maior que 2 o código sai)
    jg exceptionInvalidHour
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidHour
    cmp dl, '2'
    jl skiph1
    ;Verifica se o segundo digito das horas do compromisso é válido
    mov dl, [valorHoraCompromisso+1] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '3'             ;Move o valor 2 para dh (para comparar)
    cmp dl, dh            ;Compara dl com dh (se o valor em dl for maior que 4 o código sai)
    jg exceptionInvalidHour
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidHour
    jmp continueh1
skiph1:
    ;Verifica se o segundo digito das horas do compromisso é válido
    mov dl, [valorHoraCompromisso+1] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '9'             ;Move o valor 2 para dh (para comparar)
    cmp dl, dh            ;Compara dl com dh (se o valor em dl for maior que 4 o código sai)
    jg exceptionInvalidHour
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidHour
continueh1:
    ;Scaneia o valor dos minutos do compromisso
    mov rdx, 37         ;Tamanho da string + 1 para incluir a newline
    mov rsi, printMinCompromisso   
    call printf
    mov rdx, 2
    mov rsi, valorMinCompromisso
    call scanf
    ;Veficia se o primeiro digito dos minutos do compromisso é um digito válido
    mov dl, [valorMinCompromisso] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '5'         ;Move o valor em ascii de 5 para dh (para comparar)
    cmp dl, dh          ;Compara dl com dh (se o valor em dl for maior que o valor em ascii de 5 o código sai)
    jg exceptionInvalidMin
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidMin
    ;Veficia se o segundo digito dos minutos do compromisso é um digito válido
    mov dl, [valorMinCompromisso+1] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '9'             ;Move o valor em ascii de 9 para dh (para comparar)
    cmp dl, dh            ;Compara dl com dh (se o valor em dl for maior o valor em ascii de 9 o código sai)
    jg exceptionInvalidMin
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidMin
    ;Scaneia o valor das horas de chegada
    mov rdx, 29         ;Tamanho da string + 1 para incluir a newline
    mov rsi, printHoraChegada
    call printf
    mov rdx, 2
    mov rsi, valorHoraChegada
    call scanf
    ;Verifica se o primeiro digito das horas de chegada é válido
    mov dl, [valorHoraChegada] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '2'           ;Move o valor 2 para dh (para comparar)
    cmp dl, dh          ;Compara dl com dh (se o valor em dl for maior que 2 o código sai)
    jg exceptionInvalidHour
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidHour
    cmp dl, '2'
    jl skiph2
    ;Verifica se o segundo digito das horas do compromisso é válido
    mov dl, [valorHoraChegada+1] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '3'             ;Move o valor 2 para dh (para comparar)
    cmp dl, dh            ;Compara dl com dh (se o valor em dl for maior que 4 o código sai)
    jg exceptionInvalidHour
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidHour
    jmp continueh2
skiph2:
    ;Verifica se o segundo digito das horas do compromisso é válido
    mov dl, [valorHoraChegada+1] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '9'             ;Move o valor 2 para dh (para comparar)
    cmp dl, dh            ;Compara dl com dh (se o valor em dl for maior que 4 o código sai)
    jg exceptionInvalidHour
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidHour
continueh2:
    ;Scaneia o valor dos minutos de chegada
    mov rdx, 33         ;Tamanho da string + 1 para incluir a newline
    mov rsi, printMinChegada
    call printf
    mov rdx, 2
    mov rsi, valorMinChegada
    call scanf
    ;Veficia se o primeiro digito dos minutos de chegada é um digito válido
    mov dl, [valorMinChegada] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '5'         ;Move o valor em ascii de 5 para dh (para comparar)
    cmp dl, dh          ;Compara dl com dh (se o valor em dl for maior que o valor em ascii de 5 o código sai)
    jg exceptionInvalidMin
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidMin
    ;Veficia se o segundo digito dos minutos de chegada é um digito válido
    mov dl, [valorMinChegada+1] ;Move o primeiro byte de valorHoraCompromisso para dl
    mov dh, '9'             ;Move o valor em ascii de 9 para dh (para comparar)
    cmp dl, dh            ;Compara dl com dh (se o valor em dl for maior o valor em ascii de 9 o código sai)
    jg exceptionInvalidMin
    mov dh, 48
    cmp dl, dh
    jl exceptionInvalidMin
    ;Comparação dos valores
    mov dl, [valorHoraCompromisso]
    mov dh, [valorHoraChegada]
    cmp dl, dh
    jg calculoMaior
    cmp dl, dh
    jl calculoMenor
    mov dl, [valorHoraCompromisso+1]
    mov dh, [valorHoraChegada+1]
    cmp dl, dh
    jg calculoMaior
    cmp dl, dh
    jl calculoMenor
    mov dl, [valorMinCompromisso]
    mov dh, [valorMinChegada]
    cmp dl, dh
    jg calculoMaior
    cmp dl, dh
    jl calculoMenor
    mov dl, [valorMinCompromisso+1]
    mov dh, [valorMinChegada+1]
    cmp dl, dh
    jg calculoMaior
    cmp dl, dh
    jl calculoMenor
    ;chegou pontualmente
    mov rsi, pontualmente
    mov rdx, 30
    call printf
    call exit
;Imprime uma mensagem na tela
;O endereço da mensagem deve estar no registrador RSI
;O tamanho da mensagem deve estar no registrador RDX
printf:
    push rax
    push rdi
    mov rax,1
    mov rdi,1
    syscall
    pop rdi
    pop rax
    ret
;Scaneia uma input do usuário
;O endereço da input deve estar no registrador RSI
;O tamanho da input deve estar no registrador RDX
scanf:
    push rax
    push rdi
    mov rax, 0
    mov rdi, 0
    syscall
    pop rdi
    pop rax
    ret
;Finaliza o código
exit:
    mov rax, 60
    mov rdi, 0
    syscall
    ret
exceptionInvalidHour:
    mov rsi, invalidHour
    mov rdx, 15
    call printf
    call exit
exceptionInvalidMin:
    mov rsi, invalidMin
    mov rdx, 19
    call printf
    call exit
calculoMaior:
    mov rsi, chegou
    mov rdx, 16
    call printf
    mov rax, valorHoraCompromisso
    call str_to_int
    push rax
    xor rax, rax
    mov rax, 60
    mul rbx
    mov rdx, rax
    pop rax
    mov rax, valorMinCompromisso
    call str_to_int
    add rdx, rbx
    push rdx
    xor rdx, rdx
    mov rax, valorHoraChegada
    call str_to_int
    push rax
    xor rax, rax
    mov rax, 60
    mul rbx
    mov rdx, rax
    pop rax
    mov rax, valorMinChegada
    call str_to_int
    add rdx, rbx
    pop rax
    sub rax, rdx
    push rbx
    push rdx
    mov rbx, 60
    xor rdx, rdx
    div rbx
    push rdx ; rax -> horas ; rdx -> minutos
    cmp rax, 0
    je L2
    cmp rax, 10
    jl L1
    call print_int
    jmp L3
L3:
    mov rsi, dotdot
    mov rdx, 1
    call printf
    pop rdx
    mov rax, rdx
    cmp rax, 0
    je L5
    cmp rax, 10
    jl L4
    call print_int
    jmp L6
L6:
    mov rsi, adiantada
    mov rdx, 12
    call printf
    call exit
L1: ;imprime um zero
    mov rsi, strZero
    mov rdx, 1
    call printf
    call print_int
    jmp L3
L2: ; imprime dois zero 
    mov rsi, strZero
    mov rdx, 1
    call printf
    mov rsi, strZero
    mov rdx, 1
    call printf
    jmp L3
L4: ;imprime um zero
    mov rsi, strZero
    mov rdx, 1
    call printf
    call print_int
    jmp L6
L5: ; imprime dois zero 
    mov rsi, strZero
    mov rdx, 1
    call printf
    mov rsi, strZero
    mov rdx, 1
    call printf
    jmp L6
calculoMenor:
    mov rsi, chegou
    mov rdx, 16
    call printf
    mov rax, valorHoraChegada
    call str_to_int
    push rax
    xor rax, rax
    mov rax, 60
    mul rbx
    mov rdx, rax
    pop rax
    mov rax, valorMinChegada
    call str_to_int
    add rdx, rbx
    push rdx
    xor rdx, rdx
    mov rax, valorHoraCompromisso
    call str_to_int
    push rax
    xor rax, rax
    mov rax, 60
    mul rbx
    mov rdx, rax
    pop rax
    mov rax, valorMinCompromisso
    call str_to_int
    add rdx, rbx
    pop rax
    sub rax, rdx
    push rbx
    push rdx
    mov rbx, 60
    xor rdx, rdx
    div rbx
    push rdx
    ; rax -> horas
    ; rdx -> minutos
    cmp rax, 0
    je L2m
    cmp rax, 10
    jl L1m
    call print_int
    jmp L3m
L3m:
    mov rsi, dotdot
    mov rdx, 1
    call printf
    pop rdx
    mov rax, rdx
    cmp rax, 0
    je L5m
    cmp rax, 10
    jl L4m
    call print_int
    jmp L6m
L6m:
    mov rsi, atrasada
    mov rdx, 11
    call printf
    call exit
L1m: ;imprime um zero
    mov rsi, strZero
    mov rdx, 1
    call printf
    call print_int
    jmp L3m
L2m: ; imprime dois zero 
    mov rsi, strZero
    mov rdx, 1
    call printf
    mov rsi, strZero
    mov rdx, 1
    call printf
    jmp L3m
L4m: ;imprime um zero
    mov rsi, strZero
    mov rdx, 1
    call printf
    call print_int
    jmp L6m
L5m: ; imprime dois zero 
    mov rsi, strZero
    mov rdx, 1
    call printf
    mov rsi, strZero
    mov rdx, 1
    call printf
    jmp L6m
str_to_int:
    xor rbx, rbx            ; zera rbx para receber resultados.
    push rdx
    xor rdx, rdx            ; zera rdx para virar contador
    .loop:
        cmp rdx, 1
        jg .end_sub
        movzx rcx, byte [rax]   ; copia o byte e zera restante do registro.
        inc rax                 ; incrementa endereço em rax.
        cmp rcx, '0'            ; compara o byte com o menor byte válido.
        jl .end_sub             ; se menor, encerra a sub-rotina.
        sub rcx, '0'            ; subtrai 0x30 do byte.
        imul rbx, 10            ; multiplica resultado parcial por 10.
        add rbx, rcx            ; soma o valor em rbx com o valor em rcx.
        inc rdx
	jmp .loop               ; repete até encontrar um byte inválido.
    .end_sub:
    pop rdx
    ret
print_int:
        xor rcx, rcx        ; Zera contador (rcx).
        push rdx
    .loop:
        inc rcx             ; Incrementa o contador.
        xor rdx, rdx        ; Zera rdx (restos).
        mov rbx, 10         ; Copia o divisor para rbx.
        div rbx             ; Divide rax por rbx.
        add dl, '0'         ; Soma 0x30 ao resto no último byte de rdx.
        push rdx            ; Salva rdx na pilha.
        cmp rax, 0          ; Compara o quociente (rax) com zero.
        jnz .loop           ; Se não for zero, repete o loop.        
        mov rbx, rcx        ; Copia o contador (rcx) para rbx.
    .write:
        mov rax, 1          
        mov rdi, 1
        mov rsi, rsp        ; Usa o endereço do topo da pilha.
        mov rdx, 1          ; Imprimir apenas 1 byte.
        syscall
        pop rax             ; Remove o elemento no topo da pilha.
        dec rbx             ; Decrementa o contador (rbx).
        jnz .write          ; Enquanto não for zero, repete.
    pop rdx
    ret
```
