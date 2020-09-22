keys = ['-'] * 9

print("Enter Player 1's Name!")
plr1 = input()
print("Enter Player 2's Name!")
plr2 = input()

def printboard():
	print("\t%s | %s | %s" % (keys[0], keys[1], keys[2]))
	print("\t%s | %s | %s" % (keys[3], keys[4], keys[5]))
	print("\t%s | %s | %s" % (keys[6], keys[7], keys[8]))

def takeinp(num):
	if num == 0:
		num = 2
	if num == 1:
		print("Player %s: Enter Position!" % plr1)
	else:
		print("Player %s: Enter Position!" % plr2)
	temp = int(input())
	if num == 1:
		if keys[temp - 1] != '-':
			print ("Please Enter Valid Input!\n")
			takeinp(1)
		else:
			keys[temp - 1] = 'o'
	if num == 2:
		if keys[temp - 1] != '-':
			print ("Please Enter Valid Input!\n")
			takeinp(2)
		else:
			keys[temp - 1] = 'x'

def winner(x):
	if (keys[x] == 'o'):
			print("Player 1 Wins!")
			exit()
	if (keys[x] == 'x'):
			print("Player 2 Wins!")
			exit()

def checkwin():
	x = 0
	while x <= 8:
		if keys[x] == keys[x + 1] and keys[x + 1] == keys[x + 2]:
			winner(x)
		x += 3

	x = 0
	while x <= 2:
		if keys[x] == keys[x + 3] and keys[x + 3] == keys[x + 6]:
			winner(x)
		x += 1

	if (keys[0] == keys[4] and keys[4] == keys[8]):
		winner(0)
	if (keys[2] == keys[4] and keys[4] == keys[6]):
		winner(2)
	x = 0
	while x < 9:
		if keys[x] == '-':
			break ;
		x += 1
	if x == 9:
		print("Draw!")
		exit()

count = 1
while True:
	printboard()
	takeinp(count % 2)
	checkwin()
	count += 1
