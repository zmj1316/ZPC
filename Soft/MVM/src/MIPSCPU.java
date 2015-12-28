import javax.swing.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.*;

public class MIPSCPU extends JPanel implements Runnable,KeyListener,MouseListener{
	private static final long serialVersionUID = 1L;
	private final int PCstart = 0;// program loading address
	private final int INTaddr = 1036;// interrupt vector list

	/* CPU */
	private MMU memory = new MMU();
	private int Reg[] = new int[32];
	private int cReg[] = new int[32];// 14:EPC;13:cause;12:STATUS
	private int stage = 0;
	private int Instruction = 0;
	private int PC = 0;
	private int opcode = 0, rs = 0, rt = 0, rd = 0, shamt = 0, func = 0, imme = 0, label = 0;// wire
																								// to
																								// Instruction
	private int immeSignEx = 0, immeUnsignEx = 0;// wire to imme
	public int addrBUS = 0;
	public int dataBUS;
	/* CPU */

	/* register */
	private int regAddrIn = 0;
	private int regA = 0, regB = 0;
	/* register */

	/* alu */
	private int aluA = 0, aluB = 0;
	private int aluRes = 0;
	/* alu */

	/* memory */
	private int memAddr;
	private int memIn;
	private int memOut;
	/* memory */

	/* interrupt */
	public boolean INTin = false;
	public boolean INTable = true;
	public boolean INT = false;
	public int INTnum = 0;
	public int Syscallno = 0;
	/* interrupt */

	/* control */
	private byte BYTE = 0;
	private byte RTYPE = 0;
	private byte ALUSOURCEA = 0;
	private byte ALUSOURCEB = 0;
	private byte REGDST = 0;
	private byte MEMTOREG = 0;
	private byte REGWRITE = 0;
	private byte MEMREAD = 0;
	private byte MEMWRITE = 0;
	private byte JUMPCOND = 0;
	private byte JUMP = 0;
	// wire to opcode
	/* control */

	public MIPSCPU() {
		super();
		setFocusable(true);
//		memory.memWriteWord(0, 0x20090040);// addi $t1 $zero -1
//		memory.memWriteWord(2, 0x200B0000);// addi $t3 $zero 0
//		memory.memWriteWord(4, 0x200C005A);// addi $t4 $zero 26+64
//		memory.memWriteWord(6, 0x3C0AA000);// lui $t2,A000
//		memory.memWriteWord(8, 0x21290001);// addi $t1 $t1 1
//		memory.memWriteWord(10, 0xAD490000);// sw $t2 $t1 0
//		memory.memWriteWord(12, 0x216B0001);// addi $t3 $t3 1
//		memory.memWriteWord(14, 0x112C0001);// beq $t1 $t4 1
//		memory.memWriteWord(16, 0x1000FFFB);// beq $zero $zero -5
//		memory.memWriteWord(18, 0x1000FFFF);// beq $zero $zero -1
//
//		memory.memWriteWord(256, 0x21290001);// addi $t1 $t1 1
//		memory.memWriteWord(258, 0x42000000);// eret
//		memory.memWriteWord(260, 0x1000FFFF);// beq $zero $zero -1
//		memory.memWriteWord(18, 0x1000FFFF);// beq $zero $zero -1
//		memory.memWriteWord(18, 0x1000FFFF);// beq $zero $zero -1
//		memory.memWriteWord(18, 0x1000FFFF);// beq $zero $zero -1
//		memory.memWriteWord(18, 0x1000FFFF);// beq $zero $zero -1
		PC = PCstart;
		for (int i = 0; i < 32; i++)
			Reg[i] = i;
		for (int i = 0; i < 32; i++)
			cReg[i] = 0;
		this.addKeyListener(this);
		this.addMouseListener(this);
	}

	private void setInstruction() {
		opcode = Instruction >> 26 & 0x3F;
		rs = Instruction >> 21 & 0x1F;
		rt = Instruction >> 16 & 0x1F;
		rd = Instruction >> 11 & 0x1F;
		shamt = Instruction >> 6 & 0x1F;
		func = Instruction & 0x3F;
		imme = Instruction & 0xFFFF;
		label = Instruction & 0x3FFFFFF;
		if ((imme >> 15 & 1) == 1)
			immeSignEx = imme | 0xFFFF0000;
		else
			immeSignEx = imme;
		immeUnsignEx = imme & 0xFFFF;
		setControl();
	}

