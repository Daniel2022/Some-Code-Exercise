import re
var_dict = {}
def bool_convert(s):
	#s = s.strip()
	if s == 'True':
		return True
	elif s=='False':
		return False
	else:
		var_names = re.findall(r'[0-9a-zA-Z][0-9a-zA-Z_]*',s)
		for name in var_names:
			s = re.sub(name,str(int(var_dict[name]))+r'#',s)
			#print(s)
		s = re.sub(r'!','not ',s)
		s = re.sub(r'\|',' or ',s)
		s = re.sub(r'&',' and ',s)
		s = re.sub(r'1#','True',s)
		s = re.sub(r'0#','False',s)
			#print(s)
		return eval(s)

def cmp_list(s1,s2):
	if len(s1)!=len(s2):
		return False
	l = len(s1)
	for i in range(l):
		if s1[i] == s2[i]:
			continue
		else:
			return False
	return True

class program(object):
	def __init__(self,code):
		self.code = code
	def get_var(self):
		line_list = re.split(r';?\n',self.code)
		p1 = re.compile(r'\s*bool ')
		#p2 = re.compile(r'\s*[0-9]+:\s{0,2}')
		for line in line_list:
			if p1.match(line):
				line = p1.sub('',line)
				name, value = map(lambda x:x.strip(), line.split('='))
				var_dict.update({name:bool_convert(value)})
		#print(var_dict)
		#print(bool_convert('XroOh7Q & False'))
	def part(self):
		ma = re.search(r'main\(\)\s*\{[\s\W\w]*\}',self.code)
		main_part = ma.group()
		lines = re.split(r';?\n\s*',main_part)
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
		"""for ob in self.block_list:
			for li in ob.block:
				print(li.code)
			print(ob.index, ob.type)"""
	def evaluate(self):
		self.get_var()
		self.part()
		i = 0
		flag = None
		break_flag = 0
		loop_counter = 0
		while i < len(self.block_list):
			#print(i)#ex
			#print(loop_counter)#ex
			if self.block_list[i].type in ['if','normal']:
				flag = self.block_list[i].process()
				if flag == 'skip':
					i += 2
					continue
				else:
					i+=1
					continue	
			if self.block_list[i].type == 'while':
				judge, var_list =self.block_list[i].block[0].while_process()
				if judge:
					if loop_counter == 90:
						print('infinite')
						break_flag = 1
						break
					loop_counter += 1
					self.block_list[i+1].process()
					tmp, val_list_p = self.block_list[i].block[0].while_process()
					del tmp
					if cmp_list(val_list_p,var_list):
						print('infinite')
						break_flag = 1
						break
					continue
				else:
					i+=2
		if break_flag !=1:
			print(flag)
				

		#self.block_list[3].process()
		#print(var_dict)

		
class line_index(object):
	def __init__(self, index, code):
		self.index = index
		self.code = code
	def assign_process(self):
		#print(self.code)#ex
		name, expr = map(lambda x:x.strip(), self.code.split('='))
		var_dict[name] = bool_convert(expr)
	def if_process(self):
		tmp = self.code.partition('if')[2].strip()
		return bool_convert(tmp)
	def return_process(self):
		tmp = self.code.partition('return')[2].strip()
		return bool_convert(tmp)
	def while_process(self):
		tmp = self.code.partition('while')[2].strip()
		#print(tmp)#ex
		var_names = re.findall(r'[0-9a-zA-Z_]+',tmp)
		val_list = []
		#print(var_names)#ex
		for name in var_names:
			val_list.append(bool_convert(name))
		return bool_convert(tmp),val_list 

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
	def process(self):
		if self.type == 'normal':
			for line in self.block:
				if 'pass' in line.code:
					continue
				if 'return' in line.code:
					return line.return_process()
				line.assign_process()
			return 'continue'
		if self.type == 'if':
			for i in range(len(self.block)):
				if 'pass' in self.block[i].code:
					continue
				if i == len(self.block)-1:
					if self.block[i].if_process():
						return 'continue'
					return 'skip'
				self.block[i].assign_process()

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
	p.evaluate()