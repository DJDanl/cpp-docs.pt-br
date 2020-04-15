---
title: lgamma, lgammaf, lgammal
ms.date: 4/2/2020
api_name:
- lgamma
- lgammaf
- lgammal
- _o_lgamma
- _o_lgammaf
- _o_lgammal
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
- lgamma
- lgammaf
- lgammal
- math/lgamma
- math/lgammaf
- math/lgammal
helpviewer_keywords:
- lgamma function
- lgammal function
- lgammaf function
ms.assetid: 6e326c58-7077-481a-a329-c82ae56ae9e6
ms.openlocfilehash: e2bdfbeac7b995be0b589156437a3ded39114adf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81342156"
---
# <a name="lgamma-lgammaf-lgammal"></a>lgamma, lgammaf, lgammal

Determina o logaritmo natural do valor absoluto da função gama do valor especificado.

## <a name="syntax"></a>Sintaxe

```C
double lgamma( double x );
float lgammaf( float x );
long double lgammal( long double x );
```

```cpp
float lgamma( float x ); //C++ only
long double lgamma( long double x ); //C++ only
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor a ser computado.

## <a name="return-value"></a>Valor retornado

Se for bem sucedido, devolva o logaritmo natural do valor absoluto da função gama de *x*.

|Problema|Retorno|
|-----------|------------|
|*x* = NaN|NaN|
|*x* = ±0|+INFINITY|
|*x*= inteiro negativo|+INFINITY|
|±INFINITY|+INFINITY|
|erro de polo|+HUGE_VAL, +HUGE_VALF ou +HUGE_VALL|
|erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como c++ permite sobrecarga, você pode chamar sobrecargas de **lgamma** que pegam e retornam **flutuam** e tipos **duplos** **longos.** Em um programa C, **lgamma** sempre pega e devolve um **duplo**.

Se x é um número racional, esta função retorna o logaritmo do fatorial de (x - 1).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**lgamma**, **lgammaf,** **lgammal**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[tgamma, tgammaf, tgammal](tgamma-tgammaf-tgammal.md)<br/>
