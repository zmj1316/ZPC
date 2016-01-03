.orign 0
.text
	addi $sp, $zero, 6000
	j boot

.orign 4
.data
	#键盘缓冲区指针
	keyboard_head .word 0x10
	keyboard_tail .word 0x10
	im_head .word  1032
	im_tail .word 1032
	shift .word 0

.orign 16
	#键盘缓冲区 16-128

.orign 128
.data
	#文件系统结构体 FATFS
	fs_wflag .word         0
	fs_last_clust .word    0
	fs_free_clust .word    0xFFFF
	fs_n_fatent .word      13600
	fs_volbase .word  	   0x80  
	fs_fatbase .word   0x88  
	fs_dirbase .word   0xF8
	fs_database .word  0x118
	fs_winsect .word 0x0     
	fs_win .word 0x0 		 
	#256
.orign 410
.data
	#文件结构体1
	f0_flag .word 0x20 	# 0
	f0_fptr .word 0x0 	# 2
	f0_fsize .word 0x105 	# 4
	f0_sclust .word 0x2 # 6
	f0_clust .word 0  # 8
	f0_dsect .word 0  # 10
	f0_dir_sect .word 0xF8 # 12
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
.data
	#中断表开始
	time_counter .addr time_int
	keyboard .addr keyboard_int
	#syscall .addr syscall_int

.orign 1032
#留出2个word给输入法缓冲区

.orign 1036
.text
	#中断入口
int:	
	push $s5

	#查中断向量表
	mfc0 $s5, 13
	add $s5, $s5, $s5
	addi $s5, $s5, 1024
	lw $s5, 0($s5)
	jr $s5

int_end:
	pop $s5
	eret



.data
	hour .word 0x0
	minute .word 0x0
	second .word 0x0


.text
	#每秒一次计时器中断
time_int:
	push $s5
	push $s4
	push $s3
time_int_second:
	la $s5, second
	lw $s4, 0($s5)
	addi $s4, $s4, 1
	slti $s3, $s4, 60
	bne $s3, $zero, time_int_second_uncarry
	mov $s4, $zero
time_int_second_uncarry:
	sw $s4, 0($s5)
	bne $s3, $zero, time_int_end

time_int_minute:
	la $s5, minute
	lw $s4, 0($s5)
	addi $s4, $s4, 1
	slti $s3, $s4, 60
	bne $s3, $zero, time_int_minute_uncarry
	mov $s4, $zero
time_int_minute_uncarry:
	sw $s4, 0($s5)
	bne $s3, $zero, time_int_end

time_int_hour:
	la $s5, hour
	lw $s4, 0($s5)
	addi $s4, $s4, 1
	slti $s3, $s4, 24
	bne $s3, $zero, time_int_hour_uncarry
	mov $s4, $zero
time_int_hour_uncarry:
	sw $s4, 0($s5)
	bne $s3, $zero, time_int_end

time_int_end:
	pop $s3
	pop $s4
	pop $s5
	j int_end


.orign 1150
.text
	#键盘中断
keyboard_int:
	push $s7
	push $s6
	push $s5
	push $s4
	#获得键盘输入的值
	lui $s7, 0xB000
	lb $s7, 0($s7)

keyboard_normal:
	la $s6, keyboard_tail
	lw $s6, 0($s6)
	la $s5, keyboard_head
	lw $s5, 0($s5)	
	
	sb $s7, 0($s6)
	addi $s6, $s6, 1

	slti $s4, $s6, 128
	bne $s4, $zero, keyboard_next
	addi $s6, $zero, 0x10
keyboard_next:
	la $s7, keyboard_tail
	sw $s6, 0($s7)
	j keyboard_end


keyboard_end:
	pop $s4
	pop $s5
	pop $s6
	pop $s7
	j int_end


#include disk_read
# $a0 buff
# $a1 sect

disk_read:
	push $s0
	push $s1
	mov $s0 $a0
	mov $s1 $a1
	lui $t1 0xD000
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
	srl $t3 $t0 1	#  /2
	andi $t3 $t3 0xFF
	add $t5 $t3 $s0	# buff+i
	sb $t4 0($t5)	
	addi $t0 $t0 2  
	bne $t0 $t2 disk_read_buff_loop

