
;R7- return address

;R6- stack pointer

;R5- frame pointer

.ORIG x3000

    LD R1, N ; loading input N

    LD R6,STACK_POINTER ; loading stack pointer

	ADD R6,R6,#-1 ; decrementing stack pointer in preparation of a push

    STR R1,R6,#0 ; storing the local variable on the stack

	ADD R6,R6,#-1 ; return address

	STR R7,R6,#0

	ADD R6,R6,#-1 ; space for return value

	ADD R6,R6,#-1 ; space for callers frame pointer

	ADD R6,R6,#-1 ; space for local variable

    ADD R5,R6,#0 ; set frame pointer

    ADD R6,R6,#-1 ; space for pushing parameter for fibonacci function 

    STR R1,R6,#0 ; pushing paramenter for fibonacci function

	JSR Fibonacci

    LDR R4,R6,#0 ; getting return value from previous function call

	HALT



Fibonacci

    LDR R1,R6,#0 ; popping parameter

	ADD R6,R6,#-1 ; space for return value

	ADD R6,R6,#-1 ; space for return address

	STR R7,R6,#0 ; pushing return address of caller

	ADD R6,R6,#-1 ; space for callers frame pointer

	STR R5,R6,#0 ; pushing frame pointer of caller

	ADD R6,R6,#-1 ; space for local variable

	ADD R5,R6,#0 ; setting frame pointer

	ADD R6,R6,#-2 ; space for other 2 local variables

    ADD R1,R1,#0 ;checking parameter

    BRz return_zero

	ADD R1,R1,#-1; checking if parameter is 1

	BRz return_one    

	ADD R6,R6,#-1 ; making space for parameter on stack

	STR R1,R6,#0 ; pushing n-1 onto stack

	JSR Fibonacci

    LDR R1,R6,#0    ; getting the return value from the previous call (ADD CODE HERE)

    STR R1,R5,#-1	; storing the return value as a local variable (ADD CODE HERE)

    ADD R6,R6,#2	; popping off the return value and the parameter from the previous call (ADD CODE HERE)

    LDR R1,R5,#4   	; loading the parameter from the stack (ADD CODE HERE)

    ADD R1,R1,#-2   ; calculate n-2 (ADD CODE HERE)

    ADD R6,R6,#-1   ; creating space for parameter to next call (ADD CODE HERE)

    STR R1,R6,#0    ; pushing parameter for next call onto stack (ADD CODE HERE)

    JSR Fibonacci

	LDR R2,R6,#0 ; getting the return value from the previous call

	STR R2,R5,#-1 ; storing the return value as a local variable

	LDR R2,R5,#0 ; loading a return value stored as a local variable

	LDR R3,R5,#-1 ; loading a return value stored as a local variable

	ADD R4,R2,R3 ; adding the two

	STR R4,R5,#-2 ; storing it as a local variable

	STR R4,R5,#3 ; storing it as a return value

    ADD R6,R6,#2 ; popping of the return value and the parameter from the previous call

	ADD R6,R6,#3 ; popping of the 3 local variables

	LDR R7,R6,#1 ; restoring return address

	LDR R5,R6,#0 ; restoring callers frame pointer

	ADD R6,R6,#2 ; popping off return address and callers frame pointer

	RET











return_zero

   AND R2,R2,#0 ; return value should be 0

   ADD R6,R6,#3 ; popping off space for local variables

   LDR R7,R5,#2 ; loading return address into R7

   STR R2,R5,#3 ; storing return value onto stack

   LDR R5,R5,#1 ; restore callers frame pointer

   ADD R6,R6,#2 ; pop callers frame pointer and return address

   RET

return_one

   AND R2,R2,#0 ; return value should be 0

   ADD R2,R2,#1

   ADD R6,R6,#3 ; popping off space for local variables

   LDR R7,R5,#2 ; loading return address into R7

   STR R2,R5,#3 ; storing return value onto stack

   LDR R5,R5,#1 ; restore callers frame pointer

   ADD R6,R6,#2 ; pop callers frame pointer and return address

   RET



STACK_BASE .FILL x5000

STACK_POINTER .FILL x5000

N .FILL x6



.END

fibonacci_recursive.txt
Open with
Displaying fibonacci_recursive.txt.
