
def f(x):
	a = 2*x
	b = a^x
	c = a+x
	d = b+x
	e = c^d
	return e

def g(x):
	a = 4*x
	b = a^x
	c = a+(2*x)
	d = b+(2*x)
	e = c^d
	return e

def move(a):
	aa = a
	aaa = a
	while(aaa):
		aa*=2
		aaa=aaa//2
	aa//=2
	b = a ^ aa
	c = a + aa
	print(a,aa,b,c)
	return b^c
	
x = int(input())
print(f(x), g(x), move(x))