---
title: lgamma, lgammaf, lgammal
ms.date: 04/05/2018
api_name:
- lgamma
- lgammaf
- lgammal
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
ms.openlocfilehash: 9baf8f0fefb50cea6a5301aac9ffd48ff3cd5bde
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953367"
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

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retorna o logaritmo natural do valor absoluto da função gama de *x*.

|Problema|Valor de|
|-----------|------------|
|*x* = Nan|NaN|
|*x* = ±0|+INFINITY|
|*x*= número inteiro negativo|+INFINITY|
|±INFINITY|+INFINITY|
|erro de polo|+HUGE_VAL, +HUGE_VALF ou +HUGE_VALL|
|erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **lGamma** que usam e retornam tipos **float** e **Long** **duplos** . Em um programa C, **lGamma** sempre pega e retorna um **Double**.

Se x for um número racional, essa função retornará o logaritmo do fatorial de (x-1).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**lgamma**, **lgammaf**, **lgammal**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[tgamma, tgammaf, tgammal](tgamma-tgammaf-tgammal.md)<br/>
