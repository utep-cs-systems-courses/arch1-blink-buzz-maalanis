/*	__attribute__
	.arch msp430g2553
	.p2align y0
	.text


	.global state_advance
	add &blink_mode, r12
	comp r12, #0,
	JNZ flip
	Mov power, r13
	comp r13, #0
	jnz off
	call sound_on
	jmp end
off:
	call sound_off
	jmp end
flip:
	call state_advance_flip
	jmp end

end:
	pop r0
	
*/
