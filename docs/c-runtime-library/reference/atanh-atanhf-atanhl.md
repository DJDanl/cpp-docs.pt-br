---
title: atanh, atanhf, atanhl
description: Referência de API para ATANH, atanhf e atanhl; que calcula a tangente hiperbólica inversa de um valor de ponto flutuante.
ms.date: 08/31/2020
api_name:
- atanhl
- atanhf
- atanh
- _o_atanh
- _o_atanhf
- _o_atanhl
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
- atanhl
- atanhf
- atanh
helpviewer_keywords:
- atanhf function
- atanhl function
- atanh funciton
ms.assetid: 83a43b5b-2580-4461-854f-dc84236d9f32
ms.openlocfilehash: c0a8e06963519553144c7e49d26e61dbbde51c21
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555586"
---
# <a name="atanh-atanhf-atanhl"></a>atanh, atanhf, atanhl

Calcula a tangente hiperbólica inversa.

## <a name="syntax"></a>Sintaxe

```C
double atanh( double x );
float atanhf( float x );
long double atanhl( long double x );
#define atanh(X) // Requires C11 or higher

float atanh( float x );  // C++ only
long double atanh( long double x );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
Valor de ponto flutuante.

## <a name="return-value"></a>Valor Retornado

As funções **ATANH** retornam a tangente inversa hyberbolic (tangente hiperbólica do arco) de *x*. Se *x* for maior que 1 ou menor que-1, **errno** será definido como **Edom** e o resultado será um NaN silencioso. Se *x* for igual a 1 ou-1, um infinito positivo ou negativo será retornado, respectivamente, e **errno** será definido como **ERANGE**.

|Entrada|Exceção SEH|**Matherr** Exception|
|-----------|-------------------|-------------------------|
|± QNAN,IND|nenhum|nenhum|
|*X* ≥ 1; *x* ≤-1|nenhum|nenhum|

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **ATANH** que usam e retornam **`float`** **`long double`** valores. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **ATANH** sempre leva e retorna **`double`** .

Se você usar a \<tgmath.h> `atanh()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**ATANH**, **atanhf**, **atanhl**|\<math.h>|\<cmath> ou \<math.h>|
|macro **ATANH ()** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_atanh.c
// This program displays the hyperbolic tangent of pi / 4
// and the arc hyperbolic tangent of the result.
//

#include <math.h>
#include <stdio.h>

int main( void )
{
   double pi = 3.1415926535;
   double x, y;

   x = tanh( pi / 4 );
   y = atanh( x );
   printf( "tanh( %f ) = %f\n", pi/4, x );
   printf( "atanh( %f ) = %f\n", x, y );
}
```

```Output
tanh( 0.785398 ) = 0.655794
atanh( 0.655794 ) = 0.785398
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[acosh, acoshf, acoshl](acosh-acoshf-acoshl.md)<br/>
[asinh, asinhf, asinhl](asinh-asinhf-asinhl.md)<br/>
[cosh, coshf, coshl](cosh-coshf-coshl.md)<br/>
[sinh, sinhf, sinhl](sinh-sinhf-sinhl.md)<br/>
[tanh, tanhf, tanhl](tanh-tanhf-tanhl.md)<br/>
