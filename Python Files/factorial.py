from sys import argv
name, arg = argv
num = int(arg)
if num < 0:
	print "Please enter a valid number!"
	exit(0)
if num == 0:
	print "The factorial of 0 is 1!"
	exit(0)
i = 1
fact = 1
while i <= num:
	fact = fact * i
	i = i + 1
print "The factorial of %d is %d!" % (num, fact)
