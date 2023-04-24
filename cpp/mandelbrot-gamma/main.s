	.file	"main.cpp"
# GNU C++17 (GCC) version 12.2.0 (x86_64-unknown-linux-gnu)
#	compiled by GNU C version 12.2.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -Ofast
	.text
	.section	.text._ZNKSt5ctypeIcE8do_widenEc,"axG",@progbits,_ZNKSt5ctypeIcE8do_widenEc,comdat
	.align 2
	.p2align 4
	.weak	_ZNKSt5ctypeIcE8do_widenEc
	.type	_ZNKSt5ctypeIcE8do_widenEc, @function
_ZNKSt5ctypeIcE8do_widenEc:
.LFB2154:
	.cfi_startproc
# /usr/include/c++/12.2/bits/locale_facets.h:1092:       do_widen(char __c) const
	movl	%esi, %eax	# tmp87, __c
# /usr/include/c++/12.2/bits/locale_facets.h:1093:       { return __c; }
	ret	
	.cfi_endproc
.LFE2154:
	.size	_ZNKSt5ctypeIcE8do_widenEc, .-_ZNKSt5ctypeIcE8do_widenEc
	.section	.text._ZN12bitmap_imageD2Ev,"axG",@progbits,_ZN12bitmap_imageD5Ev,comdat
	.align 2
	.p2align 4
	.weak	_ZN12bitmap_imageD2Ev
	.type	_ZN12bitmap_imageD2Ev, @function
_ZN12bitmap_imageD2Ev:
.LFB9816:
	.cfi_startproc
	pushq	%rbx	#
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
# /usr/include/bitmap_image.hpp:37: class bitmap_image
	movq	%rdi, %rbx	# tmp96, this
# /usr/include/c++/12.2/bits/stl_vector.h:730: 	std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
	movq	56(%rdi), %rdi	# MEM[(struct vector *)this_1(D) + 56B].D.206349._M_impl.D.205698._M_start, _8
# /usr/include/c++/12.2/bits/stl_vector.h:386: 	if (__p)
	testq	%rdi, %rdi	# _8
	je	.L4	#,
# /usr/include/c++/12.2/bits/stl_vector.h:367: 		      _M_impl._M_end_of_storage - _M_impl._M_start);
	movq	72(%rbx), %rsi	# MEM[(struct _Vector_base *)this_1(D) + 56B]._M_impl.D.205698._M_end_of_storage, tmp91
	subq	%rdi, %rsi	# _8, tmp91
# /usr/include/c++/12.2/bits/new_allocator.h:158: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	call	_ZdlPvm@PLT	#
.L4:
# /usr/include/c++/12.2/bits/basic_string.h:234:       { return _M_dataplus._M_p; }
	movq	(%rbx), %rdi	# MEM[(const struct basic_string *)this_1(D)]._M_dataplus._M_p, _4
# /usr/include/c++/12.2/bits/basic_string.h:252: 	return std::pointer_traits<const_pointer>::pointer_to(*_M_local_buf);
	leaq	16(%rbx), %rax	#, tmp93
# /usr/include/c++/12.2/bits/basic_string.h:285: 	if (!_M_is_local())
	cmpq	%rax, %rdi	# tmp93, _4
	je	.L3	#,
# /usr/include/c++/12.2/bits/basic_string.h:292:       { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
	movq	16(%rbx), %rsi	# MEM[(struct basic_string *)this_1(D)].D.36870._M_allocated_capacity, MEM[(struct basic_string *)this_1(D)].D.36870._M_allocated_capacity
# /usr/include/bitmap_image.hpp:37: class bitmap_image
	popq	%rbx	#
	.cfi_remember_state
	.cfi_def_cfa_offset 8
# /usr/include/c++/12.2/bits/basic_string.h:292:       { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
	addq	$1, %rsi	#, tmp94
# /usr/include/c++/12.2/bits/new_allocator.h:158: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	jmp	_ZdlPvm@PLT	#
	.p2align 4,,10
	.p2align 3
.L3:
	.cfi_restore_state
# /usr/include/bitmap_image.hpp:37: class bitmap_image
	popq	%rbx	#
	.cfi_def_cfa_offset 8
	ret	
	.cfi_endproc
.LFE9816:
	.size	_ZN12bitmap_imageD2Ev, .-_ZN12bitmap_imageD2Ev
	.weak	_ZN12bitmap_imageD1Ev
	.set	_ZN12bitmap_imageD1Ev,_ZN12bitmap_imageD2Ev
	.section	.rodata._ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.str1.8,"aMS",@progbits,1
	.align 8
.LC0:
	.string	"bitmap_image::save_image(): Error - Could not open file "
	.section	.rodata._ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE.str1.1,"aMS",@progbits,1
.LC1:
	.string	" for writing!"
	.section	.text._ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"axG",@progbits,_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.align 2
	.p2align 4
	.weak	_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB9823:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA9823
	pushq	%r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	movq	%rsi, %r12	# tmp340, file_name
	pushq	%rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rdi, %rbx	# tmp339, this
	subq	$632, %rsp	#,
	.cfi_def_cfa_offset 688
# /usr/include/c++/12.2/bits/basic_string.h:234:       { return _M_dataplus._M_p; }
	movq	(%rsi), %r13	# MEM[(const struct basic_string *)file_name_32(D)]._M_dataplus._M_p, _65
# /usr/include/bitmap_image.hpp:431:    void save_image(const std::string& file_name) const
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp352
	movq	%rax, 616(%rsp)	# tmp352, D.235391
	xorl	%eax, %eax	# tmp352
# /usr/include/c++/12.2/bits/basic_ios.h:462: 	_M_streambuf(0), _M_ctype(0), _M_num_put(0), _M_num_get(0)
	leaq	344(%rsp), %r14	#, tmp334
	leaq	96(%rsp), %rbp	#, tmp336
	movq	%r14, %rdi	# tmp334,
	movq	%r14, 8(%rsp)	# tmp334, %sfp
	call	_ZNSt8ios_baseC2Ev@PLT	#
# /usr/include/c++/12.2/bits/basic_ios.h:462: 	_M_streambuf(0), _M_ctype(0), _M_num_put(0), _M_num_get(0)
	pxor	%xmm0, %xmm0	# tmp175
# /usr/include/c++/12.2/bits/basic_ios.h:461:       : ios_base(), _M_tie(0), _M_fill(char_type()), _M_fill_init(false), 
	xorl	%r8d, %r8d	#
# /usr/include/c++/12.2/ostream:385:       { this->init(0); }
	xorl	%esi, %esi	#
# /usr/include/c++/12.2/bits/basic_ios.h:462: 	_M_streambuf(0), _M_ctype(0), _M_num_put(0), _M_num_get(0)
	leaq	16+_ZTVSt9basic_iosIcSt11char_traitsIcEE(%rip), %rax	#, tmp356
# /usr/include/c++/12.2/bits/basic_ios.h:462: 	_M_streambuf(0), _M_ctype(0), _M_num_put(0), _M_num_get(0)
	movaps	%xmm0, 576(%rsp)	# tmp175, MEM <vector(2) long unsigned int> [(void *)&stream + 480B]
# /usr/include/c++/12.2/bits/basic_ios.h:462: 	_M_streambuf(0), _M_ctype(0), _M_num_put(0), _M_num_get(0)
	movq	%rax, 344(%rsp)	# tmp356, MEM[(struct basic_ios *)&stream + 248B].D.52332._vptr.ios_base
# /usr/include/c++/12.2/ostream:385:       { this->init(0); }
	movq	8+_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rax	# MEM[(const void * *)&_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE + 8B], tmp357
# /usr/include/c++/12.2/bits/basic_ios.h:461:       : ios_base(), _M_tie(0), _M_fill(char_type()), _M_fill_init(false), 
	movw	%r8w, 568(%rsp)	#, MEM <unsigned short> [(void *)&stream + 472B]
# /usr/include/c++/12.2/bits/basic_ios.h:462: 	_M_streambuf(0), _M_ctype(0), _M_num_put(0), _M_num_get(0)
	movaps	%xmm0, 592(%rsp)	# tmp175, MEM <vector(2) long unsigned int> [(void *)&stream + 496B]
# /usr/include/c++/12.2/ostream:385:       { this->init(0); }
	movq	-24(%rax), %rdi	# MEM[(long int *)_85 + -24B], _88
	movq	%rax, 96(%rsp)	# tmp357, MEM[(struct basic_ostream *)&stream]._vptr.basic_ostream
	movq	16+_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rax	# MEM[(const void * *)&_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE + 16B], tmp360
# /usr/include/c++/12.2/bits/basic_ios.h:461:       : ios_base(), _M_tie(0), _M_fill(char_type()), _M_fill_init(false), 
	movq	$0, 560(%rsp)	#, MEM[(struct basic_ios *)&stream + 248B]._M_tie
# /usr/include/c++/12.2/ostream:385:       { this->init(0); }
	addq	%rbp, %rdi	# tmp336, _88
	movq	%rax, (%rdi)	# tmp360, MEM[(struct basic_ios *)_88].D.52332._vptr.ios_base
.LEHB0:
# /usr/include/c++/12.2/ostream:385:       { this->init(0); }
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE4initEPSt15basic_streambufIcS1_E@PLT	#
.LEHE0:
# /usr/include/c++/12.2/fstream:797:       : __ostream_type(), _M_filebuf()
	leaq	24+_ZTVSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rax	#, tmp361
# /usr/include/c++/12.2/fstream:797:       : __ostream_type(), _M_filebuf()
	leaq	104(%rsp), %r15	#, tmp337
# /usr/include/c++/12.2/fstream:797:       : __ostream_type(), _M_filebuf()
	movq	%rax, 96(%rsp)	# tmp361, MEM[(struct basic_ofstream *)&stream].D.72273._vptr.basic_ostream
# /usr/include/c++/12.2/fstream:797:       : __ostream_type(), _M_filebuf()
	movq	%r15, %rdi	# tmp337,
# /usr/include/c++/12.2/fstream:797:       : __ostream_type(), _M_filebuf()
	addq	$40, %rax	#, tmp362
	movq	%rax, 344(%rsp)	# tmp362, MEM[(struct basic_ios *)&stream + 248B].D.52332._vptr.ios_base
.LEHB1:
# /usr/include/c++/12.2/fstream:797:       : __ostream_type(), _M_filebuf()
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEEC1Ev@PLT	#
.LEHE1:
# /usr/include/c++/12.2/fstream:799: 	this->init(&_M_filebuf);
	movq	%r15, %rsi	# tmp337,
	movq	%r14, %rdi	# tmp334,
.LEHB2:
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE4initEPSt15basic_streambufIcS1_E@PLT	#
# /usr/include/c++/12.2/fstream:928: 	if (!_M_filebuf.open(__s, __mode | ios_base::out))
	movl	$20, %edx	#,
	movq	%r13, %rsi	# _65,
	movq	%r15, %rdi	# tmp337,
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEE4openEPKcSt13_Ios_Openmode@PLT	#
# /usr/include/c++/12.2/fstream:929: 	  this->setstate(ios_base::failbit);
	movq	96(%rsp), %rdx	# stream.D.72273._vptr.basic_ostream, stream.D.72273._vptr.basic_ostream
	movq	-24(%rdx), %rdi	# MEM[(long int *)pretmp_164 + -24B], _174
	addq	%rbp, %rdi	# tmp336, _174
# /usr/include/c++/12.2/fstream:928: 	if (!_M_filebuf.open(__s, __mode | ios_base::out))
	testq	%rax, %rax	# tmp341
	je	.L43	#,
# /usr/include/c++/12.2/fstream:933: 	  this->clear();
	xorl	%esi, %esi	#
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT	#
.LEHE2:
.L12:
# /usr/include/bitmap_image.hpp:435:       if (!stream)
	testb	$5, 376(%rsp)	#, MEM[(const struct basic_ios *)&stream + 248B].D.52332._M_streambuf_state
	jne	.L44	#,
# /usr/include/bitmap_image.hpp:444:       bih.width            = width_;
	movl	32(%rbx), %eax	# this_36(D)->width_, _1
# /usr/include/bitmap_image.hpp:446:       bih.bit_count        = static_cast<unsigned short>(bytes_per_pixel_ << 3);
	movl	44(%rbx), %ecx	# this_36(D)->bytes_per_pixel_, _3
# /usr/include/bitmap_image.hpp:458:       bfh.type             = 19778;
	movl	$19778, %edi	#,
# /usr/include/bitmap_image.hpp:449:       bih.compression      = 0;
	movl	$0, 64(%rsp)	#, bih.compression
# /usr/include/bitmap_image.hpp:445:       bih.height           = height_;
	movl	36(%rbx), %edx	# this_36(D)->height_, _2
# /usr/include/bitmap_image.hpp:458:       bfh.type             = 19778;
	movw	%di, 32(%rsp)	#, bfh.type
# /usr/include/bitmap_image.hpp:1392:       stream.write(reinterpret_cast<const char*>(&t),sizeof(T));
	movq	%rbp, %rdi	# tmp336,
# /usr/include/bitmap_image.hpp:444:       bih.width            = width_;
	movl	%eax, 52(%rsp)	# _1, bih.width
# /usr/include/bitmap_image.hpp:454:       bih.size_image       = (((bih.width * bytes_per_pixel_) + 3) & 0x0000FFFC) * bih.height;
	imull	%ecx, %eax	# _3, tmp237
# /usr/include/bitmap_image.hpp:446:       bih.bit_count        = static_cast<unsigned short>(bytes_per_pixel_ << 3);
	leal	0(,%rcx,8), %esi	#, tmp236
	movw	%si, 62(%rsp)	# tmp236, bih.bit_count
# /usr/include/bitmap_image.hpp:450:       bih.planes           = 1;
	movl	$1, %esi	#,
# /usr/include/bitmap_image.hpp:445:       bih.height           = height_;
	movl	%edx, 56(%rsp)	# _2, bih.height
# /usr/include/bitmap_image.hpp:454:       bih.size_image       = (((bih.width * bytes_per_pixel_) + 3) & 0x0000FFFC) * bih.height;
	addl	$3, %eax	#, tmp238
# /usr/include/bitmap_image.hpp:450:       bih.planes           = 1;
	movw	%si, 60(%rsp)	#, bih.planes
# /usr/include/bitmap_image.hpp:1392:       stream.write(reinterpret_cast<const char*>(&t),sizeof(T));
	leaq	32(%rsp), %rsi	#, tmp242
# /usr/include/bitmap_image.hpp:454:       bih.size_image       = (((bih.width * bytes_per_pixel_) + 3) & 0x0000FFFC) * bih.height;
	andl	$65532, %eax	#, tmp239
# /usr/include/bitmap_image.hpp:451:       bih.size             = bih.struct_size();
	movl	$40, 48(%rsp)	#, bih.size
# /usr/include/bitmap_image.hpp:452:       bih.x_pels_per_meter = 0;
	movq	$0, 72(%rsp)	#, MEM <unsigned long> [(unsigned int *)&bih + 24B]
# /usr/include/bitmap_image.hpp:454:       bih.size_image       = (((bih.width * bytes_per_pixel_) + 3) & 0x0000FFFC) * bih.height;
	imull	%edx, %eax	# _2, _9
# /usr/include/bitmap_image.hpp:1392:       stream.write(reinterpret_cast<const char*>(&t),sizeof(T));
	movl	$2, %edx	#,
# /usr/include/bitmap_image.hpp:448:       bih.clr_used         = 0;
	movq	$0, 80(%rsp)	#, MEM <unsigned long> [(unsigned int *)&bih + 32B]
# /usr/include/bitmap_image.hpp:454:       bih.size_image       = (((bih.width * bytes_per_pixel_) + 3) & 0x0000FFFC) * bih.height;
	movl	%eax, 68(%rsp)	# _9, bih.size_image
# /usr/include/bitmap_image.hpp:459:       bfh.size             = bfh.struct_size() + bih.struct_size() + bih.size_image;
	addl	$54, %eax	#, tmp240
	movl	%eax, 36(%rsp)	# tmp240, bfh.size
# /usr/include/bitmap_image.hpp:460:       bfh.reserved1        = 0;
	movabsq	$231928233984, %rax	#, tmp378
	movq	%rax, 40(%rsp)	# tmp378, MEM <unsigned long> [(void *)&bfh + 8B]
.LEHB3:
# /usr/include/bitmap_image.hpp:1392:       stream.write(reinterpret_cast<const char*>(&t),sizeof(T));
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	36(%rsp), %rsi	#, tmp245
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	40(%rsp), %rsi	#, tmp248
	movl	$2, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	42(%rsp), %rsi	#, tmp251
	movl	$2, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	44(%rsp), %rsi	#, tmp254
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	48(%rsp), %rsi	#, tmp256
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	52(%rsp), %rsi	#, tmp259
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	56(%rsp), %rsi	#, tmp262
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	60(%rsp), %rsi	#, tmp265
	movl	$2, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	62(%rsp), %rsi	#, tmp268
	movl	$2, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	64(%rsp), %rsi	#, tmp271
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	68(%rsp), %rsi	#, tmp274
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	72(%rsp), %rsi	#, tmp277
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	76(%rsp), %rsi	#, tmp280
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	80(%rsp), %rsi	#, tmp283
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
	leaq	84(%rsp), %rsi	#, tmp286
	movl	$4, %edx	#,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
# /usr/include/bitmap_image.hpp:467:       unsigned int padding = (4 - ((3 * width_) % 4)) % 4;
	movl	32(%rbx), %eax	# this_36(D)->width_,
# /usr/include/bitmap_image.hpp:470:       for (unsigned int i = 0; i < height_; ++i)
	movl	36(%rbx), %esi	# this_36(D)->height_, _26
# /usr/include/bitmap_image.hpp:468:       char padding_data[4] = { 0x00, 0x00, 0x00, 0x00 };
	movl	$0, 612(%rsp)	#, padding_data
# /usr/include/bitmap_image.hpp:467:       unsigned int padding = (4 - ((3 * width_) % 4)) % 4;
	leal	(%rax,%rax,2), %r13d	#, tmp290
# /usr/include/bitmap_image.hpp:467:       unsigned int padding = (4 - ((3 * width_) % 4)) % 4;
	negl	%r13d	# tmp291
# /usr/include/bitmap_image.hpp:467:       unsigned int padding = (4 - ((3 * width_) % 4)) % 4;
	andl	$3, %r13d	#, padding
# /usr/include/bitmap_image.hpp:470:       for (unsigned int i = 0; i < height_; ++i)
	testl	%esi, %esi	# _26
	je	.L24	#,
# /usr/include/bitmap_image.hpp:470:       for (unsigned int i = 0; i < height_; ++i)
	xorl	%r12d, %r12d	# i
# /usr/include/bitmap_image.hpp:475:          stream.write(padding_data,padding);
	leaq	612(%rsp), %r14	#, tmp338
	jmp	.L25	#
	.p2align 4,,10
	.p2align 3
.L45:
# /usr/include/bitmap_image.hpp:474:          stream.write(reinterpret_cast<const char*>(data_ptr), sizeof(unsigned char) * bytes_per_pixel_ * width_);
	movl	32(%rbx), %eax	# this_36(D)->width_,
.L25:
# /usr/include/bitmap_image.hpp:474:          stream.write(reinterpret_cast<const char*>(data_ptr), sizeof(unsigned char) * bytes_per_pixel_ * width_);
	movl	44(%rbx), %edx	# this_36(D)->bytes_per_pixel_, this_36(D)->bytes_per_pixel_
# /usr/include/bitmap_image.hpp:472:          const unsigned char* data_ptr = &data_[(row_increment_ * (height_ - i - 1))];
	subl	%r12d, %esi	# i, tmp295
