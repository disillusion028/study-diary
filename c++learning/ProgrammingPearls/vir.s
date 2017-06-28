	.file	"vir.cc"
	.section	.text._ZN6PersonC2Ej,"axG",@progbits,_ZN6PersonC5Ej,comdat
	.align 2
	.weak	_ZN6PersonC2Ej
	.type	_ZN6PersonC2Ej, @function
_ZN6PersonC2Ej:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movl	$_ZTV6Person+16, %edx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	_ZN6PersonC2Ej, .-_ZN6PersonC2Ej
	.weak	_ZN6PersonC1Ej
	.set	_ZN6PersonC1Ej,_ZN6PersonC2Ej
	.section	.text._ZN6Person6getAgeEv,"axG",@progbits,_ZN6Person6getAgeEv,comdat
	.align 2
	.weak	_ZN6Person6getAgeEv
	.type	_ZN6Person6getAgeEv, @function
_ZN6Person6getAgeEv:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	_ZN6Person6getAgeEv, .-_ZN6Person6getAgeEv
	.section	.text._ZN3ManC2Ej,"axG",@progbits,_ZN3ManC5Ej,comdat
	.align 2
	.weak	_ZN3ManC2Ej
	.type	_ZN3ManC2Ej, @function
_ZN3ManC2Ej:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, %esi
	movq	%rax, %rdi
	call	_ZN6PersonC2Ej
	movl	$_ZTV3Man+16, %edx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, 12(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	_ZN3ManC2Ej, .-_ZN3ManC2Ej
	.weak	_ZN3ManC1Ej
	.set	_ZN3ManC1Ej,_ZN3ManC2Ej
	.section	.text._ZN3Man6getAgeEv,"axG",@progbits,_ZN3Man6getAgeEv,comdat
	.align 2
	.weak	_ZN3Man6getAgeEv
	.type	_ZN3Man6getAgeEv, @function
_ZN3Man6getAgeEv:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	12(%rax), %eax
	addl	$5, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	_ZN3Man6getAgeEv, .-_ZN3Man6getAgeEv
	.section	.text._ZN6PersonC2EOS_,"axG",@progbits,_ZN6PersonC5EOS_,comdat
	.align 2
	.weak	_ZN6PersonC2EOS_
	.type	_ZN6PersonC2EOS_, @function
_ZN6PersonC2EOS_:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$_ZTV6Person+16, %edx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-16(%rbp), %rax
	movl	8(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 8(%rax)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	_ZN6PersonC2EOS_, .-_ZN6PersonC2EOS_
	.weak	_ZN6PersonC1EOS_
	.set	_ZN6PersonC1EOS_,_ZN6PersonC2EOS_
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZN6PersonC1Ej
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6Person6getAgeEv
	movl	%eax, -72(%rbp)
	leaq	-32(%rbp), %rax
	movl	$10, %esi
	movq	%rax, %rdi
	call	_ZN3ManC1Ej
	leaq	-32(%rbp), %rdx
	leaq	-48(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN6PersonC1EOS_
	leaq	-48(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN6Person6getAgeEv
	movl	%eax, -68(%rbp)
	movl	$0, %eax
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L10
	call	__stack_chk_fail
.L10:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.weak	_ZTV3Man
	.section	.rodata._ZTV3Man,"aG",@progbits,_ZTV3Man,comdat
	.align 8
	.type	_ZTV3Man, @object
	.size	_ZTV3Man, 24
_ZTV3Man:
	.quad	0
	.quad	_ZTI3Man
	.quad	_ZN3Man6getAgeEv
	.weak	_ZTV6Person
	.section	.rodata._ZTV6Person,"aG",@progbits,_ZTV6Person,comdat
	.align 8
	.type	_ZTV6Person, @object
	.size	_ZTV6Person, 24
_ZTV6Person:
	.quad	0
	.quad	_ZTI6Person
	.quad	_ZN6Person6getAgeEv
	.weak	_ZTI3Man
	.section	.rodata._ZTI3Man,"aG",@progbits,_ZTI3Man,comdat
	.align 8
	.type	_ZTI3Man, @object
	.size	_ZTI3Man, 24
_ZTI3Man:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS3Man
	.quad	_ZTI6Person
	.weak	_ZTS3Man
	.section	.rodata._ZTS3Man,"aG",@progbits,_ZTS3Man,comdat
	.type	_ZTS3Man, @object
	.size	_ZTS3Man, 5
_ZTS3Man:
	.string	"3Man"
	.weak	_ZTI6Person
	.section	.rodata._ZTI6Person,"aG",@progbits,_ZTI6Person,comdat
	.align 8
	.type	_ZTI6Person, @object
	.size	_ZTI6Person, 16
_ZTI6Person:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS6Person
	.weak	_ZTS6Person
	.section	.rodata._ZTS6Person,"aG",@progbits,_ZTS6Person,comdat
	.align 8
	.type	_ZTS6Person, @object
	.size	_ZTS6Person, 8
_ZTS6Person:
	.string	"6Person"
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
