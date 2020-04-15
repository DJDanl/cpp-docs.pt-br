---
title: tgamma, tgammaf, tgammal
ms.date: 4/2/2020
api_name:
- tgamma
- tgammaf
- tgammal
- _o_tgamma
- _o_tgammaf
- _o_tgammal
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
- tgamma
- tgammaf
- tgammal
- math/tgamma
- math/tgammaf
- math/tgammal
helpviewer_keywords:
- tgamma function
- tgammaf function
- tgammal function
ms.assetid: f1bd2681-8af2-48a9-919d-5358fd068acd
ms.openlocfilehash: d7e27e8b818a16cb0c18f58e2f40c0090dd13ecf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362498"
---
# <a name="tgamma-tgammaf-tgammal"></a>tgamma, tgammaf, tgammal

Determina a função gama do valor especificado.

## <a name="syntax"></a>Sintaxe

```C
double tgamma(
   double x
);

float tgamma(
   float x
); //C++ only

long double tgamma(
   long double x
); //C++ only

float tgammaf(
   float x
);

long double tgammal(
   long double x
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor do qual o gama será encontrado.

## <a name="return-value"></a>Valor retornado

Se for bem sucedido, retorna o gama de *x*.

Um erro de intervalo pode ocorrer se a magnitude de *x* for muito grande ou muito pequena para o tipo de dados. Um erro de domínio ou erro de intervalo pode ocorrer se *x* <= 0.

|Problema|Retorno|
|-----------|------------|
|x = ±0|±INFINITY|
|x = inteiro negativo|NaN|
|x = -INFINITO|NaN|
|x = +INFINITY|+INFINITY|
|x = NaN|NaN|
|erro de domínio|NaN|
|erro de polo|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|
|erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|
|erro de intervalo de estouro negativo|o valor correto, após o arredondamento.|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como c++ permite sobrecarga, você pode chamar sobrecargas de **tgamma** que pegam e retornam **flutuam** e tipos **duplos** **longos.** Em um programa C, **tgamma** sempre pega e devolve um **duplo**.

Se x for um número natural, essa função retornará o fatorial de (x-1).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**tgamma**, **tgammaf,** **tgammal**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[lgamma, lgammaf, lgammal](lgamma-lgammaf-lgammal.md)<br/>
