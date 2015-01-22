"""
FILE: precision.py

Programer: Poruri Sai Rahul rahul.poruri@gmail.com

Date: 22 Jan 2015

Version: Adapted from original

Revision-History:

Comments:
22 Jan 2015 : adapted from the original code, solutions to the various to-do problems
mentioned in the code have been mentioned beneath the original code.

NOTES:
"""
eps = 1.
while (1.+eps != 1.):
	print eps	
	eps = eps/2
print 'machine precision is', eps
