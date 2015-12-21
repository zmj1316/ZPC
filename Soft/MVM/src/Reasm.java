
class NotHexException extends Exception{
	
}

class NotInstructionException extends Exception{
	
}

class InstructionLengthException extends Exception{
	
}

public class Reasm{
	private static int op, rs, rt, rd, func, sh, abs_addr, sign_addr, data, im;

	public static String translate(int ir) throws Exception
	{
		String res = "";
		decode(ir);

		if(ir == 0)
		{
			res = "nop";
		}
		else
		{
			switch(op){
				case 0:
					switch(func){
						case 32: res = "add\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 38: res = "xor\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 34: res = "sub\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 42: res = "slt\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 43: res = "sltu\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 36: res = "and\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 37: res = "or\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 39: res = "nor\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
						case 0: res = "sll\t" + intToReg(rd) + ", " + intToReg(rt) + ", " + sh; break;
						case 2: res = "srl\t" + intToReg(rd) + ", " + intToReg(rt) + ", " + sh; break;
						case 8: res = "jr\t" + intToReg(rs); break;
					} break;
				case 28: res = "mul\t" + intToReg(rd) + ", " + intToReg(rs) + ", " + intToReg(rt); break;
				case 16:
					switch(rs)
					{
						case 16: res = "eret";
						case 0: res = "mfc0\t" + intToReg(rt) + ", " + rd; break;
						case 4: res = "mtc0\t" + intToReg(rt) + ", " + rd; break;
					}
				case 17:
					switch(rs)
					{
						case 0: res = "mfc1\t" + intToReg(rt) + ", " + rd; break;
						case 4: res = "mtc1\t" + intToReg(rt) + ", " + rd; break;
					}
				case 2:	res = "j\t" + abs_addr; break;
				case 3:	res = "jal\t" + abs_addr; break;
				case 14: res = "xori\t" + intToReg(rt) + ", " + intToReg(rs) + ", " + data; break;
				case 4: res = "beq\t" + intToReg(rs) + ", " + intToReg(rt) + ", " + sign_addr; break;
				case 5: res = "bne\t" + intToReg(rs) + ", " + intToReg(rt) + ", " + sign_addr; break;
				case 13: res = "ori\t" + intToReg(rt) + ", " + intToReg(rs) + ", " + data; break;
				case 35: res = "lw\t" + intToReg(rt) + ", " + im + "(" + intToReg(rs) + ")"; break;
				case 43: res = "sw\t" + intToReg(rt) + ", " + im + "(" + intToReg(rs) + ")"; break;
				case 32: res = "lb\t" + intToReg(rt) + ", " + im + "(" + intToReg(rs) + ")"; break;
				case 40: res = "sb\t" + intToReg(rt) + ", " + im + "(" + intToReg(rs) + ")"; break;
				case 10: res = "slti\t" + intToReg(rt) + ", " + intToReg(rs) + ", " + im; break;
				case 11: res = "sltiu\t" + intToReg(rt) + ", " + intToReg(rs) + ", " + data; break;
				case 8: res = "addi\t" + intToReg(rt) + ", " + intToReg(rs) + ", " + im; break;
				case 12: res = "andi\t" + intToReg(rt) + ", " + intToReg(rs) + ", " + data; break;
				case 15: res = "lui\t" + intToReg(rt) + ", " + data; break;
//				default: throw new NotInstructionException();
				default:res = "Unrecognized instruction!";

			}
		}
		
		return res;
	}

	private static String intToReg(int r)
	{
		String reg = new String();

		if(r >= 8 && r <= 15) 
			reg = "$t" + (r - 8);
		else if(r >= 16 && r <= 23)
			reg = "$s" + (r - 16);
		else 
			switch(r & 31){
				case 0: reg = "$zero"; break;
				case 1:	reg = "$at"; break;
				case 2:	reg = "$v0"; break;
				case 3: reg = "$v1"; break;
				case 4: reg = "$a0"; break;
				case 5: reg = "$a1"; break;
				case 6: reg = "$a2"; break;
				case 7: reg = "$a3"; break;
				case 24: reg = "$t8"; break;
				case 25: reg = "$t9"; break;
				case 26: reg = "$k0"; break;
				case 27: reg = "$k1"; break;
				case 28: reg = "$gp"; break;
				case 29: reg = "$sp"; break;
				case 30: reg = "$fp"; break;
				case 31: reg = "$ra"; break;
			}

		return reg;
	}

	private static void decode(int ir)
	{
		op = ir >> 26;
		rs = (ir >> 21) & 31;	
		rt = (ir >> 16) & 31;	
		rd = (ir >> 11) & 31;	
		sh = (ir >> 6) & 31;
		func = ir & 63;
		data = ir & 0xffff;
		im = ((data >> 15) != 0) ? (data | 0xffff0000) : data;
		abs_addr = (ir & 0x3ffffff) << 1;
		sign_addr = im << 1;
	}

	public static int strToInt(String ir) throws Exception
	{
		int res = 0;

		if(ir.length() != 8)
		{
			throw new InstructionLengthException();
		}
		else
		{
			int i = 0;
			while(i < 8)
			{
				if(ir.charAt(i) <= '9' && ir.charAt(i) >= '0')
				{

				}
				else if(ir.charAt(i) <= 'z' && ir.charAt(i) >= 'a')
				{
					res += ir.charAt(i) - 'a';
				}
				else if(ir.charAt(i) <= 'Z' && ir.charAt(i) >= 'A')
				{
					res += ir.charAt(i) - 'A';
				}
				else
				{
					throw new NotHexException();
				}
			}
		}

		return res;
	}
	
	/*public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int ir = 0x3C10D000;
		System.out.println(translate(ir));
		ir = 0x20110041;
		System.out.println(translate(ir));
	}*/
}
