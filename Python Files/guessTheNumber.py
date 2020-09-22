import random

def checkCorrect(inpNum, ranNum):
	if inpNum == ranNum:
		return 1
	else:
		return 0

def genRandom():
	return random.randint(1, 10)

score = 0
while (1):
	print "Enter a number from 1 till 10:"
	try:
		numEntered = int(raw_input())
	except ValueError:
		print "Please enter an integer:"
		numEntered = int(raw_input())
	randomNumber = genRandom()
	print "randomNumber = ",  randomNumber
	while (1):
			if (checkCorrect(numEntered, randomNumber)):
				print "Congratulations! You guesses correctly!",
				score = score + 1
				print "Current score:", score
				break
			elif numEntered < randomNumber:
				print "The number is higher."
			else:
				print "The number is lower."
			print "Try again:"
			numEntered = int(raw_input())

