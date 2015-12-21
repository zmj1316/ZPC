create_chain:
# $a0 clst
# $s0 clst
# $s1 fs
# $s2 cs
# $s3 ncl
# $s4 scl
	push $s0
	push $s1
	push $s2
	push $s3
	push $s4
	move $s0 $a0 # clst
	addi $s1 $zero 128 # fs
	lw $t0 2($s1) # last_clust
	bne $s0 $zero create_chain_stretch
	move $s4 $t0 # scl = last_clust
	bne $s4 $zero create_chain_not_scl # scl != 0
	addi $s4 $zero 1 # scl = 1
	j create_chain_start_cluster
create_chain_not_scl:
	lw $t0 6($s1) # fatent
	slt $t1 $t0 $s4   # fatent < scl
	bne $t1 $zero create_chain_start_cluster
	addi $s4 $zero 1 # scl = 1
	j create_chain_start_cluster
create_chain_stretch:
	jal get_fat
	move $s2 $v0 # cs = get_fat()
	lw $t0 6($s1) # fatent
	slt $t1 $s2 $t0   # cs < fatent
	beq $t1 $zero create_chain_not_return
	move $v0 $s2
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra # return cs
create_chain_not_return:
	move $s4 $s0 scl = clst

create_chain_start_cluster:
	move $s3 $s4 # ncl = scl
create_chain_for:
	addi $s3 $s3 1 # ncl++
	lw $t0 6($s1) # fatent
	slt $t1 $t0 $s3   # fatent < ncl
	bne $t1 $zero create_chain_no_check_wrap_around
	addi $s3 $zero 2 # ncl = 2
	slt $t1 $s4 $s3 # scl < ncl
	beq $t1 $zero create_chain_no_check_wrap_around
	add $v0 $zero $zero
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra # return 0
create_chain_no_check_wrap_around:
	jal get_fat
	move $s2 $v0 # cs = get_fat()
	beq $s2 $zero create_chain_break
	beq $s3 $s4 create_chain_no_free
	j create_chain_for
create_chain_no_free:
	move $v0 $zero
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra # return 0
create_chain_break:
	move $a0 $s3
	addi $a1 $zero -1
	jal put_fat
	beq $s4 $zero create_chain_not_link
	move $a0 $s4
	move $a1 $s3
	jal put_fat
create_chain_not_link:
	sw $s3 2($s1) # last_clust = ncl
	addi $t0 $zero -1
	lw $t1 4($s1) #free_clust
	beq $t1 $t0 remove_chain_else
	addi $t1 $t1 -1
	sw $t1 4($s1) #free_clust--
	j remove_chain_return
remove_chain_else:
	addi $s3 $zero 1 # ncl = 1
remove_chain_return:
	move $v0 $s3
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra









