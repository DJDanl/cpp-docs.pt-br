---
title: asinh, asinhf, asinhl
description: Referência de API para asinh, asinhf e asinhl; que calcula o seno hiperbólico inverso de um valor de ponto flutuante.
ms.date: 08/31/2020
api_name:
- asinh
- asinhf
- asinhl
- _o_asinh
- _o_asinhf
- _o_asinhl
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
- asinhf
- asinhl
- asinh
helpviewer_keywords:
- asinh function
- asinhl function
- asinhf function
ms.assetid: 4488babe-1a7e-44ca-8b7b-c2db0a70084f
ms.openlocfilehash: face2eb5f7c6220e1a4369ae0aa11514a918d21c
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91505610"
---
# <a name="asinh-asinhf-asinhl"></a>asinh, asinhf, asinhl

Calcula o seno hiperbólico inverso.

## <a name="syntax"></a>Sintaxe

```C
double asinh( double x );
float asinhf( float x );
long double asinhl( long double x );
#define asinh(X) // Requires C11 or higher

float asinh( float x );  // C++ only
long double asinh( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Valor de ponto flutuante.

## <a name="return-value"></a>Valor Retornado

As funções **asinh** retornam o seno hyberbolic inverso (seno hiperbólico de arco) de *x*. Essa função é válida no domínio de ponto flutuante. Se *x* for um erro Nan, indefinido ou infinito, o mesmo valor será retornado.

|Entrada|Exceção SEH|**_matherr** Exception|
|-----------|-------------------|--------------------------|
|± QNAN, IND, INF|nenhum|nenhum|

## <a name="remarks"></a>Comentários

Ao usar o C++, você pode chamar sobrecargas de **asinh** que usam e retornam **`float`** **`long double`** valores. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **asinh** sempre leva e retorna **`double`** .

Se você usar a \<tgmath.h> `asinh()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C necessário|Cabeçalho C++ necessário|
|--------------|--------------|------------------|
|**asinh**, **asinhf**, **asinhl**|\<math.h>|\<cmath> ou \<math.h>|
|macro **asinh ()** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acosh, acoshf, acoshl](acosh-acoshf-acoshl.md)<br/>
[atanh, atanhf, atanhl](atanh-atanhf-atanhl.md)<br/>
[cosh, coshf, coshl](cosh-coshf-coshl.md)<br/>
[sinh, sinhf, sinhl](sinh-sinhf-sinhl.md)<br/>
[tanh, tanhf, tanhl](tanh-tanhf-tanhl.md)<br/>
