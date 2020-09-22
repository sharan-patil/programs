from sys import argv

def fail():
	print "The given word is not a palindrome!"
	exit (0)

name, word = argv
i = len(word)
x = 0
i = i - 1
while x < (i / 2):
	if (word[x] != word[i]):
		fail()
	x = x + 1
	i = i - 1
print "The given word is a palindrome!"