disk_read_buff_loopend:

	pop $s1
	pop $s0
	jr $ra

boot:
	addi $a0 $zero 2000
	addi $a1 $zero 0x118
	jal disk_read
	addi $a0 $zero 2256
	addi $a1 $zero 0x119
	jal disk_read
	addi $a0 $zero 2512
	addi $a1 $zero 0x11a
	jal disk_read
	addi $a0 $zero 2768
	addi $a1 $zero 0x11b
	jal disk_read
	addi $a0 $zero 3024
	addi $a1 $zero 0x11c
	jal disk_read
	addi $a0 $zero 3280
	addi $a1 $zero 0x11d
	jal disk_read
	addi $a0 $zero 3536
	addi $a1 $zero 0x11e
	jal disk_read
	la $a0 startstr
	jal println_string
	j main

.data
	startstr .asciiz "Sys Loaded"

.orign 2000
.text
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
# $t8 btr  
	push $s0
	push $s1
	push $s2
	push $s3
	push $s4
	push $s5
	push $s6
	push $s7
	push $t8
	add $s6 $zero $a0
	add $s7 $zero $a1
	add $t8 $zero $a2
	addi $s5 $zero 0 #br = 0
	lw $t0 4($s6)	 #fp->fsize
	lw $t1 2($s6) 	 #fp->fptr
	sub $s1 $t0 $t1  #remain = fp->fsize - fp->fptr
	slt $t0 $s1 $a2  #remain < btr ?
	beq $t0 $zero 1  
	mov $t8 $s1	#btr = remain
fread_loop0:
	slt $t0 $zero $t8
	beq $t0 $zero fread_loopexit #btr > 0
	lw $t0 2($s6)	#fp->fptr
	andi $t1 $t0 255 #fptr % 256
	bne $t1 $zero fread_get  
	#on the boundary
	bne $t0 $zero fread_fptr0_else	#if fptr == 0?
	lw $s4 6($s6)   #clst = fp->sclust
	beq $zero $zero fread_fptr0_endif
	fread_fptr0_else:
	# clst = getfat(fp->clust)

	lw $a0 8($s6)   
	push $ra
	jal get_fat
	pop $ra
	add $s4 $zero $v0 
	fread_fptr0_endif:
	sw $s4 8($s6)	# fp->clust = clst
	# sect = clust2sect(fp->fs, fp->clust(//clst))
	mov $a0 $s4
	push $ra
	jal clust2sect
	pop $ra
	mov $s0 $v0
	
	srl $s3 $t8 8 # cc = btr / 256(sector size)
	beq $s3 $zero fread_ccmark # if cc (more than 1 sector)
	# disk_read(buff,sect)
	add $a0 $zero $s7
	add $a1 $zero $s0
	push $ra
	jal disk_read
	pop $ra
	sll $s2 $s3 8 # rcnt = cc * 256
	beq $zero $zero fread_loopend
fread_ccmark:
	lw $t0 10($s6) #dsect
	beq $t0 $s0 fread_dsect # if dsect != sect
	lw $t1 0($s6) 	#flag
	andi $t2 $t1 0x40#flag & FA__DIRTY
	beq $t2 $zero fread_ccmark_t1 #if t1 != 0
#	beq $zero $zero fread_ccmark_t1 #if t1 != 0
	# disk_write(fp->buf,fp->dsect)
	addi $a0 $s6 16
	lw $a1 10($s6)
	push $ra
	jal disk_write
	pop $ra
	lw $t1 0($s6) 	#flag
	andi $t1 $t1 -0x41 #flag &=~FA__DIRTY
	sw $t1 0($s6)	# fp->flag
fread_ccmark_t1:

	addi $a0 $s6 16
	mov $a1 $s0
	push $ra
	jal disk_read
	pop $ra
fread_dsect:
	sw $s0 10($s6) #fp->dsect = sect

fread_get:
	lw $t2 2($s6) # fp-> fptr
	andi $t2 $t2 255 # fptr % SS
	addi $s2 $t2 -256 #
	sub $s2 $zero $s2 # rcnt = SS - fptr%SS
	slt $t0 $t8 $s2 # if t8 < s2
	beq $t0 $zero 1
	add $s2 $zero $t8
	# mem_cpy(buff,fp->buf + fptr % SS,rcnt)
	add $a0 $s7 $zero
	addi $t3 $s6 16
	add $a1 $t2 $t3
	add $a2 $zero $s2
	push $ra
	jal mem_cpy
	pop $ra

fread_loopend:
	add $s7 $s7 $s2 	#rbuff += rcnt
	lw $t0 2($s6)		#fp->fptr += rcnt
	add $t0 $t0 $s2
	sw $t0 2($s6)
	add $s5 $s5 $s2		#br += rcnt
	sub $t8 $t8 $s2 	#btr -= rcnt
	beq $zero $zero fread_loop0
fread_loopexit:
	add $v0 $zero $s5  	#return br
	pop $t8
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
	#addi $a0 $s2 18 # win
	lw $a0 10($s2) # fatbase
	add $a0 $a0 $t0 # fatbase + clst/256
	push $ra
	jal move_window
	pop $ra
	addi $s2 $s2 18 # win
	andi $t1 $s0 255
	add $s2 $s2 $t1# win+offset
	lb $s1 0($s2)
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
	addi $s1 $zero 128
	lw $t0 14($s1) # database
	add $t1 $s0 $t0
	mov $v0 $t1
	pop $s0
	jr $ra


#include move_window
move_window:
# $a0 sector
# $s0 sector
# $s1 fs
	push $s0
	push $s1
	mov $s0 $a0
	addi $s1 $zero 128 # fs
	lw $t0 16($s1) # winsect
	beq $s0 $t0 move_window_exit
	push $ra
	jal sync_window
	pop $ra
	addi $a0 $s1 18
	mov $a1 $s0
	push $ra
	jal disk_read
	pop $ra
	sw $s0 16($s1) # winsect = sector
move_window_exit:
	pop $s1
	pop $s0	
	jr $ra

sync_window:
# $s0 wsect
# $s1 fs
	push $s0
	push $s1
	addi $s1 $zero 128 # fs
	lw $t0 0($s1) # wflag
	#debug
	beq $zero $zero sync_window_exit
	#beq $t0 $zero sync_window_exit
	lw $t1 16($s1) # winsect
	mov $s0 $t1 # wsect = fs_winsect
	addi $a0 $s1 18
	mov $a1 $s0
	push $ra
	jal disk_write
	pop $ra
	sw $zero 0($s1) # wflag = 0
sync_window_exit:
	pop $s1
	pop $s0
	jr $ra



	

#include mem_cpy
	mem_cpy:
		push $s0
		push $s1

		add $s1, $zero, $zero
	mem_cpy_again:
		beq $s1, $a2, mem_cpy_end
		lb $s0, 0($a1)
		sb $s0, 0($a0)
		addi $s1, $s1, 1
		addi $a0, $a0, 1
		addi $a1, $a1, 1
		beq $zero $zero mem_cpy_again
	mem_cpy_end:
		pop $s1
		pop $s0
		jr $ra
#include disk_write
# $a0 buff
# $a1 sect
# $a2 count
disk_write:
	push $s0
	push $s1
	mov $s0 $a0
	mov $s1 $a1
	lui $t1 0xD000
	sb $s1 0x200($t1)


	mov $t0 $zero
	addi $t2 $zero 512

disk_write_buff_loop:
	srl $t3 $t0 1	# 512>>256
	andi $t3 $t3 0xFF
	add $t5 $t3 $s0	# buff+i
	add $t3 $t0 $t1 # D000-
	mov $t6 $zero
	lb $t6 0($t5)
	sb $t6 0($t3)
	srl $t6 $t6 8
	sb $t6 1($t3)

	addi $t0 $t0 2  
	bne $t0 $t2 disk_write_buff_loop
	sb $t3 0x202($t1)
disk_write_loop:
	lb $t2 0x201($t1)
	bne $t2 $zero disk_write_loop

disk_write_buff_loopend:
	pop $s1
	pop $s0
	jr $ra


printdir:
	push $s0
	addi $s0 $zero 128
	lw $s0 12($s0)	# dirbase
	lui $a0 0xF000
	mov $a1 $s0
#	addi $a1 $zero 0xF8
	push $ra
	jal disk_read
	pop $ra
	mov $t4 $zero
	lui $t0 0xD000
	lui $t1	0xA000
	addi $t6 $zero 0xE5
	la $a0 dirstr
	jal println_string
printdir_loop:
	lb $t2 0($t0)
	beq $t2 $t6 printdir_loop_end
	beq $t2 $zero printdir_loop_exit
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
	lb $t2 6($t0)
	sb $t2 6($t1)
	lb $t2 7($t0)
	sb $t2 7($t1)
	lb $t2 8($t0)
	sb $t2 8($t1)
	lb $t2 9($t0)
	sb $t2 9($t1)
	addi $t2 $zero 13
	sb $t2 6($t1)
	addi $t0 $t0 32
printdir_loop_end:
	addi $t4 $t4 1
	addi $t5 $zero 32
	bne $t4 $t5 printdir_loop
printdir_loop_exit:
	pop $s0
	jr $ra
.data
	dirstr .asciiz "Dir:"
.text


#include create_chain
create_chain:
# $a0 clst
# $s0 clst
# $s1 fs
# $s2 cs
# $s3 ncl
# $s4 scl
	push $s0
	push $s1
	push $s2
	push $s3
	push $s4
	nop
	mov $s0 $a0 # clst
	addi $s1 $zero 128 # fs
	lw $t0 2($s1) # last_clust
	bne $s0 $zero create_chain_stretch
	addi $s4 $zero 1 # scl = 1
	beq $zero $zero create_chain_start_cluster
create_chain_stretch:
	push $ra
	jal get_fat
	pop $ra
	mov $s2 $v0 # cs = get_fat()
	lw $t0 6($s1) # fatent
	slt $t1 $s2 $t0   # cs < fatent
	beq $zero $zero create_chain_not_return
	mov $v0 $s2
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra # return cs
create_chain_not_return:
	mov $s4 $s0 #scl = clst

create_chain_start_cluster:
	mov $s3 $s4 # ncl = scl
create_chain_for:
	addi $s3 $s3 1 # ncl++
	lw $t0 6($s1) # fatent
	slt $t1 $s3 $t0   # fatent > ncl
	bne $t1 $zero create_chain_no_check_wrap_around
	addi $s3 $zero 2 # ncl = 2
	slt $t1 $s4 $s3 # scl < ncl
	beq $t1 $zero create_chain_no_check_wrap_around
	add $v0 $zero $zero
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra # return 0
create_chain_no_check_wrap_around:
	mov $a0 $s3
	push $ra
	jal get_fat
	pop $ra
	mov $s2 $v0 # cs = get_fat()
	beq $s2 $zero create_chain_break
	beq $s3 $s4 create_chain_no_free
	j create_chain_for
create_chain_no_free:
	mov $v0 $zero
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra # return 0
create_chain_break:
	mov $a0 $s3
	addi $a1 $zero -1
	push $ra
	jal put_fat
	pop $ra
	beq $s0 $zero create_chain_not_link
	mov $a0 $s0
	mov $a1 $s3
	push $ra
	jal put_fat
	pop $ra
create_chain_not_link:
	sw $s3 2($s1) # last_clust = ncl
	addi $t0 $zero -1
	lw $t1 4($s1) #free_clust
	beq $t1 $t0 create_chain_else
	addi $t1 $t1 -1
	sw $t1 4($s1) #free_clust--
	j create_chain_return
create_chain_else:
	addi $s3 $zero 1 # ncl = 1
create_chain_return:
	mov $v0 $s3
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra










#include put_fat
put_fat:
# $a0 clst
# $a1 val
# $s0 clst
# $s1 fs
	push $s0
	push $s1
	mov $s0 $a0 # clst
	srl $t0 $s0 8  # clst >> 8
	
	addi $s1 $zero 128 # fs
	lw $a0 10($s1) # fatbase
	add $a0 $a0 $t0 # fatbase + clst >> 8
	push $ra
	jal move_window	
	pop $ra
	addi $s1 $s1 18 # win
	andi $t1 $s0 255  # clst&255
	add $t3 $s1 $t1# win+offset
	sb $a1 0($t3)
	addi $s1 $zero 128 # fs
	addi $t0 $zero 1
	sw $t0 0($s1) # wflag = 1
	pop $s1
	pop $s0
	jr $ra

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
# $t8 btw

	push $s0
	push $s1
	push $s2
	push $s3
	push $s4
	push $s5
	push $s6
	push $s7
	push $t8
	add $s6 $zero $a0
	add $s7 $zero $a1
	add $t8 $zero $a2
	add $s5 $zero $zero # bw = 0

