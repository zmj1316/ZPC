.text
SS:;this is lable uppercase only
addi $t1 $zero S
lw $t2 $t1 0
SR:
add $t1 $t2 $t3
beq $zero $zero SSS
bne $zero $at SS
SSS:
j SR

.data
X:	.word 0xEEEE
S:  .ascii "ABCDEFGHIJKLMNOPQ"