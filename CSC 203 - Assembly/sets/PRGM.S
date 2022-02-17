                ORG             $0
                DC.L            $8000
                DC.L            MAIN

**EQUATE DELCARATIONS

INITSET         EQU             12
ONBIT           EQU             12
ADDSET          EQU             16
OFFBIT          EQU             12
DELSET          EQU             16
FSTSET          EQU             12
SNDSET          EQU             16
TESTBIT		EQU		12
TESTSET		EQU		16
PRNTSET         EQU             20

**DATA DECLARATIONS

SETA            DS.L            1
SETB            DS.L            1
SETC            DS.L            1
PRINTSET        DC.B            '{',$20
PSDATA          DS.B            97
                DC.B            0
PSETA		DC.B		$0A,$0D,'Set A: '
PSETB		DC.B		$0A,$0D,'Set B: '
PSETC		DC.B		$0A,$0D,'Set C: '

*****************************************************************************
      
MAIN		JSR             SETUPIO
		
		MOVE.L		SETA,-(A7)	*
		JSR		INIT		* A = []
		MOVE.L		(A7)+,SETA	*

		MOVE.L		#0,D0		*
MOREB		MOVE.L		SETB,-(A7)	*
		MOVE.L		D0,-(A7)	*
		JSR		ADDELEMENT	* B = [ 0 2 4 6 8 10 12 14 16
		MOVE.L		(A7)+,SETB	*       18 20 ]
		ADD.L		#4,A7		*
		ADD.L		#2,D0		*		
		CMP.L		#22,D0		*
		BNE		MOREB		*

		MOVE.L		#16,D0		*
MOREC		MOVE.L		SETC,-(A7)	*
		MOVE.L		D0,-(A7)	*
		JSR		ADDELEMENT	* C = [ 16 17 18 19 20 21 22
		MOVE.L		(A7)+,SETC	*	22 23 24 25 ]
		ADD.L		#4,A7		*
		ADD.L		#1,D0		*
		CMP.L		#26,D0		*
		BNE		MOREC		*

		PEA		PSETA		*
		JSR		PRINTF		*
		ADD.L		#4,A7		* Print A
		MOVE.L          SETA,-(A7)	*
                JSR             PRINT		*
                ADD.L           #4,A7		*

                PEA		PSETB		*
		JSR		PRINTF		*
		ADD.L		#4,A7		* Print B
		MOVE.L          SETB,-(A7)	*
                JSR             PRINT		*
                ADD.L           #4,A7		*

                PEA		PSETC		*
		JSR		PRINTF		*
		ADD.L		#4,A7		* Print C
		MOVE.L          SETC,-(A7)	*
                JSR             PRINT		*
                ADD.L           #4,A7		*

		MOVE.L		SETB,-(A7)	*
		MOVE.L		SETC,-(A7)	*
		JSR		UNION		* A = C union B
		MOVE.L		(A7)+,SETA	*
		ADD.L		#4,A7		*

		MOVE.L		SETA,-(A7)	*
		MOVE.L		#30,-(A7)	*
		JSR		ADDELEMENT	* A = A add element 30
		MOVE.L		(A7)+,SETA	*
		ADD.L		#4,A7		*
	
                PEA		PSETA		*
		JSR		PRINTF		*
		ADD.L		#4,A7		* Print A
		MOVE.L          SETA,-(A7)	*
                JSR             PRINT		*
                ADD.L           #4,A7		*

                PEA		PSETB		*
		JSR		PRINTF		*
		ADD.L		#4,A7		* Print B
		MOVE.L          SETB,-(A7)	*
                JSR             PRINT		*
                ADD.L           #4,A7		*

		MOVE.L		SETA,-(A7)	*
		MOVE.L		#0,-(A7)	*
		JSR		DELELEMENT	* A = A delete element 0
		MOVE.L		(A7)+,SETA	*
		ADD.L		#4,A7		*

		MOVE.L		SETA,-(A7)	*
		MOVE.L		#2,-(A7)	*
		JSR		DELELEMENT	* A = A delete element 2
		MOVE.L		(A7)+,SETA	*
		ADD.L		#4,A7		*

		MOVE.L		SETA,-(A7)	*
		MOVE.L		#25,-(A7)	*
		JSR		DELELEMENT	* A = A delete element 25
		MOVE.L		(A7)+,SETA	*
		ADD.L		#4,A7		*

                PEA		PSETA		*
		JSR		PRINTF		*
		ADD.L		#4,A7		* Print A
		MOVE.L          SETA,-(A7)	*
                JSR             PRINT		*
                ADD.L           #4,A7		*

		MOVE.L		SETB,-(A7)	*
		MOVE.L		SETC,-(A7)	*
		JSR		INTERSECT	* Print B intersection C
		JSR		PRINT		*
		ADD.L		#8,A7		*

		MOVE.L		SETA,-(A7)	*
		MOVE.L		#30,-(A7)	*
		JSR		ISIN		*
		BNE		ADONTPRINT	*
		PEA		PSETA		*
		JSR		PRINTF		* If 30 in A then Print A
		ADD.L		#4,A7		*
		MOVE.L          SETA,-(A7)	*
                JSR             PRINT		*
                ADD.L           #4,A7		*
