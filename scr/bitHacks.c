/**
 * \file bitHacks.c
 * \author LUcio Pintanel
 * \date 9 Aug 2016
 * \brief File containing includes, defines, and demias externados.
 *
 */

/***	SESSION INCLUDE	***********************************************/
#include <stdio.h>

#include "../includes/bithacks.h"
/**********************************************************************/

/***	SESSION DEFINE, STRUCT, TYPEDEF	*******************************/
#define MAX_TAM 256UL /*!< Define tamanho maximo de vetor */

#define VERSAO_MAX _VERSAO_MAX  /*!< Definicao de versao Maxima, valor da definicao vem via Makefile */
#define VERSAO_MIN _VERSAO_MIN  /*!< Definicao de versao Minima, valor da definicao vem via Makefile */
#define VERSAO_NRO _VERSAO_NRO  /*!< Definicao de versao Númeor, valor da definicao vem via Makefile */

/**********************************************************************/

/***	SESSION MACROS	*******************************/
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
#define B_TOGGLE(x, n)   ({ \
			    typeof(x) __x = x; \
			    typeof(n) __n = n; \
			    ((__x) ^= (1<<(__n))); \
			    x = __x; \
			  })

/* turn off right-most 1-bit in x */
#define B_TURNOFF_1(x)   ({ \
			    typeof(x) __x = x; \
			    ((__x) &= ((__x)-1)); \
			    x = __x; \
			 })

/* isolate right-most 1-bit in x */
#define B_ISOLATE_1(x)   ({ \
			    typeof(x) __x = x; \
			    ((__x) &= (-(__x))); \
			 })

/* right-propagate right-most 1-bit in x */
#define B_PROPAGATE_1(x) ({ \
			    typeof(x) __x = x; \
			    ((__x) |= ((__x)-1)); \
			    x = __x; \
			 })

/* isolate right-most 0-bit in x */
#define B_ISOLATE_0(x)   ({ \
			    typeof(x) __x = x; \
			    ((__x) = ~(__x) & ((__x)+1)); \
			    x = __x; \
			 })

/* turn on right-most 0-bit in x */
#define B_TURNON_0(x)    ({ \
			    typeof(x) __x = x; \
			    ((__x) |= ((__x)+1)); \
			    x = __x; \
			 })

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

/**********************************************************************/

/***	SESSION VARIAVEIS GLOBAIS	*******************************/

/**********************************************************************/

/***	SESSION PROTOTIPO DE FUNCOES	*******************************/

/**********************************************************************/

/***	SESSION FUNCOES	***********************************************/

/* 
 * \brief Get library version. Function returns version and build number of bitHacks 
 * library. Return value is char pointer. Argument min is flag for output 
 * format. If min is 1, function returns version in full  format, if flag 
 * is 0 function returns only version numbers, For examle: 1.3.0
-*/
const int libEdmVersion(int min, char* vrsStr)
{
	if (NULL == vrsStr) {
		printf("Vetor nao inicializado\n");
		return -1;
	}
	char verstr[MAX_TAM];

	/* Version short */
	if (min) snprintf(verstr, sizeof(verstr), "%d.%d.%d",
		VERSAO_MAX, VERSAO_MIN, VERSAO_NRO);

		/* Version long */
	else snprintf(verstr, sizeof(verstr), "%d.%d build %d (%s)",
		VERSAO_MAX, VERSAO_MIN, VERSAO_NRO, __DATE__);

	return 0;
}

int checkEven(int x)
{
	return B_EVEN(x);
}

int checkOdd(int x)
{
	return B_ODD(x);
}

int bitIsSet(int x, int n)
{
	return B_IS_SET(x, n);
}

int bitSet(int x, int n)
{
	return B_SET(x, n);
	;
}

int bitUnSet(int x, int n)
{
	return B_UNSET(x, n);
	;
}

int bitToggle(int x, int n)
{
	return B_TOGGLE(x, n);
}

int bitTurnOff(int x)
{
	return B_TURNOFF_1(x);
}

int bitIsolate(int x)
{
	return B_ISOLATE_1(x);
}

int bitPropagate_1(int x)
{
	return B_PROPAGATE_1(x);
}

int bitIsolate_0(int x)
{
	return B_ISOLATE_0(x);
}

int bitTurnOn_0(int x)
{
	return B_TURNON_0(x);
}

int bitPos(int x)
{
	return BIT_POS(x);
}

int bitSetFlag(int x, int n)
{
	return SET_FLAG(x, n);
}

int bitClrFlag(int x, int n)
{
	return CLR_FLAG(x, n);
}

int bitShiftL(int x, int n)
{
	return BIT_SHIFTL(x, n);
}

int bitShiftR(int x, int n)
{
	return BIT_SHIFTR(x, n);
}


/* end BITHACKS_C */