fwrite_loop:
	slt $t0 $zero $t8	
	beq $t0 $zero fwrite_loopexit #btw > 0
	lw $t0 2($s6)	#fp->fptr
	andi $t1 $t0 255 #fptr % 256
	bne $t1 $zero fwrite_get  
	bne $t0 $zero fwrite_fptrmark #if fptr == 0?
	lw $s0 6($s6)	#clst = fp->sclust
	bne $s0 $zero fwrite_fptrmarkend
	# clst = create_chain(fp->fs, 0)
	addi $a0 $zero 0
	push $ra
	jal create_chain
	pop $ra
	mov $s0 $v0
	beq $zero $zero fwrite_fptrmarkend
fwrite_fptrmark:
	# clst = create_chain(fp->fs, fp->clust);
	lw $a0 8($s6)
	push $ra
	jal create_chain
	pop $ra
	mov $s0 $v0

fwrite_fptrmarkend:
	sw $s1 8($s6)	# fp->clust = clst
	lw $t0 6($s6)	# fp->sclust
	bne $t0 $zero 1 # if sclust == 0
	sw $s0 6($s6)	# fp->sclust = clst
	lw $t2 0($s6)	# fp->flag
	andi $t3 $t2 0x40 # fp->flag & FA__DIRTY
	beq $t3 $zero fwrite_dirtyend 
	# disk_write(fp->win,dsect)
	addi $a0 $s6 16
	lw $a1 10($s6)	
	push $ra
	jal disk_write
	pop $ra
	andi $t2 $t2 -41 #flag &=~FA__DIRTY
	sw $t2 0($s6)	# fp->flag
fwrite_dirtyend:
	# sect = clust2sect(fp->clust)
	lw $a0 6($s6)
	push $ra
	jal clust2sect
	pop $ra
	mov $s1 $v0
	srl $s3 $t8 8			# cc = btw / 256
	beq $s3 $zero fwrite_cc # if cc
	addi $s3 $zero 1   		# cc = 1
	# disk_write(buff,sect)

	mov $a0 $s7
	mov $a1 $s1
	push $ra
	jal disk_write
	pop $ra
	sll $s2 $s3 8 # wcnt = SS * cc
	beq $zero $zero fwrite_loopend
fwrite_cc:
	lw $t0 10($s6) #dsect
	beq $t0 $s0 fwrite_dsect # if dsect != sect
	# disk_read(fp->buf,sect)
	addi $a0 $s6 16
	mov $a1 $s1
	# addi $a2 $zero 1
	push $ra
	jal disk_read
	pop $ra
fwrite_dsect:
	sw $s1 10($s6) # fp->dsect = sect

fwrite_get:
	lw $t2 2($s6) # fp-> fptr
	andi $t2 $t2 255 # fptr % SS
	addi $s2 $t2 -256
	sub $s2 $zero $s2 # wcnt = SS - fptr%SS
	slt $t0 $t8 $s2 # if t8 < s2 wcnt > btw
	beq $t0 $zero 1
	add $s2 $zero $t8
	# mem_cpy(fp->buf + fptr % SS,buff,wcnt)
	add $a1 $s7 $zero
	addi $t3 $s6 16
	add $a0 $t2 $t3
	add $a2 $zero $s2 
	push $ra
	jal mem_cpy
	pop $ra
	lw $t2 0($s6)	# fp->flag
	ori $t2 $t2 0x40
	sw $t2 0($s6)
fwrite_loopend:
	add $s7 $s7 $s2 	#wbuff += wcnt
	lw $t0 2($s6)		#fp->fptr += wcnt
	add $t0 $t0 $s2
	sw $t0 2($s6)
	add $s5 $s5 $s2		#bw += wcnt
	sub $t8 $t8 $s2 	#btw -= wcnt
	beq $zero $zero fwrite_loop
