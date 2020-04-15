---
title: rand_s
ms.date: 4/2/2020
api_name:
- rand_s
- _o_rand_s
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-utility-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- rand_s
helpviewer_keywords:
- generating pseudorandom numbers
- random numbers, cryptographically secure
- random numbers, generating
- rand_s function
- numbers, pseudorandom
- cryptographically secure random numbers
- pseudorandom numbers
- numbers, generating pseudorandom
ms.openlocfilehash: b11a40dd9dc58964df77330767a55aa95a179319
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338197"
---
# <a name="rand_s"></a>rand_s

Gera um número pseudoaleatório. Esta é uma versão mais segura do [rand](rand.md)de função, com melhorias de segurança descritas [em Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t rand_s(unsigned int* randomValue);
```

### <a name="parameters"></a>Parâmetros

*Randomvalue*<br/>
Um ponteiro para um inteiro para manter o valor gerado.

## <a name="return-value"></a>Valor retornado

Zero se for bem-sucedido; caso contrário, um código de erro. Se o ponteiro de entrada _randomValue_ for um ponteiro nulo, a função invoca um manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna **EINVAL** e define **errno** para **EINVAL**. Se a função falhar por qualquer outro motivo, *_randomValue_ será definido como 0.

## <a name="remarks"></a>Comentários

A função **rand_s** grava um inteiro pseudoaleatório na faixa 0 a **UINT_MAX** ao ponteiro de entrada. A função **rand_s** usa o sistema operacional para gerar números aleatórios criptograficamente seguros. Não utiliza a semente gerada pela função [srand,](srand.md) nem afeta a seqüência de números aleatórios utilizada pelo [rand](rand.md).

A função **rand_s** exige que **_CRT_RAND_S** constantes sejam definidas antes da declaração de inclusão para que a função seja declarada, como no exemplo a seguir:

```C
By default, this function's global state is scoped to the application. To change this, see [Global state in the CRT](../global-state.md).

#define _CRT_RAND_S
#include <stdlib.h>
```

**rand_s** depende da API [RtlGenRandom,](/windows/win32/api/ntsecapi/nf-ntsecapi-rtlgenrandom) que só está disponível no Windows XP e posteriormente.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**rand_s**|\<stdlib.h>|

Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_rand_s.c
// This program illustrates how to generate random
// integer or floating point numbers in a specified range.

// Remembering to define _CRT_RAND_S prior
// to inclusion statement.
#define _CRT_RAND_S

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int main( void )
{
    int             i;
    unsigned int    number;
    double          max = 100.0;
    errno_t         err;

    // Display 10 random integers in the range [ 1,10 ].
    for( i = 0; i < 10;i++ )
    {
        err = rand_s( &number );
        if (err != 0)
        {
            printf_s("The rand_s function failed!\n");
        }
        printf_s( "  %u\n", (unsigned int) ((double)number /
                       ((double) UINT_MAX + 1 ) * 10.0) + 1);
    }

    printf_s("\n");

    // Display 10 random doubles in [0, max).
    for (i = 0; i < 10;i++ )
    {
        err = rand_s( &number );
        if (err != 0)
        {
            printf_s("The rand_s function failed!\n");
        }
        printf_s( "  %g\n", (double) number /
                          ((double) UINT_MAX + 1) * max );
    }
}
```

### <a name="sample-output"></a>Saída de exemplo

```Output
10
4
5
2
8
2
5
6
1
1

32.6617
29.4471
11.5413
6.41924
20.711
60.2878
61.0094
20.1222
80.9192
65.0712
```

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[Rand](rand.md)<br/>
[srand](srand.md)<br/>