ADONTPRINT	ADD.L		#8,A7		*

		MOVE.L		SETB,-(A7)	*
		MOVE.L		#30,-(A7)	*
		JSR		ISIN		*
		BNE		BDONTPRINT	*
		PEA		PSETB		*
		JSR		PRINTF		* If 30 in B then Print B
		ADD.L		#4,A7		*
		MOVE.L		SETB,-(A7)	*
		JSR		PRINT		*
		ADD.L		#4,A7		*
BDONTPRINT	ADD.L		#8,A7		*
		
		BREAK



***INIT function
***Preconditions: Pointer to set must be pushed on SP immeditaly before
***               function call.
***
***Postconditions: 4 extra bytes of data are on SP.
***                Resulting set will be top four bytes of SP when
***                function terminates.
***
***Easier way to do this is just to CLR.L the register and push it on
***the stack, but I was figuring out how to use the boolean operations
***as I missed that lecture.

INIT            MOVEM.L         D0/D1,-(A7)     *Save values in registers
                                                *to be used in function.
                MOVE.L          INITSET(A7),D0  *Grab parameter from SP.
                CLR.L           D1              *Set all bits in a longword
                                                *to zero.
                AND.L           D1,D0           *Turn all bits in parameter
                                                *set off.
                MOVE.L          D0,INITSET(A7)  *Place the resulting set on
                                                *SP.
                MOVEM.L         (A7)+,D0/D1     *Restore register values.
                RTS                             *Back to main.

***ADDELEMENT function
***
***Preconditions: Bit to be turned on must be second element of SP.
***               Pointer to set being changed must be third element of
***               SP.
***
***Postconditions: 8 extra bytes of data are on SP.
***                Resulting set will be top four bytes of SP when
***                function terminates.

ADDELEMENT      MOVEM.L         D0/D1,-(A7)     *Save values in registers
                                                *to be used in function.
                MOVE.L          ONBIT(A7),D0    *Grab parameter from SP.
                MOVE.L          ADDSET(A7),D1   *Grab other parameter.
                BSET.L          D0,D1           *Turn the bit on.
                MOVE.L          D1,12(A7)       *Put the resulting set on SP.
                MOVEM.L         (A7)+,D0/D1     *Restore register values.
                RTS                             *Back to main.

***DELELEMENT function
***
***Preconditions: Bit to be turned off must be second element of SP.
***               Pointer to set being changed must be third element of
***               SP.
***
***Postconditions: 8 extra bytes of data are on SP.
***                Resulting set will be top four bytes of SP when
***                function terminates.

