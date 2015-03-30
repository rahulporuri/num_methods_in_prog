!	http://www.owlnet.rice.edu/~ceng303/manuals/fortran/FOR5_3.html
!	a good reference for matrix manipulation

	Program matrix_alloc

	integer, parameter :: N = 5
	integer, dimension (N,N) :: A
c	integer :: A(3,3) is also acceptable
	double precision, dimension(N) :: B
	double precision, dimension(N) :: U

	double precision :: h, y
	double precision, parameter :: c=0, d=1
	integer :: row, column, w, x

	y = c
	h = (d-c)/(N-1)
	print *, 'stepsize is', h

	do column = 1,N
		B(column) = (3*y +y*y)*exp(y)
		U(column) = y*(1-y)*exp(y)
		do row = 1,N
			if (row .eq. column) then
				A(row, column) = 2
		 	else if (abs(row-column) .eq. 1) then
				A(row, column) = -1
			else
				A(row, column) = 0
			endif
		enddo
		y = y+h
	enddo

!	do x = 1,N
!		print *, B(x), U(x)
!		do w = 1,N
!			print *, A(w, x)
!		enddo
!		print *,
!	enddo

	print *,((A(row,column), row=1, N),column=1, N)
!	this is referred to as an implied do loop

	end
