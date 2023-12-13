	.file	"main.cpp"
# GNU C++20 (GCC) version 12.2.0 (x86_64-unknown-linux-gnu)
#	compiled by GNU C version 12.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -Ofast -std=c++20
	.text
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB2307:
	.cfi_startproc
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 16
# /usr/include/c++/12.2/ostream:228: 	return _M_insert(static_cast<double>(__f));
	movsd	.LC0(%rip), %xmm0	#,
	leaq	_ZSt4cout(%rip), %rdi	#, tmp84
	call	_ZNSo9_M_insertIdEERSoT_@PLT	#
# main.cpp:31: int main() { std::cout << Q_rsqrt(1); }
	xorl	%eax, %eax	#
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE2307:
	.size	main, .-main
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB2954:
	.cfi_startproc
	pushq	%rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/c++/12.2/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rbx	#, tmp82
	movq	%rbx, %rdi	# tmp82,
	call	_ZNSt8ios_base4InitC1Ev@PLT	#
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rdi	#,
	movq	%rbx, %rsi	# tmp82,
# main.cpp:31: int main() { std::cout << Q_rsqrt(1); }
	popq	%rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/12.2/iostream:74:   static ios_base::Init __ioinit;
	leaq	__dso_handle(%rip), %rdx	#, tmp83
	jmp	__cxa_atexit@PLT	#
	.cfi_endproc
.LFE2954:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC0:
	.long	-536870912
	.long	1072689697
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
