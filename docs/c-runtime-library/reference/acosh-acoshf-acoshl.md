---
title: acosh, acoshf, acoshl
ms.date: 4/2/2020
api_name:
- acoshf
- acosh
- acoshl
- _o_acosh
- _o_acoshf
- _o_acoshl
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
- acosh
- acoshf
- acoshl
- math/acosh
- math/acoshf
- math/acoshl
helpviewer_keywords:
- acoshf function
- acosh function
- acoshl function
ms.assetid: 6985c4d7-9e2a-44ce-9a9b-5a43015f15f7
ms.openlocfilehash: a6883c23d06115c8775dd919123671feac380b99
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220750"
---
# <a name="acosh-acoshf-acoshl"></a>acosh, acoshf, acoshl

Calcula o cosseno hiperbólico inverso.

## <a name="syntax"></a>Sintaxe

```C
double acosh( double x );
float acoshf( float x );
long double acoshl( long double x );
```

```cpp
float acosh( float x );  // C++ only
long double acosh( long double x );  // C++ only
```

### <a name="parameters"></a>parâmetros

*x*<br/>
Valor de ponto flutuante.

## <a name="return-value"></a>Valor retornado

As funções **ACOSH** retornam o cosseno hyberbolic inverso (arco hiperbólico cosseno) de *x*. Essas funções são válidas no domínio *x* ≥ 1. Se *x* for menor que 1, `errno` será definido como `EDOM` e o resultado será um NaN silencioso. Se *x* for um erro Nan, indefinido ou infinito, o mesmo valor será retornado.

|Entrada|Exceção SEH|Exceção `_matherr`|
|-----------|-------------------|--------------------------|
|± QNAN, IND, INF|nenhuma|nenhuma|
|*x* < 1|nenhuma|nenhuma|

## <a name="remarks"></a>Comentários

Ao usar o C++, você pode chamar sobrecargas de **ACOSH** que usam e retornam **`float`** **`long double`** valores. Em um programa C, **ACOSH** sempre leva e retorna **`double`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**ACOSH**, **acoshf**, **acoshl**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_acosh.c
// Compile by using: cl /W4 crt_acosh.c
// This program displays the hyperbolic cosine of pi / 4
// and the arc hyperbolic cosine of the result.

#include <math.h>
#include <stdio.h>

int main( void )
{
   double pi = 3.1415926535;
   double x, y;

   x = cosh( pi / 4 );
   y = acosh( x );
   printf( "cosh( %f ) = %f\n", pi/4, x );
   printf( "acosh( %f ) = %f\n", x, y );
}
```

```Output
cosh( 0.785398 ) = 1.324609
acosh( 1.324609 ) = 0.785398
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[asinh, asinhf, asinhl](asinh-asinhf-asinhl.md)<br/>
[atanh, atanhf, atanhl](atanh-atanhf-atanhl.md)<br/>
[cosh, coshf, coshl](cosh-coshf-coshl.md)<br/>
[sinh, sinhf, sinhl](sinh-sinhf-sinhl.md)<br/>
[tanh, tanhf, tanhl](tanh-tanhf-tanhl.md)
