# $a0 buff
# $a1 sect

disk_read:
	push $s0
	push $s1
	mov $s0 $a0
	mov $s1 $a1
	lui $t1 $zero 0xD000
	sb $s1 0x200($t1)
	lb $t3 0x202($t1)
disk_read_loop:
	lb $t2 0x201($t1)
	bne $t2 $zero disk_read_loop

	mov $t0 $zero
	addi $t2 $zero 512
disk_read_buff_loop:
	add $t3 $t0 $t1 # D000-
	lb $t4 0($t3)	# 
	lb $t5 1($t3)
	sll $t5 $t5 8	# hi-lo
	or $t4 $t4 $t5	# 
	srl $t3 $t0 1	# 512>256
	add $t5 $t3 $s0	# buff+i
	sb $t4 0($t5)	
	addi $t0 $t0 2  
	bne $t0 $t1 disk_read_buff_loop

disk_read_buff_loopend:

	pop $s1
	pop $s0