# /usr/include/bitmap_image.hpp:474:          stream.write(reinterpret_cast<const char*>(data_ptr), sizeof(unsigned char) * bytes_per_pixel_ * width_);
	movq	%rbp, %rdi	# tmp336,
# /usr/include/bitmap_image.hpp:472:          const unsigned char* data_ptr = &data_[(row_increment_ * (height_ - i - 1))];
	subl	$1, %esi	#, tmp296
# /usr/include/bitmap_image.hpp:472:          const unsigned char* data_ptr = &data_[(row_increment_ * (height_ - i - 1))];
	imull	40(%rbx), %esi	# this_36(D)->row_increment_, tmp298
# /usr/include/c++/12.2/bits/stl_vector.h:1143: 	return *(this->_M_impl._M_start + __n);
	addq	56(%rbx), %rsi	# MEM[(const struct vector *)this_36(D) + 56B].D.206349._M_impl.D.205698._M_start, tmp299
# /usr/include/bitmap_image.hpp:474:          stream.write(reinterpret_cast<const char*>(data_ptr), sizeof(unsigned char) * bytes_per_pixel_ * width_);
	imulq	%rax, %rdx	# pretmp_159, tmp294
# /usr/include/bitmap_image.hpp:474:          stream.write(reinterpret_cast<const char*>(data_ptr), sizeof(unsigned char) * bytes_per_pixel_ * width_);
	call	_ZNSo5writeEPKcl@PLT	#
# /usr/include/bitmap_image.hpp:475:          stream.write(padding_data,padding);
	movl	%r13d, %edx	# padding, padding
	movq	%r14, %rsi	# tmp338,
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSo5writeEPKcl@PLT	#
# /usr/include/bitmap_image.hpp:470:       for (unsigned int i = 0; i < height_; ++i)
	movl	36(%rbx), %esi	# this_36(D)->height_, _26
# /usr/include/bitmap_image.hpp:470:       for (unsigned int i = 0; i < height_; ++i)
	addl	$1, %r12d	#, i
# /usr/include/bitmap_image.hpp:470:       for (unsigned int i = 0; i < height_; ++i)
	cmpl	%esi, %r12d	# _26, i
	jb	.L45	#,
.L24:
# /usr/include/c++/12.2/fstream:1000: 	if (!_M_filebuf.close())
	movq	%r15, %rdi	# tmp337,
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT	#
.LEHE3:
	movq	.LC2(%rip), %xmm1	#, _72
	leaq	16+_ZTVSt13basic_filebufIcSt11char_traitsIcEE(%rip), %rdx	#, tmp308
	movq	%rdx, %xmm3	# tmp308, tmp308
	punpcklqdq	%xmm3, %xmm1	# tmp308, _72
	movaps	%xmm1, 16(%rsp)	# _72, %sfp
# /usr/include/c++/12.2/fstream:1000: 	if (!_M_filebuf.close())
	testq	%rax, %rax	# tmp349
	je	.L46	#,
.L26:
# /usr/include/c++/12.2/fstream:868:       { }
	movdqa	16(%rsp), %xmm4	# %sfp, _72
	leaq	64+_ZTVSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rax	#, tmp383
# /usr/include/c++/12.2/fstream:254: 	  { this->close(); }
	movq	%r15, %rdi	# tmp337,
# /usr/include/c++/12.2/fstream:868:       { }
	movq	%rax, 344(%rsp)	# tmp383, MEM[(struct basic_ios *)&stream + 248B].D.52332._vptr.ios_base
	movaps	%xmm4, 96(%rsp)	# _72, MEM <vector(2) long unsigned int> [(int (*) () * *)&stream]
.LEHB4:
# /usr/include/c++/12.2/fstream:254: 	  { this->close(); }
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT	#
.LEHE4:
.L28:
# /usr/include/c++/12.2/fstream:257:       }
	leaq	208(%rsp), %rdi	#, tmp319
	call	_ZNSt12__basic_fileIcED1Ev@PLT	#
# /usr/include/c++/12.2/streambuf:203:       { }
	leaq	16+_ZTVSt15basic_streambufIcSt11char_traitsIcEE(%rip), %rax	#, tmp385
	leaq	160(%rsp), %rdi	#, tmp322
	movq	%rax, 104(%rsp)	# tmp385, MEM[(struct basic_streambuf *)&stream + 8B]._vptr.basic_streambuf
	call	_ZNSt6localeD1Ev@PLT	#
# /usr/include/c++/12.2/ostream:93:       ~basic_ostream() { }
	movq	8+_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rax	# MEM[(const void * *)&_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE + 8B], tmp386
# /usr/include/c++/12.2/bits/basic_ios.h:282:       ~basic_ios() { }
	movq	8(%rsp), %rdi	# %sfp,
# /usr/include/c++/12.2/ostream:93:       ~basic_ostream() { }
	movq	16+_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rcx	# MEM[(const void * *)&_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE + 16B], tmp388
	movq	%rax, 96(%rsp)	# tmp386, MEM[(struct basic_ostream *)&stream]._vptr.basic_ostream
	movq	-24(%rax), %rax	# MEM[(long int *)_85 + -24B], MEM[(long int *)_85 + -24B]
	movq	%rcx, 96(%rsp,%rax)	# tmp388,
# /usr/include/c++/12.2/bits/basic_ios.h:282:       ~basic_ios() { }
	leaq	16+_ZTVSt9basic_iosIcSt11char_traitsIcEE(%rip), %rax	#, tmp389
	movq	%rax, 344(%rsp)	# tmp389, MEM[(struct basic_ios *)&stream + 248B].D.52332._vptr.ios_base
	call	_ZNSt8ios_baseD2Ev@PLT	#
# /usr/include/bitmap_image.hpp:479:    }
	movq	616(%rsp), %rax	# D.235391, tmp353
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp353
	jne	.L47	#,
	addq	$632, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L44:
	.cfi_restore_state
# /usr/include/c++/12.2/ostream:620: 	__ostream_insert(__out, __s,
	leaq	_ZSt4cerr(%rip), %rbx	#, tmp333
	movl	$56, %edx	#,
	leaq	.LC0(%rip), %rsi	#, tmp210
	movq	%rbx, %rdi	# tmp333,
.LEHB5:
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
# /usr/include/c++/12.2/bits/basic_string.h:3888:       return __ostream_insert(__os, __str.data(), __str.size());
	movq	8(%r12), %rdx	# MEM[(const struct basic_string *)file_name_32(D)]._M_string_length, MEM[(const struct basic_string *)file_name_32(D)]._M_string_length
	movq	(%r12), %rsi	# MEM[(const struct basic_string *)file_name_32(D)]._M_dataplus._M_p, MEM[(const struct basic_string *)file_name_32(D)]._M_dataplus._M_p
	movq	%rbx, %rdi	# tmp333,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
# /usr/include/c++/12.2/ostream:620: 	__ostream_insert(__out, __s,
	movl	$13, %edx	#,
	leaq	.LC1(%rip), %rsi	#, tmp215
	movq	%rax, %rdi	# _76,
# /usr/include/c++/12.2/bits/basic_string.h:3888:       return __ostream_insert(__os, __str.data(), __str.size());
	movq	%rax, %rbx	# tmp345, _76
# /usr/include/c++/12.2/ostream:620: 	__ostream_insert(__out, __s,
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l@PLT	#
# /usr/include/c++/12.2/ostream:689:     { return flush(__os.put(__os.widen('\n'))); }
	movq	(%rbx), %rax	# _76->_vptr.basic_ostream, _76->_vptr.basic_ostream
	movq	-24(%rax), %rax	# MEM[(long int *)_109 + -24B], MEM[(long int *)_109 + -24B]
	movq	240(%rbx,%rax), %r12	# MEM[(const struct __ctype_type * *)_112 + 240B], _117
# /usr/include/c++/12.2/bits/basic_ios.h:49:       if (!__f)
	testq	%r12, %r12	# _117
	je	.L48	#,
# /usr/include/c++/12.2/bits/locale_facets.h:882: 	if (_M_widen_ok)
	cmpb	$0, 56(%r12)	#, MEM[(const struct ctype *)_117]._M_widen_ok
	je	.L19	#,
# /usr/include/c++/12.2/ostream:689:     { return flush(__os.put(__os.widen('\n'))); }
	movsbl	67(%r12), %esi	# MEM[(const struct ctype *)_117]._M_widen[10], _161
.L20:
	movq	%rbx, %rdi	# _76,
	call	_ZNSo3putEc@PLT	#
	movq	.LC2(%rip), %xmm2	#, _176
	movq	%rax, %rdi	# tmp347, _115
	leaq	16+_ZTVSt13basic_filebufIcSt11char_traitsIcEE(%rip), %rax	#, tmp221
	movq	%rax, %xmm5	# tmp221, tmp221
	punpcklqdq	%xmm5, %xmm2	# tmp221, _176
	movaps	%xmm2, 16(%rsp)	# _176, %sfp
# /usr/include/c++/12.2/ostream:711:     { return __os.flush(); }
	call	_ZNSo5flushEv@PLT	#
.LEHE5:
# /usr/include/c++/12.2/fstream:868:       { }
	movdqa	16(%rsp), %xmm2	# %sfp, _176
	leaq	64+_ZTVSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rax	#, tmp371
# /usr/include/c++/12.2/fstream:254: 	  { this->close(); }
	movq	%r15, %rdi	# tmp337,
# /usr/include/c++/12.2/fstream:868:       { }
	movq	%rax, 344(%rsp)	# tmp371, MEM[(struct basic_ios *)&stream + 248B].D.52332._vptr.ios_base
	movaps	%xmm2, 96(%rsp)	# _176, MEM <vector(2) long unsigned int> [(int (*) () * *)&stream]
.LEHB6:
# /usr/include/c++/12.2/fstream:254: 	  { this->close(); }
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEE5closeEv@PLT	#
.LEHE6:
	jmp	.L28	#
	.p2align 4,,10
	.p2align 3
