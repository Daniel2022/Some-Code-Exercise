import re
class program(object):
	def __init__(self,code):
		self.code = code
	def part(self):
		ma = re.search(r'main\(\)\s*\{[\s\W\w]*\}',self.code)
		main_part = ma.group()
		lines = re.split(r'\n\s*',main_part)
		lines_list = []
		for line in lines:
			if re.search(r':\s{0,2}',line):
				index = re.split(r':\s{0,2}', line)
				lines_list.append(line_index(index[0],index[1]))
			elif re.match(r'main\(\)|[\{\}]',line):
				pass
			else:
				lines_list.append(line_index(index='*',code=line))
		self.block_list = []
		for objects in lines_list:
			try:
				block
			except NameError:
				block = []
			if re.match(r'while',objects.code):
				if len(block) != 0:
					self.block_list.append(basic_block(block))
				block = []
			if (objects.index != '*'):
				block.append(objects)
			if re.match(r'(if[\s\(]+)|(while[\s\(]+)',objects.code) or objects.index == '*' or objects == lines_list[len(lines_list)-1]:
				self.block_list.append(basic_block(block))
				del block
				continue
	def getCFG(self):
		self.part()
		block_index_list =[]
		for i in range(len(self.block_list)):
			block_index_list.append(self.block_list[i].index)
			if self.block_list[i-1].type == 'while':
				self.block_list[i].link.append(self.block_list[i-1].index)
				continue 
			if self.block_list[i].type == 'normal' and i != len(self.block_list)-1:
				self.block_list[i].link.append(self.block_list[i+1].index)
			if (self.block_list[i].type == 'if' or self.block_list[i].type == 'while'):
				self.block_list[i].link.append(self.block_list[i+1].index)
				if i != len(self.block_list)-2:
					self.block_list[i].link.append(self.block_list[i+2].index)
		block_index_list = sorted(block_index_list)
		self.block_list = sorted(self.block_list, key = lambda x : x.index)
		print('[',end='')
		for i in range(len(self.block_list)):
			for j in range(len(block_index_list)):
				if block_index_list[j] in self.block_list[i].link:
					print('1',end='')
				else:
					print('0',end='')
				if i == len(self.block_list)-1 and j== len(block_index_list)-1:
					print(']')
				elif j == len(block_index_list)-1:
					print(';',end='')
				else:
					print(',',end='')
			
class line_index(object):
	def __init__(self, index, code):
		self.index = index
		self.code = code

class basic_block(object):
	def __init__(self, block):
		self.block = block
		self.index = block[0].index
		self.link = []
		control_ma = re.match(r'(if[\s\(])|(while[\s\(])',block[len(block)-1].code)
		if control_ma:
			self.type = control_ma.group()[:-1]
		else:
			self.type = 'normal'

if __name__ == "__main__":
	c = []
	while True:
		try:
			line = input()
			c.append(line)
		except:
			break
	a = ''
	for line in c:
		a += line + '\n'
	p = program(a)
	p.getCFG()