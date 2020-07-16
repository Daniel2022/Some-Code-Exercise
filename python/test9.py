x = "global"
def foo():
	def bar():
		def baz():
			#nonlocal x
			print(x)
		baz()
	bar()
foo()