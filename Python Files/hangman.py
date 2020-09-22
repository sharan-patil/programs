import random

correctGuess = []
actualWord = []
currentGuesses = 0

def giveWord():
	words = ['laptop', 'mouse', 'phone', 'computer', 'window', 'walnut']
	return words[random.randint(0, 5)]

def checkGuess(charGuess):
	temp = []
	if charGuess[0] in actualWord:
		ind = 0
		for i in range(0, actualWord.count(charGuess[0])):
			ind = actualWord.index(charGuess[0], ind)
			correctGuess[ind] = charGuess[0]
			ind = ind + 1
		return correctGuess
	else:
		return 'none'

actualWord = list(giveWord())
correctGuess = list(len(actualWord) * '#')
print 'You get a total of 8 incorrect guesses!'
while 1:
	print 'Your word is: ' + "".join(correctGuess)
	print 'Your current incorrect guesses: %s' % currentGuesses
	print 'Make a guess (From a to z): ',
	charGuess = list(raw_input())
	if checkGuess(charGuess) == 'none':
		currentGuesses += 1
	else:
		correctGuess = checkGuess(charGuess)
	if "".join(correctGuess) == "".join(actualWord):
		print 'Your word is: ' + "".join(correctGuess)
		print "Congratulations! You guessed the word correctly!"
		exit()
	if (currentGuesses == 8):
		print 'You lose! You ran out of guesses!'
