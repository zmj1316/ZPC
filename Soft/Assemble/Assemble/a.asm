#deinfe screen_size 1200
#define vga 40960(lui 40960) 实际上是0xA0000000
#define keyboard_data 45056(lui 45056) 实际上是0xB0000000
#define keyboard_begin 0x500
#define int_vector 0x40

#define keyboard_begin 0x300
#define keyboard_end 0x400

#汇编之前先把上面的值全部替换一遍


.orign 0	
.text
	#BIOS 自检以及初始化栈指针等操作
	addi $sp, $zero, 0x1000

	#跳转到主函数
	j main	

.data
#系统数据

	
	#键盘缓冲区指针
	keyboard_head .word 0x300
	keyboard_tail .word 0x300

	error .asciiz "commandnotfound"


#中断向量表
.orign 0x40
.data
	time_counter .word 0x80
	keyboard .word  0xB0



.orign 0x50
#中断处理入口
.text
int:	
	push $s5
	push $s6

	lui $s6, 0xA000
	addi $s5, $zero, 65
	sw $s5, 0($s6)

	#屏蔽中断
	addi $s5, $zero, 1
	mtc0 $s5, 12

	mfc0 $s5, 13
	add $s5, $s5, $s5
	addi $s5, $s5, 0x40
	lw $s5, 0($s5)
	jr $s5

int_end:
	#打开中断
	mtc0 $zero, 12

	lui $s6, 0xA000
	addi $s5, $zero, 66
	sw $s5, 0($s6)

	pop $s6
	pop $s5
	eret



#计时器中断
.orign 0x80
.text
time_int:
	j int_end




#键盘中断
.orign 0xB0
.text
keyboard_int:
	push $s7
	push $s6
	push $s5
	
	lui $s7, 0xB000
	#获得键盘输入的值
	lw $s7, 0($s7)
	lui $s6, 0xA000
	sw $s7, 0($s6)
	la $s6, keyboard_tail
	lw $s6, 0($s6)
	la $s5, keyboard_head
	lw $s5, 0($s5)
	sb $s7, 0($s6)
	
	addi $s6, $s6, 1
	#暂时保存$s6的值
	add $s7, $s6, $zero
	addi $s7, $zero, 0x400
	bne $s6, $s7, key_board_next1
	addi $s6, $zero, 0x300
keyboard_next1:
	bne $s6, $s5, keyboard_next2
	add $s6, $s7, $zero
keyboard_next2:
	la $s7, keyboard_tail
	sw $s6, 0($s7)

	pop	$s5
	pop $s6
	pop $s7
	j int_end



.orign 0x600
.text
main:
	j main