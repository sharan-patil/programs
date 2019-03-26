def volumeofsphere(rad):
	return ((4.0 / 3) * 3.1415 * (rad ** 3))

def checkran(num, low, high):
	if (num >= low and num <= high):
		return True
	else:
		return False

def up_low(s):
	up = 0
	low = 0
	i = 0
	for letter in s:
		if s[i].isupper():
			up += 1
		elif s[i].islower():
			low += 1
		i += 1
	print (up)
	print (low)

def unique_list(lt):
	new_lt = []
	for item in lt:
		if item not in new_lt:
			new_lt.append(item)
	return new_lt

def multiply(li):
	res = 1
	for item in li:
		res = res * item
	return res

def checkpal(s):
	i = 0
	n = len(s)
	while i < n / 2:
		if (s[i] != s[n - i - 1]):
			return False
		i += 1
	return True

def checkpan(s):
	alpha = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
	 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
	chk = []
	for item in s:
		if item in alpha and item not in chk:
			chk.append(item)
	chk.sort()
	if alpha != chk:
		return False
	else:
		return True

print (checkpan("lmao"))
