	.file	"time_meas.c"
	.text
	.section	.rodata
.LC1:
	.string	"%s: %.10f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movl	%edi, -68(%rbp)
	movq	%rsi, -80(%rbp)
	movl	$0, -4(%rbp)
	leaq	-48(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	timespec_get
	movq	$0, -16(%rbp)
	jmp	.L2
.L3:
	movq	-16(%rbp), %rax
	movl	%eax, %edx
	movl	-4(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -4(%rbp)
	addq	$1, -16(%rbp)
.L2:
	cmpq	$999999999, -16(%rbp)
	jbe	.L3
	leaq	-64(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	timespec_get
	movq	-64(%rbp), %rdx
	movq	-48(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm1
	movq	-56(%rbp), %rdx
	movq	-40(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	cvtsi2sdq	%rax, %xmm2
	movsd	.LC0(%rip), %xmm0
	mulsd	%xmm2, %xmm0
	addsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm3
	movss	%xmm3, -20(%rbp)
	movq	-80(%rbp), %rax
	movq	(%rax), %rax
	movl	$45, %esi
	movq	%rax, %rdi
	call	strrchr
	addq	$1, %rax
	movq	%rax, -32(%rbp)
	cvtss2sd	-20(%rbp), %xmm0
	movq	-32(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	3894859413
	.long	1041313291
	.ident	"GCC: (GNU) 8.1.1 20180712 (Red Hat 8.1.1-5)"
	.section	.note.GNU-stack,"",@progbits
