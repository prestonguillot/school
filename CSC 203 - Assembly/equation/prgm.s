	org	$0
	dc.l	$8000
	dc.l	main
main
	clr.l	d0	clear answer indicator
	move.l	X,d1	x^3	
	muls.w	d1,d1	x^3	   
	muls.w	X+2,d1	x^3	
	move.l	A,d2	4a^2
	muls.w	d2,d2	4a^2
	muls.w	#4,d2	4a^2
	move.l	A,d3	a^2x
	muls.w	d3,d3	a^2x
	muls.w	X+2,d3	a^2x
	add.l	d2,d1	x^3 + 4a^2
	sub.l	d3,d1	x^3 + 4a^2 - a^2x
	muls.w	X+2,d1	2x(x^3 + 4a^2 - a^2x)
	muls.w	#2,d1	2x(x^3 + 4a^2 - a^2x)
	move.l	X,d2	2x
	muls.w	d2,d2	2x
	move.l	#8,d3	a^2(8 - 2x)
	sub.l	d2,d3	a^2(8 - 2x)
	move.l	A,d2	a^2(8 - 2x)
	muls.w	d2,d2	a^2(8 - 2x)
	muls.w	d3,d2	a^2(8 - 2x)
	move.l	X,d3	2x^2
	muls.w	d3,d3	2x^2
	muls.w	#2,d3	2x^2
	add.l	d3,d2	2x^2 + a^2(8 - 2x)
	muls.w	X+2,d2	x(2x^2 + a^2(8 - 2x))
	sub.l	d2,d1	subtract right side of equation from left side to see if they are equal
	bne	end	if not equal goto end
	move.l	#1,d0	if equal set data register 1 to 1
end	break







X	dc.l	2
A	dc.l	4
	dc.l	end
