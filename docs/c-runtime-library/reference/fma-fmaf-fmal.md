---
title: fma, fmaf, fmal
ms.date: 4/2/2020
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
ms.openlocfilehash: be3578aa9c66f329e191749b4506091bff69b1eb
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82914946"
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

*Iar*<br/>
O segundo valor a ser multiplicado.

*z*<br/>
O valor a ser adicionado.

## <a name="return-value"></a>Valor retornado

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

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **FMA** que levam e retornam tipos **float** e **Long** **duplos** . Em um programa C, o **FMA** sempre usa e retorna um **Double**.

Esta função calcula o valor como se ele tivesse precisão infinita e arredonda o resultado final.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**FMA**, **fmaf**, **Fmal**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[remainder, remainderf, remainderl](remainder-remainderf-remainderl.md)<br/>
[remquo, remquof, remquol](remquo-remquof-remquol.md)<br/>
