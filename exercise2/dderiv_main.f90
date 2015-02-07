	PROGRAM deriv_main
	implicit none
	double precision, parameter :: x = 0, h_min = 1e-16, h_max = 1e-01
	double precision :: deriv, error,  h
	h = h_max
10	if (h .gt. h_min) then
	h = h/2
	deriv = (exp(x+h)+exp(x-h)-2*exp(x))/(h*h)
	error = deriv - exp(x)
!	print *, 'the product of the two numbers is:', deriv
!	print *, 'the error in derivative is:', error
	write(10,*) h, deriv, error
	goto 10
	end if
	END
