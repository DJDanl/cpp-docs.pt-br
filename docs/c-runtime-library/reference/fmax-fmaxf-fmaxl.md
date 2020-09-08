---
title: fmax, fmaxf, fmaxl
description: Referência de API para FMAX, fmaxf e fmaxl; que determina o maior de dois valores numéricos.
ms.date: 9/1/2020
api_name:
- fmax
- fmaxf
- fmaxl
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
- fmax
- fmaxf
- fmaxl
- math/fmax
- math/fmaxf
- math/fmaxl
helpviewer_keywords:
- fmax function
- fmaxf function
- fmaxl function
ms.assetid: a773ccf7-495e-4a9a-8c6d-dfb53e341e35
ms.openlocfilehash: 4f38db64b30598e7cfb4eb4d0f57dccf257dabc5
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556678"
---
# <a name="fmax-fmaxf-fmaxl"></a>fmax, fmaxf, fmaxl

Determine o maior entre dois valores numéricos especificados.

## <a name="syntax"></a>Sintaxe

```C
double fmax(
   double x,
   double y
);

float fmax(
   float x,
   float y
); //C++ only

long double fmax(
   long double x,
   long double y
); //C++ only

float fmaxf(
   float x,
   float y
);

long double fmaxl(
   long double x,
   long double y
);

#define fmax(X, Y) // Requires C11 or higher
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O primeiro valor a ser comparado.

*Iar*\
O segundo valor a ser comparado.

## <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, retorna o maior de *x* ou *y*. O valor retornado é exato e não depende de nenhuma forma de arredondamento.

Caso contrário, pode retornar um dos seguintes valores:

|Problema|Retorno|
|-----------|------------|
|*x* = Nan|*y*|
|*y* = Nan|*x*|
|*x* e *y* = Nan|NaN|

Essa função não usa os erros especificados em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de Fmax que usam e retornam `float` `long double` tipos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, o `fmax` sempre usa e retorna um Double.

Se você usar a \<tgmath.h> `fmax()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**Fmax**, **fmaxf**, **fmaxl**|\<math.h>|\<cmath> ou \<math.h>|
|macro **Fmax** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[fmin, fminf, fminl](fmin-fminf-fminl.md)<br/>
