remove_chain:
# $a0 clst
# $s0 clst
# $s1 fs
# $s2 nxt
# $s3 free_clst
	push $s0
	push $s1
	push $s2
	push $s3
	move $s0 $a0 # clst
	addi $s1 $zero 128 # fs
	lw $t0 6($s1) # fatent

remove_chain_while_loop:
	slt $t1 $s0 $t0   # While clst < fatent
    beq $t1 $zero remove_chain_exit
	jal get_fat
	move $s2 $v0 # nxt = get_fat()
	beq $s2 $zero remove_chain_exit
	addi $a1 $zero 0
	jal put_fat
	lw $s3 4($s1) # free_clust
	addi $t1 $zero -1
	beq $s3 $t1 remove_chain_next
	addi $s3 $s3 1 
	sw $s3 4($s1) # free_clust++
remove_chain_next:
	move $s0 $s2 # clst = nxt
	j while_loop
remove_chain_exit:
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra


