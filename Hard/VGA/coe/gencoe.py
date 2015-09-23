import struct
import functools
def prhz(a,b):
	with open('./hzk16','rb') as f:
		# print a,b
		offset = (((a - 0xa1) & 0xFF)* 94 + ((b - 0xa1) & 0xFF)) * 32
		f.seek(offset)
		# print offset
		# buff = map( functools.partial(struct.pack,),f.read(0x20))
		buff = map(ord,list(f.read(0x20)))
		# bb = functools.partial(struct.unpack,'c')
		# tt = map(bb,list(buff))

		for i in xrange(0x10):
			# for j in xrange(0x10):
			# 	byte_ord = (i * 0x10 + j) / 8
			# 	bit_ord = 7 - ((i * 0x10 + j) % 8)
			# 	c = buff[byte_ord]
			# 	if c & (1 << bit_ord):
			# 		print 'm',
			# 	else:
			# 		print '.' ,
			print "%016X," % (((buff[i*2] & 0xff) << 8) | (buff[i*2+1] & 0xff))
for i in xrange(256):
	prhz(0xa3,128 + i)

