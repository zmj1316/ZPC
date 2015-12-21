.orign 0

.text
j main
.data
	keyboard_head .word 0x0
	keyboard_tail .word 0x0
.orign 128
.data
	#文件系统结构体 FATFS
	fs_wflag .word         0
	fs_last_clust .word    0
	fs_free_clust .word    0xFFFF
	fs_n_fatent .word      2
	fs_volbase .word  	   0x80  
	fs_fatbase .word 0x0   0x88  
	fs_dirbase .word 0x0   0xF8
	fs_database .word 0x0  0x118
	fs_winsect .word 0x0     
	fs_win .word 0x0 		 
	#256
.orign 410
.data
	#文件结构体1
	f0_flag .word 0x0 	# 0
	f0_fptr .word 0x0 	# 2
	f0_fsize .word 0x0 	# 4
	f0_sclust .word 0x0 # 6
	f0_clust .word 0x0  # 8
	f0_dsect .word 0x0  # 10
	f0_dir_sect .word 0x0 # 12
	f0_dir_ptr .word 0x0 # 14
	f0_buf .word 0x0 		#16
.orign 700
.data
	#文件结构体2
	f1_flag .word 0x0
	f1_fptr .word 0x0
	f1_fsize .word 0x0
	f1_sclust .word 0x0
	f1_clust .word 0x0
	f1_dsect .word 0x0
	f1_dir_sect .word 0x0
	f1_dir_ptr .word 0x0
	f1_buf .word 0x0
.orign 990
.data
	#目录结构体
	dir_index .word 0x0
	dir_sclust .word 0x0
	dir_sect .word 0x0
	dir_dir .word 0x0
	dir_sfn .word 0x0
.orign 1000
.data
	#文件信息结构体
	fi_fsize .word 0x0
	fi_fdate .word 0x0
	fi_ftiem .word 0x0
	fi_fattr .word 0x0
	fi_fname .word 0x0
	#char [13]
.orign 1024
	#中断表开始
	.data
	time_counter .word 0x80
	keyboard .word  0xB0
	
.orign 1030
.text
	#中断入口

.orign 3000
.text
	#系统程序
#Head	
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
	mov $s8 $s1 	#btr = remain
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
	mov $a0 $s4
	jal clust2sect
	mov $s0 $v0
	
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



#include get_fat
get_fat:
# $a0 clst
# $s0 clst
# $s1 p
# $s2 fs
	push $s0
	push $s1
	push $s2
	mov $s0 $a0 # clst
	srl $t0 $s0 8  # clst/256
	
	addi $s2 $zero 128 # fs
	lw $a0 10($t2) # fatbase
	add $a0 $a0 $t0 # fatbase + clst/256
	jal move_window
	addi $s2 $s2 18 # win
	sll $t1 $s0 8  # clst%256
	add $s2 $s2 $t1# win+offset
	lh $s1 0($s2)
	mov $v0 $s1
	pop $s2
	pop $s1
	pop $s0
	jr $ra

#include clust2sect
clust2sect:
# $a0 clst
# $s0 clst
# $s1 fs
	push $s0
	mov $s0 $a0 # clst
	addi $s0 $s0 -2 # clst-=2

	lw $t0 14($s1) # database
	add $t1 $s0 $t0
	mov $v0 $t1
	pop $s0
	jr $ra
#include disk_read
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
	jr $ra
#include mem_cpy

#include disk_write
# $a0 buff
# $a1 sect

disk_write:
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

disk_write_buff_loopend:

	pop $s1
	pop $s0
	jr $ra

.orign 5000
main:
