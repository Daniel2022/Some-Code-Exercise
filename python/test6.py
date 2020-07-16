def gcd(a, b):
	if b == 0:
		return a
	return gcd(b, a % b)

class Rational(object):
	def __init__(self, p, q):
		self.p = p
		self.q = q
	def __add__(self, r):
		return Rational(self.p * r.q + self.q * r.p, self.q * r.q)
	def __sub__(self, r):
		return Rational(self.p * r.q - r.p * self.q, self.q * r.q)
	def __mul__(self, r):
		return Rational(self.p * r.p, self.q * r.q)
	def __truediv__(self, r):
		return Rational(self.p * r.q, self.q * r.p)
	def __str__(self):
		g = gcd(self.p, self.q)
		if self.q / g == 1:
			return 'result: %s' % (int(self.p / g))
		else:
			return 'result: %s/%s' % (int(self.p / g),int(self.q / g))

def cal(r1, r2, point):
	if point == '+':
		print(r1 + r2)
	elif point == '-':
		print(r1 - r2)
	elif point == '*':
		print(r1 * r2)
	elif point == '/':
		print(r1 / r2)

def trans(r):
	if '/' in r:
		a, b = map(int, r.split('/'))
	else:
		a = int(r)
		b = 1
	return Rational(a, b)

print("Please type like '1/2 + 1/2' or '2 + 1\nType'q' to exit")
while True:
	try:
		input_value = input()
		if input_value == 'q':
			print('Program exits.')
			break
		r1, point, r2= map(str, input_value.split())
		r1 = trans(r1)
		r2 = trans(r2)
		cal(r1, r2, point)
	except:
		print('Error!Please input again.')

		