---
title: fmin, fminf, fminl
description: Referência de API para Fmin, fminf e fminl; que determina o menor de dois valores.
ms.date: 9/1/2020
api_name:
- fmin
- fminf
- fminl
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
- fmin
- fminf
- fminl
- math/fmin
- math/fminf
- math/fminl
helpviewer_keywords:
- fmin function
- fminf function
- fminl function
ms.assetid: 1916dfb5-99c1-4b0d-aefb-513525c3f2ac
ms.openlocfilehash: 6a070835d809c6adcb5b7bfd57b5373886b348ca
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556704"
---
# <a name="fmin-fminf-fminl"></a>fmin, fminf, fminl

Determina o menor dos dois valores especificados.

## <a name="syntax"></a>Sintaxe

```C
double fmin(
   double x,
   double y
);

float fmin(
   float x,
   float y
); //C++ only

long double fmin(
   long double x,
   long double y
); //C++ only

float fminf(
   float x,
   float y
);

long double fminl(
   long double x,
   long double y
);

#define fmin(x) // Requires C11 or higher
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O primeiro valor a ser comparado.

*Iar*\
O segundo valor a ser comparado.

## <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, retorna o menor de *x* ou *y*.

|Entrada|Result|
|-----------|------------|
|*x* é Nan|*y*|
|*y* é Nan|*x*|
|*x* e *y* são NaN|NaN|

A função não faz com que [_matherr](matherr.md) seja invocado, cause qualquer exceção de ponto flutuante ou altere o valor de **errno**.

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **Fmin** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **Fmin** sempre pega e retorna um **`double`** .

Se você usar a \<tgmath.h> `fmin()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Fmin**, **fminf**, **fminl**|& \<math.h><br />C++: \<math.h> ou \<cmath>|
|macro **Fmin** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[fmax, fmaxf, fmaxl](fmax-fmaxf-fmaxl.md)<br/>
