x = "global"
def foo():
	x = "non-local-foo"
	def bar():
		global x
		x = "local-bar"
		print(x)
	print(x)
	bar()
def baz():
	x = "local-baz"
	print(x)
print(x)
foo()
print(x)
baz()