.L43:
# /usr/include/c++/12.2/bits/ios_base.h:171:   { return _Ios_Iostate(static_cast<int>(__a) | static_cast<int>(__b)); }
	movl	32(%rdi), %esi	# MEM[(const struct basic_ios *)_174].D.52332._M_streambuf_state, tmp194
	orl	$4, %esi	#, tmp194
.LEHB7:
# /usr/include/c++/12.2/bits/basic_ios.h:158:       { this->clear(this->rdstate() | __state); }
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT	#
.LEHE7:
	jmp	.L12	#
	.p2align 4,,10
	.p2align 3
.L19:
# /usr/include/c++/12.2/bits/locale_facets.h:884: 	this->_M_widen_init();
	movq	%r12, %rdi	# _117,
.LEHB8:
	call	_ZNKSt5ctypeIcE13_M_widen_initEv@PLT	#
# /usr/include/c++/12.2/bits/locale_facets.h:885: 	return this->do_widen(__c);
	movq	(%r12), %rax	# MEM[(const struct ctype *)_117].D.48851._vptr.facet, MEM[(const struct ctype *)_117].D.48851._vptr.facet
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rdx	#, tmp219
	movl	$10, %esi	#, _161
	movq	48(%rax), %rax	# MEM[(int (*) () *)_127 + 48B], _128
	cmpq	%rdx, %rax	# tmp219, _128
	je	.L20	#,
	movq	%r12, %rdi	# _117,
	call	*%rax	# _128
# /usr/include/c++/12.2/ostream:689:     { return flush(__os.put(__os.widen('\n'))); }
	movsbl	%al, %esi	# tmp346, _161
	jmp	.L20	#
	.p2align 4,,10
	.p2align 3
.L46:
# /usr/include/c++/12.2/fstream:929: 	  this->setstate(ios_base::failbit);
	movq	96(%rsp), %rax	# stream.D.72273._vptr.basic_ostream, stream.D.72273._vptr.basic_ostream
	movq	-24(%rax), %rdi	# MEM[(long int *)_168 + -24B], _171
	addq	%rbp, %rdi	# tmp336, _171
# /usr/include/c++/12.2/bits/ios_base.h:171:   { return _Ios_Iostate(static_cast<int>(__a) | static_cast<int>(__b)); }
	movl	32(%rdi), %esi	# MEM[(const struct basic_ios *)_171].D.52332._M_streambuf_state, tmp313
	orl	$4, %esi	#, tmp313
# /usr/include/c++/12.2/bits/basic_ios.h:158:       { this->clear(this->rdstate() | __state); }
	call	_ZNSt9basic_iosIcSt11char_traitsIcEE5clearESt12_Ios_Iostate@PLT	#
# /usr/include/c++/12.2/bits/basic_ios.h:158:       { this->clear(this->rdstate() | __state); }
	jmp	.L26	#
.L47:
# /usr/include/bitmap_image.hpp:479:    }
	call	__stack_chk_fail@PLT	#
.L48:
# /usr/include/c++/12.2/bits/basic_ios.h:50: 	__throw_bad_cast();
	call	_ZSt16__throw_bad_castv@PLT	#
.LEHE8:
.L32:
# /usr/include/bitmap_image.hpp:479:    }
	movq	%rax, %rbx	# tmp351, tmp329
	jmp	.L29	#
.L37:
# /usr/include/c++/12.2/fstream:255: 	__catch(...)
	movq	%rax, %rdi	# tmp350, tmp327
	jmp	.L27	#
.L29:
# /usr/include/bitmap_image.hpp:479:    }
	movq	%rbp, %rdi	# tmp336,
	call	_ZNSt14basic_ofstreamIcSt11char_traitsIcEED1Ev@PLT	#
	movq	%rbx, %rdi	# tmp329,
.LEHB9:
	call	_Unwind_Resume@PLT	#
.LEHE9:
.L27:
# /usr/include/c++/12.2/fstream:255: 	__catch(...)
	call	__cxa_begin_catch@PLT	#
	call	__cxa_end_catch@PLT	#
	jmp	.L28	#
.L36:
	movq	%rax, %rdi	# tmp348, tmp235
	jmp	.L22	#
.L34:
# /usr/include/c++/12.2/ostream:93:       ~basic_ostream() { }
	movq	%rax, %rbx	# tmp343, tmp200
	jmp	.L16	#
.L22:
# /usr/include/c++/12.2/fstream:255: 	__catch(...)
	call	__cxa_begin_catch@PLT	#
	call	__cxa_end_catch@PLT	#
	jmp	.L28	#
.L15:
# /usr/include/c++/12.2/fstream:801:       }
	movq	%r15, %rdi	# tmp337,
	call	_ZNSt13basic_filebufIcSt11char_traitsIcEED1Ev@PLT	#
.L16:
# /usr/include/c++/12.2/ostream:93:       ~basic_ostream() { }
	movq	8+_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rax	# MEM[(const void * *)&_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE + 8B], tmp365
	movq	16+_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE(%rip), %rcx	# MEM[(const void * *)&_ZTTSt14basic_ofstreamIcSt11char_traitsIcEE + 16B], tmp367
	movq	%rax, 96(%rsp)	# tmp365, MEM[(struct basic_ostream *)&stream]._vptr.basic_ostream
	movq	-24(%rax), %rax	# MEM[(long int *)_85 + -24B], MEM[(long int *)_85 + -24B]
	movq	%rcx, 96(%rsp,%rax)	# tmp367, MEM[(struct basic_ios *)_95].D.52332._vptr.ios_base
.L17:
# /usr/include/c++/12.2/bits/basic_ios.h:282:       ~basic_ios() { }
	movq	8(%rsp), %rdi	# %sfp,
	leaq	16+_ZTVSt9basic_iosIcSt11char_traitsIcEE(%rip), %rax	#, tmp368
	movq	%rax, 344(%rsp)	# tmp368, MEM[(struct basic_ios *)&stream + 248B].D.52332._vptr.ios_base
	call	_ZNSt8ios_baseD2Ev@PLT	#
	movq	%rbx, %rdi	# tmp205,
.LEHB10:
	call	_Unwind_Resume@PLT	#
.LEHE10:
.L33:
	movq	%rax, %rbx	# tmp344, tmp205
	jmp	.L17	#
.L35:
# /usr/include/c++/12.2/fstream:801:       }
	movq	%rax, %rbx	# tmp342, tmp201
	jmp	.L15	#
	.cfi_endproc
.LFE9823:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table._ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"aG",@progbits,_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.align 4
.LLSDA9823:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT9823-.LLSDATTD9823
.LLSDATTD9823:
	.byte	0x1
	.uleb128 .LLSDACSE9823-.LLSDACSB9823
.LLSDACSB9823:
	.uleb128 .LEHB0-.LFB9823
	.uleb128 .LEHE0-.LEHB0
	.uleb128 .L33-.LFB9823
	.uleb128 0
	.uleb128 .LEHB1-.LFB9823
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L34-.LFB9823
	.uleb128 0
	.uleb128 .LEHB2-.LFB9823
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L35-.LFB9823
	.uleb128 0
	.uleb128 .LEHB3-.LFB9823
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L32-.LFB9823
	.uleb128 0
	.uleb128 .LEHB4-.LFB9823
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L37-.LFB9823
	.uleb128 0x1
	.uleb128 .LEHB5-.LFB9823
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L32-.LFB9823
	.uleb128 0
	.uleb128 .LEHB6-.LFB9823
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L36-.LFB9823
	.uleb128 0x1
	.uleb128 .LEHB7-.LFB9823
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L35-.LFB9823
	.uleb128 0
	.uleb128 .LEHB8-.LFB9823
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L32-.LFB9823
	.uleb128 0
	.uleb128 .LEHB9-.LFB9823
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB10-.LFB9823
	.uleb128 .LEHE10-.LEHB10
	.uleb128 0
	.uleb128 0
.LLSDACSE9823:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT9823:
	.section	.text._ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,"axG",@progbits,_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE,comdat
	.size	_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.rodata._ZNSt6vectorIhSaIhEE17_M_default_appendEm.str1.1,"aMS",@progbits,1
.LC3:
	.string	"vector::_M_default_append"
	.section	.text._ZNSt6vectorIhSaIhEE17_M_default_appendEm,"axG",@progbits,_ZNSt6vectorIhSaIhEE17_M_default_appendEm,comdat
	.align 2
	.p2align 4
	.weak	_ZNSt6vectorIhSaIhEE17_M_default_appendEm
	.type	_ZNSt6vectorIhSaIhEE17_M_default_appendEm, @function
_ZNSt6vectorIhSaIhEE17_M_default_appendEm:
.LFB11318:
	.cfi_startproc
# /usr/include/c++/12.2/bits/vector.tcc:629:       if (__n != 0)
	testq	%rsi, %rsi	# __n
	je	.L73	#,
# /usr/include/c++/12.2/bits/vector.tcc:635: 	  if (__size > max_size() || __navail > max_size() - __size)
	movabsq	$9223372036854775807, %rdx	#, tmp113
# /usr/include/c++/12.2/bits/vector.tcc:626:     vector<_Tp, _Alloc>::
	pushq	%r15	#
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14	#
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
# /usr/include/c++/12.2/bits/vector.tcc:635: 	  if (__size > max_size() || __navail > max_size() - __size)
	movq	%rdx, %rcx	# tmp113, tmp113
# /usr/include/c++/12.2/bits/vector.tcc:626:     vector<_Tp, _Alloc>::
	pushq	%r13	#
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	movq	%rdi, %r13	# tmp132, this
	pushq	%r12	#
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	pushq	%rbp	#
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	pushq	%rbx	#
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	movq	%rsi, %rbx	# tmp133, __n
	subq	$8, %rsp	#,
	.cfi_def_cfa_offset 64
# /usr/include/c++/12.2/bits/stl_vector.h:988:       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
	movq	8(%rdi), %rax	# MEM[(const struct vector *)this_16(D)].D.206349._M_impl.D.205698._M_finish, _23
