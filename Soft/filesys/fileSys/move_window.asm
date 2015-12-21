move_window:
# $a0 sector
# $s0 sector
# $s1 fs
	push $s0
	push $s1
	move $s0 $a0
	addi $s1 $zero 128 # fs
	lw $t0 16($s1) # winsect
	beq $s0 $t0 move_window_exit
	jal sync_window
	lw $a0 18($s1)
	move $a1 $s0
	jal disk_read
	addi $t0 $zero -1
	move $s0 $t0
	sw $s0 16($s1) # winsect = sector
move_window_exit:
	pop $s1
	pop $s0	
	jr $ra

