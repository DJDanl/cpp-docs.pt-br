---
title: exp2, exp2f, exp2l
ms.date: 4/2/2020
api_name:
- exp2
- exp2f
- exp2l
- _o_exp2
- _o_exp2f
- _o_exp2l
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
- exp2
- math/exp2
- exp2f
- math/exp2f
- exp2l
- math/exp2l
helpviewer_keywords:
- exp2 function
- exp2f function
- exp2l function
ms.assetid: 526e3e10-201a-4610-a886-533f44ece344
ms.openlocfilehash: a5df1a216b4565f013a4c42b4ef4369b5b7f9b04
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347575"
---
# <a name="exp2-exp2f-exp2l"></a>exp2, exp2f, exp2l

Cálculos 2 elevados ao valor especificado.

## <a name="syntax"></a>Sintaxe

```C
double exp2(
   double x
);

float exp2(
   float x
);  // C++ only

long double exp2(
   long double x
); // C++ only

float exp2f(
   float x
);

long double exp2l(
   long double x
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor do expoente.

## <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna o expoente base-2 de *x*, ou seja, 2<sup>x</sup>. Caso contrário, ele retorna um dos seguintes valores:

|Problema|Retorno|
|-----------|------------|
|*x* = ±0|1|
|*x* = -INFINITO|+0|
|*x* = +INFINITO|+INFINITY|
|*x* = NaN|NaN|
|Erro de intervalo de estouro|+HUGE_VAL, +HUGE_VALF ou +HUGE_VALL|
|Erro de intervalo de estouro negativo|Resultado correto, após arredondamento|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como c++ permite sobrecarga, você pode chamar sobrecargas de **exp2** que pegam e retornam **flutuam** e tipos **duplos longos.** Em um programa C, **exp2** sempre pega e devolve um **duplo**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**exp**, **expf,** **expl**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[exp, expf, expl](exp-expf.md)<br/>
[log2, log2f, log2l](log2-log2f-log2l.md)<br/>
