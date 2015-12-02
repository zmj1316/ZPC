#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

#define MAX_LINE 1000
#define CO 2
typedef unsigned int word;
typedef unsigned short byte;

struct codeInf
{
	//记录真实的行号
	word realLine;
	string code[4];
};

class assembler
{
public:
	int segment;

	string buf;

	map<string, word> labelMap;
	map<word, word> addrMap;	//数组里的位置和真实汇编地址的对应表

	codeInf code[MAX_LINE];
	
	word codeLen;

	assembler()
	{
		segment = 0;
		codeLen = 0;
	}

	word translate(string reg)	//寄存器名, 转换为二进制数
	{
		if (reg == "$zero" || reg == "$0")
			return 0;
		else if (reg == "$at" || reg == "$1")
			return 1;
		else if (reg == "$v0" || reg == "$2")
			return 2;
		else if (reg == "$v1" || reg == "$3")
			return 3;
		else if (reg == "$a0" || reg == "$4")
			return 4;
		else if (reg == "$a1" || reg == "$5")
			return 5;
		else if (reg == "$a2" || reg == "$6")
			return 6;
		else if (reg == "$a3" || reg == "$7")
			return 7;
		else if (reg == "$t0" || reg == "$8")
			return 8;
		else if (reg == "$t1" || reg == "$9")
			return 9;
		else if (reg == "$t2" || reg == "$10")
			return 10;
		else if (reg == "$t3" || reg == "$11")
			return 11;
		else if (reg == "$t4" || reg == "$12")
			return 12;
		else if (reg == "$t5" || reg == "$13")
			return 13;
		else if (reg == "$t6" || reg == "$14")
			return 14;
		else if (reg == "$t7" || reg == "$15")
			return 15;
		else if (reg == "$s0" || reg == "$16")
			return 16;
		else if (reg == "$s1" || reg == "$17")
			return 17;
		else if (reg == "$s2" || reg == "$18")
			return 18;
		else if (reg == "$s3" || reg == "$19")
			return 19;
		else if (reg == "$s4" || reg == "$20")
			return 20;
		else if (reg == "$s5" || reg == "$21")
			return 21;
		else if (reg == "$s6" || reg == "$22")
			return 22;
		else if (reg == "$s7" || reg == "$23")
			return 23;
		else if (reg == "$t8" || reg == "$24")
			return 24;
		else if (reg == "$t9" || reg == "$25")
			return 25;
		else if (reg == "$k0" || reg == "$26")
			return 26;
		else if (reg == "$k1" || reg == "$27")
			return 27;
		else if (reg == "$gp" || reg == "$28")
			return 28;
		else if (reg == "$sp" || reg == "$29")
			return 29;
		else if (reg == "$fp" || reg == "$30")
			return 30;
		else if (reg == "$ra" || reg == "$31")
			return 31;
		else
		{
			cout << "reg " << reg << " can't be recognized." << endl;
			exit(2);
		}
	}

	word getAddr(string label)
	{
		if (labelMap.find(label) == labelMap.end())
		{
			cout << "label " << label << " don't exist." << endl;
			exit(1);
		}
		
		return labelMap[label];
	}

	word getNum(string num)
	{
		transform(num.begin(), num.end(), num.begin(), tolower);
		
		word res = 0;
		int index = 0;
		bool neg = false;
		word radix = 10;

		if (num[index] == '-')
		{ 
			index++;
			neg = true;
		}

		if (index + 1 < num.length() && num.substr(index, 2) == "0x")
		{
			index += 2;
			radix = 16;
		}

		while (index < num.length())
		{
			res = res * radix + ((num[index] <= '9' && num[index] >= '0') ? (num[index] - '0') : (num[index] - 'a' + 10));
			index++;
		}

		if (neg)
		{
			res = ~res + 1; 
		}

		return res;
		//return atoi(num.c_str());
		/*if(num.substr(0, 2) == "0x" || num.substr(1, 2) == "0x")
			return strtol(num.c_str(), NULL, 16);
		else
			return strtol(num.c_str(), NULL, 10);*/
	}
 
