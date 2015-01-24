	PROGRAM summation
	IMPLICIT NONE
	INTEGER :: a, i, j
	INTEGER :: ans
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
	DO i = 1,10,1
		a = 10d0**i
		ans = 0 
10		IF (a .NE. 0) THEN
			ans = ans + 1d0/a
			a = a-1
		GOTO 10
		END IF
		print *, ans
	END DO
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
	END PROGRAM summation