# /usr/include/c++/12.2/bits/vector.tcc:633: 					 - this->_M_impl._M_finish);
	movq	16(%rdi), %rdx	# this_16(D)->D.206349._M_impl.D.205698._M_end_of_storage, __navail
# /usr/include/c++/12.2/bits/stl_vector.h:988:       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
	movq	%rax, %rbp	# _23, _19
# /usr/include/c++/12.2/bits/vector.tcc:633: 					 - this->_M_impl._M_finish);
	subq	%rax, %rdx	# _23, __navail
# /usr/include/c++/12.2/bits/stl_vector.h:988:       { return size_type(this->_M_impl._M_finish - this->_M_impl._M_start); }
	subq	(%rdi), %rbp	# MEM[(const struct vector *)this_16(D)].D.206349._M_impl.D.205698._M_start, _19
# /usr/include/c++/12.2/bits/vector.tcc:635: 	  if (__size > max_size() || __navail > max_size() - __size)
	subq	%rbp, %rcx	# _19, tmp113
# /usr/include/c++/12.2/bits/vector.tcc:638: 	  if (__navail >= __n)
	cmpq	%rsi, %rdx	# __n, __navail
	jnb	.L76	#,
# /usr/include/c++/12.2/bits/stl_vector.h:1893: 	if (max_size() - size() < __n)
	cmpq	%rsi, %rcx	# __n, _3
	jb	.L77	#,
	movabsq	$9223372036854775807, %r15	#, tmp136
# /usr/include/c++/12.2/bits/stl_vector.h:1896: 	const size_type __len = size() + (std::max)(size(), __n);
	leaq	(%rsi,%rbp), %r12	#, _93
	cmpq	%r15, %r12	# tmp136, _93
	cmovbe	%r12, %r15	# _93,, _34
# /usr/include/c++/12.2/bits/stl_algobase.h:259:       if (__a < __b)
	cmpq	%rsi, %rbp	# __n, _19
	jb	.L55	#,
	movabsq	$9223372036854775807, %rax	#, tmp135
# /usr/include/c++/12.2/bits/stl_vector.h:1896: 	const size_type __len = size() + (std::max)(size(), __n);
	leaq	(%rbp,%rbp), %r15	#, _34
	cmpq	%rax, %r15	# tmp135, _34
	cmova	%rax, %r15	# _34,, tmp135, _34
.L55:
# /usr/include/c++/12.2/bits/new_allocator.h:137: 	return static_cast<_Tp*>(_GLIBCXX_OPERATOR_NEW(__n * sizeof(_Tp)));
	movq	%r15, %rdi	# _34,
	call	_Znwm@PLT	#
# /usr/include/c++/12.2/bits/vector.tcc:655: 		      std::__uninitialized_default_n_a(__new_start + __size,
	addq	%rax, %rbp	# _35, _4
# /usr/include/c++/12.2/bits/new_allocator.h:137: 	return static_cast<_Tp*>(_GLIBCXX_OPERATOR_NEW(__n * sizeof(_Tp)));
	movq	%rax, %r14	# tmp134, _35
# /usr/include/c++/12.2/bits/stl_construct.h:119:       ::new((void*)__p) _Tp(std::forward<_Args>(__args)...);
	movb	$0, 0(%rbp)	#, *_4
# /usr/include/c++/12.2/bits/stl_algobase.h:1114:       if (__n <= 0)
	subq	$1, %rbx	#, _65
	jne	.L78	#,
# /usr/include/c++/12.2/bits/vector.tcc:663: 		  _S_relocate(this->_M_impl._M_start, this->_M_impl._M_finish,
	movq	0(%r13), %rbx	# this_16(D)->D.206349._M_impl.D.205698._M_start, _6
# /usr/include/c++/12.2/bits/stl_uninitialized.h:1104:       ptrdiff_t __count = __last - __first;
	movq	8(%r13), %rdx	# this_16(D)->D.206349._M_impl.D.205698._M_finish, __count
	subq	%rbx, %rdx	# _6, __count
# /usr/include/c++/12.2/bits/stl_uninitialized.h:1105:       if (__count > 0)
	testq	%rdx, %rdx	# __count
	jg	.L79	#,
.L57:
# /usr/include/c++/12.2/bits/stl_vector.h:386: 	if (__p)
	testq	%rbx, %rbx	# _6
	jne	.L80	#,
.L59:
# /usr/include/c++/12.2/bits/vector.tcc:693: 	      this->_M_impl._M_start = __new_start;
	movq	%r14, 0(%r13)	# _35, this_16(D)->D.206349._M_impl.D.205698._M_start
# /usr/include/c++/12.2/bits/vector.tcc:694: 	      this->_M_impl._M_finish = __new_start + __size + __n;
	addq	%r14, %r12	# _35, tmp130
# /usr/include/c++/12.2/bits/vector.tcc:695: 	      this->_M_impl._M_end_of_storage = __new_start + __len;
	addq	%r15, %r14	# _34, tmp131
# /usr/include/c++/12.2/bits/vector.tcc:694: 	      this->_M_impl._M_finish = __new_start + __size + __n;
	movq	%r12, 8(%r13)	# tmp130, this_16(D)->D.206349._M_impl.D.205698._M_finish
# /usr/include/c++/12.2/bits/vector.tcc:695: 	      this->_M_impl._M_end_of_storage = __new_start + __len;
	movq	%r14, 16(%r13)	# tmp131, this_16(D)->D.206349._M_impl.D.205698._M_end_of_storage
# /usr/include/c++/12.2/bits/vector.tcc:698:     }
	addq	$8, %rsp	#,
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L76:
	.cfi_restore_state
# /usr/include/c++/12.2/bits/stl_algobase.h:1114:       if (__n <= 0)
	movq	%rsi, %rdx	# __n, _49
# /usr/include/c++/12.2/bits/stl_construct.h:119:       ::new((void*)__p) _Tp(std::forward<_Args>(__args)...);
	movb	$0, (%rax)	#, *_23
# /usr/include/c++/12.2/bits/stl_uninitialized.h:662: 	      ++__first;
	leaq	1(%rax), %rdi	#, __first
# /usr/include/c++/12.2/bits/stl_algobase.h:1114:       if (__n <= 0)
	subq	$1, %rdx	#, _49
	jne	.L81	#,
.L52:
# /usr/include/c++/12.2/bits/vector.tcc:641: 	      this->_M_impl._M_finish =
	movq	%rdi, 8(%r13)	# __first, this_16(D)->D.206349._M_impl.D.205698._M_finish
# /usr/include/c++/12.2/bits/vector.tcc:698:     }
	addq	$8, %rsp	#,
	.cfi_def_cfa_offset 56
	popq	%rbx	#
	.cfi_def_cfa_offset 48
	popq	%rbp	#
	.cfi_def_cfa_offset 40
	popq	%r12	#
	.cfi_def_cfa_offset 32
	popq	%r13	#
	.cfi_def_cfa_offset 24
	popq	%r14	#
	.cfi_def_cfa_offset 16
	popq	%r15	#
	.cfi_def_cfa_offset 8
	ret	
	.p2align 4,,10
	.p2align 3
.L73:
	.cfi_restore 3
	.cfi_restore 6
	.cfi_restore 12
	.cfi_restore 13
	.cfi_restore 14
	.cfi_restore 15
	ret	
	.p2align 4,,10
	.p2align 3
.L81:
	.cfi_def_cfa_offset 64
	.cfi_offset 3, -56
	.cfi_offset 6, -48
	.cfi_offset 12, -40
	.cfi_offset 13, -32
	.cfi_offset 14, -24
	.cfi_offset 15, -16
# /usr/include/c++/12.2/bits/stl_algobase.h:1119:       std::__fill_a(__first, __first + __n, __value);
	addq	%rax, %rbx	# _23, _50
# /usr/include/c++/12.2/bits/stl_algobase.h:942: 	__builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
	xorl	%esi, %esi	#
	call	memset@PLT	#
# /usr/include/c++/12.2/bits/stl_algobase.h:1120:       return __first + __n;
	movq	%rbx, %rdi	# _50, __first
	jmp	.L52	#
	.p2align 4,,10
	.p2align 3
.L78:
# /usr/include/c++/12.2/bits/stl_algobase.h:942: 	__builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
	movq	%rbx, %rdx	# _65,
# /usr/include/c++/12.2/bits/stl_uninitialized.h:662: 	      ++__first;
	leaq	1(%rbp), %rdi	#, __first
# /usr/include/c++/12.2/bits/stl_algobase.h:942: 	__builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
	xorl	%esi, %esi	#
	call	memset@PLT	#
# /usr/include/c++/12.2/bits/vector.tcc:663: 		  _S_relocate(this->_M_impl._M_start, this->_M_impl._M_finish,
	movq	0(%r13), %rbx	# this_16(D)->D.206349._M_impl.D.205698._M_start, _6
# /usr/include/c++/12.2/bits/stl_uninitialized.h:1104:       ptrdiff_t __count = __last - __first;
	movq	8(%r13), %rdx	# this_16(D)->D.206349._M_impl.D.205698._M_finish, __count
	subq	%rbx, %rdx	# _6, __count
# /usr/include/c++/12.2/bits/stl_uninitialized.h:1105:       if (__count > 0)
	testq	%rdx, %rdx	# __count
	jle	.L57	#,
.L79:
# /usr/include/c++/12.2/bits/stl_uninitialized.h:1117: 	  __builtin_memmove(__result, __first, __count * sizeof(_Tp));
	movq	%rbx, %rsi	# _6,
	movq	%r14, %rdi	# _35,
	call	memmove@PLT	#
# /usr/include/c++/12.2/bits/vector.tcc:692: 			    - this->_M_impl._M_start);
	movq	16(%r13), %rsi	# this_16(D)->D.206349._M_impl.D.205698._M_end_of_storage, _52
	subq	%rbx, %rsi	# _6, _52
.L58:
# /usr/include/c++/12.2/bits/new_allocator.h:158: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	movq	%rbx, %rdi	# _6,
	call	_ZdlPvm@PLT	#
