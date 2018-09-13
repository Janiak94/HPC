	.file	"time_meas.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%s: %.10f\n"
	.section	.text.startup,"ax",@progbits
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	decl	%edi
	jne	.L4
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rsi, %rbx
	movl	$1, %esi
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	leaq	16(%rsp), %rdi
	call	timespec_get
	leaq	32(%rsp), %rdi
	movl	$1, %esi
	call	timespec_get
	movq	40(%rsp), %rax
	subq	24(%rsp), %rax
	leaq	14(%rsp), %rsi
	cvtsi2sdq	%rax, %xmm0
	movq	32(%rsp), %rax
	subq	16(%rsp), %rax
	movl	$.LC1, %edi
	mulsd	.LC0(%rip), %xmm0
	cvtsi2sdq	%rax, %xmm1
	movq	(%rbx), %rax
	movw	10(%rax), %dx
	movw	%dx, 14(%rsp)
	movb	12(%rax), %al
	addsd	%xmm1, %xmm0
	movb	%al, 16(%rsp)
	movb	$1, %al
	cvtsd2ss	%xmm0, %xmm0
	cvtss2sd	%xmm0, %xmm0
	call	printf
	xorl	%eax, %eax
	addq	$48, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore 3
	orl	$-1, %eax
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	3894859413
	.long	1041313291
	.ident	"GCC: (GNU) 8.1.1 20180712 (Red Hat 8.1.1-5)"
	.section	.note.GNU-stack,"",@progbits
