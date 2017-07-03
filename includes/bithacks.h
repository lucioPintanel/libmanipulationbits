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
#define B_EVEN(x)        ({ \
			    typeof(x) __x = x; \
			    ((__x)&1)==0; \
			    })

/* test if x is odd */
#define B_ODD(__x)         (!B_EVEN((__x)))

/* test if n-th bit in x is set */
#define B_IS_SET(x, n)   ({ \
			    typeof(x) __x = x; \
			    typeof(n) __n = n; \
			    (((__x) & (1<<(__n)))?1:0); \
			    })

/* set n-th bit in x */
#define B_SET(x, n)      ({ \
			    typeof(x) __x = x; \
			    typeof(n) __n = n; \
			    ((__x) |= (1<<(__n))); \
			    x = __x; \
			    })

/* unset n-th bit in x */
#define B_UNSET(x, n)    ({ \
			    typeof(x) __x = x; \
			    typeof(n) __n = n; \
			    ((__x) &= ~(1<<(__n))); \
			    x = __x; \
			    })

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
#define BIT_POS(N)            ({ \
                                  typeof (N) __n = (N); \
                                  1U << (__n); \
                              })

#define SET_FLAG(N, F)        ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                (__n) |= (__f); \
                              })

#define CLR_FLAG(N, F)        ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                (__n) &= -(__f); \
                              })

#define TST_FLAG(N, F)      ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                (__n) & (__f); \
                              })

#define BIT_RANGE(N, F)      ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                BIT_POS((__f)+1 - (__n))-1 << (__n); \
                              })

#define BIT_SHIFTL(N, F)      ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                (unsigned)(__n) << (__f); \
                              })

#define BIT_SHIFTR(N, F)      ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                (unsigned)(__n) >> (__f); \
                              })

#define SET_MFLAG(N, F, V)    ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                typeof (V) __v = (V); \
                                (CLR_FLAG(__n, __f), SET_FLAG(__n, __v)); \
                              })

#define CLR_MFLAG(N, F)       ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                ((__n) &= ~(__f)); \
                              })
     
#define GET_MFLAG(N, F)       ({ \
                                typeof (N) __n = (N); \
                                typeof (F) __f = (F); \
                                ((__n) & (__f)); \
                              })

int checkEven(int x);
int checkOdd(int x);
int bitIsSet(int x, int n);
int bitSet(int x, int n);
int bitUnSet(int x, int n);


#endif
