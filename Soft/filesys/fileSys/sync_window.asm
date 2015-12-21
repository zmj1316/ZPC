sync_window:
# $s0 wsect
# $s1 fs
	push $s0
	push $s1
	addi $s1 $zero 128 # fs
	lw $t0 0($s1) # wflag
	beq $t0 $zero sync_window_exit
	lw $t1 16($s1) # winsect
	move $s0 $t1 # wsect = fs_winsect
	move $a0 18($s1)
	move $a1 $s0
	jal disk_write
	sw $zero 0($s1) # wflag = 0
sync_window_exit:
	pop $s1
	pop $s0
	jr $ra



	