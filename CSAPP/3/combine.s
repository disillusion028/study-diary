	.file	"combine.c"
	.text
	.globl	new_vec
	.type	new_vec, @function
new_vec:
.LFB23:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbp
	movl	$16, %edi
	call	malloc
	testq	%rax, %rax
	je	.L4
	movq	%rax, %rbx
	movq	%rbp, (%rax)
	testq	%rbp, %rbp
	jle	.L5
	movl	$8, %esi
	movq	%rbp, %rdi
	call	calloc
	testq	%rax, %rax
	jne	.L3
	movq	%rbx, %rdi
	call	free
	movl	$0, %eax
	jmp	.L2
.L5:
	movl	$0, %eax
.L3:
	movq	%rax, 8(%rbx)
	movq	%rbx, %rax
	jmp	.L2
.L4:
	movl	$0, %eax
.L2:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	new_vec, .-new_vec
	.globl	get_vec_element
	.type	get_vec_element, @function
get_vec_element:
.LFB24:
	.cfi_startproc
	testq	%rsi, %rsi
	js	.L9
	movl	$0, %eax
	cmpq	(%rdi), %rsi
	jge	.L8
	movq	8(%rdi), %rax
	movq	(%rax,%rsi,8), %rax
	movq	%rax, (%rdx)
	movl	$1, %eax
	ret
.L9:
	movl	$0, %eax
.L8:
	rep ret
	.cfi_endproc
.LFE24:
	.size	get_vec_element, .-get_vec_element
	.globl	vec_length
	.type	vec_length, @function
vec_length:
.LFB25:
	.cfi_startproc
	movq	(%rdi), %rax
	ret
	.cfi_endproc
.LFE25:
	.size	vec_length, .-vec_length
	.globl	combine1
	.type	combine1, @function
combine1:
.LFB26:
	.cfi_startproc
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	subq	$16, %rsp
	.cfi_def_cfa_offset 48
	movq	%fs:40, %rax
	movq	%rax, 8(%rsp)
	xorl	%eax, %eax
	movq	$0, (%rsi)
	cmpq	$0, (%rdi)
	jle	.L12
	movq	%rdi, %rbp
	movq	%rsi, %r12
	movl	$0, %ebx
.L14:
	movq	%rsp, %rdx
	movq	%rbx, %rsi
	movq	%rbp, %rdi
	call	get_vec_element
	movq	(%r12), %rax
	imulq	(%rsp), %rax
	movq	%rax, (%r12)
	addq	$1, %rbx
	cmpq	0(%rbp), %rbx
	jl	.L14
.L12:
	movq	8(%rsp), %rax
	xorq	%fs:40, %rax
	je	.L15
	call	__stack_chk_fail
.L15:
	addq	$16, %rsp
	.cfi_def_cfa_offset 32
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE26:
	.size	combine1, .-combine1
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
