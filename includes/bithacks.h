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
int bitToggle(int x, int n);
int bitTurnOff(int x);
int bitIsolate(int x);
int bitPropagate_1(int x);
int bitIsolate_0(int x);
int bitPos(int x);
int bitSetFlag(int x, int n);
int bitClrFlag(int x, int n);
int bitShiftL(int x, int n);
int bitShiftR(int x, int n);

#endif
