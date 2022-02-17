*Preston Guillot

*This code is uh, nasty, because I confused myself halfway through.
*But it works.
*It's the thought that counts right?

		ORG		$0
		DC.L		$8000
		DC.L		MAIN

MAIN		MOVE.L		#90,-(SP)
		MOVE.L		#36,-(SP)
		JSR		LCF
		MOVE.L		(SP)+,D0
		ADD.L		#4,SP

LCF		MOVE.L		8(SP),D0  *GET M
		CMP.L		#0,D0
		BGT		NEXT
		RTS
NEXT		MOVE.L		D0,D2
		MOVE.L		4(SP),D1
		DIVS.W		D2,D1
		SWAP.W		D1
		CLR.L		D2
		MOVE.W		D1,D2
		MOVE.L		D2,-(SP)
		MOVE.L		D0,-(SP)
		JSR		LCF
		MOVE.L		(SP),12(SP)
		ADD.L		#8,SP
		RTS
