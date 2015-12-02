fwrite:
# $a0 fp
# $a1 buff buffer to write
# $a2 btw  bytes to write

# $s0 clst
# $s1 sect
# $s2 wcnt
# $s3 cc
# $s4 csect

# $s6 fp
# $s7 buff
# $s8 btw

	push $s0
	push $s1
	push $s2
	push $s3
	push $s4
	push $s5
	push $s6
	push $s7
	push $s8
	add $s6 $zero $a0
	add $s7 $zero $a1
	add $s8 $zero $a2
	add $s7 $zero $zero # bw = 0

fwrite_loop:
	slt $t0 $zero $s8	
	beq $t0 $zero fwrite_loopexit #btw > 0
	lw $t0 2($s6)	#fp->fptr
	and $t1 $t0 255 #fptr % 256
	bne $t1 $zero fwrite_get  
	bne $t0 $zero fwrite_fptrmark #if fptr == 0?
	lw $s0 6($s6)	#clst = fp->sclust
	bne $s0 $zero fwrite_fptrmarkend
	# clst = create_chain(fp->fs, 0)
	addi $a0 $zero 0
	jal create_chain
	move $s0 $v0
	beq $zero $zero fwrite_fptrmarkend
fwrite_fptrmark:
	# clst = create_chain(fp->fs, fp->clust);
	lw $a0 8($s6)
	jal create_chain
	move $s0 $v0

fwrite_fptrmarkend:
	sw $s0 8($s6)
	
fwrite_get:

fwrite_loopend:
fwrite_loopexit:
