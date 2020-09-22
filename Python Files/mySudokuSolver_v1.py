import sys

currentAnswer = [[0 for x in range(9)] for y in range(9)]
givenQuestion = [[0 for x in range(9)] for y in range(9)]
inputSud = open('qSud.txt', 'r')
#Reading input into givenQuestion
for i in range(9):
	for j in range(9):
		givenQuestion[i][j] = int(inputSud.read(1))
		inputSud.read(1)

#Copying givenQuestion into currentAnswer
for i in range(9):
	for j in range(9):
		currentAnswer[i][j] = givenQuestion[i][j]

#Prints a 2d list
def printBoard(board):
	for i in range(9):
		for j in range(9):
			print board[i][j], 
		print ""

#Tests whether an integer is allowed in the line of sudoku
def testLine(pos, testInt):
	if testInt in currentAnswer[pos / 9]:
		return 0
	for i in range(9):
		if testInt == currentAnswer[i][pos % 9]:
			return 0
	return 1

#Test whether an integer is allowed in its box
def testBox(pos, testInt):
	for i in range(3):
		if pos >= 0 and pos <= 8:
			if testInt not in currentAnswer[pos / 9 + i][(pos % 9 / 3) * 3:(pos % 9 / 3 + 1) * 3]:
				pass
			else:
				return 0
		if pos > 8 and pos < 71:
			if testInt not in currentAnswer[pos / 9 + i - 1][(pos % 9 / 3) * 3:(pos % 9 / 3 + 1) * 3]:
				pass
			else:
				return 0
		if pos >= 71 and pos <= 80:
			if testInt not in currentAnswer[pos / 9 + i - 2][(pos % 9 / 3) * 3:(pos % 9 / 3 + 1) * 3]:
				pass
			else:
				return 0
	return 1

#Executes both tests and check if an integer is allowed at a certain location
def testNumber(pos, testInt):
	if testLine(pos, testInt):
		if testBox(pos, testInt):
			return 1
	return 0

def clearBoard(pos):
	pos = pos + 1
	i = pos / 9
	j = pos % 9
	while i < 9:
		while j < 9:
			currentAnswer[i][j] = givenQuestion[i][j]
			j += 1
		i += 1
		j = 0

def solve(pos, testInt):
	if pos > 80:
		return 1
	if testInt > 9:
		pos -= 1
		while givenQuestion[pos / 9][pos % 9] != 0:
			pos -= 1
		testInt = currentAnswer[pos / 9][pos % 9] + 1
		printBoard(currentAnswer)
		print ""
		clearBoard(pos)
		return solve(pos, testInt)
	while givenQuestion[pos / 9][pos % 9] != 0:
		pos += 1
	if testNumber(pos, testInt):
		currentAnswer[pos / 9][pos % 9] = testInt
		pos += 1
		testInt = 1
		return 1
	else:
		testInt += 1
		return solve(pos, testInt)

def answerSolve():
	while pos < 81:
		

solve(0, 1)
print "Question:"
printBoard(givenQuestion)
print "Answer:"
printBoard(currentAnswer)
