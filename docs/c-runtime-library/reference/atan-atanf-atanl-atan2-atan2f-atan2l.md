---
title: atan, atanf, atanl, atan2, atan2f, atan2l | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- atan2f
- atan2l
- atan2
- atanf
- atan
- atanl
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
- atan
- atan2l
- atan2
- atanl
- atanf
- atan2f
dev_langs:
- C++
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
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b1c17693a5f73ed7e755c69b5b2157d5de792c76
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="atan-atanf-atanl-atan2-atan2f-atan2l"></a>atan, atanf, atanl, atan2, atan2f, atan2l

Calcula o arco tangente de **x** (**atan**, **atanf**, e **atanl**) ou o arco tangente de **y** / **x** (**atan2**, **atan2f**, e **atan2l**).

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

**ATAN** retorna o arco tangente de *x* no intervalo - π/2 a π/2 radianos. **ATAN2** retorna o arco tangente de *y*/*x* no intervalo - π, em radianos π. Se *x* é 0, **atan** retornará 0. Se ambos os parâmetros de **atan2** são 0, a função retornará 0. Todos os resultados estão em radianos.

**ATAN2** usa os sinais de ambos os parâmetros para determinar o quadrante do valor de retorno.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± **QNAN**, **IND**|nenhum|**DOMAIN**|

## <a name="remarks"></a>Comentários

O **atan** função calcula o arco tangente (a função de tangente inversa) de *x*. **ATAN2** calcula o arco tangente de *y*/*x* (se *x* é igual a 0, **atan2** retorna π/2 se *y* for positivo, - π/2 se *y* for negativo ou 0 se *y* é 0.)

**ATAN** tem uma implementação que usa extensões Streaming SIMD 2 (SSE2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **atan** e **atan2** que usam **float** ou **longo** **duplo**  argumentos. Em um programa C, **atan** e **atan2** sempre fazer **duplo** argumentos e retornar um **duplo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------|-|
|**ATAN**, **atan2**, **atanf**, **atan2f**, **atanl**, **atan2l**|\<math.h>|\<cmath> ou \<math.h>|

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