	bool scan_1()
	{
		word realLine = 0;
		char c;
		ifstream fin;
		fin.open("a.asm");


		while (!fin.eof())
		{
			realLine++;

			do
			{
				c = fin.peek();
				
				if (c != ' ' && c != '\t')
					break;

				fin.ignore();
			} while (1);

			if (c == EOF)
			{
				return 1;
			}
			else if (c == '\n')
			{
				fin.ignore();
			}
			else if (c == '#')	//注释
			{
				getline(fin, buf);
			}
			else if (c == '.')
			{
				getline(fin, buf);
				transform(buf.begin(), buf.end(), buf.begin(), tolower);

				if (buf.substr(0, 5) == ".data" || buf.substr(0, 5) == ".text")
				{
					code[codeLen].realLine = realLine;
					code[codeLen++].code[0] = buf;
				}
				else if (buf.substr(0, 6) == ".orign")
				{
					int i = 6, j = 6, m = 0;
					code[codeLen].realLine = realLine;
					code[codeLen].code[m++] = ".orign";

					while (buf[i])
					{
						while (buf[i] == ' ' || buf[i] == '\t')
						{
							i++;
							j++;
						}

						while (buf[j] != ' ' && buf[j] != ','
							&& buf[j] != '(' && buf[j] != ')'
							&& buf[j] != '\t' && buf[j] != 0 && buf[j])
							j++;

						if (j == i)	//未读取到字符
						{
							cout << "Around Line " << realLine << ": " << " there is a mistake." << endl;
							return 0;
						}

						code[codeLen].code[m++] = buf.substr(i, j - i);

						i = ++j;
						if (i > buf.length())
							break;

						while (buf[i] == ' ' || buf[i] == '\t')
						{
							i++;
							j++;
						}
					}

					codeLen++;
				}
				else
				{
					cout << "Around Line " << realLine << ": " << buf << " can't be recognized." << endl;
					return 0;
				}
			}
			else if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || c == '_')
			{
				fin >> buf;
				transform(buf.begin(), buf.end(), buf.begin(), tolower);

				int i = 0, j = 0, m = 0;	//分割指令用的下标

				if (buf[buf.length() - 1] == ':')	//是标号
				{
					if (labelMap.find(buf.substr(0, buf.length() - 1)) == labelMap.end())
					{
						labelMap[buf.substr(0, buf.length() - 1)] = codeLen;
					}
					else
					{
						cout << "Label conflicts at " << realLine << endl;
						return 0;
					}

					realLine--; //去除多计算的一行

					while (1) //将标号之后到下一条指令前的空白和回车屏蔽
					{
						c = fin.peek();
						if (c == '\n')
						{
							realLine++;
							fin.ignore();
						}
						else if (c == ' ' || c == '\t')
						{
							fin.ignore();
						}
						else
						{
							break;
						}
					}
				}
				else
				{
					code[codeLen].code[m++] = buf;

					getline(fin, buf);	//处理真指令或者其他

					while (buf[i])
					{
						while (buf[i] == ' ' || buf[i] == '\t')
						{
							i++;
							j++;
						}

						while (buf[j] != ' ' && buf[j] != ','
							&& buf[j] != '(' && buf[j] != ')'
							&& buf[j] != '\t' && buf[j] != 0 && buf[j])
							j++;

						if (j == i)	//未读取到字符
						{
							cout << "Around Line " << realLine << ": " << " there is a mistake." << endl;
							return 0;
						}

						code[codeLen].code[m++] = buf.substr(i, j - i);

						i = ++j;
						if (i > buf.length())
							break;

						while (buf[i] == ' ' || buf[i] == '\t')
						{
							i++;
							j++;
						}
					}

					//code[codeLen].codeLine = codeLen;
					code[codeLen].realLine = realLine;
					codeLen++;
				}
			}
			else	//非正常字符
			{
				cout << "Around Line " << realLine << ": " << " there is a mistake." << endl;
				return 0;
			}
		}

