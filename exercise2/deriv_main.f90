!	FILE: integ_test.c
!	Programer: Poruri Sai Rahul email ID : rahul.poruri@gmail.com
!
!	Version: Original
!
!	Date: 14 Feb 2015
!	Revision-History:
!	14 Feb 2015
!
!	Comments:
!	14 Feb 2015: Estimates the first derivative of the function exp(x) at x = 0 for a range of values in h

	PROGRAM deriv_main
	implicit none
	double precision, parameter :: x = 0, h_min = 1e-16, h_max = 1e-01
	double precision :: deriv, error,  h
	h = h_max
10	if (h .gt. h_min) then
	h = h/2
	deriv = (exp(x+h)-exp(x-h))/(2*h)
	error = deriv - exp(x)
!	print *, 'the product of the two numbers is:', deriv
!	print *, 'the error in derivative is:', error
	write(10,*) h, deriv, error
	goto 10
	end if
	END





