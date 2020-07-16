import re
class program(object):
	def __init__(self,code):
		self.code = code
	def trans(self):
		line_list = re.split(r';?\n',self.code)
		code_str = ''
		for line in line_list:
			p1 = re.compile(r'\s*bool ')
			p2 = re.compile(r'\s*[0-9]+:\s{0,2}')
			if p1.match(line):
				code_str += p1.sub('',line) + '\n'
				continue
			if p2.match(line):
				pa1 = re.compile(r'\s*if[\s\(]+')
				line_pro = p1.sub('',line)
				if pa1.match(line_pro):
					pass
		print(code_str)
		#code_str += 'return x'
		exec(code_str)
		#print(x)

		

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
	p.trans()