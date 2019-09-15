---
title: atan, atanf, atanl, atan2, atan2f, atan2l
ms.date: 04/05/2018
api_name:
- atan2f
- atan2l
- atan2
- atanf
- atan
- atanl
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- atan
- atan2l
- atan2
- atanl
- atanf
- atan2f
helpviewer_keywords:
- atan function
- atanf function
- atanl function
- atan2 function
- atan2l function
- arctangent function
- trigonometric functions
- atan2f function
ms.assetid: 7a87a18e-c94d-4727-9cb1-1bb5c2725ae4
ms.openlocfilehash: 8c485dea281d2b754628c9663e38ea10a9b6ab57
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70939601"
---
# <a name="atan-atanf-atanl-atan2-atan2f-atan2l"></a>atan, atanf, atanl, atan2, atan2f, atan2l

Calcula o arco tangente de **x** (**ATAN**, **atanf**e **atanl**) ou o arco tangente de **y**/**x** (**ATAN2**, **atan2f**e **atan2l**).

## <a name="syntax"></a>Sintaxe

```C
double atan( double x );
float atanf( float x );
long double atanl( long double x );

double atan2( double y, double x );
float atan2f( float y, float x );
long double atan2l( long double y, long double x );
```

```cpp
float atan( float x );  // C++ only
long double atan( long double x );  // C++ only

float atan2( float y, float x );  // C++ only
long double atan2( long double y, long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*, *y*<br/>
Quaisquer números.

## <a name="return-value"></a>Valor de retorno

**ATAN** retorna o arco tangente de *x* no intervalo de-π/2 a π/2 radianos. **ATAN2** retorna o arco tangente de *y*/*x* no intervalo de π a π radianos. Se *x* for 0, **ATAN** retornará 0. Se ambos os parâmetros de **ATAN2** forem 0, a função retornará 0. Todos os resultados estão em radianos.

**ATAN2** usa os sinais de ambos os parâmetros para determinar o quadrante do valor de retorno.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± **QNAN**, **IND**|nenhum|**_DOMAIN**|

## <a name="remarks"></a>Comentários

A função **ATAN** calcula o arco tangente (a função tangente inversa) de *x*. **ATAN2** calcula o arco tangente de *y*/*x* (se *x* for igual a 0, **ATAN2** retornará π/2 se *y* for positivo,-π/2 se *y* for negativo ou 0 se *y* for 0.)

**ATAN** tem uma implementação que usa Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **ATAN** e **ATAN2** que têm argumentos **duplos** **float** ou **Long** . Em um programa C, **ATAN** e **ATAN2** sempre assumem argumentos **duplos** e retornam um **Double**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------|-|
|**atan**, **atan2**, **atanf**, **atan2f**, **atanl**, **atan2l**|\<math.h>|\<cmath> ou \<math.h>|

## <a name="example"></a>Exemplo

```C
// crt_atan.c
// arguments: 5 0.5
#include <math.h>
#include <stdio.h>
#include <errno.h>

int main( int ac, char* av[] )
{
   double x, y, theta;
   if( ac != 3 ){
      fprintf( stderr, "Usage: %s <x> <y>\n", av[0] );
      return 1;
   }
   x = atof( av[1] );
   theta = atan( x );
   printf( "Arctangent of %f: %f\n", x, theta );
   y = atof( av[2] );
   theta = atan2( y, x );
   printf( "Arctangent of %f / %f: %f\n", y, x, theta );
   return 0;
}
```

```Output
Arctangent of 5.000000: 1.373401
Arctangent of 0.500000 / 5.000000: 0.099669
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acos, acosf, acosl](acos-acosf-acosl.md)<br/>
[asin, asinf, asinl](asin-asinf-asinl.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[_matherr](matherr.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
[tan, tanf, tanl](tan-tanf-tanl.md)<br/>
[_CIatan](../../c-runtime-library/ciatan.md)<br/>
[_CIatan2](../../c-runtime-library/ciatan2.md)<br/>
