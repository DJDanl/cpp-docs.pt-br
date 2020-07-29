---
title: exp, expf, expl
ms.date: 4/2/2020
api_name:
- expf
- expl
- exp
- _o_exp
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
- _expl
- expf
- expl
- exp
helpviewer_keywords:
- exponential calculations
- expf function
- expl function
- calculating exponentials
- exp function
ms.assetid: 7070016d-1143-407e-9e9a-6b059bb88867
ms.openlocfilehash: 9872a83ba3ec5346b7aed5fb51ee837d3ed827aa
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234166"
---
# <a name="exp-expf-expl"></a>exp, expf, expl

Calcula o exponencial.

## <a name="syntax"></a>Sintaxe

```C
double exp(
   double x
);
float exp(
   float x
);  // C++ only
long double exp(
   long double x
);  // C++ only
float expf(
   float x
);
long double expl(
   long double x
);
```

### <a name="parameters"></a>parâmetros

*x*<br/>
O valor de ponto flutuante para exponentiate a base do logaritmo natural *e* by.

## <a name="return-value"></a>Valor retornado

As funções **exp** retornam o valor exponencial do parâmetro de ponto flutuante, *x*, se for bem-sucedido. Ou seja, o resultado é *e*<sup>*x*</sup>, em que *e* é a base do logaritmo natural. No estouro, a função retorna INF (infinito) e no estouro negativo, **exp** retorna 0.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± Quiet NaN, indeterminado|Nenhum|_DOMAIN|
|± Infinito|INVALID|_DOMAIN|
|x ≥ 7,097827e+002|INEXACT+OVERFLOW|OVERFLOW|
|X ≤ -7,083964e+002|INEXACT+UNDERFLOW|UNDERFLOW|

A função **exp** tem uma implementação que usa Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições sobre como usar a implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

## <a name="remarks"></a>Comentários

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **exp** que usam um **`float`** **`long double`** argumento ou. Em um programa C, **exp** sempre usa e retorna um **`double`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C necessário|Cabeçalho C++ necessário|
|--------------|---------------------|---|
|**exp**, **expf**, **sol**|\<math.h>|\<cmath> ou \<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_exp.c

#include <math.h>
#include <stdio.h>

int main( void )
{
   double x = 2.302585093, y;

   y = exp( x );
   printf( "exp( %f ) = %f\n", x, y );
}
```

```Output
exp( 2.302585 ) = 10.000000
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md)<br/>
[_CIexp](../../c-runtime-library/ciexp.md)<br/>
