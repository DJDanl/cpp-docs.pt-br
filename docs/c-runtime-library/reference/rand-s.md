---
title: rand_s
ms.date: 01/02/2018
api_name:
- rand_s
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
ms.openlocfilehash: 652521ab472736783ba1b4498ca7d7c3f297e7ee
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949651"
---
# <a name="rand_s"></a>rand_s

Gera um número pseudoaleatório. Essa é uma versão mais segura da função [Rand](rand.md), com aprimoramentos de segurança, conforme descrito em [recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t rand_s(unsigned int* randomValue);
```

### <a name="parameters"></a>Parâmetros

*randomValue*<br/>
Um ponteiro para um inteiro para manter o valor gerado.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; caso contrário, um código de erro. Se o ponteiro de entrada _randomValue_ for um ponteiro NULL, a função invocará um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará **EINVAL** e definirá **errno** como **EINVAL**. Se a função falhar por qualquer outro motivo, *_randomValue_ será definido como 0.

## <a name="remarks"></a>Comentários

A função **rand_s** grava um número inteiro de pseudoaleatória no intervalo de 0 a **UINT_MAX** para o ponteiro de entrada. A função **rand_s** usa o sistema operacional para gerar números aleatórios criptograficamente seguros. Ele não usa a semente gerada pela função [srand](srand.md) , nem afeta a sequência numérica aleatória usada pelo [Rand](rand.md).

A função **rand_s** requer que a constante **_CRT_RAND_S** seja definida antes da instrução de inclusão para que a função seja declarada, como no exemplo a seguir:

```C
#define _CRT_RAND_S
#include <stdlib.h>
```

o **rand_s** depende da API do [RtlGenRandom](/windows/win32/api/ntsecapi/nf-ntsecapi-rtlgenrandom) , que está disponível apenas no Windows XP e posterior.

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

### <a name="sample-output"></a>Saída de Exemplo

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[rand](rand.md)<br/>
[srand](srand.md)<br/>
