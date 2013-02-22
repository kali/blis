/*

   BLIS    
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2013, The University of Texas

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name of The University of Texas nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#ifndef BLIS_BLAS_MACRO_DEFS_H
#define BLIS_BLAS_MACRO_DEFS_H


// -- Fortran-77 name-mangling macros --

//#define F77_FUNC(name,NAME)     name ## _

#define PASTEF77(ch1,name)       ch1        ## name ## _
#define PASTEF772(ch1,ch2,name)  ch1 ## ch2 ## name ## _


// -- Other compatibility macros --

#define bl2_convert_blas_dim1( n_blas, n_blis )\
{ \
	if ( n_blas < 0 ) n_blis = 0; \
	else              n_blis = n_blas; \
}

#define bl2_convert_blas_incv( n, x_blas, incx_blas, \
                                  x_blis, incx_blis ) \
{ \
	if ( incx_blas < 0 ) \
	{ \
		x_blis    = (x_blas) + (n-1) * (incx_blas); \
		incx_blis = -(incx_blas); \
	} \
	else \
	{ \
		x_blis    = (x_blas); \
		incx_blis = (incx_blas); \
	} \
}





#endif
