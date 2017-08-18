from sys import argv
name, charnum = argv
num = int(charnum)
if num <= 0:
	print "Please enter a valid number of terms!"
	exit(0)
if num == 1:
	print "The fibonacci sequence for %d term(s):" % num
	print "1"
	exit(0)
if num == 2:
	print "The fibonacci sequence for %d term(s):" % num
	print "1, 1"
	exit(0)
i = 3
nums = [1, 1]
print "The fibonacci sequence for %d term(s):" % num
print "1, 1,",
x = 1
while i <= num:
	count = nums[x] + nums[x - 1]
	nums.append(count)
	x = x + 1
	if i == num:
		print "%d" % count
		exit(0)
	print "%d," % count,
	i = i + 1