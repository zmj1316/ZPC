import ply.lex as lex
dodo = True




tokens=(
	"LABLEdef",
	"LABLEref",
	"REG",
	"DEC",
	"HEX",
	"OP",
	"TEXT",
	"DATA",
	"WORD",
	"BYTE",
	"SPACE",
	"ASCII",
	"STRING"
	)

t_ignore  = ' \t'
t_ignore_COMMENT = r';.*'

t_TEXT = '.text'




t_DATA = '.data'

def t_WORD(t):
	'.word'
	t.value = t.lexer.lineno
	t.lexer.lineno+=1
	return t 
def t_BYTE(t):
	'.byte'
	t.value = t.lexer.lineno
	t.lexer.lineno+=1
	return t
def t_SPACE(t):
	r'.space [0-9]+'
	t.value = t.lexer.lineno
	t.lexer.lineno+=((int(t.value[7:]) - 1)/4 + 1)
	return t

def t_ASCII(t):
	'.ascii'
	t.value = t.lexer.lineno
	return t

def t_STRING(t):
	r'\042.*\042'
	t.value = t.value[1:-1]
	t.lexer.lineno+=((len(t.value) - 1) / 4 + 1)
	return t


def t_newline(t):
    r'\n+'

LABLEdict={}

def t_LABLEdef(t):
	r'[A-Z][a-zA-Z0-9_]*\:'
	t.value = t.value[:-1]
	# print t.value,t.lexer.lineno
	if dodo:LABLEdict[t.value] = t.lexer.lineno - 1
	return t

def t_LABLEref(t):
	r'[A-Z][a-zA-Z0-9_]*'
	t.value = (t.value,t.lexer.lineno - 1)
	return t

REGdict = {}
REGdict['$zero'] = 0
REGdict['$at'] = 1
REGdict['$v0'] = 2
REGdict['$v1'] = 3
REGdict['$a0'] = 4
REGdict['$a1'] = 5
REGdict['$a2'] = 6
REGdict['$a3'] = 7
REGdict['$t0'] = 8
REGdict['$t1'] = 9
REGdict['$t2'] = 10
REGdict['$t3'] = 11
REGdict['$t4'] = 12
REGdict['$t5'] = 13
REGdict['$t6'] = 14
REGdict['$t7'] = 15
REGdict['$s0'] = 16
REGdict['$s1'] = 17
REGdict['$s2'] = 18
REGdict['$s3'] = 19
REGdict['$s4'] = 20
REGdict['$s5'] = 21
REGdict['$s6'] = 22
REGdict['$s7'] = 23
REGdict['$t8'] = 24
REGdict['$t9'] = 25
REGdict['$k0'] = 26
REGdict['$k1'] = 27
REGdict['$gp'] = 28
REGdict['$sp'] = 29
REGdict['$fp'] = 30
REGdict['$ra'] = 31

def t_REG(t):
	r'\$[a-z]+[0-9]*'
	t.value = REGdict[t.value]
	return t

def t_DEC(t):
	r'\b\-?[0-9]+\b'
	t.value = int(t.value)
	return t
def t_HEX(t):
	r'0x[0-9a-fA-F]+'
	t.value = int(t.value[2:],16)
	return t


OPdict = {
	
}
# R-type
OPdict['add'] = 0x20
OPdict['addu']= 0x21
OPdict['sub'] = 0x22
OPdict['subu'] = 0x23
OPdict['and'] = 0x24
OPdict['or'] = 0x25
OPdict['xor'] = 0x26
OPdict['nor'] = 0x27
OPdict['slt'] = 0x28
OPdict['sltu'] = 0x29

OPdict['srl'] = 0x2



OPdict['addi']= 0x20000000
OPdict['andi'] = 0x30000000

OPdict['lui'] = 0x3C000000
OPdict['lw']  = 0x8C000000
OPdict['sw']  = 0xAC000000
OPdict['beq'] = 0x10000000
OPdict['bne'] = 0x14000000
OPdict['slti'] = 0x24000000

OPdict["j"] = 0x08000000


REGdict = {}
REGdict['$zero'] = 0
REGdict['$at'] = 1
REGdict['$v0'] = 2
REGdict['$v1'] = 3
REGdict['$a0'] = 4
REGdict['$a1'] = 5
REGdict['$a2'] = 6
REGdict['$a3'] = 7
REGdict['$t0'] = 8
REGdict['$t1'] = 9
REGdict['$t2'] = 10
REGdict['$t3'] = 11
REGdict['$t4'] = 12
REGdict['$t5'] = 13
REGdict['$t6'] = 14
REGdict['$t7'] = 15
REGdict['$s0'] = 16
REGdict['$s1'] = 17
REGdict['$s2'] = 18
REGdict['$s3'] = 19
REGdict['$s4'] = 20
REGdict['$s5'] = 21
REGdict['$s6'] = 22
REGdict['$s7'] = 23
REGdict['$t8'] = 24
REGdict['$t9'] = 25
REGdict['$k0'] = 26
REGdict['$k1'] = 27
REGdict['$gp'] = 28
REGdict['$sp'] = 29
REGdict['$fp'] = 30
REGdict['$ra'] = 31

def t_OP(t):
	r'\b[a-z]+\b'
	t.value = OPdict[t.value]
	t.lexer.lineno+=1
	return t

def t_error(t):
    print "Illegal character '%s'" % t.value[0]
    t.lexer.skip(1)

lexer = lex.lex()

# s = '''addi $t1 $zero 0x1234'''
# lexer.input(s)
# for i in lexer:
#   print i

import ply.yacc as yacc

def p_expression_program(p):
	'''program : TEXT textseg DATA dataseg
			   | TEXT textseg'''
	pass

def p_expression_textseg(p):
	'''textseg : IR
			   | IR textseg
			   | LABLEdef textseg'''

def p_expression_dataseg(p):
	'''dataseg : datastate
			   | dataseg datastate'''

def p_expression_datastate(p):
	'''datastate : LABLEdef WORD INT
				 | LABLEdef BYTE INT'''
	res = p[3]
	print "%08X" % res
	r.write("%08X" % res + "\n")


def p_expression_datastate_string(p):
	'''datastate : LABLEdef ASCII STRING'''
	arr = map(ord,p[3])
	res = 0
	N = 0
	for i in arr:
		res |= (i<<N*8)
		N+=1
		if N == 4:
			print "%08X" % res
			r.write("%08X" % res + "\n")
			N = 0
			res = 0
	if N > 0:
		print "%08X" % res
		r.write("%08X" % res + "\n")
		


def p_expression_IR_R(p):
	'''IR : OP REG REG REG'''
	res = (p[1])|(p[2]<<11)|(p[3])<<21|(p[4]<<16)
	print "%08X" % res
	r.write("%08X" % res + "\n")

def p_expression_IR_I(p):
	'''IR : OP REG REG INT'''
	res = (p[1])|(p[2]<<16)|(p[3]<<21)|(p[4] & 0xFFFF)
	print "%08X" % res
	r.write("%08X" % res + "\n")

def p_expression_IR_I_LABLE(p):
	'''IR : OP REG REG LABLEref'''
	if p[1] == 0x10000000 or p[1] == 0x14000000:
		res = (p[1])|(p[2]<<16)|(p[3]<<21)|((LABLEdict[p[4][0]] - p[4][1]) & 0x0000FFFF)
	else:
		res = (p[1])|(p[2]<<16)|(p[3]<<21)|((LABLEdict[p[4][0]]) & 0x0000FFFF)
	print "%08X" % res 
	r.write("%08X" % res + "\n")


# def p_expression_IR_I_DATA(p):
# 	'IR : OP REG REG ADDR'
# 	res = (p[1])|(p[2]<<16)|(p[3]<<21)|p[4]
# 	print "%08X" % res + "\n"
# 	r.write("%08X" % res + "\n")

# def p_expression_ADDR(p):
# 	'''ADDR : WORD
# 			| BYTE
# 			| SPACE
# 			| ASCII'''
# 	p[0] = p[1]

def p_expression_IR_J(p):
	'IR : OP INT'
	res = p[1]|p[2]
	print "%08X" % res
	r.write("%08X" % res + "\n")

def p_expression_J_L(p):
	'IR : OP LABLEref'
	res = p[1]|(LABLEdict[p[2][0]])
	print "%08X" % res
	r.write("%08X" % res + "\n")

def p_expression_INT(p):
	'''INT  : DEC 
			| HEX'''
	p[0] = p[1]

parser = yacc.yacc()


f = open("1.asm",'r')
r = open("1.out",'w')

s = f.read()
lexer.input(s)
for i in lexer:
  print i
lex.lexer.lineno = 1
parser.parse(s)
# print LABLEdict
r.close()