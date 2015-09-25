;comments here
SS:;this is lable uppercase only
addi $t1 $zero 0xFFFF
SR:
add $t1 $t2 $t3
beq $zero $zero SSS
SSS:
bne $zero $at SSS
j SR
