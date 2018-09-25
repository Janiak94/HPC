	.file	"time_meas.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%s: %.10f\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB11:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rsi, %rbx
	movl	$1, %esi
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	movq	%rsp, %rdi
	call	timespec_get
	leaq	16(%rsp), %rdi
	movl	$1, %esi
	call	timespec_get
	movq	(%rbx), %rdi
	movl	$45, %esi
	call	strrchr
	movq	24(%rsp), %rdx
	pxor	%xmm0, %xmm0
	subq	8(%rsp), %rdx
	cvtsi2sdq	%rdx, %xmm0
	pxor	%xmm1, %xmm1
	movq	16(%rsp), %rdx
	subq	(%rsp), %rdx
	cvtsi2sdq	%rdx, %xmm1
	leaq	1(%rax), %rsi
	movl	$.LC1, %edi
	movl	$1, %eax
	mulsd	.LC0(%rip), %xmm0
	addsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	printf
	xorl	%eax, %eax
	addq	$32, %rsp
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
