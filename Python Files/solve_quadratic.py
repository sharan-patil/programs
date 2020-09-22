print "The general equation of a Quadratic Equation is Ax^2 + Bx + C!"
print "Enter the value of A!"
A = float(raw_input("> "))
print "Enter the value of B!"
B = float(raw_input("> "))
print "Enter the value of C!"
C = float(raw_input("> "))
discriminant = (B * B) - (4 * A * C)
if discriminant < 0:
	print "The given equation has imaginary roots!"
	exit(0)
if discriminant == 0:
	root1 = (-B + (discriminant ** 0.5)) / (2 * A)
	root2 = root1
	print "The roots are %f and %f!" % (root1, root2)
	exit(0)
if discriminant > 0:
	root1 = (-B + (discriminant ** 0.5)) / (2 * A)
	root2 = (-B - (discriminant ** 0.5)) / (2 * A)
	print "The roots are %f and %f!" % (root1, root2)
	exit(0)
	