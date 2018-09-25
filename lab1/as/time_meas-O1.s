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
	subq	$32, %rsp
	.cfi_def_cfa_offset 48
	movq	%rsi, %rbx
	movl	$1, %esi
	leaq	16(%rsp), %rdi
	call	timespec_get
	movl	$1000000000, %eax
.L2:
	subq	$1, %rax
	jne	.L2
	movl	$1, %esi
	movq	%rsp, %rdi
	call	timespec_get
	movl	$45, %esi
	movq	(%rbx), %rdi
	call	strrchr
	movq	8(%rsp), %rdx
	subq	24(%rsp), %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	mulsd	.LC0(%rip), %xmm0
	movq	(%rsp), %rdx
	subq	16(%rsp), %rdx
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rdx, %xmm1
	addsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	1(%rax), %rsi
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
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
