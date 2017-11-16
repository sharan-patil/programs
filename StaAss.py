st = 'Print only the words that start with s in this sentence'
st2 = st.split(' ')
for word in st2:
	if word[0] == 's':
		print(word)

ra = range(1, 11)
for n in ra:
	if n % 2 == 0:
		print(n)

li = [num for num in range(1, 50) if num % 3 == 0]
print(li)

st = 'Print every word in this sentence that has an even number of letters'

st3 = st.split(' ')
for word in st3:
	if len(word) % 2 == 0:
		print('even!')

for num in range(1, 101):
	if num % 3 == 0 and num % 5 == 0:
		print("FizzBuzz")
	elif num % 3 == 0:
		print("Fizz")
	elif num % 5 == 0:
		print("Buzz")
	else:
		print(num)

st = 'Create a list of the first letters of every word in this string'

st4 = st.split(' ')
lis = []
for word in st4:
	lis.append(word[0])

print(lis)
