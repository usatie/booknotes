.LBBO_1:
	ldr		w8, [x0]	; while (*x0 > 3)
	cmp		w8, 3
	b.hi	.LBBO_1
.Ltmp1:
	ldaxr	w2, [x0]	; w2 = [x0]
	cmp		w2, 0x4
	b.lo	.Ltmp2		; if (w2 < 4) then goto .Ltmp2
	clrex				; clear exclusive
	b		.LBBO_1		; goto LBBO_1
Ltmp2
	add		w2, w2, #1	; w2 = w2 + 1
	stlxr	w3, w2, [x0]; [x0] = w2, w3 = {if error}
	cbnz	w3, .Ltmp1	; if (w3 != 0) then goto .Ltmp1
	ret
