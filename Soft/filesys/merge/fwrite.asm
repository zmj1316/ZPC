#include create_chain
#include disk_write
#include clust2sect
#include mem_cpy
#include disk_read
fwrite:


# $a0 fp
# $a1 buff buffer to write
# $a2 btw  bytes to write

# $s0 clst
# $s1 sect
# $s2 wcnt
# $s3 cc
# $s4 csect
# $s5 bw
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
	add $s5 $zero $zero # bw = 0

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
	sw $s0 8($s6)	# fp->clust = clst
	lw $t0 6($s6)	# fp->sclust
	bne $t0 $zero 1 # if sclust == 0
	sw $s0 6($s6)	# fp->sclust = clst
	lw $t2 0($s6)	# fp->flag
	andi $t3 $t2 0x40 # fp->flag & FA__DIRTY
	beq $t3 $zero fwrite_dirtyend 
	# disk_write(buff,dsect)
	move $a0 $s7
	lw $a1 10($s6)	
	jal disk_write
	andi $t2 $t2 0xFFFFFFBF flag &=~FA__DIRTY
	sw $t2 0($s6)	# fp->flag
fwrite_dirtyend:
	# sect = clust2sect(fp->clust)
	lw $a0 6($s6)
	jal clust2sect
	move $s1 $v0
	srl $s3 $s8 8			# cc = btw / 256
	beq $s3 $zero fwrite_cc # if cc
	# disk_write(buff,sect)
	move $a0 $s7
	move $a1 $s1
	jal disk_write
	sll $s2 $s3 8 # wcnt = SS * cc
	beq $zero $zero fwrite_loopend
fwrite_cc:
	lw $t0 10($s6) #dsect
	beq $t0 $s0 fwrite_dsect # if dsect != sect
	# disk_read(fp->buf,sect)
	lw $a0 16($s6)
	move $a1 $s1
	# addi $a2 $zero 1
	jal disk_read
fwrite_dsect:
	sw $s1 10($s6) # fp->dsect = sect

fwrite_get:
	lw $t2 2($s6) # fp-> fptr
	andi $t2 $t2 255 # fptr % SS
	subi $s2 $t2 256
	sub $s2 $zero $s2 # wcnt = SS - fptr%SS
	slt $t0 $s8 $s2 # if s8 < s2 wcnt > btw
	beq $t0 $zero 1
	add $s2 $zero $s8
	# mem_cpy(fp->buf + fptr % SS,buff,wcnt)
	add $a1 $s7 $zero
	lw $t3 16($s6)
	add $a0 $t2 $t3
	add $a2 $zer0 $s2 
	jal mem_cpy
	lw $t2 0($s6)	# fp->flag
	ori $t2 $t2 0x40
	sw $t2 0($s6)
fwrite_loopend:
	add $s7 $s7 $s2 	#wbuff += wcnt
	lw $t0 2($s6)		#fp->fptr += wcnt
	add $t0 $t0 $s2
	sw $t0 2($s6)
	add $s5 $s5 $s2		#bw += wcnt
	sub $s8 $s8 $s2 	#btw -= wcnt
	beq $zero $zero fwrite_loop
fwrite_loopexit:
	lw $t0 4($s6) # fsize
	lw $t1 2($s6) # fptr
	slt $t3 $t0 $t1 # fsize<fptr?
	beq $t3 $zero 1
	sw $t1 4($s6) # fp->fsize = fp->fptr
	# fp->flag |= FA__WRITTEN?!
	
	add $v0 $zero $s5  	#return bw
	pop $s8
	pop $s7
	pop $s6
	pop $s5
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	
	jr $ra
