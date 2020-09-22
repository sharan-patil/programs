from sys import argv

def fail():
	print "The given number is not a perfect square!"
	exit(0)

name, num_char = argv
num = int(num_char)
i = 1
while i != num:
	if i * i == num:
		break
	i = i + 1
	if i == num:
		fail()
		break
print "The square root of the given number is %d" % i
