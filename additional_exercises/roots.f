	PROGRAM roots
	IMPLICIT NONE
	DOUBLE PRECISION, PARAMETER :: a = 1d0 ,b = 1d0
	INTEGER :: n
	DOUBLE PRECISION :: c, ans
	DO n = 1,15
		print *, n
		c = 1d0/10**n
		print *, c
		ans =  (-b + SQRT(b*b-4*a*c))/2*a
		print *, ans
	END DO
	END PROGRAM roots
