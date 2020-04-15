---
title: pow, powf, powl
ms.date: 4/2/2020
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: b181959ac05814a673ab11f33e4cfc5a39e3869e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81333115"
---
# <a name="pow-powf-powl"></a>pow, powf, powl

Calcula *x* elevado ao poder de *y*.

## <a name="syntax"></a>Sintaxe

```C
double pow( double x, double y );
float powf( float x, float y );
long double powl( long double x, long double y );
```

```cpp
double pow( double x, int y );  // C++ only
float pow( float x, float y );  // C++ only
float pow( float x, int y );  // C++ only
long double pow( long double x, long double y );  // C++ only
long double pow( long double x, int y );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Base.

*Y*<br/>
Expoente.

## <a name="return-value"></a>Valor retornado

Retorna o valor de *x*<sup>*y*</sup>. Nenhuma mensagem de erro é impressa em estouro ou estouro negativo.

|Valores de x e y|Valor retornado de pow|
|-----------------------|-------------------------|
|*x* != 0,0 e *y* == 0,0|1|
|*x* == 0,0 e *y* == 0,0|1|
|*x* == 0,0 e *y* < 0|INF|

## <a name="remarks"></a>Comentários

**pow** não reconhece valores de ponto flutuante integral superiores a 2<sup>64</sup> (por exemplo, 1.0E100).

**pow** tem uma implementação que usa o Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

Como c++ permite sobrecarga, você pode chamar qualquer uma das várias sobrecargas de **pow**. Em um programa C, **pow** sempre pega dois valores **duplos** e retorna um valor **duplo.**

A sobrecarga `pow(int, int)` não está mais disponível. Se você usar esta sobrecarga, o compilador pode emitir [C2668](../../error-messages/compiler-errors-2/compiler-error-c2668.md). Para evitar esse problema, lance o primeiro parâmetro para **dobrar,** **flutuar**ou **dobrar.** **double**

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-|-|-|
|**pow**, **powf,** **powl**|\<math.h>|\<math.h> ou \<cmath>|

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

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md) <br/>
[exp, expf, expl](exp-expf.md) <br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md) <br/>
[sqrt, sqrtf, sqrtl](sqrt-sqrtf-sqrtl.md) <br/>
[_CIpow](../../c-runtime-library/cipow.md)<br/>