	private void setControl() {
		switch (opcode) {
		case 0x00:// R-type
			BYTE = 0;
			RTYPE = 1;
			ALUSOURCEA = 1;
			ALUSOURCEB = 0;
			REGDST = 1;
			MEMTOREG = 0;
			REGWRITE = 1;
			MEMREAD = 0;
			MEMWRITE = 0;
			JUMPCOND = 0;
			JUMP = 0;
			break;
		case 0x02:// j
			BYTE = 0;
			RTYPE = 0;
			ALUSOURCEA = 0;
			ALUSOURCEB = 3;
			REGDST = 0;
			MEMTOREG = 0;
			REGWRITE = 0;
			MEMREAD = 0;
			MEMWRITE = 0;
			JUMPCOND = 0;
			JUMP = 1;
			break;
		case 0x03:// jal
			BYTE = 0;
			RTYPE = 0;
			ALUSOURCEA = 0;
			ALUSOURCEB = 3;
			REGDST = 2;
			MEMTOREG = 0;
			REGWRITE = 1;
			MEMREAD = 0;
			MEMWRITE = 0;
			JUMPCOND = 0;
			JUMP = 1;
			break;
		case 0x04:
		case 0x05:
			BYTE = 0;
			RTYPE = 0;
			ALUSOURCEA = 0;
			ALUSOURCEB = 3;
			REGDST = 0;
			MEMTOREG = 0;
			REGWRITE = 0;
			MEMREAD = 0;
			MEMWRITE = 0;
			JUMPCOND = 1;
			JUMP = 0;
			break;
		case 0x08:// I-type
		case 0x09:
		case 0x0A:
		case 0x0B:
		case 0x0C:
		case 0x0D:
		case 0x0E:
		case 0x0F:
			BYTE = 0;
			RTYPE = 0;
			ALUSOURCEA = 1;
			ALUSOURCEB = 2;
			REGDST = 0;
			MEMTOREG = 0;
			REGWRITE = 1;
			MEMREAD = 0;
			MEMWRITE = 0;
			JUMPCOND = 0;
			JUMP = 0;
			break;
		case 0x10:
			BYTE = 0;
			RTYPE = 0;
			ALUSOURCEA = 1;
			ALUSOURCEB = 2;
			REGDST = 0;
			MEMTOREG = 0;
			if(rs==0x00)REGWRITE = 1;
			else REGWRITE=0;
			MEMREAD = 0;
			MEMWRITE = 0;
			JUMPCOND = 0;
			JUMP = 0;
			break;
		case 0x20:// lb
			BYTE = 1;
			RTYPE = 0;
			ALUSOURCEA = 1;
			ALUSOURCEB = 2;
			REGDST = 0;
			MEMTOREG = 1;
			REGWRITE = 1;
			MEMREAD = 1;
			MEMWRITE = 0;
			JUMPCOND = 0;
			JUMP = 0;
			break;
		case 0x23:// lw
			BYTE = 0;
			RTYPE = 0;
			ALUSOURCEA = 1;
			ALUSOURCEB = 2;
			REGDST = 0;
			MEMTOREG = 1;
			REGWRITE = 1;
			MEMREAD = 1;
			MEMWRITE = 0;
			JUMPCOND = 0;
			JUMP = 0;
			break;
		case 0x28:// sb
			BYTE = 1;
			RTYPE = 0;
			ALUSOURCEA = 1;
			ALUSOURCEB = 2;
			REGDST = 0;
			MEMTOREG = 0;
			REGWRITE = 0;
			MEMREAD = 0;
			MEMWRITE = 1;
			JUMPCOND = 0;
			JUMP = 0;
			break;
		case 0x2B:// sw
			BYTE = 0;
			RTYPE = 0;
			ALUSOURCEA = 1;
			ALUSOURCEB = 2;
			REGDST = 0;
			MEMTOREG = 0;
			REGWRITE = 0;
			MEMREAD = 0;
			MEMWRITE = 1;
			JUMPCOND = 0;
			JUMP = 0;
			break;
		}
	}
	
	public void writeWord(int addr,int data){
		this.memory.memWriteWord(addr, data);
	}
	
