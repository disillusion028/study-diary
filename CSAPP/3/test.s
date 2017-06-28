	.text
	.file	"testllvm.bc"
	.globl	func
	.align	16, 0x90
	.type	func,@function
func:                                   # @func
	.cfi_startproc
# BB#0:
	leal	(%rdi,%rsi), %eax
	retq
.Lfunc_end0:
	.size	func, .Lfunc_end0-func
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rax
.Ltmp0:
	.cfi_def_cfa_offset 16
	movl	$.L.str, %edi
	movl	$15, %esi
	xorl	%eax, %eax
	callq	printf
	movl	$15, %eax
	popq	%rcx
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%d\n"
	.size	.L.str, 4


	.ident	"clang version 3.8.0-2ubuntu4 (tags/RELEASE_380/final)"
	.section	".note.GNU-stack","",@progbits
