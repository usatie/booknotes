// clang -O3 -S non_volatil.c
/*
This produces the code below on my m1 macbookair. 
```
	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 1
	.globl	_wait_while_0                   ; -- Begin function wait_while_0
	.p2align	2
_wait_while_0:                          ; @wait_while_0
	.cfi_startproc
; %bb.0:
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
```

This is so different from the code of the book
```
wait_while_0:
	ldr w8, [x0]
	cbz w8, .LBB0_2	; if w8 == 0 then goto .LBB0_2
	ret
.LBB0_2:
	b	.LBB0_2		; goto .LBB0_2
```


On Linux VM, it produces equivalent x86 asm to the code of the book.
*/
void	wait_while_0(int *p) {
	while (*p == 0) {}
}
