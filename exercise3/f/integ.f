!	FILE: integ.f
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

	PROGRAM integ
	implicit none
	double precision, parameter :: h_min = 1e-4, h_max = 1e-01
	double precision :: integ_trap, temp, error,  h, x, fn, int_trap
	double precision, parameter :: a = 0, b = 1
	h = h_max
10	if (h .gt. h_min) then
		x = 0
		temp = 0
		integ_trap = 0
!20		if (x .le. 1) then
!			temp = temp + (fn(x+h)+fn(x))
!			x = x + h
!			goto 20
!		end if
!		print *, 'summation is done'
!		integ_trap = temp*(h/2)
!		error = integ_trap - exp(1.) + 1
		integ_trap = int_trap(a,b,h)
		print *, 'the integration gives:', integ_trap
!		print *, 'the error in integration is:', error
!		write(10,*) h, integ_trap, error
		h = h/5
!		print *, h
!		print *, 'moving on'
		goto 10
	end if
	END

	double precision function fn(a)
	implicit none
	double precision :: a
	fn = exp(a)
	return
	end

	double precision function int_trap(a,b,h0)
	implicit none
	double precision :: a,b,h0,fn
	int_trap = 0
30	if (a .le. b) then
		int_trap = int_trap + (fn(a+h0)+fn(a))
		a = a+h0
		goto 30
	end if
	int_trap = int_trap*(h0/2.)
	return
	end
