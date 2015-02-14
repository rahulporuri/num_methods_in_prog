!	FILE: integ_test.c
!	Programer: Poruri Sai Rahul email ID : rahul.poruri@gmail.com
!
!	Version: Original
!	Date: 14 Feb 2015
!	Revision-History:
!	14 Feb 2015
!	Comments:
!	14 Feb 2015: estimates system precision
!
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
