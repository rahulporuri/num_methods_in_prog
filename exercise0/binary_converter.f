!	FILE: integ_test.c
!	Programer: Poruri Sai Rahul email ID : rahul.poruri@gmail.com
!
!	Version: Original
!	Date: 14 Feb 2015
!	Revision-History:
!	14 Feb 2015
!	Comments:
!	14 Feb 2015: Converts a number to it's binary equivalent
!
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