DELELEMENT      MOVEM.L         D0/D1,-(A7)     *Save values in registers
                                                *to be used in function.
                MOVE.L          OFFBIT(A7),D0   *Grab parameter from SP.
                MOVE.L          DELSET(A7),D1   *Grab other parameter.
                BCLR.L          D0,D1           *Turn the bit off.
                MOVE.L          D1,12(A7)       *Put the resulting set on SP.
                MOVEM.L         (A7)+,D0/D1     *Restore register values.
                RTS                             *Back to main.

***UNION function
***
***Preconditions: Two sets to be AND'ed together must be second and
***               third elements of SP.
***
***Postconditions: 8 extra bytes of data are on SP.
***                Resulting set will be top four bytes of SP when
***                function terminates.

UNION           MOVEM.L         D0/D1,-(A7)     *Save values in registers
                                                *to be used in function.
                MOVE.L          FSTSET(A7),D0   *Grab parameter from SP.
                MOVE.L          SNDSET(A7),D1   *Grab other parameter.
                AND.L           D1,D0           *AND the two sets.
                MOVE.L          D0,12(A7)       *Put the resulting set on SP.
                MOVEM.L         (A7)+,D0/D1     *Restore register values.
                RTS                             *Back to main.

***INTERSECT function
***
***Preconditions: Two sets to be OR'ed together must be second and
***               third elements of SP.
***
***Postconditions: 8 extra bytes of data are on SP.
***                Resulting set will be top four bytes of SP when
***                function terminates.

INTERSECT       MOVEM.L         D0/D1,-(A7)     *Save values in registers
                                                *to be used in function.
                MOVE.L          FSTSET(A7),D0   *Grab parameter from SP.
                MOVE.L          SNDSET(A7),D1   *Grab other parameter.
                OR.L            D1,D0           *OR the two sets.
                MOVE.L          D0,12(A7)       *Put the resulting set on SP.
                MOVEM.L         (A7)+,D0/D1     *Restore register values.
                RTS                             *Back to main.

***ISIN function
***
***Preconditions: Bit to be examined must be second element of SP.
***		  Pointer to set being examined must be third element of SP.
***
***Postconditons: 8 extra bytes of data are on SP.
***		  Z CC bit will be 1 if bit is on, else 0.
***

ISIN		MOVEM.L		D0/D1,-(A7)	*Save values in registers
						*to be used in function.
		MOVE.L		TESTBIT(A7),D0	*Grap parameter from SP.
		MOVE.L		TESTSET(A7),D1	*Grab other parameter.
		BTST.L		D0,D1		*Test if the bit is on.
		MOVE.W		CCR,D0		*Copy the CCR register.
		BCHG.L		#2,D0		*NOT the Z bit of CCR.
		MOVE.W		D0,CCR		*Put the result back in CCR.
		MOVEM.L		(A7)+,D0/D1	*Restore register values.
		RTS	

***PRINT function
***
***Preconditions: Pointer to set to be printed must be pushed on
***               SP just prior to function call.
***		  PSDATA is initialized as a 97 element byte array.
***
***Postconditions: 4 extra bytes of data are on SP.

PRINT           MOVEM.L         D0/D1/D2/A0,-(A7) *Save values in registers
                                                *to be used in function.
                LEA             PSDATA,A0       *Grab a pointer to answer
                                                *array.
                MOVE.L          #97,D0          *Set up a decremental
                                                *counter.
ZEROOUT         MOVE.B          0,(A0)+         *Clear an element of the
                                                *answer array.
                ADD.L           #-1,D0          *Decrement the counter.
                BNE             ZEROOUT         *Done of counter is zero.
                LEA             PSDATA,A0       *Get a fresh pointer to
                                                *answer array.
                MOVE.L          PRNTSET(A7),D0  *Get the set to be printed.
                CLR.L           D1              *Set up an incremental
                                                *counter.
GOON            BTST.L          D1,D0           *Is the D1'th bit on?
                BNE             INSET           *If so, put it in the
                                                *answer array.
