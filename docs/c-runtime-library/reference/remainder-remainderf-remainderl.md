---
title: remainder, remainderf, remainderl
description: Referência de API para resto, remainderf e restoal; que calcula o restante do quociente de dois valores de ponto flutuante, arredondado para o valor integral mais próximo.
ms.date: 9/1/2020
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
ms.openlocfilehash: 288d6b0d373a5b318a139b030181c671e2c01048
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507580"
---
# <a name="remainder-remainderf-remainderl"></a>remainder, remainderf, remainderl

Calcula o restante do quociente de dois valores de ponto flutuantes, arredondados para o valor integral mais próximo.

## <a name="syntax"></a>Sintaxe

```C
double remainder( double x, double y );
float remainderf( float x, float y );
long double remainderl( long double x, long double y );
#define remainder(X, Y) // Requires C11 or higher

float remainder( float x, float y ); /* C++ only */
long double remainder( long double x, long double y ); /* C++ only */
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O numerador.

*Iar*\
O denominador.

## <a name="return-value"></a>Valor Retornado

O restante de ponto flutuante de *x*  /  *y*. Se o valor de *y* for 0,0, **resto** retornará um NaN silencioso. Para obter informações sobre a representação de um NaN silencioso pela família **printf** , consulte [printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

As **funções restantes** calculam o *r* restante de ponto flutuante *de x*  /  *y* de forma que *x*  =  *n* \* *y*  +  *r*, em que *n*é o inteiro mais próximo no valor para *x*  /  *y* e *n*é mesmo sempre que &#124; *n*  -  *x*  /  *y* &#124; = 1/2. Quando *r* = 0, *r* tem o mesmo sinal que *x*.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **pendências** que levam e retornam **`float`** **`long double`** valores. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **resto** sempre usa dois **`double`** argumentos e retorna um **`double`** .

Se você usar a \<tgmath.h> `remainder()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------|-|
|**resto**, **remainderf**, **restantel**|\<math.h>|\<cmath> ou \<math.h>|
|macro **restante** | \<tgmath.h> ||

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

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)\
[ldiv, lldiv](./div.md)\
[imaxdiv](imaxdiv.md)\
[fmod, fmodf](fmod-fmodf.md)\
[remquo, remquof, remquol](remquo-remquof-remquol.md)