# /usr/include/c++/12.2/bits/alloc_traits.h:496:       { __a.deallocate(__p, __n); }
	jmp	.L59	#
	.p2align 4,,10
	.p2align 3
.L80:
# /usr/include/c++/12.2/bits/vector.tcc:692: 			    - this->_M_impl._M_start);
	movq	16(%r13), %rsi	# this_16(D)->D.206349._M_impl.D.205698._M_end_of_storage, _52
	subq	%rbx, %rsi	# _6, _52
	jmp	.L58	#
.L77:
# /usr/include/c++/12.2/bits/stl_vector.h:1894: 	  __throw_length_error(__N(__s));
	leaq	.LC3(%rip), %rdi	#, tmp120
	call	_ZSt20__throw_length_errorPKc@PLT	#
	.cfi_endproc
.LFE11318:
	.size	_ZNSt6vectorIhSaIhEE17_M_default_appendEm, .-_ZNSt6vectorIhSaIhEE17_M_default_appendEm
	.section	.text.unlikely,"ax",@progbits
.LCOLDB15:
	.section	.text.startup,"ax",@progbits
.LHOTB15:
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB10011:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA10011
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
# /usr/include/c++/12.2/bits/stl_vector.h:100: 	: _M_start(), _M_finish(), _M_end_of_storage()
	pxor	%xmm0, %xmm0	# tmp161
# /usr/include/c++/12.2/bits/stl_vector.h:1011: 	  _M_default_append(__new_size - size());
	movl	$12000000, %esi	#,
# main.cpp:9: int main() {
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%r15	#
	pushq	%r14	#
# /usr/include/c++/12.2/bits/stl_vector.h:1011: 	  _M_default_append(__new_size - size());
	leaq	-88(%rbp), %rdi	#, tmp164
# main.cpp:9: int main() {
	pushq	%r13	#
	pushq	%r12	#
	pushq	%rbx	#
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
# /usr/include/c++/12.2/bits/basic_string.h:200: 	: allocator_type(__a), _M_p(__dat) { }
	leaq	-128(%rbp), %rbx	#, tmp295
# main.cpp:9: int main() {
	subq	$184, %rsp	#,
# main.cpp:9: int main() {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp319
	movq	%rax, -56(%rbp)	# tmp319, D.235539
	xorl	%eax, %eax	# tmp319
# /usr/include/c++/12.2/bits/stl_vector.h:100: 	: _M_start(), _M_finish(), _M_end_of_storage()
	movups	%xmm0, -88(%rbp)	# tmp161, MEM <vector(2) long unsigned int> [(unsigned char * *)&fractal + 56B]
# /usr/include/bitmap_image.hpp:81:      width_ (width ),
	movdqa	.LC5(%rip), %xmm0	#, tmp162
# /usr/include/c++/12.2/bits/basic_string.h:200: 	: allocator_type(__a), _M_p(__dat) { }
	movq	%rbx, -144(%rbp)	# tmp295, MEM[(struct _Alloc_hider *)&fractal]._M_p
# /usr/include/c++/12.2/bits/basic_string.h:229:       { _M_string_length = __length; }
	movq	$0, -136(%rbp)	#, MEM[(struct basic_string *)&fractal]._M_string_length
# /usr/include/c++/12.2/bits/char_traits.h:354: 	__c1 = __c2;
	movb	$0, -128(%rbp)	#, MEM[(char_type &)&fractal + 16]
# /usr/include/bitmap_image.hpp:85:      channel_mode_(bgr_mode)
	movl	$1, -96(%rbp)	#, fractal.channel_mode_
# /usr/include/c++/12.2/bits/stl_vector.h:100: 	: _M_start(), _M_finish(), _M_end_of_storage()
	movq	$0, -72(%rbp)	#, MEM[(struct _Vector_impl_data *)&fractal + 56B]._M_end_of_storage
# /usr/include/bitmap_image.hpp:81:      width_ (width ),
	movaps	%xmm0, -112(%rbp)	# tmp162, MEM <vector(4) unsigned int> [(unsigned int *)&fractal + 32B]
.LEHB11:
# /usr/include/c++/12.2/bits/stl_vector.h:1011: 	  _M_default_append(__new_size - size());
	call	_ZNSt6vectorIhSaIhEE17_M_default_appendEm	#
.LEHE11:
# /usr/include/c++/12.2/bits/stl_iterator.h:1073:       : _M_current(__i) { }
	movq	-88(%rbp), %rdi	# MEM[(unsigned char * const &)&fractal + 56], _43
# /usr/include/c++/12.2/bits/stl_algobase.h:941:       if (const size_t __len = __last - __first)
	movq	-80(%rbp), %rdx	# MEM[(unsigned char * const &)&fractal + 64], __len
	subq	%rdi, %rdx	# _43, __len
	jne	.L120	#,
.L84:
# main.cpp:29:   }();
	movzbl	_ZGVZ4mainE16arrayCoordinates(%rip), %eax	#, _1
	leaq	_ZZ4mainE16arrayCoordinates(%rip), %r12	#, tmp294
	testb	%al, %al	# _1
	je	.L121	#,
.L90:
# main.cpp:22:     for (int i = 0; i < arraySize; i++) {
	leaq	_ZZ4mainE16arrayCoordinates(%rip), %rax	#, __for_begin
# main.cpp:32:   for (const std::complex<double>& coordinate : arrayCoordinates) {
	leaq	64000000(%r12), %r13	#, tmp261
# main.cpp:22:     for (int i = 0; i < arraySize; i++) {
	movq	%rax, %r14	# __for_begin, __for_begin
	.p2align 4,,10
	.p2align 3
.L95:
# main.cpp:36:     double ySquared = 0.0;
	pxor	%xmm4, %xmm4	# ySquared
	movsd	8(%r14), %xmm2	# MEM[(double *)__for_begin_171 + 8B], MEM[(double *)__for_begin_171 + 8B]
# main.cpp:37:     int iteration = 0;
	xorl	%ebx, %ebx	# iteration
# main.cpp:35:     double xSquared = 0.0;
	movapd	%xmm4, %xmm3	#, xSquared
# main.cpp:34:     double y = 0.0;
	movapd	%xmm4, %xmm0	# tmp23, y
# main.cpp:33:     double x = 0.0;
	movapd	%xmm4, %xmm1	# tmp20, x
	.p2align 4,,10
	.p2align 3
.L91:
	movsd	%xmm4, -216(%rbp)	# ySquared, %sfp
# main.cpp:45:       iteration++;
	addl	$1, %ebx	#, iteration
	movsd	%xmm3, -192(%rbp)	# xSquared, %sfp
# main.cpp:41:       y = 2 * fma(x, y, coordinate.imag());
	movsd	%xmm2, -208(%rbp)	# MEM[(double *)__for_begin_171 + 8B], %sfp
	call	fma@PLT	#
# main.cpp:42:       x = xSquared - ySquared + coordinate.real();
	movsd	-192(%rbp), %xmm3	# %sfp, xSquared
	movq	%r14, %rax	# __for_begin, __for_begin
	addsd	(%r14), %xmm3	# MEM[(double *)__for_begin_171], tmp223
	movsd	-216(%rbp), %xmm4	# %sfp, ySquared
# main.cpp:41:       y = 2 * fma(x, y, coordinate.imag());
	addsd	%xmm0, %xmm0	# tmp313, y
# main.cpp:39:     while (std::islessequal((xSquared + ySquared), 4) &&
	movsd	.LC10(%rip), %xmm6	#, tmp339
	movsd	-208(%rbp), %xmm2	# %sfp, MEM[(double *)__for_begin_171 + 8B]
# main.cpp:42:       x = xSquared - ySquared + coordinate.real();
	movapd	%xmm3, %xmm1	# tmp223, tmp223
	subsd	%xmm4, %xmm1	# ySquared, tmp223
# main.cpp:44:       ySquared = y * y;
	movapd	%xmm0, %xmm4	# y, ySquared
	mulsd	%xmm0, %xmm4	# y, ySquared
# main.cpp:43:       xSquared = x * x;
	movapd	%xmm1, %xmm3	# x, xSquared
	mulsd	%xmm1, %xmm3	# x, xSquared
# main.cpp:39:     while (std::islessequal((xSquared + ySquared), 4) &&
	movapd	%xmm3, %xmm5	# xSquared, tmp224
	addsd	%xmm4, %xmm5	# ySquared, tmp224
# main.cpp:39:     while (std::islessequal((xSquared + ySquared), 4) &&
	comisd	%xmm5, %xmm6	# tmp224, tmp339
	jb	.L122	#,
# main.cpp:39:     while (std::islessequal((xSquared + ySquared), 4) &&
	cmpl	$20000, %ebx	#, iteration
	jne	.L91	#,
	fnstcw	-178(%rbp)	#
# main.cpp:51:     const unsigned int index = &coordinate - arrayCoordinates.begin() + 1;
	movq	%r14, %rax	# __for_begin, tmp289
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	movl	$-1, %esi	#, _226
# main.cpp:51:     const unsigned int index = &coordinate - arrayCoordinates.begin() + 1;
	subq	%r12, %rax	# tmp294, tmp289
	movzwl	-178(%rbp), %edx	#, tmp317
	sarq	$4, %rax	#, tmp292
# main.cpp:51:     const unsigned int index = &coordinate - arrayCoordinates.begin() + 1;
	addl	$1, %eax	#, index
	orb	$12, %dh	#, tmp317
	movw	%dx, -180(%rbp)	# tmp317,
.L101:
# /usr/include/c++/12.2/bits/stl_algobase.h:235:       if (__b < __a)
	movl	$200, %edx	#, tmp316
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	movl	$2, %edi	#, _106
# /usr/include/c++/12.2/bits/stl_algobase.h:235:       if (__b < __a)
	cmpl	%edx, %ebx	# tmp316, iteration
	cmovle	%ebx, %edx	# iteration,, tmp235
