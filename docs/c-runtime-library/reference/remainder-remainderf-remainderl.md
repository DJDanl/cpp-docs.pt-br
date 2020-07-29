---
title: remainder, remainderf, remainderl
ms.date: 4/2/2020
api_name:
- remainderl
- remainder
- remainderf
- _o_remainder
- _o_remainderf
- _o_remainderl
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
- api-ms-win-crt-math-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- remainderf
- remainder
- remainderl
helpviewer_keywords:
- remainderf
- remainderl
- remainder
ms.assetid: 5f721fb3-8b78-4597-9bc0-ca9bcd1f1d0e
ms.openlocfilehash: b880054430574b6ea1e8bc456774acc35cf116ad
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216798"
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

### <a name="parameters"></a>parâmetros

*x*<br/>
O numerador.

*Iar*<br/>
O denominador.

## <a name="return-value"></a>Valor retornado

O restante de ponto flutuante de *x*  /  *y*. Se o valor de *y* for 0,0, **resto** retornará um NaN silencioso. Para obter informações sobre a representação de um NaN silencioso pela família **printf** , consulte [printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

As **funções restantes** calculam o *r* restante de ponto flutuante *de x*  /  *y* de forma que *x*  =  *n* \* *y*  +  *r*, em que *n*é o inteiro mais próximo no valor para *x*  /  *y* e *n*é mesmo sempre que &#124; *n*  -  *x*  /  *y* &#124; = 1/2. Quando *r* = 0, *r* tem o mesmo sinal que *x*.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **pendências** que levam e retornam **`float`** **`long double`** valores. Em um programa C, **resto** sempre usa dois **`double`** argumentos e retorna um **`double`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------|-|
|**resto**, **remainderf**, **restantel**|\<math.h>|\<cmath> ou \<math.h>|

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

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldiv, lldiv](ldiv-lldiv.md)<br/>
[imaxdiv](imaxdiv.md)<br/>
[fmod, fmodf](fmod-fmodf.md)<br/>
[remquo, remquof, remquol](remquo-remquof-remquol.md)<br/>
