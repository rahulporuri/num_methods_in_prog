C /*FILE: area.f
C
C Programer: Poruri Sai Rahul rahul.poruri@gmail.com
C
C Date: 22 Jan 2015
C
C Version: Original
C
C Revision-History:
C
C Comments:
C 22 Jan 2015 : adapting a similar code in c to fortran. need to implement the to-do list
C
C NOTES:
C
C Todo:
C done - 1. Hard code radius instead of an interactive input
C done - 2. Change the code such that r is now a grid starting from some r_min to r_max for 
C example 0. to 5. with a step size of 0.1. Generate the r grid. Using a for loop, loop 
C through all values of r and calculate the area. Print the output to screen.
C done - 3. Now declare a file pointer, open a file called area.dat and write the output to file.
C */
C
C # v1 - takes input from user

C	PROGRAM area
C	IMPLICIT none
C	DOUBLE PRECISION :: radius, circle_area
C the name of the program should not have a conflict with any of the variables
C	DOUBLE PRECISION, PARAMETER :: pi = 3.14
c	
c	print *, 'enter radius of circle'
c	read *, radius
c	print *, 'you have entered', radius
c	circle_area = pi*radius*radius
c	print *, 'the area of a circle is'
c	print *, circle_area
c	END PROGRAM area

C # v2 - input is hard coded
c	
c	PROGRAM area
c	IMPLICIT none
C the name of the program should not have a conflict with any of the variables
c	DOUBLE PRECISION :: circle_area
c	DOUBLE PRECISION, PARAMETER :: pi = 3.14, radius = 1.0
c	print *, 'when the radius of the circle is', radius
c	circle_area = pi*radius*radius
c	print *, 'the area of a circle is'
c	print *, circle_area
c	END PROGRAM area

C # v3 - measures area for a range of radius values from 0-5 in steps of 0.1
c 	and saves the data to a file fort.10

	PROGRAM area
	IMPLICIT none
	INTEGER i
	DOUBLE PRECISION :: circle_area, radius
	DOUBLE PRECISION, PARAMETER :: pi = 3.14

	DO i = 0, 50, 1
	radius = 0.1*i
	print *, 'when the radius of the circle is'
	print *, radius
	circle_area = pi*radius*radius
	print *, 'the area of the circle is'
	print *, circle_area
	write(10,*), radius, circle_area
	END DO
	END PROGRAM area
