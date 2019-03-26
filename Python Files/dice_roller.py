import random

def rollTheDice():
	return (random.randint(1, 6))

while (1):
	print rollTheDice()
	print "Do you want to roll again? (Press y/n)"
	if raw_input() == "y":
		continue
	else:
		break 
