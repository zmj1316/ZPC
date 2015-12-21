put_fat:
# $a0 clst
# $a1 val
# $s0 clst
# $s1 fs
	push $s0
	push $s1
	move $s0 $a0 # clst
	srl $t0 $s0 8  # clst >> 8
	
	addi $s1 $zero 128 # fs
	lw $a0 10($s1) # fatbase
	add $a0 $a0 $t0 # fatbase + clst >> 8
	jal move_window	
	addi $s1 $s1 18 # win
	andi $t1 $s0 255  # clst&255
	add $s1 $s1 $t1# win+offset
	lh $a1 0($s1)
	addi $s1 $zero 128 # fs
	addi $t0 $zero 1
	sw $t0 0(s1) # wflag = 1
	pop $s1
	pop $s0
	jr $ra