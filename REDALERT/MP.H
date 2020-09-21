//
// Copyright 2020 Electronic Arts Inc.
//
// TiberianDawn.DLL and RedAlert.dll and corresponding source code is free 
// software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation, 
// either version 3 of the License, or (at your option) any later version.

// TiberianDawn.DLL and RedAlert.dll and corresponding source code is distributed 
// in the hope that it will be useful, but with permitted additional restrictions 
// under Section 7 of the GPL. See the GNU General Public License in LICENSE.TXT 
// distributed with this program. You should have received a copy of the 
// GNU General Public License along with permitted additional restrictions 
// with this program. If not, see https://github.com/electronicarts/CnC_Remastered_Collection

/* $Header: /CounterStrike/MP.H 1     3/03/97 10:25a Joe_bostic $ */
/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O                 ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                    File Name : MP.H                                                         *
 *                                                                                             *
 *                   Programmer : Joe L. Bostic                                                *
 *                                                                                             *
 *                   Start Date : 04/26/96                                                     *
 *                                                                                             *
 *                  Last Update : April 26, 1996 [JLB]                                         *
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#ifndef MP_H
#define MP_H

//lint -e740 -e534 -e537 -e760

//lint -d_LINT=1
/*
**	The "bool" integral type was defined by the C++ committee in
**	November of '94. Until the compiler supports this, use the following
**	definition.
*/
#ifndef __BORLANDC__
#ifndef TRUE_FALSE_DEFINED
#define TRUE_FALSE_DEFINED
enum {false=0,true=1};
typedef int bool;
#endif
#endif


#include	"straw.h"
#include	<stdlib.h>

extern unsigned short primeTable[3511];


#define	redalert_digit	unsigned long
#define	signeddigit	signed long
#define	LOG_UNITSIZE			5
#define	UNITSIZE					32
#define	UPPER_MOST_BIT			0x80000000L
#define	SEMI_UPPER_MOST_BIT	0x8000
#define	SEMI_MASK				((unsigned short)~0)
#define	MAX_BIT_PRECISION		2048
#define	MAX_UNIT_PRECISION	(MAX_BIT_PRECISION/UNITSIZE)
#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)	(sizeof(a)/sizeof(a[0]))
#endif


