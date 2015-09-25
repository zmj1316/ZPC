import ply.lex as lex

tokens = (
	"OP",
	"REG",
  "DEC",
  "HEX",
  "LABLE",
  "FLAG"
)


t_ignore  = ' \t'

LABLEdict={}

OPdict = {}
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

def t_REG(t):
  r'\$[a-z]+[0-9]*'
  t.value = REGdict[t.value]
  return t


def t_DEC(t):
	r'\b[0-9]+\b'
	t.value = int(t.value)
	return t

def t_HEX(t):
  r'\b0x[0-9A-F]+\b'
  t.value = int(t.value[2:],16)
  return t

def t_OP(t):
  r'\b[a-z]+\b'
  t.value = OPdict[t.value]
  t.lexer.lineno+=1
  return t

def t_LABLE(t):
  r'[A-Z]+[A-Za-z0-9]*\:'
  print t.value,t.lexer.lineno
  LABLEdict[t.value] = t.lexer.lineno - 1
  return t

def t_FLAG(t):
  r'[A-Z]+[A-Za-z0-9]*'
  t.value = ((LABLEdict[t.value+':'] - t.lexer.lineno + 1) &0x0000FFFF, LABLEdict[t.value+':'])
  return t

def t_newline(t):
    r'\n+'
    # t.lexer.lineno += len(t.value)

def t_COMMENT(t):
    r';.*'
    pass
    # No return value. Token discarded


def t_error(t):
    print "Illegal character '%s'" % t.value[0]
    t.lexer.skip(1)
lexer = lex.lex()
