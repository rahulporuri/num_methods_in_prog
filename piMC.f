	PROGRAM mcpi
	implicit none
	double precision area,x,y,eRMS
	integer i, inc, iter
	double precision pi
	pi = 4*ATAN(1.)

	inc =  10
20	if (inc .le. 1000000) then
		iter = 0
		eRMS = 0
30		if (iter .le. 10) then
			area = 0
			i = 0
10			if (i .le. inc) then
		!		print *, i
				x = rand()
				y = rand()
		!		print *, 'x,y', x, y
		!		print *, 'area', area
				if (x**2 + y**2 .le. 1) then
					area = area + 1.
				end if
				i = i + 1
				goto 10
			end if
!			print *, inc, area*4./inc, area*4./inc - pi
			eRMS = eRMS + (area*4./inc - pi)*(area*4./inc - pi)
			iter = iter + 1
			goto 30
		end if
!		print *, 'rms error', sqrt(eRMS)
		write(10, *), inc,sqrt(eRMS)
		inc = inc*2
		goto 20
	end if
	end