	public void run() {
		OutputStream outputStream = null;
		try {
			outputStream = new FileOutputStream(new File("VM.log"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		while (true) {
			switch (stage) {
			case 0:
				addrBUS = 0;
				memAddr = PC;
				PC = PC + 2;
				if (PC > 5000)
					return;
				Instruction = memory.memReadWord(memAddr);
				try {
					outputStream.write(String.format("PC:%X\tINST:\t%s\n",PC-2,Reasm.translate(Instruction)).getBytes());
				} catch (Exception e) {
					e.printStackTrace();
				}
				synchronized (MIPSCPU.class) {
					if (INTin && (cReg[12] & 1) == 0) {
						try {
							outputStream.write(String.format("IR\n").getBytes());
						} catch (IOException e) {
							e.printStackTrace();
						}
						INT = true;
						INTin=false;
						cReg[13] = INTnum;
					}
					if (INT) {
						cReg[14] = PC - 2;
						PC = INTaddr;
						INT = false;
						cReg[12] = cReg[12] | 1;
						stage = 7;
					}
				}
				break;
			case 1:
				setInstruction();
				break;
			case 2:
				regA = Reg[rs];
				regB = Reg[rt];
				switch (REGDST) {
				case 0:
					regAddrIn = rt;
					break;
				case 1:
					regAddrIn = rd;
					break;
				case 2:
					regAddrIn = 0x1F;
					break;
				}
				break;
			case 3:
				switch (ALUSOURCEA) {
				case 0:
					aluA = PC;
					break;
				case 1:
					aluA = regA;
					break;
				}
				switch (ALUSOURCEB) {
				case 0:
					aluB = regB;
					break;
				case 1:
					aluB = 0x04;
					break;
				case 2:
					aluB = immeSignEx;
					break;
				case 3:
					aluB = (immeSignEx << 1);
					break;
				}

				if (RTYPE == 1) {
					switch (func) {
					case 0x20:// add
					case 0x21:// addu
						aluRes = aluA + aluB;
						break;
					case 0x22:// sub
					case 0x23:// subu
						aluRes = aluA - aluB;
						break;
					case 0x24:// and
						aluRes = aluA & aluB;
						break;
					case 0x25:// or
						aluRes = aluA | aluB;
						break;
					case 0x26:// xor
						aluRes = aluA ^ aluB;
						break;
					case 0x27:// nor
						aluRes = ~(aluA | aluB);
						break;
					case 0x2A:// slt
						aluRes = (aluA < aluB) ? 1 : 0;
						break;
					case 0x2B:// sltu
						aluRes = (((long) aluA) < ((long) aluB)) ? 1 : 0;
					case 0x00:// sll
						aluRes = aluB << shamt;
						break;
					case 0x02:// srl
						aluRes = aluB >> shamt;// srl
						break;
					case 0x03:// sra
						aluRes = aluB >> shamt;
						break;
					case 0x04:// sllv
						aluRes = aluB << aluA;
						break;
					case 0x06:// srlv
						aluRes = aluB >>> aluA;
						break;
					case 0x07:// srav
						aluRes = aluB >> aluA;
						break;
					case 0x08:// jr
						PC = Reg[rs];
						try {
							outputStream.write(String.format("Jr\t%X\n",PC).getBytes());
                            outputStream.write(String.format("$v0\t%X\n",Reg[2]).getBytes());
                        } catch (IOException e) {
							e.printStackTrace();
						}
						break;
					case 0x0C:// syscall
						synchronized (MIPSCPU.class) {
							try {
								outputStream.write(String.format("syscall\n").getBytes());
							} catch (IOException e) {
								e.printStackTrace();
							}
							cReg[13] = 8;
							INT = true;
							break;
						}
					}
				} else {
					aluRes = aluA + aluB;
					// I-type
					switch (opcode) {
					case 0x03:
						aluRes = PC;
						break;
					case 0x08:
						aluRes = aluA + aluB;
						break;
					case 0x09:
						aluRes = aluA + immeUnsignEx;
						break;
					case 0x0A:// slti
						aluRes = (aluA < immeUnsignEx) ? 1 : 0;
						break;
					case 0x0B:// sltiu
						aluRes = (((long) aluA & 0xFFFFFFFF) < ((long) immeUnsignEx & 0xFFFFFFFF)) ? 1 : 0;
						break;
					case 0x0C:// andi
						aluRes = aluA & immeUnsignEx;
						break;
					case 0x0D:// ori
						aluRes = aluA | immeUnsignEx;
						break;
					case 0x0E:// xori
						aluRes = aluA ^ immeUnsignEx;
						break;
					case 0x0F:// lui
						aluRes = immeUnsignEx << 16;
						break;
					}
				}
				// C0
				if (opcode == 16) {
					switch (rs) {
					case 0x00:// mfc
						aluRes = cReg[rd];
						break;
					case 0x04:// mtc
						cReg[rd] = regB;
						break;
					case 0x10:// eret
						PC = cReg[14];
						try {
							outputStream.write(String.format("Eret\t%X\n",PC).getBytes());
						} catch (IOException e) {
							e.printStackTrace();
						}
						cReg[12] = cReg[12] & 0xFFFFFFFE;
						break;
					}
				}
				if (JUMP == 1) {
					PC = (PC >> 27 << 27) | (label << 1);
					try {
                        outputStream.write(String.format("Jump\t%X\n",PC).getBytes());
                        outputStream.write(String.format("$a0\t%X\n",Reg[4]).getBytes());
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				if (JUMPCOND == 1) {
					try {
						outputStream.write(String.format("BJmp\t%X\t%X\n",regA,regB).getBytes());
					} catch (IOException e) {
						e.printStackTrace();
					}
					if (opcode == 0x04) {
						if (regA == regB)
							PC = aluRes;
					} else {
						if (regA != regB)
							PC = aluRes;
					}
					try {
						outputStream.write(String.format("BJmp\t%X\n",PC).getBytes());
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				break;
			case 4:
				if (MEMREAD == 1) {
					memAddr = aluRes;
					memIn = memory.memReadWord(memAddr);
					try {
						outputStream.write(String.format("LM\t%X>\t%X\n",memAddr,memIn).getBytes());
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				if (MEMWRITE == 1) {
					memAddr = aluRes;
					memOut = regB;

					if (BYTE == 1) {
						memory.memWriteByte(memAddr, (char) (memOut & 0xFFFF));
						addrBUS = memAddr;
						dataBUS = memOut & 0xFFFF;
						char c0 = (char) (dataBUS & 0xFFFF);
						if(memory.getSegment(memAddr)==0xA000){
//								System.out.print((char)(c0>>8));
								System.out.print((char)(c0&0xFF));
						}
						try {
							outputStream.write(String.format("SB\t%X\t%X\n",addrBUS,dataBUS).getBytes());
						} catch (IOException e) {
							e.printStackTrace();
						}
					} else {
						memory.memWriteWord(memAddr, memOut);
						addrBUS = memAddr;
						dataBUS = memOut;
						char c0 = (char) (dataBUS & 0xFFFF);
						if(memory.getSegment(memAddr)==0xA000){
							System.out.print((char)(c0>>8));
							System.out.print((char)(c0&0xFF));
						}
						try {
							outputStream.write(String.format("SW\t%X\t%X\n",addrBUS,dataBUS).getBytes());
						} catch (IOException e) {
							e.printStackTrace();
						}
					}
				}
				break;
			case 7:
				if (REGWRITE == 1) {
					if (MEMTOREG == 1) {
						if (BYTE == 1)
							Reg[regAddrIn] = memIn & 0xFFFF;
						else
							Reg[regAddrIn] = memIn;
					} else {
						Reg[regAddrIn] = aluRes;
					}
					Reg[0] = 0;
				}
				break;
			}
			stage = stage + 1;
			if (stage == 8) {
				stage = 0;
//				synchronized (MIPSCPU.class) {
//					try {
//						MIPSCPU.class.wait();
//					} catch (InterruptedException ie) {
//						ie.printStackTrace();
//					}
//				}
			}
		}
	}

	// private void instRun(){
	// opcode=Instruction>>26 & 0x3F;
	// rs=Instruction>>21 & 0x1F;
	// rt=Instruction>>16 & 0x1F;
	// rd=Instruction>>11 & 0x1F;
	// shamt=Instruction>>6 & 0x1F;
	// func=Instruction & 0x3F;
	// imme=Instruction & 0xFFFF;
	// label=Instruction & 0x3FFFFFF;
	// switch(opcode){
	// case 0x00://R type
	// switch(func){
	// case 0x20://add
	// Reg[rd]=Reg[rs]+Reg[rt];
	// break;
	// case 0x21://addu
	// Reg[rd]=Reg[rs]+Reg[rt];
	// break;
	// case 0x22://sub
	// Reg[rd]=Reg[rs]-Reg[rt];
	// break;
	// case 0x23://subu
	// Reg[rd]=Reg[rs]-Reg[rt];
	// break;
	// case 0x24://and
	// Reg[rd]=Reg[rs]&Reg[rt];
	// break;
	// case 0x25://or
	// Reg[rd]=Reg[rs]|Reg[rt];
	// break;
	// case 0x26://xor
	// Reg[rd]=Reg[rs]^Reg[rt];
	// break;
	// case 0x27://nor
	// Reg[rd]=~(Reg[rs]|Reg[rt]);
	// break;
	// case 0x2A://slt
	// Reg[rd]=(Reg[rs]<Reg[rt])? 1:0;
	// break;
	// case 0x2B://sltu
	// Reg[rd]=(Reg[rs]<Reg[rt])? 1:0;
	// break;
	// case 0x00://sll
	// Reg[rd]=Reg[rt]<<shamt;
	// break;
	// case 0x02://srl
	// Reg[rd]=Reg[rt]>>>shamt;
	// break;
	// case 0x03://sra
	// Reg[rd]=Reg[rt]>>shamt;
	// break;
	// case 0x04://sllv
	// Reg[rd]=Reg[rt]<<Reg[rs];
	// break;
	// case 0x06://srlv
	// Reg[rd]=Reg[rt]>>>Reg[rs];
	// break;
	// case 0x07://srav
	// Reg[rd]=Reg[rt]>>Reg[rs];
	// break;
	// case 0x08://jr
	// PC=Reg[rs];
	// break;
	// case 0x0C://syscall
	// INT=true;
	// INTnum=4;
	// Syscallno=Reg[2];
	// break;
	// }
	// break;
	// case 0x02://j
	// PC=PC & 0xF0000000 | (label << 2);
	// break;
	// case 0x03://jal
	// Reg[31]=PC;
	// PC=PC & 0xF0000000 | (label << 2);
	// break;
	// case 0x04://beq
	// if(Reg[rs]==Reg[rt]) PC+=imme<<2;
	// break;
	// case 0x05://bne
	// if(Reg[rs]!=Reg[rt]) PC+=imme<<2;
	// break;
	// case 0x08://addi
	// if(imme>>15==1) imme=imme|0xFFFF0000;
	// Reg[rt]=Reg[rs]+imme;
	// break;
	// case 0x09://addiu
	// Reg[rt]=Reg[rs]+imme;
	// break;
	// case 0x0A://slti
	// if(imme>>15==1) imme=imme|0xFFFF0000;
	// Reg[rt]=(Reg[rs]<imme)? 1:0;
	// break;
	// case 0x0B://sltiu
	// Reg[rt]=(Reg[rs]<imme)? 1:0;
	// break;
	// case 0x0C://andi
	// Reg[rt]=Reg[rs]&imme;
	// break;
	// case 0x0D://ori
	// Reg[rt]=Reg[rs]|imme;
	// break;
	// case 0x0E://xori
	// Reg[rt]=Reg[rs]^imme;
	// break;
	// case 0x0F://lui
	// Reg[rt]=imme<<16;
	// break;
	// case 0x23://lw
	// Reg[rt]=memory.memReadWord(Reg[rs]+imme);
	// break;
	// case 0x2B://sw
	// memory.memWriteWord(Reg[rs]+imme, Reg[rt]);
	// break;
	// case 0x10://CP0
	// switch(rs){
	// case 0x00://mfc0
	// Reg[rt]=cReg[14];
	// break;
	// case 0x04://mtc0
	// cReg[14]=Reg[rt];
	// break;
	// case 0x10://eret
	// PC=cReg[14];
	// cReg[12]=cReg[12]|1;
	// break;
	// }
	// break;
	// default:
	// break;
	// }
	// }
	public String getRegister(int index) {
		String s = "";
		int value = Reg[index];
		for (int j = 0; j < 8; j++) {
			char k = (char) ((value >> (28 - j * 4)) & 0xF);
			if (k >= 0 && k <= 9)
				k += 48;
			else
				k += 55;
			s = s + k;
		}
		return s;
	}

	public String getPC() {
		String s = "";
		int value = PC;
		for (int j = 0; j < 8; j++) {
			char k = (char) ((value >> (28 - j * 4)) & 0xF);
			if (k >= 0 && k <= 9)
				k += 48;
			else
				k += 55;
			s = s + k;
		}
		return s;
	}

	public void printPara() {
		System.out.print("Reg:");
		for (int i = 0; i < 32; i++)
			System.out.print(i + ":" + Reg[i] + " ");
		System.out.println();
	}
	
	public void keyPressed(KeyEvent e) {
		synchronized (MIPSCPU.class) {
			int key = e.getKeyCode();
			if (!INTin) {
				INTin = true;
				INTnum = 1;
				//System.out.println(key);
				memory.memWriteWord(0xB0000000, key);
			}
		}
	}

	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
	}

	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub

	}

	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
//		synchronized (MIPSCPU.class) {
//			MIPSCPU.class.notify();
//		}
	}

	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
}