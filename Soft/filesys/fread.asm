#include get_fat
#include clust2sect
#include disk_read
#include mem_cpy
#include disk_write

fread:
# $a0 fp 		file struct
# $a1 buff		buff to write
# $a2 btr       bytes to read

# $s0 sect 		
# $s1 remain	byte remained
# $s2 rcnt 		
# $s3 cc
# $s4 clst
# $s5 br
# $s6 fp 	
# $s7 buff
# $s8 btr  
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
	addi $s5 $zero 0 #br = 0
	lw $t0 4($s6)	 #fp->fsize
	lw $t1 2($s6) 	 #fp->fptr
	sub $s1 $t0 $t1  #remain = fp->fsize - fp->fptr
	slt $t0 $s1 $a2  #remain < btr ?
	beq $t0 $zero 1  
	addi $s8 $s1	#btr = remain
fread_loop0:
	slt $t0 $zero $s8
	beq $t0 $zero fread_loopexit #btr > 0
	lw $t0 2($s6)	#fp->fptr
	andi $t1 $t0 255 #fptr % 256
	bne $t1 $zero fread_get  
	#on the boundary
	bne $t0 $zero 4	#if fptr == 0?
	lw $s4 6($s6)   #clst = fp->sclust
	#else
	# clst = getfat(fp->clust)
	lw $a0 8($s6)   
	jal getfat
	add $s4 $zero $v0 
	#endif
	sw $s0 8($s6)	# fp->clust = clst
	# sect = clust2sect(fp->fs, fp->clust(//clst))
	move $a0 $s4
	jal clust2sect
	move $s0 $v0
	
	srl $s3 $s8 8 # cc = btr / 256(sector size)
	beq $s3 $zero fread_ccmark # if cc (more than 1 sector)
	# disk_read(buff,sect)
	add $a0 $zero $s7
	add $a1 $zero $s0
	jal disk_read
	sll $s2 $s3 8 # rcnt = cc * 256
	beq $zero $zero fread_loopend
fread_ccmark:
	lw $t0 10($s6) #dsect
	beq $t0 $s0 fread_dsect # if dsect != sect
	lw $t1 0($s6) 	#flag
	andi $t2 $t1 0x40#flag & FA__DIRTY
	beq $t2 $zero fread_ccmark_t1 #if t1 != 0
	# disk_write(fp->buf,fp->dsect)
	lw $a0 16($s6)
	lw $a1 10($s6)
	jal disk_write
	lw $t1 0($s6) 	#flag
	andi $t1 $t1 0xFFFFFFBF flag &=~FA__DIRTY
	sw $t1 0($s6)	# fp->flag
fread_ccmark_t1:
fread_dsect:
	sw $s0 10($s6) #fp->dsect = sect

fread_get:
	lw $t2 2($s6) # fp-> fptr
	andi $t2 $t2 255 # fptr % SS
	subi $s2 $t2 256
	sub $s2 $zero $s2 # rcnt = SS - fptr%SS
	slt $t0 $s8 $s2 # if s8 < s2
	beq $t0 $zero 1
	add $s2 $zero $s8
	# mem_cpy(buff,fp->buf + fptr % SS,rcnt)
	add $a0 $s7 $zero
	lw $t3 16($s6)
	add $a1 $t2 $t3
	add $a2 $zer0 $s2
	jal mem_cpy

fread_loopend:
	add $s7 $s7 $s2 	#rbuff += rcnt
	lw $t0 2($s6)		#fp->fptr += rcnt
	add $t0 $t0 $s2
	sw $t0 2($s6)
	add $s5 $s5 $s2		#br += rcnt
	sub $s8 $s8 $s2 	#btr -= rcnt
	beq $zero $zero fread_loop0
fread_loopexit:
	add $v0 $zero $s5  	#return br
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
