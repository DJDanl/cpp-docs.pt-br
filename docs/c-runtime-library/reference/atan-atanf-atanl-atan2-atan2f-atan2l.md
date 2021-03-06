---
title: atan, atanf, atanl, atan2, atan2f, atan2l
description: Referência de API para Atan, atanf, atanl, atan2, atan2f e atan2l; que calcula o arco tangente de um valor de ponto flutuante.
ms.date: 08/31/2020
api_name:
- atan2f
- atan2l
- atan2
- atanf
- atan
- atanl
- _o_atan
- _o_atan2
- _o_atan2f
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
ms.openlocfilehash: 1f1d33aac86d94ab3731dd5cf5b124af99ccb3f2
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555624"
---
# <a name="atan-atanf-atanl-atan2-atan2f-atan2l"></a>atan, atanf, atanl, atan2, atan2f, atan2l

Calcula o arco tangente de **x** (**ATAN**, **atanf**e **atanl**) ou o arco tangente de **y** / **x** (**ATAN2**, **atan2f**e **atan2l**).

## <a name="syntax"></a>Sintaxe

```C
double atan( double x );
float atanf( float x );
long double atanl( long double x );
#define atan(X) // Requires C11 or higher

float atan( float x );  // C++ only
long double atan( long double x );  // C++ only

double atan2( double y, double x );
float atan2f( float y, float x );
long double atan2l( long double y, long double x );
#define atan2(Y, X) // Requires C11 or higher

float atan2( float y, float x );  // C++ only
long double atan2( long double y, long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*, *y*\
Quaisquer números.

## <a name="return-value"></a>Valor Retornado

**ATAN** retorna o arco tangente de *x* no intervalo de-π/2 a π/2 radianos. **ATAN2** retorna o arco tangente de *y* / *x* no intervalo de π a π radianos. Se *x* for 0, **ATAN** retornará 0. Se ambos os parâmetros de **ATAN2** forem 0, a função retornará 0. Todos os resultados estão em radianos.

**ATAN2** usa os sinais de ambos os parâmetros para determinar o quadrante do valor de retorno.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± **QNAN**, **Ind**|nenhum|**_DOMAIN**|

## <a name="remarks"></a>Comentários

A função **ATAN** calcula o arco tangente (a função tangente inversa) de *x*. **ATAN2** calcula o arco tangente de *y* / *x* (se *x* for igual a 0, **ATAN2** retornará π/2 se *y* for positivo,-π/2 se *y* for negativo ou 0 se *y* for 0.)

Se você usar a \<tgmath.h> `atan()` `atan2()` macro ou, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

**ATAN** tem uma implementação que usa Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **ATAN** e **ATAN2** que levam **`float`** ou **`long double`** argumentos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **ATAN** e **ATAN2** sempre usam **`double`** argumentos e retornam um **`double`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-------------|---------------------|-|
|**ATAN**, **ATAN2**, **atanf**, **atan2f**, **atanl**, **atan2l**|\<math.h>|\<cmath> ou \<math.h>|
|macros **ATAN ()**, **ATAN2** | \<tgmath.h> ||

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

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acos, acosf, acosl](acos-acosf-acosl.md)<br/>
[asin, asinf, asinl](asin-asinf-asinl.md)<br/>
[cos, cosf, cosl](cos-cosf-cosl.md)<br/>
[_matherr](matherr.md)<br/>
[sin, sinf, sinl](sin-sinf-sinl.md)<br/>
[tan, tanf, tanl](tan-tanf-tanl.md)<br/>
[_CIatan](../../c-runtime-library/ciatan.md)<br/>
[_CIatan2](../../c-runtime-library/ciatan2.md)<br/>
