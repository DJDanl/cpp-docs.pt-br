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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: cbf303b2b92afd83a1c3181dc98a1dbdcd639c1b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347591"
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

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor do ponto flutuante para exponenciar a base logaritmo natural *e* por.

## <a name="return-value"></a>Valor retornado

As **funções exp** retornam o valor exponencial do parâmetro de ponto flutuante, *x*, se bem sucedido. Ou seja, o resultado é *e*<sup>*x*</sup>, onde *e* é a base do logaritmo natural. No estouro, a função retorna INF (infinito) e, no subfluxo, **exp** retorna 0.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± NaN tranquila, indeterminada|Nenhum|_DOMAIN|
|± Infinito|INVALID|_DOMAIN|
|x ≥ 7,097827e+002|INEXACT+OVERFLOW|OVERFLOW|
|X ≤ -7,083964e+002|INEXACT+UNDERFLOW|UNDERFLOW|

A **função exp** tem uma implementação que usa o Streaming SIMD Extensions 2 (SSE2). Para obter informações e restrições sobre como usar a implementação de SSE2, consulte [_set_SSE2_enable](set-sse2-enable.md).

## <a name="remarks"></a>Comentários

C++ permite sobrecarga, para que você possa chamar sobrecargas de **exp** que tomam um **flutuador** ou **um longo argumento duplo.** Em um programa C, **exp** sempre pega e devolve um **duplo**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C necessário|Cabeçalho C++ necessário|
|--------------|---------------------|---|
|**exp**, **expf,** **expl**|\<math.h>|\<cmath> ou \<math.h>|

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

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md)<br/>
[_CIexp](../../c-runtime-library/ciexp.md)<br/>
