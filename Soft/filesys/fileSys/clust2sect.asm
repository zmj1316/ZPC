clust2sect:
# $a0 clst
# $s0 clst
# $s1 fs
	push $s0
	move $s0 $a0 # clst
	addi $s0 $s0 -2 # clst-=2

	lw $t0 14($s1) # database
	add $t1 $s0 $t0
	move $v0 $t1
	pop $s0
	jr $ra