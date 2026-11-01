/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* setjmp / longjmp for Lua's errors (lua/luaport.h LUAI_THROW): r0..r3 carry the arguments and are the
 * caller's, r4..r15 the callee's (as the compiler saves them), then sp and the return address. Main loop only. */
	.section .text.lj_setjmp,"ax",@progbits
	.balign 2
	.globl lj_setjmp
lj_setjmp:
	[r0+16] = r4
	[r0+20] = r5
	[r0+24] = r6
	[r0+28] = r7
	[r0+32] = r8
	[r0+36] = r9
	[r0+40] = r10
	[r0+44] = r11
	[r0+48] = r12
	[r0+52] = r13
	[r0+56] = r14
	[r0+60] = r15
	r1 = sp
	[r0+64] = r1
	r1 = rets
	[r0+68] = r1
	r0 = 0
	rts
	.section .text.lj_longjmp,"ax",@progbits
	.balign 2
	.globl lj_longjmp
lj_longjmp:
	r2 = [r0+68]
	rets = r2
	r2 = [r0+64]
	sp = r2
	r4 = [r0+16]
	r5 = [r0+20]
	r6 = [r0+24]
	r7 = [r0+28]
	r8 = [r0+32]
	r9 = [r0+36]
	r10 = [r0+40]
	r11 = [r0+44]
	r12 = [r0+48]
	r13 = [r0+52]
	r14 = [r0+56]
	r15 = [r0+60]
	r0 = r1
	rts
