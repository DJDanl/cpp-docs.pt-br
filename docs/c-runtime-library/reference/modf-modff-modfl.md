---
title: modf, modff, modfl
description: Referência de API para modf, modff e modfl; que divide um valor de ponto flutuante em partes fracionárias e de inteiros.
ms.date: 4/2/2020
api_name:
- modff
- modf
- modfl
- _o_modf
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
- modff
- _modfl
- modf
- modfl
- math/modf
- math/modff
- math/modfl
helpviewer_keywords:
- modf function
- modff function
- modfl function
ms.assetid: b1c7abf5-d476-43ca-a03c-02072a86e32d
ms.openlocfilehash: 0d3522079acc8a9d2c8409b1cad78e7f50a7f788
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556756"
---
# <a name="modf-modff-modfl"></a>modf, modff, modfl

Divide um valor de ponto flutuante em partes inteiras e fracionárias.

## <a name="syntax"></a>Sintaxe

```C
double modf( double x, double * intptr );
float modff( float x, float * intptr );
long double modfl( long double x, long double * intptr );
```

```cpp
float modf( float x, float * intptr );  // C++ only
long double modf( long double x, long double * intptr );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Valor de ponto flutuante.

*IntPtr*<br/>
Ponteiro para a parte inteira armazenada.

## <a name="return-value"></a>Valor Retornado

Esta função retorna a parte fracionária com sinal de *x*. Não há nenhum retorno de erro.

## <a name="remarks"></a>Comentários

As funções **modf** dividem o valor de ponto flutuante *x* em partes fracionárias e de inteiros, cada um com o mesmo sinal de *x*. A parte fracionária assinada de *x* é retornada. A parte inteira é armazenada como um valor de ponto flutuante em *IntPtr*.

o **modf** tem uma implementação que usa Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições sobre como usar a implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **modf** que usam e retornam **`float`** **`long double`** parâmetros. Em um programa C, **modf** sempre usa dois valores double e retorna um valor Double.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**modf**, **modff**, **modfl**|& \<math.h><br /><br /> C++: \<cmath> ou \<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_modf.c

#include <math.h>
#include <stdio.h>

int main( void )
{
   double x, y, n;

   x = -14.87654321;      /* Divide x into its fractional */
   y = modf( x, &n );     /* and integer parts            */

   printf( "For %f, the fraction is %f and the integer is %.f\n",
           x, y, n );
}
```

```Output
For -14.876543, the fraction is -0.876543 and the integer is -14
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[frexp](frexp.md)<br/>
[ldexp](ldexp.md)<br/>