		fin.close();
		return 1;
	}

	bool scan_2()
	{
		segment = 0;

		word line = 0;
		word address = 0;

		while (line < codeLen)
		{
			addrMap[line] = address;

			if (code[line].code[0] == ".data")
			{
				segment = 1;
			}
			else if (code[line].code[0] == ".text")
			{
				segment = 2;
			}
			else if (code[line].code[0] == ".orign")
			{
				segment = 0;
				address = getNum(code[line].code[1]);
			}
			else if (segment == 1)	//data
			{
				if (labelMap.find(code[line].code[0]) == labelMap.end())
				{
					labelMap[code[line].code[0]] = line;
				}
				else
				{
					cout << "label conflicts at " << code[line].realLine << endl;
					return 0;
				}

				if (code[line].code[1] == ".asciiz")
				{
					if (code[line].code[2][0] != '\"' || code[line].code[2][code[line].code[2].length() - 1] != '\"')
					{
						cout << "Around Line " << code[line].realLine << ": " << " there is a mistake." << endl;
						return 0;
					}
					
					if ((code[line].code[2].length() - 2) % 2 == 0)
						address += code[line].code[2].length();
					else
						address += code[line].code[2].length() - 1;
				}
				else if (code[line].code[1] == ".word")
				{
					address += CO;
				}
				else
				{
					cout << "Around Line " << code[line].realLine << ": " << " there is a mistake." << endl;
					return 0;
				}
			}
			else if (segment == 2)	//text
			{
				if (code[line].code[0] == "nop") //各种伪指令
				{
					address += CO;
				}
				else if (code[line].code[0] == "ret")
				{
					address += CO;
				}
				else if (code[line].code[0] == "eret")
				{
					address += CO;
				}
				else if (code[line].code[0] == "la")
				{
					address += 2 * CO;
				}
				else if (code[line].code[0] == "push")
				{
					address += 2 * CO;
				}
				else if (code[line].code[0] == "pop")
				{
					address += 2 * CO;
				}
				else //普通指令
				{
					address += CO;
				}
			}
			else //未注明段类型
			{
				cout << "There is no segment definatiuon at " << code[line].realLine << endl;
				return 0;
			}
			
			line++;
		}

		map<string, word>::iterator it;	//将虚拟地址转换为真实地址
		for (it = labelMap.begin(); it != labelMap.end(); it++)
		{
			it->second = addrMap[it->second];
		}

		return 1;
	}

	void output(ofstream& fout, word oneWord)
	{
		fout << setw(8) << oneWord << endl;
	}
	
	bool assemble()
	{
		segment = 0;
		ofstream fout;
		fout << hex << uppercase << setfill('0');
		fout.open("a.out");

		word line = 0;
		word data, ir;
		word addr;
		int im;

		while (line < codeLen)
		{
			if (code[line].code[0] == ".data")
			{
				segment = 1;
			}
			else if (code[line].code[0] == ".text")
			{
				segment = 2;
			}
			else if (code[line].code[0] == ".orign")
			{
				word setAddr = addrMap[line + 1];
				word addr = addrMap[line];
				
				if (addr > setAddr)
				{
					cout << "Around Line " << code[line].realLine << ": " << " there is a mistake." << endl;
					return 0;
				}

				addr += CO;
				while (addr <= setAddr)
				{
					output(fout, 0);
					addr += CO;
				}
			}
			else if (segment == 1)	//data
			{
				if (code[line].code[1] == ".asciiz")
				{
					int i;
					for (i = 1; i < code[line].code[2].length() - 1; i = i + 2)
					{
						if(i == code[line].code[2].length() - 2)
						{
							data = code[line].code[2][i];
							data <<= 16;
						}
						else
						{
							data = code[line].code[2][i];
							data = (data << 16) + code[line].code[2][i + 1];
						}
						output(fout, data);
					}
					if(i == code[line].code[2].length() - 1)
						output(fout, 0);
				}
				else if (code[line].code[1] == ".word")
				{
					data = getNum(code[line].code[2].c_str());
					output(fout, data);
				}
				else
				{
					cout << "Around Line " << code[line].realLine << ": " << " there is a mistake." << endl;
					return 0;
				}
			}
			else if(segment == 2)  //text
			{
				if (code[line].code[0] == "nop") //各种伪指令
				{
					output(fout, 0);
				}
				else if (code[line].code[0] == "la")	//lui addi  lw
				{
					im = getAddr(code[line].code[2]) >> 14;
					ir = (translate(code[line].code[1]) << 16) | (im & 0xffff) | (15 << 26);
					output(fout, ir);

					im = getAddr(code[line].code[2]);
					ir = (translate(code[line].code[1]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (8 << 26);
					output(fout, ir);
				}
				/*else if (code[line].code[0] == "back")	//lui addi sw
				{
					im = getNum(code[line].code[2]) >> 16;
					ir = (translate(code[line].code[1]) << 16) | (im & 0xffff) | (15 << 26);
					output(fout, ir);

					im = getNum(code[line].code[2]);
					ir = (translate(code[line].code[1]) << 16) | (im & 0xffff) | (8 << 26);
					output(fout, ir);

					ir = (translate(code[line].code[1]) << 21) | (translate(code[line].code[1]) << 16) | (43 << 26);
					output(fout, ir);
				}*/
				else if (code[line].code[0] == "ret")
				{
					ir = (31 << 21) | 8;
					output(fout, ir);
				}
				else if (code[line].code[0] == "eret")
				{
					ir = (16 << 26) | (16 << 21) | 24;
					output(fout, ir);
				}
				else if (code[line].code[0] == "push")
				{
					ir = (29 << 21) | (29 << 16) | 0xfffe | (8 << 26);
					output(fout, ir);

					ir = (29 << 21) | (translate(code[line].code[1]) << 16) | (43 << 26);
					output(fout, ir);
				}
				else if (code[line].code[0] == "pop")
				{
					ir = (29 << 21) | (translate(code[line].code[1]) << 16) | (35 << 26);
					output(fout, ir);

					ir = (29 << 21) | (29 << 16) | 2 | (8 << 26);
					output(fout, ir);					
				}
				else //普通指令
				{
					if (code[line].code[0] == "add")	//R类型
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 32;
					}
					else if (code[line].code[0] == "addu")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 33;
					}
					else if (code[line].code[0] == "sub")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 34;
					}
					else if (code[line].code[0] == "subu")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 35;
					}
					else if (code[line].code[0] == "slt")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 42;
					}
					else if (code[line].code[0] == "sltu")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 43;
					}
					else if (code[line].code[0] == "and")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 36;
					}
					else if (code[line].code[0] == "or")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 37;
					}
					else if (code[line].code[0] == "nor")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 39;
					}
					else if (code[line].code[0] == "sll")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 0;
					}
					else if (code[line].code[0] == "srl")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 2;
					}
					else if (code[line].code[0] == "xor")
					{
						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 38;
					}
					else if (code[line].code[0] == "jr")
					{
						ir = (translate(code[line].code[1]) << 21) | 8;
					}


					else if (code[line].code[0] == "mfc0")	//R类型
					{
						im = getNum(code[line].code[2]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[1]) << 16) | ((im & 0xffff) << 11) | (16 << 26);
					}
					else if (code[line].code[0] == "mtc0")	//R类型
					{
						im = getNum(code[line].code[2]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[1]) << 16) | ((im & 0xffff) << 11) | (16 << 26) | (4 << 21);
					}
					else if (code[line].code[0] == "addi")	//i类型
					{
						im = getNum(code[line].code[3]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (8 << 26);
					}
					else if (code[line].code[0] == "andi")	
					{
						im = getNum(code[line].code[3]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (12 << 26);
					}
					else if (code[line].code[0] == "ori")
					{
						im = getNum(code[line].code[3]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (13 << 26);
					}
					else if (code[line].code[0] == "xori")
					{
						im = getNum(code[line].code[3]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (14 << 26);
					}
					else if (code[line].code[0] == "slti")
					{
						im = getNum(code[line].code[3]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (10 << 26);
					}
					else if (code[line].code[0] == "sltiu")
					{
						im = getNum(code[line].code[3]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (11 << 26);
					}
					else if (code[line].code[0] == "lui")
					{
						im = getNum(code[line].code[2]);

						ir = (translate(code[line].code[1]) << 16) | (im & 0xffff) | (15 << 26);
					}
					else if (code[line].code[0] == "beq")
					{
						if (labelMap.find(code[line].code[3]) != labelMap.end())
							im = (int)(labelMap[code[line].code[3]] - 1 - addrMap[line]);
						else
							im = getNum(code[line].code[3]);

						/*if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}*/

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | ((im & 0xffff) / CO) | (4 << 26);
					}
					else if (code[line].code[0] == "bne")
					{
						if (labelMap.find(code[line].code[3]) != labelMap.end())
							im = (int)(labelMap[code[line].code[3]] - 1 - addrMap[line]);
						else
							im = getNum(code[line].code[3]);

						/*if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}*/

						ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | ((im & 0xffff) / CO) | (5 << 26);
					}
					else if (code[line].code[0] == "sw")
					{
						im = getNum(code[line].code[2]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[3]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (43 << 26);
					}
					else if (code[line].code[0] == "sb")
					{
						im = getNum(code[line].code[2]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[3]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (40 << 26);
					}
					else if (code[line].code[0] == "lw")	
					{
						im = getNum(code[line].code[2]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[3]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (35 << 26);
					}
					else if (code[line].code[0] == "lb")
					{
						im = getNum(code[line].code[2]);
						if (im > 0x7fff || im < -0x8000)
						{
							cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
							return 0;
						}

						ir = (translate(code[line].code[3]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (32 << 26);
					}
					

					else if (code[line].code[0] == "j")	//j类型
					{
						//if (labelMap.find(code[line].code[1]) != labelMap.end())
						addr = getAddr(code[line].code[1]);

						if ((addr >> 26) != 0)
						{
							cout << "Around Line " << code[line].realLine << ": " << " addr is so large." << endl;
							return 0;
						}
						else
						{
							ir = (2 << 26) | (addr / CO);
						}
					}
					else if (code[line].code[0] == "jal")	//
					{
						if (labelMap.find(code[line].code[1]) != labelMap.end())
							addr = labelMap[code[line].code[1]];
						else
						{
							cout << "Around Line " << code[line].realLine << ": " << " label doesn't exist." << endl;
							return 0;
						}

						if ((addr >> 26) != 0)
						{
							cout << "Around Line " << code[line].realLine << ": " << " addr is so large." << endl;
							return 0;
						}
						else
						{
							ir = (3 << 26) | (addr / CO);
						}
					}

					else
					{
						cout << "Around Line " << code[line].realLine << ": " << " there is a mistake." << endl;
						return 0;
					}

					output(fout, ir);
				}
			}
			else //段未定义
			{
				cout << "Around Line " << code[line].realLine << ": " << " segment not be defined." << endl;
				return 0;
			}

			line++;
		}

		return 1;
	}
};

int main()
{
	assembler a;

	if (!a.scan_1())
		cout << "First scan failed." << endl;
	else if (!a.scan_2())
		cout << "Second scan failed." << endl;
	else if (!a.assemble())
		cout << "Assemble failed." << endl;
	else
		cout << "Complished" << endl;

	return 0;
}
