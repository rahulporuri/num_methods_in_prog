"""
FILE: base_conversion.py

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 22 Jan 2015

Version: Adapted from original

Revision-History:

Comments:
22 Jan 2015 : adapted from the original code, solutions to the various to-do problems
mentioned in the code have been mentioned beneath the original code.

NOTES:
"""
output=[]
input = raw_input('input number to be converted to base 2:')
input = int(input)
while (input != 0):
	print input - 2*(input/2)
	output.append(input - 2*(input/2))
	input = input/2
print output[::-1]
