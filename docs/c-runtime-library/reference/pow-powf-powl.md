---
title: pow, powf, powl
description: Referência de API para pow, powf e Powl; que calculam o aumento para uma potência.
ms.date: 08/31/2020
api_name:
- powl
- pow
- powf
- _o_pow
- _o_powf
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
- powl
- pow
- _powl
- powf
helpviewer_keywords:
- exponential calculations
- powl function
- _powl function
- exponentiation
- powers, calculating
- calculating exponentials
- powf function
- pow function
ms.assetid: e75c33ed-2e59-48b1-be40-81da917324f1
ms.openlocfilehash: 8fb6679e2b509274b4ea60c410a81b54df866416
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91505569"
---
# <a name="pow-powf-powl"></a>pow, powf, powl

Calcula *x* elevado à potência de *y*.

## <a name="syntax"></a>Sintaxe

```C
double pow( double x, double y );
float powf( float x, float y );
long double powl( long double x, long double y );
define pow(X, Y) // Requires C11 or higher

double pow( double x, int y );  // C++ only
float pow( float x, float y );  // C++ only
float pow( float x, int y );  // C++ only
long double pow( long double x, long double y );  // C++ only
long double pow( long double x, int y );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
Base.

*Iar*\
Expoente.

## <a name="return-value"></a>Valor Retornado

Retorna o valor de *x*<sup>*y*</sup>. Nenhuma mensagem de erro é impressa em estouro ou estouro negativo.

|Valores de x e y|Valor retornado de pow|
|-----------------------|-------------------------|
|*x* ! = 0,0 e *y* = = 0,0|1|
|*x* = = 0,0 e *y* = = 0,0|1|
|*x* = = 0,0 e *y* < 0|INF|

## <a name="remarks"></a>Comentários

**pow** não reconhece valores inteiros de ponto flutuante maiores que 2<sup>64</sup> (por exemplo, 1,0 E100).

o **pow** tem uma implementação que usa Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

Como o C++ permite sobrecarga, você pode chamar qualquer uma das várias sobrecargas de **pow**. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **pow** sempre pega dois **`double`** valores e retorna um **`double`** valor.

Se você usar a \<tgmath.h> `pow()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

A sobrecarga `pow(int, int)` não está mais disponível. Se você usar essa sobrecarga, o compilador poderá emitir [C2668](../../error-messages/compiler-errors-2/compiler-error-c2668.md). Para evitar esse problema, converta o primeiro parâmetro para **`double`** , **`float`** ou **`long double`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-|-|-|
|**pow**, **powf**, **Powl**|\<math.h>|\<math.h> ou \<cmath>|
|macro **pow** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_pow.c

#include <math.h>
#include <stdio.h>

int main( void )
{
   double x = 2.0, y = 3.0, z;

   z = pow( x, y );
   printf( "%.1f to the power of %.1f is %.1f\n", x, y, z );
}
```

```Output
2.0 to the power of 3.0 is 8.0
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md) <br/>
[exp, expf, expl](exp-expf.md) <br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md) <br/>
[sqrt, sqrtf, sqrtl](sqrt-sqrtf-sqrtl.md) <br/>
[_CIpow](../../c-runtime-library/cipow.md)<br/>