# main.cpp:55:                       std::min(iteration, 200) * colorFactor,
	movl	%edx, -208(%rbp)	# tmp235, %sfp
	fildl	-208(%rbp)	# %sfp
	fmull	.LC11(%rip)	#
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	fldcw	-180(%rbp)		#
	fistps	-208(%rbp)	# %sfp
	fldcw	-178(%rbp)		#
	movzwl	-208(%rbp), %r8d	# %sfp, prephitmp_157
.L94:
	movl	%eax, %edx	# index, index
# /usr/include/bitmap_image.hpp:199:       const unsigned int y_offset = y * row_increment_;
	movl	-104(%rbp), %ecx	# fractal.row_increment_, y_offset
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	imulq	$274877907, %rdx, %rdx	#, index, tmp243
	shrq	$39, %rdx	#, tmp241
# /usr/include/bitmap_image.hpp:199:       const unsigned int y_offset = y * row_increment_;
	imull	%edx, %ecx	# tmp241, y_offset
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	imull	$2000, %edx, %edx	#, tmp241, tmp250
	subl	%edx, %eax	# tmp250, tmp251
# /usr/include/bitmap_image.hpp:200:       const unsigned int x_offset = x * bytes_per_pixel_;
	imull	-100(%rbp), %eax	# fractal.bytes_per_pixel_, x_offset
# /usr/include/bitmap_image.hpp:201:       const unsigned int offset   = y_offset + x_offset;
	leal	(%rax,%rcx), %edx	#,
# /usr/include/bitmap_image.hpp:203:       data_[offset + 0] = blue;
	movq	-88(%rbp), %rcx	# MEM[(struct vector *)&fractal + 56B].D.206349._M_impl.D.205698._M_start, MEM[(struct vector *)&fractal + 56B].D.206349._M_impl.D.205698._M_start
# /usr/include/bitmap_image.hpp:201:       const unsigned int offset   = y_offset + x_offset;
	movq	%rdx, %rax	#,
# /usr/include/bitmap_image.hpp:203:       data_[offset + 0] = blue;
	movb	%dil, (%rcx,%rdx)	# _106, *_76
# /usr/include/bitmap_image.hpp:204:       data_[offset + 1] = green;
	movq	-88(%rbp), %rcx	# MEM[(struct vector *)&fractal + 56B].D.206349._M_impl.D.205698._M_start, MEM[(struct vector *)&fractal + 56B].D.206349._M_impl.D.205698._M_start
# /usr/include/bitmap_image.hpp:204:       data_[offset + 1] = green;
	leal	1(%rdx), %edx	#, tmp256
# /usr/include/bitmap_image.hpp:205:       data_[offset + 2] = red;
	addl	$2, %eax	#, tmp259
# /usr/include/bitmap_image.hpp:204:       data_[offset + 1] = green;
	movb	%r8b, (%rcx,%rdx)	# prephitmp_157, *_80
# /usr/include/bitmap_image.hpp:205:       data_[offset + 2] = red;
	movq	-88(%rbp), %rdx	# MEM[(struct vector *)&fractal + 56B].D.206349._M_impl.D.205698._M_start, MEM[(struct vector *)&fractal + 56B].D.206349._M_impl.D.205698._M_start
	movb	%sil, (%rdx,%rax)	# _226, *_84
# main.cpp:32:   for (const std::complex<double>& coordinate : arrayCoordinates) {
	movq	%r14, %rax	# __for_begin, __for_begin
	addq	$16, %rax	#, __for_begin
	movq	%rax, %r14	# __for_begin, __for_begin
# main.cpp:32:   for (const std::complex<double>& coordinate : arrayCoordinates) {
	cmpq	%r13, %rax	# tmp261, __for_begin
	jne	.L95	#,
# /usr/include/c++/12.2/ostream:233:       { return _M_insert(__f); }
	fldl	.LC11(%rip)	#
	leaq	_ZSt4cout(%rip), %rdi	#, tmp265
	fstpt	-208(%rbp)	# %sfp
	movq	-208(%rbp), %rax	# %sfp,
	movl	-200(%rbp), %edx	# %sfp,
	pushq	%rdx	#
	pushq	%rax	#
.LEHB12:
	.cfi_escape 0x2e,0x10
	call	_ZNSo9_M_insertIeEERSoT_@PLT	#
.LEHE12:
# /usr/include/c++/12.2/ostream:233:       { return _M_insert(__f); }
	popq	%rax	#
# main.cpp:61:   fractal.save_image("mandelbrot.bmp");
	leaq	-144(%rbp), %rbx	#, tmp305
# /usr/include/c++/12.2/bits/basic_string.h:200: 	: allocator_type(__a), _M_p(__dat) { }
	leaq	-160(%rbp), %r14	#, tmp304
# /usr/include/c++/12.2/ostream:233:       { return _M_insert(__f); }
	popq	%rdx	#
# /usr/include/c++/12.2/bits/char_traits.h:431: 	return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
	movabsq	$8242269450773881197, %rax	#, tmp353
# /usr/include/c++/12.2/bits/basic_string.h:200: 	: allocator_type(__a), _M_p(__dat) { }
	leaq	-176(%rbp), %rsi	#, tmp266
# main.cpp:61:   fractal.save_image("mandelbrot.bmp");
	movq	%rbx, %rdi	# tmp305,
# /usr/include/c++/12.2/bits/basic_string.h:200: 	: allocator_type(__a), _M_p(__dat) { }
	movq	%r14, -176(%rbp)	# tmp304, MEM[(struct _Alloc_hider *)&D.212620]._M_p
# /usr/include/c++/12.2/bits/char_traits.h:431: 	return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
	movq	%rax, -160(%rbp)	# tmp353, MEM <char[1:14]> [(void *)&D.212620 + 16B]
	movabsq	$8101239256370868834, %rax	#, tmp354
	movq	%rax, -154(%rbp)	# tmp354, MEM <char[1:14]> [(void *)&D.212620 + 16B]
# /usr/include/c++/12.2/bits/basic_string.h:229:       { _M_string_length = __length; }
	movq	$14, -168(%rbp)	#, D.212620._M_string_length
# /usr/include/c++/12.2/bits/char_traits.h:354: 	__c1 = __c2;
	movb	$0, -146(%rbp)	#, MEM[(char_type &)&D.212620 + 30]
.LEHB13:
	.cfi_escape 0x2e,0
# main.cpp:61:   fractal.save_image("mandelbrot.bmp");
	call	_ZNK12bitmap_image10save_imageERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE	#
.LEHE13:
# /usr/include/c++/12.2/bits/basic_string.h:234:       { return _M_dataplus._M_p; }
	movq	-176(%rbp), %rdi	# D.212620._M_dataplus._M_p, _88
# /usr/include/c++/12.2/bits/basic_string.h:285: 	if (!_M_is_local())
	cmpq	%r14, %rdi	# tmp304, _88
	je	.L97	#,
# /usr/include/c++/12.2/bits/basic_string.h:292:       { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
	movq	-160(%rbp), %rax	# D.212620.D.36870._M_allocated_capacity, tmp356
	leaq	1(%rax), %rsi	#, tmp276
# /usr/include/c++/12.2/bits/new_allocator.h:158: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	call	_ZdlPvm@PLT	#
.L97:
# main.cpp:63: }
	movq	%rbx, %rdi	# tmp305,
	call	_ZN12bitmap_imageD1Ev	#
	movq	-56(%rbp), %rax	# D.235539, tmp320
	subq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp320
	jne	.L123	#,
	leaq	-40(%rbp), %rsp	#,
	xorl	%eax, %eax	#
	popq	%rbx	#
	popq	%r12	#
	popq	%r13	#
	popq	%r14	#
	popq	%r15	#
	popq	%rbp	#
	.cfi_remember_state
	.cfi_def_cfa 7, 8
	ret	
	.p2align 4,,10
	.p2align 3
.L122:
	.cfi_restore_state
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	fnstcw	-178(%rbp)	#
# main.cpp:56:                       std::min(iteration, 20) * colorFactor);
	movl	%ebx, -208(%rbp)	# iteration, %sfp
	fildl	-208(%rbp)	# %sfp
# main.cpp:51:     const unsigned int index = &coordinate - arrayCoordinates.begin() + 1;
	subq	%r12, %rax	# tmp294, tmp226
# main.cpp:56:                       std::min(iteration, 20) * colorFactor);
	fmull	.LC11(%rip)	#
# main.cpp:51:     const unsigned int index = &coordinate - arrayCoordinates.begin() + 1;
	sarq	$4, %rax	#, tmp229
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	movzwl	-178(%rbp), %edx	#, tmp318
# main.cpp:51:     const unsigned int index = &coordinate - arrayCoordinates.begin() + 1;
	addl	$1, %eax	#, index
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	orb	$12, %dh	#, tmp318
	movw	%dx, -180(%rbp)	# tmp318,
	fldcw	-180(%rbp)		#
	fistps	-208(%rbp)	# %sfp
	fldcw	-178(%rbp)		#
	movzbl	-208(%rbp), %edi	# %sfp, _106
	movl	%edi, %esi	# _106, _226
# /usr/include/c++/12.2/bits/stl_algobase.h:235:       if (__b < __a)
	cmpl	$20, %ebx	#, iteration
	jg	.L101	#,
# main.cpp:53:     fractal.set_pixel(index % canvasSize, index / canvasSize,
	movl	%edi, %r8d	# _226, prephitmp_157
	jmp	.L94	#
.L120:
# /usr/include/c++/12.2/bits/stl_algobase.h:942: 	__builtin_memset(__first, static_cast<unsigned char>(__tmp), __len);
	xorl	%esi, %esi	#
	call	memset@PLT	#
	jmp	.L84	#
.L121:
# main.cpp:29:   }();
	leaq	_ZGVZ4mainE16arrayCoordinates(%rip), %r13	#, tmp303
	movq	%r13, %rdi	# tmp303,
	call	__cxa_guard_acquire@PLT	#
	testl	%eax, %eax	# tmp310
	je	.L90	#,
