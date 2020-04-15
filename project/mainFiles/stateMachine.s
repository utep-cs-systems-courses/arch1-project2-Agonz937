
	.txt
jt:	.word option1		;jt[1]
	.word option2		;jt[2]
	.word option3 		;jt[3]
	.word option4		;jt[4]

	.global state_advance
state_advance:
	;;Range checker on selector (s)
	cmp #4, switch_state_advance ; s-4 doesn't borrow if s > 3
	jhs end			    ; exit the program

	;; index into jt
	mov switch_state_advance, r12 
	add r12, r12		;r12=*12
	mov jt(r12), r0

	;; Swith table options
	;; same order as in source code
option1: call #toggle_red
	jmp end
option2: call #toggle_green
	jmp end
option3: call #dim_red
	jmp end
option4: call #dim_green
	jmp end

end: pop r0			;exit from the method
	
