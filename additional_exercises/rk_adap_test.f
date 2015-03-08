	program rk_adap_test

	real(kind=4) :: x,y,yt,h
	real(kind=4) :: k1, k2, k3, k4, k5, k6, temp1, temp2
	real(kind=4) :: temp3
	integer :: i
	i = 0
	x = 0
	y = 5e-01
	h = 1e-01
10	if (i .le. 100) then
	k1 = func(x,y)
	k2 = func(x +h/5, y+k1*h/5)
	k3 = func(x +3*h/10, y +3*k1*h/40 +9*k2*h/40)
	k4 = func(x +3*h/5, y +3*k1*h/10 -9*k2*h/10 + 6*k3*h/5)
	k5 = func(x+h,y-11*k1*h/54+5*k2*h/2-70*k3*h/27+35*k4*h/27)
	temp1=1631*k1*h/55296+175*k2*h/512+575*k3*h/13824
	temp2=44275*k4*h/110592+253*k5*h/4096
	k6=func(x+7*h/8,y+temp)

	y = y + (37*k1/378 +250*k3/621 +125*k4/594 +512*k6/1771)*h;
	temp3 = 13525*k4/55296+277*k5/14336+k6/4
	yt=y+(2825*k1/27648+12575*k3/48384+temp3)*h
		x = x +h
!		print *, x
!		print *, abs(y-yt)
		write(10,*) x,y,yt
		i = i +1
		goto 10
	end if
	end

	real(kind=4) function func(a,b)
	real(kind=4) ::  a,b
	func = 10*exp(-(a-2)*(a-2)/(2*0.075*0.075)) - 0.6*b
	return
	end

!	real(kind=4) function rk_step(a,b)
!	real(kind=4) ::
