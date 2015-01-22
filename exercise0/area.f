c /*FILE: area.f
c
c Programer: Poruri Sai Rahul rahul.poruri@gmail.com
c
c Date: 22 Jan 2015
c
c Version: Original
c
c Revision-History:
c
c Comments:
c 22 Jan 2015 : adapting a similar code in c to fortran. need to implement the to-do list
c
c NOTES:
c
c Todo:
c 1. Hard code radius instead of an interactive input
c 2. Change the code such that r is now a grid starting from some r_min to r_max for 
c example 0. to 5. with a step size of 0.1. Generate the r grid. Using a for loop, loop 
c through all values of r and calculate the area. Print the output to screen.
c 3. Now declare a file pointer, open a file called area.dat and write the output to file.
c */

program area
	implicit none
	integer :: RADIUS, AREA
	double :: pi
	pi = 3.14
	print *, 'enter radius of circle'
	read *, radius
	area = pi * radius * radius
	print *, area
end program area
