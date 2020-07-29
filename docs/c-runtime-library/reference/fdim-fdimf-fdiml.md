---
title: fdim, fdimf, fdiml
ms.date: 04/05/2018
api_name:
- fdim
- fdimf
- fdiml
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
ms.openlocfilehash: 1a7bbeaf77c94f620a82f77fb1aad3c71c34f2ef
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221907"
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

### <a name="parameters"></a>parâmetros

*x*<br/>
O primeiro valor.

*Iar*<br/>
O segundo valor.

## <a name="return-value"></a>Valor retornado

Retorna a diferença positiva entre *x* e *y*:

|Retornar valor|Cenário|
|------------------|--------------|
|x-y|se x > y|
|0|se x <= y|

Caso contrário, pode retornar um dos seguintes erros:

|Problema|Retorno|
|-----------|------------|
|Erro de intervalo de estouro|+HUGE_VAL, +HUGE_VALF ou +HUGE_VALL|
|Erro de intervalo de estouro negativo|valor correto (após o arredondamento)|
|*x* ou *y* é Nan|NaN|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **fdim** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, o **fdim** sempre pega e retorna um **`double`** .

Exceto para a manipulação de NaN, essa função é equivalente a `fmax(x - y, 0)` .

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fdim**, **fdimf**, **fdiml**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[fmax, fmaxf, fmaxl](fmax-fmaxf-fmaxl.md)<br/>
[abs, labs, llabs, _abs64](abs-labs-llabs-abs64.md)<br/>
