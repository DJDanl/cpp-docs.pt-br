---
title: acosh, acoshf, acoshl
ms.date: 04/05/2018
apiname:
- acoshf
- acosh
- acoshl
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
ms.openlocfilehash: e61b9ed4222898e3f2340a5e54f6983fb0411c72
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62341685"
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

### <a name="parameters"></a>Parâmetros

*x*<br/>
Valor de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

O **acosh** funções retornam o cosseno hiperbólico inverso (arcosseno hiperbólico) de *x*. Essas funções são válidas no domínio *x* ≥ 1. Se *x* é menor que 1 `errno` é definido como `EDOM` e o resultado será um NaN silencioso. Se *x* é um NaN silencioso, indefinido, ou infinito, o mesmo valor é retornado.

|Entrada|Exceção SEH|Exceção `_matherr`|
|-----------|-------------------|--------------------------|
|± QNAN, IND, INF|nenhum|nenhum|
|*x* < 1|nenhum|nenhum|

## <a name="remarks"></a>Comentários

Ao usar o C++, é possível chamar sobrecargas de **acosh** que usam e retornam **float** ou **longo** **double** valores. Em um programa do C **acosh** sempre usa e retorna **duplo**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**acosh**, **acoshf**, **acoshl**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[asinh, asinhf, asinhl](asinh-asinhf-asinhl.md)<br/>
[atanh, atanhf, atanhl](atanh-atanhf-atanhl.md)<br/>
[cosh, coshf, coshl](cosh-coshf-coshl.md)<br/>
[sinh, sinhf, sinhl](sinh-sinhf-sinhl.md)<br/>
[tanh, tanhf, tanhl](tanh-tanhf-tanhl.md)