.orign 0
.text
printdir:
	addi $t0 $zero 128
	lw $t0 0xF8($t0)	# dirbase
	lui $a0 0xF000
	mov $a1 $t0
	push $ra
	jal disk_read
	pop $ra
	mov $t4 $zero
	lui $t0 0xD000
	lui $t1	0xA000
printdir_loop:
	lb $t2 0($t0)
	sb $t2 0($t1)
	lb $t2 1($t0)
	sb $t2 1($t1)
	lb $t2 2($t0)
	sb $t2 2($t1)
	lb $t2 3($t0)
	sb $t2 3($t1)
	lb $t2 4($t0)
	sb $t2 4($t1)
	lb $t2 5($t0)
	sb $t2 5($t1)
	addi $t0 $t0 32
	addi $t4 $t4 1
	addi $t5 $zero 4
	bne $t4 $t5 printdir_loop
main:
	j main
	jr $ra
