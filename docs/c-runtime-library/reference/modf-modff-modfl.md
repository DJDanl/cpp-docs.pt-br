---
title: modf, modff, modfl
ms.date: 04/05/2018
apiname:
- modff
- modf
- modfl
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
ms.openlocfilehash: 59d6e2b9b02ad182c5630d6dc9a989c035e8fa92
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62156324"
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

*intptr*<br/>
Ponteiro para a parte inteira armazenada.

## <a name="return-value"></a>Valor de retorno

Esta função retorna a parte fracionária com sinal de *x*. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

O **modf** funções dividem o valor de ponto flutuante *x* em fracionários e partes de inteiro, cada um deles tem o mesmo sinal *x*. A parte fracionária com sinal de *x* é retornado. A parte inteira é armazenada como um valor de ponto flutuante em *intptr*.

**modf** tem uma implementação que usa Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições sobre como usar a implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

C++ permite sobrecargas, portanto, é possível chamar sobrecargas de **modf** que usam e retornam **float** ou **longo** **double** parâmetros. Em um programa do C **modf** sempre usa dois valores duplos e retorna um valor duplo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**modf**, **modff**, **modfl**|C: \<math.h><br /><br /> C++: , \<cmath> ou \<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[frexp](frexp.md)<br/>
[ldexp](ldexp.md)<br/>
