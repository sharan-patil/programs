currentAnswer = [[0 for x in range(9)] for y in range(9)]
givenQuestion = [[0 for x in range(9)] for y in range(9)]

#Opening the file in which the question is written.
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
		if ((pos >= 0 and pos <= 8) or (pos >= 27 and pos <= 35) or (pos >= 54 and pos <= 62)):
			if testInt not in currentAnswer[pos / 9 + i][(pos % 9 / 3) * 3:(pos % 9 / 3 + 1) * 3]:
				pass
			else:
				return 0
		if ((pos >= 9 and pos <= 17) or (pos >= 36 and pos <= 44) or (pos >= 63 and pos <= 71)):
			if testInt not in currentAnswer[pos / 9 + i - 1][(pos % 9 / 3) * 3:(pos % 9 / 3 + 1) * 3]:
				pass
			else:
				return 0
		if ((pos >= 72 and pos <= 80) or (pos >= 18 and pos <= 26) or (pos >= 45 and pos <= 53)):
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

#Clears the board when backtracking.
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

#Function which iterates and backtracks to find the answer.
def answerSolve():
	pos = 0
	testInt = 1
	while pos < 81:
		if testInt > 9:
			pos -= 1
			while givenQuestion[pos / 9][pos % 9] != 0:
				pos -= 1
			testInt = currentAnswer[pos / 9][pos % 9] + 1
			clearBoard(pos)
			continue
		while givenQuestion[pos / 9][pos % 9] != 0:
			pos += 1
		if testNumber(pos, testInt):
			currentAnswer[pos / 9][pos % 9] = testInt
			pos += 1
			if pos > 80:
				return 1
			while givenQuestion[pos / 9][pos % 9] != 0:
					pos += 1
			testInt = 1
		else:
			testInt += 1

#Solving the sudoku and printing the question along with the answer.
answerSolve()
print "Question:"
printBoard(givenQuestion)
print "Answer:"
printBoard(currentAnswer)
