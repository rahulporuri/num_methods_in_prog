	PROGRAM precision
	IMPLICIT NONE
	DOUBLE PRECISION ::  eps
	eps = 1d0
10	IF ((1d0 + eps) .NE. 1d0) THEN
	eps = eps/2
	GOTO 10
	ENDIF
	print *, eps
	END PROGRAM precision