# main.cpp:21:     std::array<std::complex<double>, arraySize> generatorArray{};
	movl	$64000000, %edx	#,
	xorl	%esi, %esi	#
	movq	%r12, %rdi	# tmp294,
	movq	%r12, %r14	# tmp294, ivtmp.265
	call	memset@PLT	#
# main.cpp:22:     for (int i = 0; i < arraySize; i++) {
	xorl	%eax, %eax	# i
	.p2align 4,,10
	.p2align 3
.L89:
# main.cpp:25:                                fma(i % canvasSize, yFactor, -0.56));
	movl	%eax, %ebx	# i,
# main.cpp:25:                                fma(i % canvasSize, yFactor, -0.56));
	pxor	%xmm0, %xmm0	# tmp200
# main.cpp:22:     for (int i = 0; i < arraySize; i++) {
	addq	$16, %r14	#, ivtmp.265
# main.cpp:25:                                fma(i % canvasSize, yFactor, -0.56));
	movq	%rbx, %r15	#,
	imulq	$274877907, %rbx, %rbx	#, i, tmp188
	movl	%r15d, %eax	# i, tmp191
# main.cpp:22:     for (int i = 0; i < arraySize; i++) {
	addl	$1, %r15d	#, i
# main.cpp:25:                                fma(i % canvasSize, yFactor, -0.56));
	shrq	$39, %rbx	#, tmp186
	imull	$2000, %ebx, %edx	#, tmp186, tmp190
	subl	%edx, %eax	# tmp190, tmp191
# main.cpp:25:                                fma(i % canvasSize, yFactor, -0.56));
	cvtsi2sdl	%eax, %xmm0	# tmp191, tmp200
	movq	.LC6(%rip), %rax	#, tmp327
	movq	%rax, %xmm2	# tmp327,
	movq	.LC7(%rip), %rax	#, tmp328
	movq	%rax, %xmm1	# tmp328,
	call	fma@PLT	#
	movq	.LC8(%rip), %rax	#, tmp329
	movsd	%xmm0, -208(%rbp)	# tmp201, %sfp
	pxor	%xmm0, %xmm0	# tmp215
	cvtsi2sdl	%ebx, %xmm0	# tmp186, tmp215
	movq	%rax, %xmm2	# tmp329,
	movq	.LC9(%rip), %rax	#, tmp330
	movq	%rax, %xmm1	# tmp330,
	call	fma@PLT	#
# main.cpp:26:       generatorArray[i] = vectorCoordinate;
	movsd	-208(%rbp), %xmm3	# %sfp, tmp201
# main.cpp:22:     for (int i = 0; i < arraySize; i++) {
	movl	%r15d, %eax	# i, i
# main.cpp:26:       generatorArray[i] = vectorCoordinate;
	unpcklpd	%xmm3, %xmm0	# tmp201, tmp218
	movaps	%xmm0, -16(%r14)	# tmp218, MEM[(struct value_type *)_178]
# main.cpp:22:     for (int i = 0; i < arraySize; i++) {
	cmpl	$4000000, %r15d	#, i
	jne	.L89	#,
# main.cpp:29:   }();
	movq	%r13, %rdi	# tmp303,
	call	__cxa_guard_release@PLT	#
	jmp	.L90	#
.L123:
# main.cpp:63: }
	call	__stack_chk_fail@PLT	#
.L106:
# /usr/include/c++/12.2/bits/stl_vector.h:730: 	std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
	movq	%rax, %r14	# tmp309, tmp168
	jmp	.L85	#
.L104:
# main.cpp:63: }
	movq	%rax, %r12	# tmp315, tmp284
	leaq	-144(%rbp), %rbx	#, tmp305
	jmp	.L100	#
.L105:
# /usr/include/c++/12.2/bits/basic_string.h:234:       { return _M_dataplus._M_p; }
	movq	%rax, %r12	# tmp314, tmp285
	jmp	.L98	#
	.section	.gcc_except_table,"a",@progbits
.LLSDA10011:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE10011-.LLSDACSB10011
.LLSDACSB10011:
	.uleb128 .LEHB11-.LFB10011
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L106-.LFB10011
	.uleb128 0
	.uleb128 .LEHB12-.LFB10011
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L104-.LFB10011
	.uleb128 0
	.uleb128 .LEHB13-.LFB10011
	.uleb128 .LEHE13-.LEHB13
	.uleb128 .L105-.LFB10011
	.uleb128 0
.LLSDACSE10011:
	.section	.text.startup
	.cfi_endproc
	.section	.text.unlikely
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDAC10011
	.type	main.cold, @function
main.cold:
.LFSB10011:
.L85:
	.cfi_def_cfa 6, 16
	.cfi_offset 3, -56
	.cfi_offset 6, -16
	.cfi_offset 12, -48
	.cfi_offset 13, -40
	.cfi_offset 14, -32
	.cfi_offset 15, -24
# /usr/include/c++/12.2/bits/stl_vector.h:730: 	std::_Destroy(this->_M_impl._M_start, this->_M_impl._M_finish,
	movq	-88(%rbp), %rdi	# MEM[(struct vector *)&fractal + 56B].D.206349._M_impl.D.205698._M_start, _111
# /usr/include/c++/12.2/bits/stl_vector.h:367: 		      _M_impl._M_end_of_storage - _M_impl._M_start);
	movq	-72(%rbp), %rsi	# MEM[(struct _Vector_base *)&fractal + 56B]._M_impl.D.205698._M_end_of_storage, _114
	subq	%rdi, %rsi	# _111, _114
# /usr/include/c++/12.2/bits/stl_vector.h:386: 	if (__p)
	testq	%rdi, %rdi	# _111
	je	.L86	#,
# /usr/include/c++/12.2/bits/new_allocator.h:158: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	call	_ZdlPvm@PLT	#
.L86:
# /usr/include/c++/12.2/bits/basic_string.h:234:       { return _M_dataplus._M_p; }
	movq	-144(%rbp), %rdi	# MEM[(const struct basic_string *)&fractal]._M_dataplus._M_p, _115
# /usr/include/c++/12.2/bits/basic_string.h:285: 	if (!_M_is_local())
	cmpq	%rbx, %rdi	# tmp295, _115
	je	.L87	#,
# /usr/include/c++/12.2/bits/basic_string.h:292:       { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
	movq	-128(%rbp), %rax	# MEM[(struct basic_string *)&fractal].D.36870._M_allocated_capacity, tmp324
	leaq	1(%rax), %rsi	#, tmp173
# /usr/include/c++/12.2/bits/new_allocator.h:158: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	call	_ZdlPvm@PLT	#
.L87:
	movq	%r14, %rdi	# tmp168,
.LEHB14:
	call	_Unwind_Resume@PLT	#
.L98:
# /usr/include/c++/12.2/bits/basic_string.h:234:       { return _M_dataplus._M_p; }
	movq	-176(%rbp), %rdi	# D.212620._M_dataplus._M_p, _91
# /usr/include/c++/12.2/bits/basic_string.h:285: 	if (!_M_is_local())
	cmpq	%r14, %rdi	# tmp304, _91
	je	.L100	#,
# /usr/include/c++/12.2/bits/basic_string.h:292:       { _Alloc_traits::deallocate(_M_get_allocator(), _M_data(), __size + 1); }
	movq	-160(%rbp), %rax	# D.212620.D.36870._M_allocated_capacity, tmp358
	leaq	1(%rax), %rsi	#, tmp282
# /usr/include/c++/12.2/bits/new_allocator.h:158: 	_GLIBCXX_OPERATOR_DELETE(_GLIBCXX_SIZED_DEALLOC(__p, __n));
	call	_ZdlPvm@PLT	#
.L100:
# main.cpp:63: }
	movq	%rbx, %rdi	# tmp305,
	call	_ZN12bitmap_imageD1Ev	#
	movq	%r12, %rdi	# tmp284,
	call	_Unwind_Resume@PLT	#
.LEHE14:
	.cfi_endproc
.LFE10011:
	.section	.gcc_except_table
.LLSDAC10011:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSEC10011-.LLSDACSBC10011
.LLSDACSBC10011:
	.uleb128 .LEHB14-.LCOLDB15
	.uleb128 .LEHE14-.LEHB14
	.uleb128 0
	.uleb128 0
.LLSDACSEC10011:
	.section	.text.unlikely
	.section	.text.startup
	.size	main, .-main
	.section	.text.unlikely
	.size	main.cold, .-main.cold
.LCOLDE15:
	.section	.text.startup
.LHOTE15:
	.p2align 4
	.type	_GLOBAL__sub_I_main, @function
_GLOBAL__sub_I_main:
.LFB12143:
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
# main.cpp:63: }
	popq	%rbx	#
	.cfi_def_cfa_offset 8
# /usr/include/c++/12.2/iostream:74:   static ios_base::Init __ioinit;
	leaq	__dso_handle(%rip), %rdx	#, tmp83
	jmp	__cxa_atexit@PLT	#
	.cfi_endproc
.LFE12143:
	.size	_GLOBAL__sub_I_main, .-_GLOBAL__sub_I_main
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I_main
	.local	_ZGVZ4mainE16arrayCoordinates
	.comm	_ZGVZ4mainE16arrayCoordinates,8,8
	.local	_ZZ4mainE16arrayCoordinates
	.comm	_ZZ4mainE16arrayCoordinates,64000000,32
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.data.rel.ro,"aw"
	.align 8
.LC2:
	.quad	_ZTVSt14basic_ofstreamIcSt11char_traitsIcEE+24
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC5:
	.long	2000
	.long	2000
	.long	6000
	.long	3
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC6:
	.long	515396076
	.long	-1075713147
	.align 8
.LC7:
	.long	-674825261
	.long	1061312926
	.align 8
.LC8:
	.long	0
	.long	-1073741824
	.align 8
.LC9:
	.long	655583809
	.long	1062484983
	.align 8
.LC10:
	.long	0
	.long	1074790400
	.align 8
.LC11:
	.long	-2061584302
	.long	1069568491
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (GNU) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
