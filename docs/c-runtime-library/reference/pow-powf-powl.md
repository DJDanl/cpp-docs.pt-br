---
title: pow, powf, powl | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- powl
- pow
- powf
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
- powl
- pow
- _powl
- powf
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5daf7348198cb6f3ba0186eb4586b2486548f6f5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="pow-powf-powl"></a>pow, powf, powl

Calcula *x* elevado à potência de *y*.

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

*y*<br/>
Expoente.

## <a name="return-value"></a>Valor de retorno

Retorna o valor de *x*<sup>*y*</sup>. Nenhuma mensagem de erro é impressa em estouro ou estouro negativo.

|Valores de x e y|Valor retornado de pow|
|-----------------------|-------------------------|
|*x* ! = 0,0 e *y* = = 0,0|1|
|*x* = = 0,0 e *y* = = 0,0|1|
|*x* = = 0,0 e *y* < 0|INF|

## <a name="remarks"></a>Comentários

**pow** não reconhecer os valores de ponto flutuantes integrais maiores que 2<sup>64</sup> (por exemplo, 1.0E100).

**pow** tem uma implementação que usa extensões Streaming SIMD 2 (SSE2). Para obter informações e restrições relativas ao uso da implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

Como o C++ permite sobrecarga, você pode chamar qualquer uma das várias sobrecargas do **pow**. Em um programa C, **pow** sempre leva dois **duplo** valores e retorna um **duplo** valor.

A sobrecarga `pow(int, int)` não está mais disponível. Se você usar essa sobrecarga, o compilador pode emitir [C2668](../../error-messages/compiler-errors-2/compiler-error-c2668.md). Para evitar esse problema, converta o primeiro parâmetro para **duplo**, **float**, ou **longo** **duplo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|-|-|-|
|**pow**, **powf**, **powl**|\<math.h>|\<math.h> ou \<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md) <br/>
[exp, expf, expl](exp-expf.md) <br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md) <br/>
[sqrt, sqrtf, sqrtl](sqrt-sqrtf-sqrtl.md) <br/>
[_CIpow](../../c-runtime-library/cipow.md)<br/>
