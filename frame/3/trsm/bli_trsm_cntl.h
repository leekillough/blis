/*

   BLIS
   An object-based framework for developing high-performance BLAS-like
   libraries.

   Copyright (C) 2014, The University of Texas at Austin
   Copyright (C) 2018 - 2019, Advanced Micro Devices, Inc.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    - Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    - Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    - Neither the name(s) of the copyright holder(s) nor the names of its
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

struct trsm_var_cntl_s
{
    cntl_t           cntl; //this field must be present and come first
    gemmtrsm_ukr_vft gemmtrsm_ukr;
    gemm_ukr_vft     gemm_ukr;
};
typedef struct trsm_var_cntl_s trsm_var_cntl_t;

BLIS_INLINE gemmtrsm_ukr_vft bli_trsm_var_cntl_gemmtrsm_ukr( const cntl_t* cntl )
{
    return ( ( const trsm_var_cntl_t* ) cntl )->gemmtrsm_ukr;
}

BLIS_INLINE gemm_ukr_vft bli_trsm_var_cntl_gemm_ukr( const cntl_t* cntl )
{
    return ( ( const trsm_var_cntl_t* ) cntl )->gemm_ukr;
}

void bli_trsm_var_cntl_init_node
     (
       void_fp          var_func,
       gemmtrsm_ukr_vft gemmtrsm_ukr,
       gemm_ukr_vft     gemm_ukr,
       trsm_var_cntl_t* cntl
     );

struct trsm_cntl_s
{
         part_cntl_t part_jc;
         part_cntl_t part_pc;
    packm_def_cntl_t pack_b;
         part_cntl_t part_ic;
    packm_def_cntl_t pack_a_trsm;
     trsm_var_cntl_t trsm_ker;
    packm_def_cntl_t pack_a_gemm;
     trsm_var_cntl_t gemm_ker;
              cntl_t ir_loop_gemm;
              cntl_t ir_loop_trsm;
};
typedef struct trsm_cntl_s trsm_cntl_t;

void bli_trsm_cntl_init
     (
       const obj_t*       a,
       const obj_t*       b,
       const obj_t*       c,
             pack_t       schema_a,
             pack_t       schema_b,
       const cntx_t*      cntx,
             trsm_cntl_t* cntl
     );

void bli_trsm_l_cntl_init
     (
       const obj_t*       a,
       const obj_t*       b,
       const obj_t*       c,
             pack_t       schema_a,
             pack_t       schema_b,
       const cntx_t*      cntx,
             trsm_cntl_t* cntl
     );

void bli_trsm_r_cntl_init
     (
       const obj_t*       a,
       const obj_t*       b,
       const obj_t*       c,
             pack_t       schema_a,
             pack_t       schema_b,
       const cntx_t*      cntx,
             trsm_cntl_t* cntl
     );

