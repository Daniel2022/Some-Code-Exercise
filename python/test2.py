import re
var_dict = {'x': True, 'y': False, 'z': True, 'a': True}
def bool_convert(s):
	#s = s.strip()
	if s == 'True':
		return True
	elif s=='False':
		return False
	else:
		var_names = re.findall(r'[0-9a-zA-Z_]+',s)
		for name in var_names:
			s = re.sub(name,str(int(var_dict[name])),s)
			print(s)
		s = re.sub(r'!','not ',s)
		s = re.sub(r'\|',' or ',s)
		s = re.sub(r'&',' and ',s)
		s = re.sub(r'1','True',s)
		s = re.sub(r'0','False',s)
		
		
		return eval(s)
		#print(s)

print(bool_convert('( ( x | y) & (a | z) )'))