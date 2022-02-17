		ORG		$0
		DC.L		$8000
		DC.L		MAIN

**DATA DECLARATIONS

NUMBER1		DS.B	21
OPERATOR	DS.B	1
NUMBER2		DS.B	21
ANSWER		DS.B	41

STRING1		DC.B	'127*345'
		DC.L	0

*************************************

MAIN		LEA		ANSWER,A0
		MOVE.L		#41,D0
		JSR		ZEROOUT

		LEA 		STRING1,A0
		LEA 		NUMBER1,A1
		LEA		NUMBER1,A5
		JSR		GETNUM
		LEA		NUMBER1,A5
		JSR		RIGHTJUST
		JSR		GETOPER
		LEA		NUMBER2,A1
		JSR		GETNUM
		LEA		NUMBER2,A5
		JSR		RIGHTJUST
		
		LEA		NUMBER1+21,A0
		LEA		NUMBER2+21,A1
		LEA		ANSWER+41,A2
		JSR		MULTSTUFF
		
		
		BREAK

*** GETNUM function
*** Preconditions: Address for begining of number array must be in A1
***			 Address for begining of string array must be in A0
*** 
*** Postconditions: A0 will be pointing to the operator in the string.
***			  Number data will be in array, left hand justified.
***			  D6 is over written.

GETNUM		MOVE.B		(A0)+,D6	*Get an array element and bump
						*the array pointer
		CMP.B		#'0',D6		*If the data is less than zero
		BLT		NODIGIT		*it's not a number, done.
		CMP.B		#'9',D6		*If the data is greater than nine
		BGT		NODIGIT		*it's not a number, done.
		ADD.B		#-$30,D6	*If it's a number, convert it to binary.
		MOVE.B		D6,(A1)+	*Put the binary number in the number array and bump its pointer.
		BRA		GETNUM		*Do it again.	
NODIGIT		SUB.L		#1,A0		*Back up string pointer to grab operator.
		RTS				*Back to main.

*** GETOPER function

GETOPER		MOVE.B	(A0)+,D6
		MOVE.B	D6,OPERATOR
		RTS

*** RIGHTJUS function

RIGHTJUST	MOVE.L		A5,A6		*Copy the begining of the array location to A6.
		ADDA.L		#21,A6		*Make A6 point to the end of the array.
LOOPY		MOVE.B		-(A1),-(A6)	*Copy a number to the next availible space at the right of the array.
		CMP.L		A5,A1		*Are there any more numbers?
		BNE		LOOPY		*If so, do it again.
LOOPEY		MOVE.B		0,(A5)+		*If not, start putting zeros at the front of the array.
		CMP.L		A5,A6		*Check to see if we've reached our number yet.
		BNE		LOOPEY		*If not add more leading zeros.
		RTS				*Back to main.

*** ADDSTUFF function

ADDSTUFF	CLR.L		D6			*Clear out workspace.
		MOVE.B		-(A0),D6		*Get a digit from NUMBER1.
		ADD.B		-(A1),D6		*Add a digit from NUMBER2.
		ADD.B		-(A2),D6		*Add the carry digit.
		DIVS.W		#10,D6			*Break the number in two parts.
		SWAP		D6			*Move the remainder so we can access it.
		MOVE.B		D6,(A2)			*Put the remainder into the answer array.
		SWAP		D6			*Move the carry so we can access it.
		MOVE.B		D6,-(A2)		*Put the carry into the answer array.
		ADDA.L		#1,A2			*Shift the answer array pointer back to its proper position.
		CMP.L		#NUMBER1+1,A0		*Check to see if we've added the whole number.
		BNE		ADDSTUFF		*If not, keep adding.
		RTS					*Back to main.

*** MULTSTUFF function
*** Preconditions: All strings are binary data, not character.
***			 One byte past NUMBER1 array is loaded in A0.
***			 One byte past NUMBER2 array is loaded in A1.
***			 One byte past ANSWER array is loaded in A2.
***
*** Postconditions: Answer array contains answer in binary data form.
***			  A0,A1,A2,A6,D0,D2 are over written.

MULTSTUFF	MOVE.L		A2,A6
OUTER	 	MOVE.B		-(A1),D2
INNER		MOVE.L		D2,D0
		MOVE.B		-(A0),D1
		MULS.W		D1,D0
		ADD.B		-(A2),D0
		DIVS.W		#10,D0
		SWAP		D0
		MOVE.B		D0,(A2)
		SWAP		D0
		ADD.B		D0,-(A2)
		ADDA.L		#1,A2
		CMP.L		#NUMBER1+1,A0
		BNE		INNER
		ADDA.L		#-1,A6
		MOVE.L		A6,A2
		LEA		NUMBER1+21,A0
		CMP.L		#NUMBER2+1,A1
		BNE		OUTER
		RTS
		
*** ZEROOUT function
*** Preconditions: Address for first node of array must be in a0.
***                Total number of elements in array must be in d0.
***
*** Postconditions: Each element of the array will contain a ascii space character.
***                 A0 will point to the last element of the array.

ZEROOUT         MOVE.B  0,(A0)+         Put a zero in array and bump index.
                ADD.L   #-1,D0          Decrement the counter.
                BNE     ZEROOUT         If the counter isn't zero do it again.
                RTS                     If the counter is zero return to main program.

*
