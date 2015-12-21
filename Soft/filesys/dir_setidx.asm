dir_setidx:
# $a0 fil
# $s0 fil
# $a1 index
# $s1 index
# $s2 fs
	push $s0
	push $s1
	push $s2
	mov $s0 $a0
	mov $s1 $a1
	addi $s2 $zero 128
	lw $s3 12($s2)	# dirbase
	# read dir sector
	addi $a0 $s2 18  # win
	mov $a1 $s3
	push $ra
	jal disk_read
	pop $ra
	srl $s1 $s1 5	# index *32
	addi $t0 $s2 18  # win
	add $t0 $t0 $s1
	lb $t1 13($t0) # sclust
	sw $t1 6($s0)  # fp
	lw $t1 14($t0) # fsize
	sw $t1 4($s0)  # fp->fsize
	sw $zero 0($s0)
	sw $zero 2($s0)
	sw $zero 8($s0)
	sw $zero 10($s0)
	sw $s3 12($s0)
	sw $s1 14($s0)
	

	pop $s2
	pop $s1
	pop $s0
	jr $ra
