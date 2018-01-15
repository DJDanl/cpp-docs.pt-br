---
title: rand_s | Microsoft Docs
ms.custom: 
ms.date: 1/02/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: rand_s
apilocation:
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
apitype: DLLExport
f1_keywords: rand_s
dev_langs: C++
helpviewer_keywords:
- generating pseudorandom numbers
- random numbers, cryptographically secure
- random numbers, generating
- rand_s function
- numbers, pseudorandom
- cryptographically secure random numbers
- pseudorandom numbers
- numbers, generating pseudorandom
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d5fde51ee8fb65426166d9d5d2e7d6e5873dd6e8
ms.sourcegitcommit: a5d8f5b92cb5e984d5d6c9d67fe8a1241f3fe184
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/05/2018
---
# <a name="rands"></a>rand_s

Gera um número pseudoaleatório. Esta é uma versão mais segura do que a função [rand](../../c-runtime-library/reference/rand.md), com aprimoramentos de segurança, conforme descrito em [recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md). 

## <a name="syntax"></a>Sintaxe

```C
errno_t rand_s(unsigned int* randomValue);
```

### <a name="parameters"></a>Parâmetros

*randomValue*  
Um ponteiro para um inteiro para manter o valor gerado.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; caso contrário, um código de erro. Se o ponteiro de entrada _randomValue_ é um ponteiro nulo, a função invoca um manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará `EINVAL` e definirá `errno` como `EINVAL`. Se a função falhar por algum motivo, *_randomValue_ é definido como 0.

## <a name="remarks"></a>Comentários

A função `rand_s` grava um inteiro pseudoaleatório no intervalo de 0 a `UINT_MAX` para o ponteiro de entrada. A função `rand_s` usa o sistema operacional para gerar números aleatórios protegidos por criptografia. Ele não usa a semente gerada pela função [srand](../../c-runtime-library/reference/srand.md), nem afeta a sequência de números aleatória usada pelo `rand`.

A função `rand_s` exige que a constante `_CRT_RAND_S` seja definida antes da instrução de inclusão para a função a ser declarada, como no exemplo a seguir:

```C
#define _CRT_RAND_S
#include <stdlib.h>
```

`rand_s` depende da API [RtlGenRandom](http://msdn.microsoft.com/library/windows/desktop/aa387694), que só está disponível no Windows XP e versões posteriores.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`rand_s`|\<stdlib.h>|

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

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)  
[rand](../../c-runtime-library/reference/rand.md)  
[srand](../../c-runtime-library/reference/srand.md)  