fwrite_loopexit:
	lw $t0 4($s6) # fsize
	lw $t1 2($s6) # fptr
	slt $t3 $t0 $t1 # fsize<fptr?
	beq $t3 $zero 1
	sw $t1 4($s6) # fp->fsize = fp->fptr
	# fp->flag |= FA__WRITTEN?!
	
	add $v0 $zero $s5  	#return bw
	pop $t8
	pop $s7
	pop $s6
	pop $s5
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	
	jr $ra

fclose:
# $a0 fp
	push $s6
	push $s2
	mov $s6 $a0
	addi $s2 $zero 128
	lw $t0 12($s2)	# dirbase
	# read dir sector
	mov $a0 $t0
	push $ra
	jal move_window
	pop $ra
	lw $t1 14($s6)   # offset
	addi $t0 $s2 18  # win
	add $t0 $t0 $t1
	lw $t1 6($s6)  # fp
	sb $t1 13($t0) # sclust
	lw $t1 4($s6)  # fp->fsize
	sw $t1 14($t0) # fsize
	addi $t2 $zero 1
	sw $t2 0($s2) #dirty

	lw $t2 0($s6)	# fp->flag
	andi $t3 $t2 0x40 # fp->flag & FA__DIRTY
	beq $t3 $zero fclose_dirtyend 
	# disk_write(buff,dsect)
	addi $a0 $s6 16
	lw $a1 10($s6)	
	push $ra
	jal disk_write
	pop $ra
	andi $t2 $t2 -41 #flag &=~FA__DIRTY
	sw $t2 0($s6)	# fp->flag
fclose_dirtyend:
pop $s2
	pop $s6
	jr $ra

dir_setidx:
# $a0 fil
# $s0 fil
# $a1 index
# $s1 index
# $s2 fs
	push $s0
	push $s1
	push $s2
	push $s3
	mov $s0 $a0
	mov $s1 $a1
	addi $s2 $zero 128
	lw $s3 12($s2)	# dirbase
	# read dir sector
	mov $a0 $s3
	push $ra
	jal move_window
	pop $ra
	sll $s1 $s1 4	# index *16
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
	
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	jr $ra


get_char:
	push $s0
	push $s1
get_char_loop:
	la $s0, keyboard_tail
	lw $s0, 0($s0)
	la $s1, keyboard_head
	lw $s1, 0($s1)
	beq $s0, $s1, get_char_nothing
	lb $v0, 0($s1)

	addi $s1, $s1, 1
	addi $s0, $zero, 128
	bne $s1, $s0, get_char_next
	addi $s1, $zero, 0x10
get_char_next:
	la $s0, keyboard_head
	sw $s1, 0($s0)
get_char_back:
	pop $s1
	pop $s0
	ret

get_char_nothing:
	#如果没有字符返回0xFF
	beq $zero $zero get_char_loop


#显示一个字符, 参数放在a0
print_char: 
	push $s0
	push $s1

	lui $s0, 0xA000
	sb $a0, 0($s0)
print_char_back:
	pop $s1
	pop $s0
	ret


print_string:
	push $s0
	push $s1

	lui $s0, 0xA000
print_string_again:
	lb $s1, 0($a0)
	beq $s1, $zero, print_string_back
	sb $s1, 0($s0)
	addi $a0, $a0, 1

	j print_string_again
print_string_back:
	pop $s1
	pop $s0
	ret


println_string:
	push $s0
	push $s1

	lui $s0, 0xA000
println_string_again:
	lb $s1, 0($a0)
	beq $s1, $zero, println_string_back
	sb $s1, 0($s0)
	addi $a0, $a0, 1

	j println_string_again
println_string_back:
	addi $s1 $zero 0xD
	sb $s1, 0($s0)
	pop $s1
	pop $s0
	ret











.orign 3600
.text
main:
#	j main
#	lui $t0 0xA000
#	addi $t1 $zero 0x41
#	sb $t1 0($t0)
#	lui $t0 0xA000
#	addi $t1 $zero 0x42
#	sb $t1 0($t0)
#	la $a0 f0_flag
#	addi $a0 $zero 4000
#	addi $a1 $zero 0x11F
#	addi $a0 $zero 4256
#	addi $a1 $zero 0x120
#	jal	disk_read
#	la $a0 overstr
#	jal print_string
	la $a0 f1_flag
	addi $a1 $zero 2
	jal dir_setidx
	la $a0 f1_flag
	addi $a1 $zero 4000
	addi $a2 $zero 3000
	jal fread
