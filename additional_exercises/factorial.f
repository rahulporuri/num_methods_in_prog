	PROGRAM factorial
	IMPLICIT NONE
	INTEGER :: n, i
	DOUBLE PRECISION :: prod
C	prod = 1
c	print *, 'enter the value:'
c	read *, n
	DO n = 2,50
		i = n
		prod = 1
10 		IF (i .NE. 1) THEN
			prod = prod*i
			i = i-1
			GOTO 10
		END IF
	print *, prod
	END DO
	END PROGRAM factorial
