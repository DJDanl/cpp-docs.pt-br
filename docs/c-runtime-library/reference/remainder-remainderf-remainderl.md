---
title: remainder, remainderf, remainderl | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- remainderl
- remainder
- remainderf
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
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- remainderf
- remainder
- remainderl
dev_langs:
- C++
helpviewer_keywords:
- remainderf
- remainderl
- remainder
ms.assetid: 5f721fb3-8b78-4597-9bc0-ca9bcd1f1d0e
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 52abbfef2e20bebd531ef2d6c7a414f8345d996b
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="remainder-remainderf-remainderl"></a>remainder, remainderf, remainderl

Calcula o restante do quociente de dois valores de ponto flutuantes, arredondados para o valor integral mais próximo.

## <a name="syntax"></a>Sintaxe

```C
double remainder( double x, double y );
float remainderf( float x, float y );
long double remainderl( long double x, long double y );
```

```cpp
float remainder( float x, float y ); /* C++ only */
long double remainder( long double x, long double y ); /* C++ only */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O numerador.

*y*<br/>
O denominador.

## <a name="return-value"></a>Valor de retorno

O restante de ponto flutuante de *x* / *y*. Se o valor de *y* é 0.0, **restante** retorna um NaN silenciosa. Para obter informações sobre a representação de um NaN silenciosa, o **printf** família, consulte [printf, printf_l, and wprintf, wprintf_l](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

O **restante** funções calculam o restante de ponto flutuante *r* de *x* / *y* , de modo que *x*   =  *n* * *y* + *r*, onde *n*é o número inteiro mais próximo valor para *x* / *y* e *n*é o mesmo sempre que &#124; *n*  -  *x* / *y* &#124; = 1/2. Quando *r* = 0, *r* tem o mesmo sinal *x*.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **restante** que levar e retornar **float** ou **longo** **duplo** valores. Em um programa C, **restante** sempre leva dois **duplo** argumentos e retorna um **duplo**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------|-|
|**restante**, **remainderf**, **remainderl**|\<math.h>|\<cmath> ou \<math.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_remainder.c
// This program displays a floating-point remainder.

#include <math.h>
#include <stdio.h>

int main( void )
{
   double w = -10.0, x = 3.0, z;

   z = remainder(w, x);
   printf("The remainder of %.2f / %.2f is %f\n", w, x, z);
}
```

```Output
The remainder of -10.00 / 3.00 is -1.000000
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldiv, lldiv](ldiv-lldiv.md)<br/>
[imaxdiv](imaxdiv.md)<br/>
[fmod, fmodf](fmod-fmodf.md)<br/>
[remquo, remquof, remquol](remquo-remquof-remquol.md)<br/>
