---
title: fma, fmaf, fmal
description: Referência de API para FMA, fmaf e Fmal; que multiplica dois valores juntos, adiciona um terceiro valor e, em seguida, arredonda o resultado, sem perder nenhuma precisão devido ao arredondamento intermediário.
ms.date: 9/1/2020
api_name:
- fma
- fmaf
- fmal
- _o_fma
- _o_fmaf
- _o_fmal
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: e9ae92c28f24b6281d73450c7cabaad775a84d42
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556691"
---
# <a name="fma-fmaf-fmal"></a>fma, fmaf, fmal

Multiplica dois valores juntos, adiciona um terceiro valor e arredonda o resultado, sem perder nenhuma precisão devido ao arredondamento intermediário.

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

#define fma(X, Y, Z) // Requires C11 or higher
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O primeiro valor a ser multiplicado.

*Iar*\
O segundo valor a ser multiplicado.

*z*\
O valor a ser adicionado.

## <a name="return-value"></a>Valor Retornado

Retorna `(x * y) + z`. O valor retornado é arredondado usando o formato de arredondamento atual.

Caso contrário, pode retornar um dos seguintes valores:

|Problema|Retorno|
|-----------|------------|
|*x* = infinito, *y* = 0 ou<br /><br /> *x* = 0, *y* = infinito|NaN|
|*x* ou *y* = infinito exato de ±, *z* = Infinity com o sinal oposto|NaN|
|*x* ou *y* = Nan|NaN|
|Não (*x* = 0, *y*= indefinido) e *z* = Nan<br /><br /> Não (*x*= indefinido, *y*= 0) e *z* = Nan|NaN|
|Erro de intervalo de estouro|±HUGE_VAL, ±HUGE_VALF ou ±HUGE_VALL|
|Erro de intervalo de estouro negativo|valor correto, após o arredondamento.|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **FMA** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, o **FMA** sempre usa e retorna um **`double`** .

Se você usar a \<tgmath.h> `fma()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Esta função calcula o valor como se ele tivesse precisão infinita e arredonda o resultado final.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**FMA**, **fmaf**, **Fmal**|\<math.h>|\<cmath>|
|macro **FMA** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[remainder, remainderf, remainderl](remainder-remainderf-remainderl.md)<br/>
[remquo, remquof, remquol](remquo-remquof-remquol.md)<br/>
