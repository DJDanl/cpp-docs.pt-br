---
title: asinh, asinhf, asinhl
ms.date: 04/05/2018
apiname:
- asinh
- asinhf
- asinhl
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
- asinhf
- asinhl
- asinh
helpviewer_keywords:
- asinh function
- asinhl function
- asinhf function
ms.assetid: 4488babe-1a7e-44ca-8b7b-c2db0a70084f
ms.openlocfilehash: f6100268b77178487b7a7aa1cc3f10ac3ea7e9dc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62341776"
---
# <a name="asinh-asinhf-asinhl"></a>asinh, asinhf, asinhl

Calcula o seno hiperbólico inverso.

## <a name="syntax"></a>Sintaxe

```C
double asinh( double x );
float asinhf( float x );
long double asinhl( long double x );
```

```cpp
float asinh( float x );  // C++ only
long double asinh( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Valor de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

O **asinh** funções retornam o seno hiperbólico inverno (seno hiperbólico do arco) de *x*. Essa função é válida no domínio de ponto flutuante. Se *x* é um NaN silencioso, indefinido, ou infinito, o mesmo valor é retornado.

|Entrada|Exceção SEH|**matherr** exceção|
|-----------|-------------------|--------------------------|
|± QNAN, IND, INF|nenhum|nenhum|

## <a name="remarks"></a>Comentários

Ao usar o C++, é possível chamar sobrecargas de **asinh** que usam e retornam **float** ou **longo** **double** valores. Em um programa do C **asinh** sempre usa e retorna **duplo**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C necessário|Cabeçalho C++ necessário|
|--------------|--------------|------------------|
|**asinh**, **asinhf**, **asinhl**|\<math.h>|\<cmath > ou \<Math <|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_asinh.c
// Compile by using: cl /W4 crt_asinh.c
// This program displays the hyperbolic sine of pi / 4
// and the arc hyperbolic sine of the result.

#include <math.h>
#include <stdio.h>

int main( void )
{
   double pi = 3.1415926535;
   double x, y;

   x = sinh( pi / 4 );
   y = asinh( x );
   printf( "sinh( %f ) = %f\n", pi/4, x );
   printf( "asinh( %f ) = %f\n", x, y );
}
```

```Output
sinh( 0.785398 ) = 0.868671
asinh( 0.868671 ) = 0.785398
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acosh, acoshf, acoshl](acosh-acoshf-acoshl.md)<br/>
[atanh, atanhf, atanhl](atanh-atanhf-atanhl.md)<br/>
[cosh, coshf, coshl](cosh-coshf-coshl.md)<br/>
[sinh, sinhf, sinhl](sinh-sinhf-sinhl.md)<br/>
[tanh, tanhf, tanhl](tanh-tanhf-tanhl.md)<br/>
