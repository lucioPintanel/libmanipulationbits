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
	//printf("[line %d] X: [%d]\n", __LINE__, x);
	return B_EVEN(x);
}

int checkOdd(int x)
{
	//printf("[line %d] X: [%d]\n", __LINE__, x);
	return B_ODD(x);
}

int bitIsSet(int x, int n)
{
	//printf("[line %d] X: [%d]\n", __LINE__, x);
	return B_IS_SET(x, n);
}

int bitSet(int x, int n)
{
	x = B_SET(x, n);
	//printf("[line %d] X: [%.2x]\n", __LINE__, x); 
	return x;
}

int bitUnSet(int x, int n)
{
	x = B_UNSET(x, n);
	//printf("[line %d] X: [%.2x]\n", __LINE__, x); 
	return x;
}

/* end BITHACKS_C */