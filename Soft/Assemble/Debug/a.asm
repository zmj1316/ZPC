#如果是系统函数，jal前后必须保存ra寄存器的值，如果有必要的话a0-a3也需要保存


.orign 0
.text
	addi $sp, $zero, 6000
	j main

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
	#文件系统结构体
	fs_wflag .word 0x0
	fs_last_clust .word 0x0
	fs_free_clust .word 0x0
	fs_fatent .word 0x0
	fs_volbase .word 0x0
	fs_fatbase .word 0x0
	fs_dirbase .word 0x0
	fs_database .word 0x0
	fs_winsect .word 0x0
	fs_win .word 0x0
	#256 缓冲区

.orign 410
.data
	#文件结构体1
	f0_flag .word 0x0
	f0_fptr .word 0x0
	f0_fsize .word 0x0
	f0_sclust .word 0x0
	f0_clust .word 0x0
	f0_dsect .word 0x0
	f0_dir_sect .word 0x0
	f0_dir_ptr .word 0x0
	f0_buf .word 0x0
	#缓冲区

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
	#缓冲区

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
	time_counter .word 0 
	keyboard .addr  keyboard_int
	

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
	lw $s7, 0($s7)

	lui $s6, 0xA000

	addi $s5, $zero, 65
	sw $s5, 0($s6)

	sw $s7, 0($s6)

	addi $s5, $zero, 66
	sw $s5, 0($s6)

keyboard_end:
	pop $s4
	pop $s5
	pop $s6
	pop $s7
	j int_end


main:
	add $a0, $zero, $zero
	add $a0, $zero, $zero
	add $a0, $zero, $zero
	j main