int XMP_Significance(const redalert_digit * r, int precision);
void XMP_Inc(redalert_digit * r, int precision);
void XMP_Dec(redalert_digit * r, int precision);
void XMP_Neg(redalert_digit * r, int precision);
void XMP_Abs(redalert_digit * r, int precision);
void XMP_Shift_Right_Bits(redalert_digit * r1, int bits, int precision);
void XMP_Shift_Left_Bits(redalert_digit * r1, int bits, int precision);
bool XMP_Rotate_Left(redalert_digit * r1, bool carry, int precision);
void XMP_Not(redalert_digit * digit_ptr, int precision);
void XMP_Init(redalert_digit * r, redalert_digit value, int precision);
unsigned XMP_Count_Bits(const redalert_digit * r, int precision);
int XMP_Count_Bytes(const redalert_digit * r, int precision);
void XMP_Move(redalert_digit * dest, redalert_digit const * source, int precision);
int XMP_Compare(const redalert_digit * r1, const redalert_digit * r2, int precision);
bool XMP_Add(redalert_digit * result, const redalert_digit * r1, const redalert_digit * r2, bool carry, int precision);
bool XMP_Add_Int(redalert_digit * result, const redalert_digit * r1, redalert_digit r2, bool carry, int precision);
bool XMP_Sub(redalert_digit * result, const redalert_digit * r1, const redalert_digit * r2, bool borrow, int precision);
bool XMP_Sub_Int(redalert_digit * result, const redalert_digit * r1, unsigned short r2, bool borrow, int precision);
int XMP_Unsigned_Mult(redalert_digit * prod, const redalert_digit * multiplicand, const redalert_digit * multiplier, int precision);
int XMP_Unsigned_Mult_Int(redalert_digit * prod, const redalert_digit * multiplicand, short multiplier, int precision);
int XMP_Signed_Mult_Int(redalert_digit * prod, const redalert_digit * multiplicand, signed short multiplier, int precision);
int XMP_Signed_Mult(redalert_digit * prod, const redalert_digit * multiplicand, const redalert_digit * multiplier, int precision);
unsigned short XMP_Unsigned_Div_Int(redalert_digit * quotient, redalert_digit const * dividend, unsigned short divisor, int precision);
int XMP_Unsigned_Div(redalert_digit * remainder, redalert_digit * quotient, redalert_digit const * dividend, redalert_digit const * divisor, int precision);
void XMP_Signed_Div(redalert_digit * remainder, redalert_digit * quotient, redalert_digit const * dividend, redalert_digit const * divisor, int precision);
int XMP_Reciprocal(redalert_digit * quotient, const redalert_digit * divisor, int precision);
void XMP_Decode_ASCII(char const * str, redalert_digit * mpn, int precision);
void xmp_single_mul(unsigned short * prod, unsigned short * multiplicand, unsigned short multiplier, int precision);
void XMP_Double_Mul(redalert_digit * prod, const redalert_digit * multiplicand, const redalert_digit * multiplier, int precision);
int xmp_stage_modulus(const redalert_digit * n_modulus, int precision);
int XMP_Mod_Mult(redalert_digit * prod, const redalert_digit * multiplicand, const redalert_digit * multiplier, int precision);
void XMP_Mod_Mult_Clear(int precision);
unsigned short mp_quo_digit(unsigned short * dividend);
int xmp_exponent_mod(redalert_digit * expout, const redalert_digit * expin, const redalert_digit * exponent_ptr, const redalert_digit * modulus, int precision);
bool XMP_Is_Small_Prime(const redalert_digit * candidate, int precision);
bool XMP_Small_Divisors_Test(const redalert_digit * candidate, int precision);
bool XMP_Fermat_Test(const redalert_digit * candidate_prime, unsigned rounds, int precision);
void XMP_Inverse_A_Mod_B(redalert_digit * result, redalert_digit const * number, redalert_digit const * modulus, int precision);
void XMP_Signed_Decode(redalert_digit * result, const unsigned char * from, int frombytes, int precision);
void XMP_Unsigned_Decode(redalert_digit * result, const unsigned char * from, int frombytes, int precision);
unsigned XMP_Encode(unsigned char * to, redalert_digit const * from, int precision);
unsigned XMP_Encode(unsigned char * to, unsigned tobytes, redalert_digit const * from, int precision);
void XMP_Randomize(redalert_digit * result, Straw & rng, int nbits, int precision);
void XMP_Randomize(redalert_digit * result, Straw & rng, redalert_digit const * min, redalert_digit const * max, int precision);
bool XMP_Is_Prime(redalert_digit const * prime, int precision);
bool XMP_Rabin_Miller_Test(Straw & rng, redalert_digit const * w, int rounds, int precision);
int XMP_DER_Length_Encode(unsigned long length, unsigned char * output);
int XMP_DER_Encode(redalert_digit const * from, unsigned char * output, int precision);
void XMP_DER_Decode(redalert_digit * result, unsigned char const * input, int precision);



inline int XMP_Digits_To_Bits(int digits)
{
	return(digits << LOG_UNITSIZE);
}


inline int XMP_Bits_To_Digits(int bits)
{
	return ((bits + (UNITSIZE-1)) / UNITSIZE);
}


inline redalert_digit XMP_Bits_To_Mask(int bits)
{
	if (!bits) return(0);
	return(1 << ((bits-1) % UNITSIZE));
}


inline bool XMP_Is_Negative(const redalert_digit * r, int precision)
{
	return((signeddigit) *(r + (precision-1)) < 0);
}


inline bool XMP_Test_Eq_Int(redalert_digit const * r, int i, int p)
{
	return( (*r == i ) && XMP_Significance(r,p) <= 1 );
}


inline void XMP_Set_Bit(redalert_digit * r, unsigned bit)
{
	r[bit >> LOG_UNITSIZE] |= ((redalert_digit)1 << (bit & (UNITSIZE-1)));
}

inline bool XMP_Test_Bit(const redalert_digit * r, unsigned bit)
{
	return (r[bit >> LOG_UNITSIZE] & ((redalert_digit)1 << (bit & (UNITSIZE-1))));
}



// Misc functions.
void memrev(char * buffer, size_t length);

#endif
