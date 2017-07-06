/* 
** bithacks-test.c - tests for bithacks.h
**
** Peteris Krumins (peter@catonmat.net)
** http://www.catonmat.net  --  good coders code, great reuse
**
** This file is explained in the following articles:
** http://www.catonmat.net/blog/bit-hacks-header-file
** http://www.catonmat.net/blog/low-level-bit-hacks-you-absolutely-must-know
**
** Released under the MIT license.
*/

#include <stdio.h>
#include <stdlib.h>

#include "../includes/bithacks.h"

int error_count;

#define TEST_OK(exp, what) do { \
    if ((exp)!=(what)) { \
        error_count++; \
        printf("Test '%s' at line %d failed.\n", #exp, __LINE__); \
    } } while(0)

#define TEST_END do { \
    if (error_count) { \
        printf("Testing failed: %d failed tests.\n", error_count); \
    } else { \
        printf("All tests OK.\n"); \
    } } while (0)

void test_B_EVEN()
{
    /* test B_EVEN */
    TEST_OK(checkEven(B8(01010101)), 0);
    TEST_OK(checkEven(44), 1);
    TEST_OK(checkEven(131), 0);
}

void test_B_ODD()
{
    /* test B_ODD */
    TEST_OK(checkOdd(B8(01010101)), 1);
    TEST_OK(checkOdd(44), 0);
    TEST_OK(checkOdd(131), 1);
}

void test_B_IS_SET()
{
    /* test B_IS_SET */
    TEST_OK(bitIsSet(B8(01010101), 5), 0);
    TEST_OK(bitIsSet(B8(01010101), 6), 1);
    TEST_OK(bitIsSet(B8(01010101), 7), 0);
}

void test_B_SET()
{
    /* test B_SET */
    unsigned char x;

    x = B8(01111111);
    x = bitSet(x, 6);
    TEST_OK(x, B8(01111111));
    x = bitSet(x, 7);
    TEST_OK(x, B8(11111111));

    x = B8(11111111);
    x = bitSet(x, 6);
    TEST_OK(x, B8(11111111));
    x = bitSet(x, 7);
    TEST_OK(x, B8(11111111));
}

void test_B_UNSET()
{
    unsigned char x;
   
    x = B8(10000000);
    x = bitUnSet(x, 6);
    TEST_OK(x, B8(10000000));
    x = bitUnSet(x, 7);
    TEST_OK(x, B8(00000000));

    x = B8(00000000);
    x = bitUnSet(x, 6);
    TEST_OK(x, B8(00000000));
    x = bitUnSet(x, 7);
    TEST_OK(x, B8(00000000));
}

void test_B_TOGGLE()
{
    unsigned char x = B8(10111111);
    x = bitToggle(x, 6);
    TEST_OK(x, B8(11111111));
    x = bitToggle(x, 7);
    TEST_OK(x, B8(01111111));
    x = bitToggle(x, 7);
    TEST_OK(x, B8(11111111));
}

void test_B_TURNOFF_1()
{
    unsigned char x = B8(10000000);
    x = bitTurnOff(x);
    TEST_OK(x, B8(00000000));

    x = B8(10101010);
    x = bitTurnOff(x);
    TEST_OK(x, B8(10101000));

    x = B8(01010101);
    x = bitTurnOff(x);
    TEST_OK(x, B8(01010100));
}

void test_B_ISOLATE_1()
{
    unsigned char x;

    x = B8(10000000);
    x = bitIsolate(x);
    TEST_OK(x, B8(10000000));

    x = B8(10001001);
    x = bitIsolate(x);
    TEST_OK(x, B8(00000001));

    x = B8(10001000);
    x = bitIsolate(x);
    TEST_OK(x, B8(00001000));
}

void test_B_PROPAGATE_1()
{
    unsigned char x;

    x = B8(00000000);
    x = bitPropagate_1(x);
    TEST_OK(x, B8(11111111));
    x = bitPropagate_1(x);
    TEST_OK(x, B8(11111111));

    x = B8(10101000);
    x = bitPropagate_1(x);
    TEST_OK(x, B8(10101111));
    x = bitPropagate_1(x);
    TEST_OK(x, B8(10101111));

    x = B8(10101010);
    x = bitPropagate_1(x);
    TEST_OK(x, B8(10101011));
    x = bitPropagate_1(x);
    TEST_OK(x, B8(10101011));

    x = B8(10101010);
    x = bitPropagate_1(x);
    TEST_OK(x, B8(10101011));
    x = bitPropagate_1(x);
    TEST_OK(x, B8(10101011));
}

void test_B_ISOLATE_0()
{
    unsigned char x;

    x = B8(00000111);
    x = bitIsolate_0(x);
    TEST_OK(x, B8(00001000));

    x = B8(01011111);
    x = bitIsolate_0(x);
    TEST_OK(x, B8(00100000));

    x = B8(01111111);
    x = bitIsolate_0(x);
    TEST_OK(x, B8(10000000));
}

int main()
{
    test_B_EVEN();
    test_B_ODD();
    test_B_IS_SET();
    test_B_SET();
    test_B_UNSET();
    test_B_TOGGLE();
    test_B_TURNOFF_1();
    test_B_ISOLATE_1();
    test_B_PROPAGATE_1();
    test_B_ISOLATE_0();

    TEST_END;
    
    unsigned char ascii_char = 'A';        /*  char = 8 bits only */
  int test_nbr = 10;
  printf("Starting character = %c\n", ascii_char);
  /*  The 5th bit position determines if the character is
      uppercase or lowercase.
      5th bit = 0  - Uppercase
      5th bit = 1  - Lowercase      */
  printf("\nTurn 5th bit on = %c\n", bitSetFlag(ascii_char, bitPos(5)) );
  printf("Turn 5th bit off = %c\n\n", bitClrFlag(ascii_char, bitPos(5)) );
  printf("Look at shifting bits\n");
  printf("=====================\n");
  printf("Current value = %d\n", test_nbr);
  printf("Shifting one position left = %d\n",
         test_nbr = bitShiftL(test_nbr, 1) );
  printf("Shifting two positions right = %d\n",
         bitShiftR(test_nbr, 2) );

    return error_count ? EXIT_FAILURE : EXIT_SUCCESS;
}
