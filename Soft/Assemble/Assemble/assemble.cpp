#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

#define MAX_LINE 1000
#define CO 2
typedef unsigned int word;
typedef unsigned short byte;

int initAddr = 0;

struct codeInf
{
    //录脟脗录脮忙脢碌碌脛脨脨潞脜
    word realLine;
    vector<string> code;
};

class assembler
{
public:
    int segment;

    string buf;

    map<string, word> labelMap;
    map<word, word> addrMap;	//脢媒脳茅脌茂碌脛脦禄脰脙潞脥脮忙脢碌禄茫卤脿碌脴脰路碌脛露脭脫娄卤铆

    codeInf code[MAX_LINE];

    word codeLen;

    assembler()
    {
        segment = 0;
        codeLen = 0;
    }

    word translate(string reg)	//录脛麓忙脝梅脙没, 脳陋禄禄脦陋露镁陆酶脰脝脢媒
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
        else if (reg == "$k0" || reg == "$rf26")
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
        int pos;
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
            else if (c == '#')	//脳垄脢脥
            {
                getline(fin, buf);
            }
            else if (c == '.')
            {
                getline(fin, buf);
                if ((pos = buf.find_first_of('#')) != string::npos)
                {
                    buf = buf.substr(0, pos);
                }

                transform(buf.begin(), buf.end(), buf.begin(), tolower);

                if (buf.length() >= 5 && (buf.substr(0, 5) == ".data" || buf.substr(0, 5) == ".text"))
                {
                    code[codeLen].realLine = realLine;
                    code[codeLen++].code.push_back(buf);
                }
                else if (buf.length() > 6 && buf.substr(0, 6) == ".orign")
                {
                    int i = 6, j = 6, m = 0;
                    code[codeLen].realLine = realLine;
                    code[codeLen].code.push_back(".orign");

                    if (buf[6] != ' ')
                    {
                        cout << "Around Line " << realLine << ": " << " unrecognized word." << endl;
                        return 0;
                    }
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

                        if (j == i)	//脦麓露脕脠隆碌陆脳脰路没
                        {
                            cout << "Around Line " << realLine << ": " << " there is a mistake." << endl;
                            return 0;
                        }

                        code[codeLen].code.push_back(buf.substr(i, j - i));

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
                if ((pos = buf.find_first_of('#')) != string::npos)
                {
                    buf = buf.substr(0, pos);
                    string a;
                    getline(fin, a);
                    realLine++;
                }

                transform(buf.begin(), buf.end(), buf.begin(), tolower);

                int i = 0, j = 0, m = 0;	//路脰赂卯脰赂脕卯脫脙碌脛脧脗卤锚

                if (buf[buf.length() - 1] == ':')	//脢脟卤锚潞脜
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

                    realLine--; //脠楼鲁媒露脿录脝脣茫碌脛脪禄脨脨

                    while (1) //陆芦卤锚潞脜脰庐潞贸碌陆脧脗脪禄脤玫脰赂脕卯脟掳碌脛驴脮掳脳潞脥禄脴鲁碌脝脕卤脦
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
                    code[codeLen].code.push_back(buf);

                    if (!getline(fin, buf))	//麓娄脌铆脮忙脰赂脕卯禄貌脮脽脝盲脣没
                    {
                        fin.close();
                        return 1;
                    }

                    if ((pos = buf.find_first_of('#')) != string::npos)
                    {
                        buf = buf.substr(0, pos);
                    }

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

                        if (j == i)	//脦麓露脕脠隆碌陆脳脰路没
                        {
                            cout << "Around Line " << realLine << ": " << " there is a mistake." << endl;
                            return 0;
                        }

                        code[codeLen].code.push_back(buf.substr(i, j - i));

                        if (code[codeLen].code.size() == 2 && code[codeLen].code[1] == ".asciiz")
                        {
                            i = j + 1;
                            if (i > buf.length())
                                break;

                            while (buf[i] == ' ' || buf[i] == '\t')
                            {
                                i++;
                            }

                            j = buf.length() - 1;
                            while (buf[j] == ' ' || buf[j] == '\t')
                            {
                                j--;
                            }

                            if (j > i)
                            {
                                code[codeLen].code.push_back(buf.substr(i, j - i + 1));
                                break;
                            }
                            else
                            {
                                cout << "Around Line " << realLine << ": " << " there is a mistake." << endl;
                                return 0;
                            }
                        }
                        else
                        {
                            i = ++j;
                            if (i > buf.length())
                                break;

                            while (buf[i] == ' ' || buf[i] == '\t')
                            {
                                i++;
                                j++;
                            }
                        }
                    }

                    //code[codeLen].codeLine = codeLen;
                    code[codeLen].realLine = realLine;
                    codeLen++;
                }
            }
            else	//路脟脮媒鲁拢脳脰路没
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
                if (code[line].code.size() != 2)
                {
                    cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                    return 0;
                }
                segment = 0;
                address = getNum(code[line].code[1]);
            }
            else if (segment == 1)	//data
            {
                if (code[line].code.size() < 3)
                {
                    cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                    return 0;
                }

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

                    if (code[line].code[2].length() % 2 == 0)
                        address += code[line].code[2].length();
                    else
                        address += code[line].code[2].length() - 1;
                }
                else if (code[line].code[1] == ".word")
                {
                    address += CO;
                }
                else if (code[line].code[1] == ".addr")
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
                if (code[line].code[0] == "nop") //赂梅脰脰脦卤脰赂脕卯
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
                else if (code[line].code[0] == "mov")
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
                else //脝脮脥篓脰赂脕卯
                {
                    address += CO;
                }
            }
            else //脦麓脳垄脙梅露脦脌脿脨脥
            {
                cout << "There is no segment definatiuon at " << code[line].realLine << endl;
                return 0;
            }

            line++;
        }

        map<string, word>::iterator it;	//陆芦脨茅脛芒碌脴脰路脳陋禄禄脦陋脮忙脢碌碌脴脰路
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
                        if (i == code[line].code[2].length() - 2)
                        {
                            data = (0xffff & code[line].code[2][i]);
                            //data <<= 16;
                        }
                        else
                        {
                            data = code[line].code[2][i + 1];
                            data = (data << 16) + code[line].code[2][i];
                        }
                        output(fout, data);
                    }
                    if (i == code[line].code[2].length() - 1)
                        output(fout, 0);
                }
                else if (code[line].code[1] == ".word")
                {
                    data = getNum(code[line].code[2].c_str());
                    output(fout, data);
                }
                else if (code[line].code[1] == ".addr")
                {
                    if (labelMap.find(code[line].code[2]) != labelMap.end())
                        data = (int)(labelMap[code[line].code[2]]);
                    else
                        cout << "Around Line " << code[line].realLine << ": " << " label doens't exist." << endl;

                    output(fout, data);
                }
                else
                {
                    cout << "Around Line " << code[line].realLine << ": " << " there is a mistake." << endl;
                    return 0;
                }
            }
            else if (segment == 2)  //text
            {
                if (code[line].code[0] == "nop") //赂梅脰脰脦卤脰赂脕卯
                {
                    if (code[line].code.size() != 1)
                    {
                        cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                        return 0;
                    }

                    output(fout, 0);
                }
                else if (code[line].code[0] == "la")	//lui addi  lw
                {
                    if (code[line].code.size() != 3)
                    {
                        cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                        return 0;
                    }

                    im = (getAddr(code[line].code[2]) + initAddr) >> 16;
                    ir = (translate(code[line].code[1]) << 16) | (im & 0xffff) | (15 << 26);
                    output(fout, ir);

                    im = (getAddr(code[line].code[2]) + initAddr);
                    ir = (translate(code[line].code[1]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (13 << 26);
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
                    if (code[line].code.size() != 1)
                    {
                        cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                        return 0;
                    }

                    ir = (31 << 21) | 8;
                    output(fout, ir);
                }
                else if (code[line].code[0] == "eret")
                {
                    if (code[line].code.size() != 1)
                    {
                        cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                        return 0;
                    }

                    ir = (16 << 26) | (16 << 21) | 24;
                    output(fout, ir);
                }
                else if (code[line].code[0] == "push")
                {
                    if (code[line].code.size() != 2)
                    {
                        cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                        return 0;
                    }

                    ir = (29 << 21) | (29 << 16) | 0xfffe | (8 << 26);
                    output(fout, ir);

                    ir = (29 << 21) | (translate(code[line].code[1]) << 16) | (43 << 26);
                    output(fout, ir);
                }
                else if (code[line].code[0] == "pop")
                {
                    if (code[line].code.size() != 2)
                    {
                        cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                        return 0;
                    }

                    ir = (29 << 21) | (translate(code[line].code[1]) << 16) | (35 << 26);
                    output(fout, ir);

                    ir = (29 << 21) | (29 << 16) | 2 | (8 << 26);
                    output(fout, ir);
                }
                else if (code[line].code[0] == "mov")
                {
                    if (code[line].code.size() != 3)
                    {
                        cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                        return 0;
                    }

                    ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 11) | 32;
                    output(fout, ir);
                }
                else //脝脮脥篓脰赂脕卯
                {
                    if (code[line].code[0] == "add")	//R脌脿脨脥
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 32;
                    }
                    else if (code[line].code[0] == "addu")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 33;
                    }
                    else if (code[line].code[0] == "sub")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 34;
                    }
                    else if (code[line].code[0] == "subu")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 35;
                    }
                    else if (code[line].code[0] == "slt")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 42;
                    }
                    else if (code[line].code[0] == "sltu")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 43;
                    }
                    else if (code[line].code[0] == "and")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 36;
                    }
                    else if (code[line].code[0] == "or")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 37;
                    }
                    else if (code[line].code[0] == "nor")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 39;
                    }
                    else if (code[line].code[0] == "sll")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        if ((getNum(code[line].code[3]) >> 5) != 0)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 16) | (getNum(code[line].code[3]) << 6) | (translate(code[line].code[1]) << 11) | 0;
                    }
                    else if (code[line].code[0] == "srl")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        if ((getNum(code[line].code[3]) >> 5) != 0)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 16) | (getNum(code[line].code[3]) << 6) | (translate(code[line].code[1]) << 11) | 2;
                    }
                    else if (code[line].code[0] == "xor")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[3]) << 16) | (translate(code[line].code[1]) << 11) | 38;
                    }
                    else if (code[line].code[0] == "jr")
                    {
                        if (code[line].code.size() != 2)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[1]) << 21) | 8;
                    }


                    else if (code[line].code[0] == "mfc0")	//R脌脿脨脥
                    {
                        if (code[line].code.size() != 3)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        im = getNum(code[line].code[2]);
                        if (im > 0x7fff || im < -0x8000)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[1]) << 16) | ((im & 0xffff) << 11) | (16 << 26);
                    }
                    else if (code[line].code[0] == "mtc0")	//R脌脿脨脥
                    {
                        if (code[line].code.size() != 3)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        im = getNum(code[line].code[2]);
                        if (im > 0x7fff || im < -0x8000)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[1]) << 16) | ((im & 0xffff) << 11) | (16 << 26) | (4 << 21);
                    }
                    else if (code[line].code[0] == "addi")	//i脌脿脨脥
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        im = getNum(code[line].code[3]);
                        if (im > 0x7fff || im < -0x8000)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (8 << 26);
                    }
                    else if (code[line].code[0] == "addiu")	//i脌脿脨脥
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        im = getNum(code[line].code[3]);
                        if (im > 0x7fff || im < -0x8000)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (9 << 26);
                    }
                    else if (code[line].code[0] == "andi")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 3)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        im = getNum(code[line].code[2]);

                        ir = (translate(code[line].code[1]) << 16) | (im & 0xffff) | (15 << 26);
                    }
                    else if (code[line].code[0] == "beq")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        if (labelMap.find(code[line].code[3]) != labelMap.end())
                            im = (int)(labelMap[code[line].code[3]] - 2 - addrMap[line]);
                        else
                            im = getNum(code[line].code[3]);

                        /*if (im > 0x7fff || im < -0x8000)
                        {
                        cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                        return 0;
                        }*/

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | ((im / CO) & 0xffff) | (4 << 26);
                    }
                    else if (code[line].code[0] == "bne")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        if (labelMap.find(code[line].code[3]) != labelMap.end())
                            im = (int)(labelMap[code[line].code[3]] - 2 - addrMap[line]);
                        else
                            im = getNum(code[line].code[3]);

                        /*if (im > 0x7fff || im < -0x8000)
                        {
                        cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                        return 0;
                        }*/

                        ir = (translate(code[line].code[2]) << 21) | (translate(code[line].code[1]) << 16) | ((im / CO) & 0xffff) | (5 << 26);
                    }
                    else if (code[line].code[0] == "sw")
                    {
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                        if (code[line].code.size() != 4)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        im = getNum(code[line].code[2]);
                        if (im > 0x7fff || im < -0x8000)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " im is so large." << endl;
                            return 0;
                        }

                        ir = (translate(code[line].code[3]) << 21) | (translate(code[line].code[1]) << 16) | (im & 0xffff) | (32 << 26);
                    }

                    else if (code[line].code[0] == "syscall")	//j脌脿脨脥
                    {
                        if (code[line].code.size() != 1)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        //if (labelMap.find(code[line].code[1]) != labelMap.end())

                        ir = 12;
                    }

                    else if (code[line].code[0] == "j")	//j脌脿脨脥
                    {
                        if (code[line].code.size() != 2)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

                        //if (labelMap.find(code[line].code[1]) != labelMap.end())

                        if (labelMap.find(code[line].code[1]) != labelMap.end())
                            addr = (int)(labelMap[code[line].code[1]]);
                        else
                            addr = getNum(code[line].code[1]);

                        if ((addr >> 26) != 0)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " addr is so large." << endl;
                            return 0;
                        }
                        else
                        {
                            ir = (2 << 26) | ((addr + initAddr) / CO);
                        }
                    }
                    else if (code[line].code[0] == "jal")	//
                    {
                        if (code[line].code.size() != 2)
                        {
                            cout << "Around Line " << code[line].realLine << ": " << " Parameters number wrong." << endl;
                            return 0;
                        }

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
                            ir = (3 << 26) | ((addr + initAddr) / CO);
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
            else //露脦脦麓露篓脪氓
            {
                cout << "Around Line " << code[line].realLine << ": " << " segment not be defined." << endl;
                return 0;
            }

            line++;
        }

        return 1;
    }
};

int main(int argc, char *argv[])
{
    assembler a;
    if (argc == 2)
    {
        cout << "User Program is being assembled." << endl;
        initAddr = a.getNum(argv[1]);
    }
    else if (argc == 1)
    {
        cout << "Kernel Program is being assembled." << endl;
    }
    else
    {
        cout << "Program parameters number is wrong." << endl;
        return 0;
    }

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
