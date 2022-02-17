		ORG		$0
		DC.L		$8000
		DC.L		MAIN

ARY		DC.L		100,-50,25,194,35,-1492,82,634,193,999,-524,1
		DC.L		-5,300,8315,81,4914,7143
ARYEND		DC.L		0

MAIN		LEA		ARY,A0		Preparing to use SUM.
		LEA		ARYEND,A1	Preparing to use SUM.
		JSR		SUM		Put sum and total number of array 
*						elements into d0 and d1.
		MOVE.L		D0,D5		Put the sum into d5 for storage.
		JSR		DIVIDE		Put average of array elements into 
*						d2.
*						Preconditions for this function are
*						already met as a result of using the
*						SUM function.
		MOVE.L		D2,D6		Put the average into d6 for storage 
*						and use in VAR.
		MOVE.L		D0,D4		Put the remainder into d4 for 
*						storage.
		LEA		ARY,A0		Preparing to use VAR.
		JSR		VAR		Put the variance into d2.
*						The end of array address is
*						already in a1.
		MOVE.L		D2,D7		Put variance in d7 for storage.
END		BREAK

*** SUM function
*** Preconditions: Address for begining of array must be in a0.
***		       Address for end of array must be in a1.
***
*** Postconditions: Data in a0,d0, and d1 will be over written.
***		        d0 will contain the sum of the array elements.
***		        d1 will contain the total number of array elements.

SUM		CLR.L		D0		accumulator set to 0
		CLR.L		D1		counter set to 0
AGAIN		ADD.L		(A0),D0		accumulator+=ary[i]
		ADD.L		#4,A0		bump address/move to next array 
*						element
		ADD.L		#1,D1		bump counter
		CMP.L		A0,A1		check to see if at the end of the 
*						array
		BNE		AGAIN		not at end, continue looping
		RTS				at end of array, continue with main 
*						program

*** DIVIDE function
*** Preconditions: Dividend must be in d0.
***			 Divisor must be in d1.
***
*** Postconditions: Data in d0 and d2 will be over written.
***			  d2 will contain the answer.
***			  d0 will contain the integer remainder.

DIVIDE		CLR.L		D2		counter set to 0
LOOP		ADD.L		#1,D2		bump counter
		SUB.L		D1,D0		subtract the divisor from the 
*						dividend
		BGT		LOOP		if the result is still positive 
*						continue subtracting
		ADD.L		#-1,D2		dec the counter to get correct 
*						number of subtracts
		ADD.L		D1,D0		add back the divisor to get correct 
*						remainder
		RTS

*** VAR function
*** Preconditions: Average must be in d6.
***			 Address for begining of array must be in a0.
***			 Address for end of array must be in a1.
***			 Number of array elements must be in d1.
***			 DIVIDE function must be present.
***
*** Postconditions: Data in a0,d0, and d2 will be over written.
***   		  d2 will contain the variance.

VAR		CLR.L		D0		accumulator set to 0
ONCEMORE	MOVE.L		(A0),D2 	grab array element to work on
		SUB.L		D6,D2		(x[i] - avg)^2
		MULS.W		D2,D2		(x[i] - avg)^2
		ADD.L		D2,D0		add the result to the accumulator
		ADD.L		#4,A0		bump address/move to next array 
*						element
		CMP.L		A0,A1		check to see if at the end of the 
*						array
		BNE		ONCEMORE	not at end, continue looping
		JSR		DIVIDE		end of array, prepare to divide
		RTS
			
