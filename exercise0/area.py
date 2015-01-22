"""
FILE: area.py

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 22 Jan 2015

Version: Adapted from original

Revision-History:

Comments:
22 Jan 2015 : adapted from the original code, solutions to the various to-do problems
mentioned in the code have been mentioned beneath the original code.

NOTES:
Compile using gcc -o area area.c This generates an executable called area. Run this 
executable using ./area at the prompt. You could also use a makefile.

Todo:
done - 1. Hard code radius instead of an interactive input
done - 2. Change the code such that r is now a grid starting from some r_min to r_max for 
example 0. to 5. with a step size of 0.1. Generate the r grid. Using a for loop, loop 
through all values of r and calculate the area. Print the output to screen.
done - 3. Now declare a file pointer, open a file called area.dat and write the output to 
file.

pi = 3.14
radius = raw_input('radius of circle is:')
# hard code radius
# radius = 1
radius = float(radius)
print 'the area of the circle is', pi * radius * radius
"""
pi = 3.14
radius = 0
for i in range(51):
	radius = 0.1*i
	print 'the area of the circle is', pi * radius * radius, 'when the radius is', radius
