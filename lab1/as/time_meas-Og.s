	.file	"time_meas.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%s: %.10f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	movq	%rsi, %rbx
	movl	$1, %esi
	leaq	32(%rsp), %rdi
	call	timespec_get
	movl	$0, %eax
.L2:
	cmpq	$999999999, %rax
	ja	.L5
	addq	$1, %rax
	jmp	.L2
.L5:
	movl	$1, %esi
	leaq	16(%rsp), %rdi
	call	timespec_get
	movq	16(%rsp), %rax
	subq	32(%rsp), %rax
	movq	24(%rsp), %rdx
	subq	40(%rsp), %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	movapd	%xmm0, %xmm1
	mulsd	.LC0(%rip), %xmm1
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	addsd	%xmm1, %xmm0
	pxor	%xmm2, %xmm2
	cvtsd2ss	%xmm0, %xmm2
	movss	%xmm2, 12(%rsp)
	movl	$45, %esi
	movq	(%rbx), %rdi
	call	strrchr
	leaq	1(%rax), %rsi
	pxor	%xmm0, %xmm0
	cvtss2sd	12(%rsp), %xmm0
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	3894859413
	.long	1041313291
	.ident	"GCC: (GNU) 8.1.1 20180712 (Red Hat 8.1.1-5)"
	.section	.note.GNU-stack,"",@progbits
