---
title: fma, fmaf, fmal
ms.date: 04/05/2018
apiname:
- fma
- fmaf
- fmal
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
- fma
- fmaf
- fmal
- math/fma
- math/fmaf
- math/fmal
helpviewer_keywords:
- fma function
- fmaf function
- fmal function
ms.assetid: 584a6037-da1e-4e86-9f0c-97aae86de0c0
ms.openlocfilehash: a3b540a72c6f2fc2264d6366111831fbe2a02a6b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50529942"
---
# <a name="fma-fmaf-fmal"></a>fma, fmaf, fmal

Multiplica dois valores, adiciona um terceiro valor e arredonda o resultado, sem perder a precisão devido a um arredondamento intermediário.

## <a name="syntax"></a>Sintaxe

```C
double fma(
   double x,
   double y,
   double z
);

float fma(
   float  x,
   float  y,
   float z
); //C++ only

long double fma(
   long double  x,
   long double  y,
   long double z
); //C++ only

float fmaf(
   float  x,
   float  y,
   float z
);

long double fmal(
   long double  x,
   long double  y,
   long double z
);

```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O primeiro valor a ser multiplicado.

*y*<br/>
O segundo valor a ser multiplicado.

*z*<br/>
O valor a ser adicionado.

## <a name="return-value"></a>Valor de retorno

Retorna `(x * y) + z`. O valor retornado é arredondado usando o formato de arredondamento atual.

Caso contrário, pode retornar um dos seguintes valores:

|Problema|Valor de|
|-----------|------------|
|*x* = infinito, *y* = 0 ou<br /><br /> *x* = 0, *y* = infinito|NaN|
|*x* ou *y* = ± exata infinito, *z* = infinito com o sinal oposto|NaN|
|*x* ou *y* = NaN|NaN|
|não (*x* = 0, *y*= indefinido) e *z* = NaN<br /><br /> não (*x*= indefinido, *y*= 0) e *z* = NaN|NaN|
|Erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|
|Erro de intervalo de estouro negativo|valor correto, após o arredondamento.|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como C++ permite sobrecargas, é possível chamar sobrecargas de **fma** que usam e retornam **float** e **longo** **double** tipos. Em um programa do C **fma** sempre usa e retorna um **duplo**.

Esta função calcula o valor como se ele tivesse precisão infinita e arredonda o resultado final.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**FMA**, **fmaf**, **fmal**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[remainder, remainderf, remainderl](remainder-remainderf-remainderl.md)<br/>
[remquo, remquof, remquol](remquo-remquof-remquol.md)<br/>
