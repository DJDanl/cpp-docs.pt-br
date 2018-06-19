---
title: rand_s | Microsoft Docs
ms.custom: ''
ms.date: 1/02/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- rand_s
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
f1_keywords:
- rand_s
dev_langs:
- C++
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
ms.workload:
- cplusplus
ms.openlocfilehash: 8407848db8f442324127df8d7267a5350c077b2f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405751"
---
# <a name="rands"></a>rand_s

Gera um número pseudoaleatório. Esta é uma versão mais segura do que a função [rand](rand.md), com aprimoramentos de segurança, conforme descrito em [recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t rand_s(unsigned int* randomValue);
```

### <a name="parameters"></a>Parâmetros

*randomValue*<br/>
Um ponteiro para um inteiro para manter o valor gerado.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; caso contrário, um código de erro. Se o ponteiro de entrada _randomValue_ é um ponteiro nulo, a função invoca um manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, a função retorna **EINVAL** e define **errno** para **EINVAL**. Se a função falhar por algum motivo, *_randomValue_ é definido como 0.

## <a name="remarks"></a>Comentários

O **rand_s** função grava um pseudoaleatórios inteiro no intervalo de 0 a **UINT_MAX** ponteiro de entrada. O **rand_s** função usa o sistema operacional para gerar números aleatórios criptograficamente seguros. Não usar a propagação gerada pelo [srand](srand.md) função, nem afeta a sequência de número aleatória usada pelo [rand](rand.md).

O **rand_s** função requer que constante **_CRT_RAND_S** ser definido antes da instrução de inclusão para a função deve ser declarado como no exemplo a seguir:

```C
#define _CRT_RAND_S
#include <stdlib.h>
```

**rand_s** depende de [RtlGenRandom](http://msdn.microsoft.com/library/windows/desktop/aa387694) API, que só está disponível no Windows XP e versões posteriores.

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
