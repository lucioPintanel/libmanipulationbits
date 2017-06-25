/* 
** bithacks.h - bit hacks macros. v1.0
**
** Peteris Krumins (peter@catonmat.net)
** http://www.catonmat.net  --  good coders code, great reuse
**
** This file is explained in the following article:
** http://www.catonmat.net/blog/bit-hacks-header-file
**
** Released under the MIT license.
*/

#ifndef BITHACKS_H
#define BITHACKS_H

#define HEXIFY(X) 0x##X##LU

#define B8IFY(Y) (((Y&0x0000000FLU)?1:0)  + \
                  ((Y&0x000000F0LU)?2:0)  + \
                  ((Y&0x00000F00LU)?4:0)  + \
                  ((Y&0x0000F000LU)?8:0)  + \
                  ((Y&0x000F0000LU)?16:0) + \
                  ((Y&0x00F00000LU)?32:0) + \
                  ((Y&0x0F000000LU)?64:0) + \
                  ((Y&0xF0000000LU)?128:0))

#define B8(Z) ((unsigned char)B8IFY(HEXIFY(Z)))

/*
** Bit hack routines. See the following article for explanation:
** http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know
**
*/

/* test if x is even */
#define B_EVEN(x)        (((x)&1)==0)

/* test if x is odd */
#define B_ODD(x)         (!B_EVEN((x)))

/* test if n-th bit in x is set */
#define B_IS_SET(x, n)   (((x) & (1<<(n)))?1:0)

/* set n-th bit in x */
#define B_SET(x, n)      ((x) |= (1<<(n)))

/* unset n-th bit in x */
#define B_UNSET(x, n)    ((x) &= ~(1<<(n)))

/* toggle n-th bit in x */
#define B_TOGGLE(x, n)   ((x) ^= (1<<(n)))

/* turn off right-most 1-bit in x */
#define B_TURNOFF_1(x)   ((x) &= ((x)-1))

/* isolate right-most 1-bit in x */
#define B_ISOLATE_1(x)   ((x) &= (-(x)))

/* right-propagate right-most 1-bit in x */
#define B_PROPAGATE_1(x) ((x) |= ((x)-1))

/* isolate right-most 0-bit in x */
#define B_ISOLATE_0(x)   ((x) = ~(x) & ((x)+1))

/* turn on right-most 0-bit in x */
#define B_TURNON_0(x)    ((x) |= ((x)+1))

/* Bit Masking */
/* Bit masking can be used to switch a character
   between lowercase and uppercase */
#define BIT_POS(N)            ( 1U << (N) )

#define SET_FLAG(N, F)        ( (N) |= (F) )

#define CLR_FLAG(N, F)        ( (N) &= -(F) )

#define TST_FLAG(N, F)        ( (N) & (F) )

#define BIT_RANGE(N, M)       ( BIT_POS((M)+1 - (N))-1 << (N) )

#define BIT_SHIFTL(B, N)      ( (unsigned)(B) << (N) )
#define BIT_SHIFTR(B, N)      ( (unsigned)(B) >> (N) )

#define SET_MFLAG(N, F, V)    ( CLR_FLAG(N, F), SET_FLAG(N, V) )

#define CLR_MFLAG(N, F)       ( (N) &= ~(F) )

#define GET_MFLAG(N, F)       ( (N) & (F) )

#endif
