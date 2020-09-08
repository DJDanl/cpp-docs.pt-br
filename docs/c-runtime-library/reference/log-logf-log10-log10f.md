---
title: log, logf, logl, log10, log10f, log10l
description: Referência de API para log, logf, logl, log10, log10f e log10l; que calcula os logaritmos.
ms.date: 9/1/2020
api_name:
- log10f
- logf
- log10
- log
- log10l
- logl
- _o_log
- _o_log10
- _o_log10f
- _o_logf
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
- logf
- logl
- _log10l
- log
- _logl
- log10f
- log10l
- log10
helpviewer_keywords:
- calculating logarithms
- log10f function
- log10 function
- log function
- log10l function
- logl function
- logf function
- logarithms
ms.assetid: 7adc77c2-04f7-4245-a980-21215563cfae
ms.openlocfilehash: f308281705170308ec83e4a5efd9c7825ba47591
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556276"
---
# <a name="log-logf-logl-log10-log10f-log10l"></a>log, logf, logl, log10, log10f, log10l

Calcula logaritmos.

## <a name="syntax"></a>Sintaxe

```C
double log(double x);
float logf(float x);
long double logl(double x);
double log10(double x);
float log10f (float x);
long double log10l(double x);
#define log(X) // Requires C11 or higher
#define log10(X) // Requires C11 or higher

float log(float x);  // C++ only
long double log(long double x);  // C++ only
float log10(float x);  // C++ only
long double log10(long double x);  // C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
Valor cujo logaritmos deve ser localizado.

## <a name="return-value"></a>Valor Retornado

As funções de **log** retornam o logaritmo natural (base *e*) de *x* , se bem-sucedidas. As funções **log10** retornam o logaritmo de base 10. Se *x* for negativo, essas funções retornarão um indefinido (IND), por padrão. Se *x* for 0, eles retornarão infinito (inf).

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± QNAN, IND|nenhum|_DOMAIN|
|± 0|ZERODIVIDE|_SING|
|*x* < 0|INVALID|_DOMAIN|

**log** e **log10** têm uma implementação que usa Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições sobre como usar a implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

## <a name="remarks"></a>Comentários

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **log** e **log10** que levam e retornam **`float`** **`long double`** valores ou. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, o **log** e o **log10** sempre assumem e retornam um **`double`** .

Se você usar a \<tgmath.h> `log()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**log**, **logf**, **logl**, **log10**, **log10f**, **log10l**|\<math.h>|
|macro de **log** | \<tgmath.h> |

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_log.c
/* This program uses log and log10
* to calculate the natural logarithm and
* the base-10 logarithm of 9,000.
*/

#include <math.h>
#include <stdio.h>

int main( void )
{
   double x = 9000.0;
   double y;

   y = log( x );
   printf( "log( %.2f ) = %f\n", x, y );
   y = log10( x );
   printf( "log10( %.2f ) = %f\n", x, y );
}
```

```Output
log( 9000.00 ) = 9.104980
log10( 9000.00 ) = 3.954243
```

Para gerar logaritmos para outras bases, use a relação matemática: log base b de a == log natural (a) / log natural (b).

```cpp
// logbase.cpp
#include <math.h>
#include <stdio.h>

double logbase(double a, double base)
{
   return log(a) / log(base);
}

int main()
{
   double x = 65536;
   double result;

   result = logbase(x, 2);
   printf("Log base 2 of %lf is %lf\n", x, result);
}
```

```Output
Log base 2 of 65536.000000 is 16.000000
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md) <br/>
[exp, expf, expl](exp-expf.md) <br/>
[_matherr](matherr.md) <br/>
[pow, powf, powl](pow-powf-powl.md) <br/>
[_CIlog](../../c-runtime-library/cilog.md) <br/>
[_CIlog10](../../c-runtime-library/cilog10.md)<br/>
