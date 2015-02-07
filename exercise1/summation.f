	PROGRAM summation
	IMPLICIT NONE
	INTEGER :: a, i, j
	DOUBLE PRECISION :: ans
c	DO i = 1,10,1
c		a = 10**i
c		ans = 0
c10		IF (a .NE. 0) THEN
c			ans = ans + a
c			a = a-1
c		GOTO 10
c		END IF
c		print *, ans
c	END DO
c	DO i = 1,10,1
c		a = 10**i
c		ans = 0
c		j = 0
c10		IF (j .NE. a+1) THEN
c			ans = ans + j
c			j = j+1
c		GOTO 10
c		END IF
c		print *, ans
c	END DO
c	DOUBLE PRECISION :: forward_sum, reverse_sum
c	DO i = 1,10,1
c		a = 10d0**i
c		reverse_sum = 0 
c10		IF (a .NE. 0) THEN
c			reverse_sum = reverse_sum + 1d0/a
c			a = a-1
c		GOTO 10
c		END IF
c		print *, reverse_sum
c	END DO
c	DO i = 1,10,1
c		a = 10d0**i
c		forward_sum = 0
c		j = 1
c20		IF (j .NE. a+1) THEN
c			forward_sum = forward_sum + 1d0/j
c			j = j+1
c		GOTO 20
c		END IF
c		print *, forward_sum
c	END DO
	DOUBLE PRECISION :: forward_sum, reverse_sum
	DO i = 1,10,1                               
		a = 10d0**i
		reverse_sum = 0
		j = 10d0**i
10		IF (j .NE. 0) THEN
			reverse_sum = reverse_sum + 1d0/j
			j = j-1
		GOTO 10
		END IF
		print *, reverse_sum
		forward_sum = 0
		j = 1
20		IF (j .NE. a+1) THEN
			forward_sum = forward_sum + 1d0/j
			j = j+1
		GOTO 20
		END IF
		print *, forward_sum
		print *, forward_sum-reverse_sum
	END DO
 	END PROGRAM summation
