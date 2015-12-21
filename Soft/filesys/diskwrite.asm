# $a0 buff
# $a1 sect

disk_read:
	push $s0
	push $s1
	mov $s0 $a0
	mov $s1 $a1
	lui $t1 $zero 0xD000
	sb $s1 0x200($t1)


	mov $t0 $zero
	addi $t2 $zero 512

disk_write_buff_loop:
	srl $t3 $t0 1	# 512>>256
	add $t5 $t3 $s0	# buff+i
	add $t3 $t0 $t1 # D000-
	mov $t6 $zero
	lb $t6 0($t5)
	sb $t6 0($t3)
	srl $t6 $t6 8
	sb $t6 1($t3)

	addi $t0 $t0 2  
	bne $t0 $t1 disk_read_buff_loop

disk_write_loop:
	lb $t2 0x201($t1)
	bne $t2 $zero disk_write_loop

disk_read_buff_loopend:

	pop $s1
	pop $s0
	jr $ra