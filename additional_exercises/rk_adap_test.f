	program rk_adap_test

	real(kind=4) :: x,y,h
	real(kind=4) :: k1, k2, k3, k4
	integer :: i
	i = 0
	x = 0.
	y = 0.5
	h = 1e-01
10	if (i .le. 100) then
		k1 = func(x,y)
		k2 = func(x+h/2., y+k1*h/2.)
		k3 = func(x+h/2., y+k2*h/2.)
		k4 = func(x+h, y+k3*h)
		y = y + (k1+2*k2+2*k3+k4)*h/6.
		x = x +h
!		print *, x
!		print *, y
		write(10,*) x,y
		i = i +1
		goto 10
	end if
	end

	real(kind=4) function func(a,b)
	real(kind=4) ::  a,b
	func = 10*exp(-(a-2)*(a-2)/(2*0.075*0.075)) - 0.6*b
	return
	end
