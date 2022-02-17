		ORG			$0
		DC.L			$8000
		DC.L			MAIN
XSUBIPLS1	EQU			2
YSUBI		EQU			1
YSUBIPLS1	EQU			3

**DATA DECLARATIONS

POLYGON1	DC.B			0,0,0,5,8,5,8,0,0,0,-99
POLYGON2	DC.B			0,0,2,5,6,7,9,4,9,0,0,0,-99
POLYGON3	DC.B			0,0,0,8,5,3,11,7,11,0,0,0,-99
POLYGON4	DC.B			0,5,6,7,7,14,8,7,14,5,8,4,9,0,7,2,5,0,6,4,0,5,-99


*****************************************************************************

MAIN		LEA			POLYGON4,A0
		JSR			GETAREA
		
		BREAK




*** GETAREA function
*** Preconditions: Address of coordinates array is in A0.
***			Last node of coordinates array is -99.
***
*** Postconditions: D1 contains area of the polygon.
***			  D1,D2,D6,D7,A0 are over written.

GETAREA	CLR.L				D0			*Clear work area.
AREALOOP	CLR.L			D1			*Clear work area.
		CLR.L			D2			*Clear work area.
		CLR.L			D6			*Clear work area.
		CLR.L			D7			*Clear work area.
		MOVE.B			XSUBIPLS1(A0),D1	*Grab X(i+1)
		MOVE.B			YSUBI(A0),D7		*Grab Y(i)
		MULS.W			D7,D1			*X(i+1) * Y(i)
		MOVE.B			(A0),D2			*Grab X(i)
		MOVE.B			YSUBIPLS1(A0),D6	*Grab Y(i+1)
		MULS.W			D6,D2			*X(i) * Y(i+1)
		SUB.L			D2,D1			*Subtract right side from left.
		ADD.L			D1,D0			*Add result to accumulator.
		ADD.L			#2,A0			*Bump array pointer to next coordinate pair.
		CMP.B			#-99,2(A0)		*Are we at the end of the array?
		BNE			AREALOOP		*If not, continue.
		DIVS.W			#2,D0			*At the end, divide by 2.
		MOVE.W			D0,D1			*Grab the result, ignoring any remainder.
		RTS						*Back to main.
*
