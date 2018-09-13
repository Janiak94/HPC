	.file	"time_meas.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%s: %.10f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	cmpl	$1, %edi
	jne	.L4
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$48, %rsp
	.cfi_def_cfa_offset 64
	movq	%rsi, %rbx
	movl	$1, %esi
	leaq	32(%rsp), %rdi
	call	timespec_get
	movl	$1000000000, %eax
.L3:
	subq	$1, %rax
	jne	.L3
	movl	$1, %esi
	leaq	16(%rsp), %rdi
	call	timespec_get
	movq	24(%rsp), %rax
	subq	40(%rsp), %rax
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	mulsd	.LC0(%rip), %xmm0
	movq	16(%rsp), %rax
	subq	32(%rsp), %rax
	pxor	%xmm1, %xmm1
	cvtsi2sdq	%rax, %xmm1
	addsd	%xmm1, %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movq	(%rbx), %rax
	movzwl	10(%rax), %edx
	movw	%dx, 14(%rsp)
	movzbl	12(%rax), %eax
	movb	%al, 16(%rsp)
	cvtss2sd	%xmm0, %xmm0
	leaq	14(%rsp), %rsi
	movl	$.LC1, %edi
	movl	$1, %eax
	call	printf
	movl	$0, %eax
	addq	$48, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
.L4:
	.cfi_restore 3
	movl	$-1, %eax
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	3894859413
	.long	1041313291
	.ident	"GCC: (GNU) 8.1.1 20180712 (Red Hat 8.1.1-5)"
	.section	.note.GNU-stack,"",@progbits
