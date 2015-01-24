	PROGRAM binary_converter
	IMPLICIT NONE
	INTEGER :: a, i
	i = 0
	read *, a
10	IF (a .NE. 0.0) THEN
	print *, a-2*(a/2), i
	a = a/2
	i = i+1
	goto 10
	ENDIF
	END PROGRAM binary_converter

