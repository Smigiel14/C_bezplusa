section .text
    global asmpow

asmpow:
    mov rax, 1
    test rsi, rsi ; 
    jz .done ;jump zero
.loop:
    imul rax, rdi
    dec rsi
    jnz .loop    ;jump not zero
 .done:
    RET
