get_fat:
# $a0 clst
# $s0 clst
# $s1 p
# $s2 fs
	push $s0
	push $s1
	push $s2
	move $s0 $a0 # clst
	srl $t0 $s0 8  # clst/256
	
	addi $s2 $zero 128 # fs
	lw $a0 10($t2) # fatbase
	jal move_window
	addi $s2 $s2 18
	sll $t1 $s0 8  # clst%256
	add $s2 $s2 $t1# win+offset
	lh $s1 0($s2)
	move $v0 $s1
	pop $s2
	pop $s1
	pop $s0
	jr $ra