---
title: fdim, fdimf, fdiml
ms.date: 04/05/2018
apiname:
- fdim
- fdimf
- fdiml
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
- fdim
- fdimf
- fdiml
- math/fdim
- math/fdimf
- math/fdiml
helpviewer_keywords:
- fdim function
- fdimf function
- fdiml function
ms.assetid: 2d4ac639-51e9-462d-84ab-fb03b06971a0
ms.openlocfilehash: d8cea831e333ebcd9677d830641c60e460ba5ed4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50515083"
---
# <a name="fdim-fdimf-fdiml"></a>fdim, fdimf, fdiml

Determina a diferença positiva entre os primeiros e segundos valores.

## <a name="syntax"></a>Sintaxe

```C
double fdim(
   double x,
   double y
);

float fdim(
   float x,
   float y
); //C++ only

long double fdim(
   long double x,
   long double y
); //C++ only

float fdimf(
   float x,
   float y
);

long double fdiml(
   long double x,
   long double y
);

```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O primeiro valor.

*y*<br/>
O segundo valor.

## <a name="return-value"></a>Valor de retorno

Retorna a diferença positiva entre *x* e *y*:

|Valor retornado|Cenário|
|------------------|--------------|
|x-y|se x > y|
|0|se x <= y|

Caso contrário, pode retornar um dos seguintes erros:

|Problema|Valor de|
|-----------|------------|
|Erro de intervalo de estouro|+HUGE_VAL, +HUGE_VALF ou +HUGE_VALL|
|Erro de intervalo de estouro negativo|valor correto (após o arredondamento)|
|*x* ou *y* é NaN|NaN|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como C++ permite sobrecargas, é possível chamar sobrecargas de **fdim** que usam e retornam **float** e **longo** **double** tipos. Em um programa do C **fdim** sempre usa e retorna um **duplo**.

Exceto para o tratamento de NaN, essa função é equivalente a `fmax(x - y, 0)`.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fdim**, **fdimf**, **fdiml**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fmax, fmaxf, fmaxl](fmax-fmaxf-fmaxl.md)<br/>
[abs, labs, llabs, _abs64](abs-labs-llabs-abs64.md)<br/>
