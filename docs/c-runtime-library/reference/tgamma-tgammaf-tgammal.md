---
title: tgamma, tgammaf, tgammal
ms.date: 04/05/2018
apiname:
- tgamma
- tgammaf
- tgammal
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
ms.openlocfilehash: 6cfe455b0e9e83cd5283d36fed33ca168bc97d0a
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50570658"
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

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retornará o gama de *x*.

Um erro de intervalo pode ocorrer se a magnitude de *x* é muito grande ou muito pequeno para o tipo de dados. Um erro de domínio ou intervalo pode ocorrer se *x* < = 0.

|Problema|Valor de|
|-----------|------------|
|x = ±0|±INFINITY|
|x = inteiro negativo|NaN|
|x = - infinito|NaN|
|x = +INFINITY|+INFINITY|
|x = NaN|NaN|
|erro de domínio|NaN|
|erro de polo|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|
|erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|
|erro de intervalo de estouro negativo|o valor correto, após o arredondamento.|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como C++ permite sobrecargas, é possível chamar sobrecargas de **tgamma** que usam e retornam **float** e **longo** **double** tipos. Em um programa do C **tgamma** sempre usa e retorna um **duplo**.

Se x for um número natural, essa função retornará o fatorial de (x-1).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**tgamma**, **tgammaf**, **tgammal**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[lgamma, lgammaf, lgammal](lgamma-lgammaf-lgammal.md)<br/>
