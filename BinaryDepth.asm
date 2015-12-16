.ORIG x3000

HALT








MAX_DEPTH
    ; Build the activation record

    ADD R6,R6,#-4		;; R6 POINTS TO LOCAL VARIABLE
    STR R5,R6,#1		;; STORE IT IN OLD FRAME POINTER
    ADD R5,R6,#0 		;; R5 IS POINTING TO BOTTOMOST LOCAL VARIABLES

    STR R7,R5,#2		;; STORES R7 IN RETURN ADDRESS LOCATION
    ADD R6,R6,#-1 		;; MAKE SPACE FOR ANOTHER LOCAL VARIABLE
    ADD R6,R6,#-1		;; PLACE FOR SAVING REGISTERS
    STR R0,R6,#0		;; STORE R0 ABOVE
    ADD R6,R6,#-1		;; MOVE ABOVE
    STR R1,R6,#0		;; STORING R1 ABOVE R0
    ADD R6,R6,#-1		;; MAKE SPACE FOR R2
    STR R2,R6,#0		;; STORE R2 THERE

    AND R0,R0,#0
    AND R1,R1,#0
    AND R2,R2,#0

    STR R0,R5,#0		;; R5 POINTS TO LDEPTH (R0)
    STR R1,R5,#-1		;; R5 POINTS TO RDEPTH (R1)


PART_A

	LDR R0,R5,#4		;; LOAD THE PARAMETER INTO R0
	BRnp PART_B
	STR R1,R5,#3		;; RETURN 0
	BRnzp DONE


; IMPLEMENT ME!
; if (node == NULL) ;{
; return 0;
;}
;
; Note: If "return 0" is to be executed, set the return
; value to "0" and then jump/branch to DONE where the rest
; of the stack is torn down. Otherwise jump/branch to PART_B



PART_B

	ADD R6,R6,#-1
	LDR R0,R5,#4		;; NOW I HAVE ADDRESS OF THE NODE
	ADD R0,R0,#1		;; NODE->LEFT
	STR R0,R6,#0		;; STORE NEW PARAMETER
	JSR MAX_DEPTH
	LDR R1,R6,#0		;; GET RETURN VALUE FROM R6 STORE IN R1
	STR R1,R5,#0		;; STORE R1 IN LOCAL VARIABLE

	ADD R6,R6,#-1		;; MAKE PLACE FOR RIGHT CHILD
	ADD R0,R0,#1		;; GET RIGHT CHILD
	STR R0,R6,#0		;; NODE->RIGHT
	JSR MAX_DEPTH
	LDR R2,R6,#0		;; GET RETURN VALUE FROM R6 STORE IN R2
	STR R2,R5,#-1		;; STORE R2 IN LOCAL VARIABLE FOR RIGHT CHILD 


    ; IMPLEMENT ME!
    ; ldepth = max_depth(node->left);
    ; rdepth = max_depth(node->right);
    ;
; Note: You will need to set up the parameters for the
; recursive call and then JSR to MAX_DEPTH. Finally,
; read the return values and store in local variables as
; needed to implement C code.
PART_C

;; LDEPTH IS R0
;; RDEPTH IS R1

	NOT R0,R0
	ADD R0,R0,#1
	ADD R2,R1,R0
	BRzp PART_D        ;; CHECK LDEPTH > RDEPTH

	LDR R0,R5,#0
	ADD R0,R0,#1
	STR R0,R5,#3		;; STORE LDEPTH +1 IN RETURN VALUE
	BRnzp DONE






; IMPLEMENT ME!
; if (ldepth > rdepth) ;{
; return ldepth + 1; ;}
;
; Note: If this is to be executed, set the return value
; and jump/branch to DONE. Otherwise jump/branch to PART_D.
PART_D

	LDR R1,R5,#-1
	ADD R1,R1,#1
	STR R1,R5,#3
	BRnzp DONE




; IMPLEMENT ME! ; else
;{
; return rdepth + 1; ;}
;
; Note: Set return value and jump/branch to DONE.
DONE
; Teardown the activation record and return RET


LDR R6,R5,#3		;; R6 POINTS TO RETURN VALUE
LDR R7,R5,#2		;; RESTORE RETURN ADDRESS TO R7
LDR R5,R5,#1		;; RESTORE OLD FRAME POINTER


RET


.END
                                                 