RETURN          ADD.L           #1,D1           *Increment the counter.
                CMP.L           #32,D1          *Have we checked all bits?
                BNE             GOON            *If not, continue checking.
                MOVE.B          #$7D,(A0)       *Put a } in the answer ary.
                PEA             PRINTSET        *Prepare to use PRINTF.
                JSR             PRINTF          *Print the set.
                ADD.L           #4,A7           *Clean the stack.
                MOVEM.L         (A7)+,D0/D1/D2/A0 *Restore register values.
                RTS                             *Back to main.

INSET           MOVE.L          D1,D2           *Get a copy of number
                                                *to be printed.
                DIVS.W          #10,D2          *Break number in quotient
                                                *and remainder.
                ADD.B           #$30,D2         *Convert quotient to
                                                *ASCII.
                MOVE.B          D2,(A0)+        *Put quotient in answer
                                                *array.
                SWAP            D2              *Make remainder high
                                                *ordered in register.
                ADD.B           #$30,D2         *Convert remainder to
                                                *ASCII.
                MOVE.B          D2,(A0)+        *Put remainder in answer
                                                *array.
                MOVE.B          #$20,(A0)+      *Put a space in answer
                                                *array.
                BRA             RETURN          *Back to print function.

*******************************************************************************

DUART   EQU     $effc01
MR1A    EQU     0
MR2A    EQU     0
SRA     EQU     2
CRA     EQU     4
CSRA    EQU     2
TBA     EQU     6
RBA     EQU     6
IMR     EQU     10
TBB     EQU     $16
CRB     EQU     $14
MR1B    EQU     $10
MR2B    EQU     $10
SRB     EQU     $12

SETUPIO: move.l a1,-(a7)
        LEA     DUART,A1
        MOVE.B  #%00010000,CRA(A1)     Reset MR?A pointer
        MOVE.B  #%00100011,MR1A(A1)    8 data bits
        MOVE.B  #%00010111,MR2A(A1)    Normal Mode
        MOVE.B  #%10111011,CSRA(A1)    Set clock to 9600
        MOVE.B  #%00000101,CRA(A1)     Enable Rx and Tx
        move.l  (a7)+,a1
        rts


*
* Routines for performing Polled I/O At the Console Serial Port
*
* By: Bradford W. Mott
*

LINEFEED:       EQU     10              * LineFeed Character value
CARR_RETURN:    EQU     13              * Carrage Return character value

*
* The character in D0 is transmitted to the CONSOLE ACIA.
* The newline character <LF> is expanded into <LF>/<CR>.
*

PUTC:   BTST    #2,SRA+DUART            * Test Transmit data register empty
        BEQ.S   PUTC                    * If not keep polling
        MOVE.B  D0,TBA+DUART            * Transmit the character
        CMP.B   #LINEFEED,D0            * Check for LINEFEED
        BNE     PUTEXT
        MOVE.B  #CARR_RETURN,D0         * Load CR into D0
        BRA     PUTC                    * Output CR
PUTEXT: RTS                             * Return to calling procedure


*
* Get a character from the CONSOLE ACIA and return it in D0
*

GETC:   BTST    #0,SRA+DUART            * Test Receive data register full
        BEQ.S   GETC                    * If not keep polling
        MOVE.B  RBA+DUART,D0            * Read the character
        RTS

*
*  Routine to print out one lineJSR             SETUPIO
*    Address on top of stack
*
printf:         MOVE.L          D0,-(A7)        *SAVE CURRENT REGS TO STACK
                move.l          a0,-(a7)
                move.l          12(a7),a0       *get string to print
PRLOOP:         MOVE.B          (A0)+,D0        *GET A CHARACTER
                CMP.B           #$00,D0         *IS IT A NULL CHARACTER?
                BEQ             PRNTEND         *IF SO, THEN YOU'RE DONE
                JSR             PUTC            *IF NOT, THEN SEND CHARACTER TO SCREEN
                BRA             PRLOOP          *LOOP UNTIL DONE
PRNTEND:        MOVE.L          (A7)+,a0        *RESTORE REGS
                move.l          (a7)+,d0
                RTS

*

		