#	addi $a0 $zero 4000
#	addi $a1 $zero 0x11F
#	jal disk_read
#	addi $a0 $zero 4256
#	addi $a1 $zero 0x120
#	jal	disk_read
	la $a0 overstr
	jal println_string
	jal user
end:
	j end
.data
	overstr .asciiz "starting bash "


.orign 4000
.text
user:
j bash
.text
	bash:
		la $a0, prompt
		jal print_string
	bash_loop:
		la $s0, keyboard_head
		lw $s0, 0($s0)
		la $s1, keyboard_tail
		lw $s1, 0($s1)
		beq $s0, $s1, bash_loop

		addi $s2, $s1, -1
		lb $s2, 0($s2)
		addi $s3, $zero, 13
		bne $s3, $s2, bash_loop
	bash_exe:
		sb $zero, -1($s1)

		mov $a0, $s0
		jal get_cmd

		addi $t0, $zero, -1
		beq $v0, $t0, bash_error

	bash_dir:
		addi $t0, $zero, 3
		bne $v0, $t0, bash_read
		jal printdir

		j bash_end
	bash_read:
		addi $t0, $zero, 4
		bne $v0, $t0, bash_error
		la $a0 f1_flag
		addi $a1 $zero 1
		jal dir_setidx
		la $a0 f1_flag
		lui $a1  0xA000
		addi $a2 $zero 1000
		jal fread

		j bash_end
	bash_end:
		la $s0, keyboard_tail
		addi $s1 $zero 0x10
		sw $s1, 0($s0)
		la $a0 cmd_done
		jal print_string
		j bash

	bash_error:
		la $a0, error
		jal print_string
		j bash_end
.data
	prompt 	.asciiz	"ZPC:>"
	error 		.asciiz	"Not Found."
	para_error	.asciiz	"Parameters needed."
	cmd_done .asciiz "Command done."
.text
#解析命令, 字符串首地址放在a0, 解析后的结果放在v0 v1
get_cmd:
	push $s0
	push $s1
	push $s2
	push $s3
	push $s4

get_cmd_dir:
	#初始化v0 v1
	addi $v0, $zero, 3
	addi $v1, $zero, -1

	mov $s2, $a0
	la $s3, cmd_dir
get_cmd_dir_again:
	lb $s0, 0($s2)
	lb $s1, 0($s3)

	addi $s2, $s2, 1
	addi $s3, $s3, 1
	
	bne $s1, $zero, get_cmd_dir_check
	beq $s0, $zero, get_cmd_dir_end
	j get_cmd_dir_next
get_cmd_dir_check:
	sub $s4, $s0, $s1
	beq $s4, $zero, get_cmd_dir_again
	j get_cmd_dir_next
get_cmd_dir_next:
	j get_cmd_read
get_cmd_dir_end:
	j get_cmd_end

get_cmd_read:
	#初始化v0 v1
	addi $v0, $zero, 4
	addi $v1, $zero, -1

	mov $s2, $a0
	la $s3, cmd_read
get_cmd_read_again:
	lb $s0, 0($s2)
	lb $s1, 0($s3)

	addi $s2, $s2, 1
	addi $s3, $s3, 1
	
	bne $s1, $zero, get_cmd_read_check
	beq $s0, $zero, get_cmd_read_end
	j get_cmd_read_next
get_cmd_read_check:
	sub $s4, $s0, $s1
	beq $s4, $zero, get_cmd_read_again
	j get_cmd_read_next
get_cmd_read_next:
	j get_cmd_error
get_cmd_read_end:
	j get_cmd_end

get_cmd_error:
	addi $v0, $zero, -1
get_cmd_end:
	pop $s4
	pop $s3
	pop $s2
	pop $s1
	pop $s0
	ret
.data
	cmd_cat	.asciiz	"cat"
	cmd_dir .asciiz "dir"
	cmd_time	.asciiz	"time"
	cmd_read	.asciiz	"read"
