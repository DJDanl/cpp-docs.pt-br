---
title: fmin, fminf, fminl
ms.date: 04/05/2018
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
ms.openlocfilehash: d6cd16c298c3f4bedb8064d66efd2d4bbe20c22b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216980"
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
```

### <a name="parameters"></a>parâmetros

*x*<br/>
O primeiro valor a ser comparado.

*Iar*<br/>
O segundo valor a ser comparado.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, retorna o menor de *x* ou *y*.

|Entrada|Result|
|-----------|------------|
|*x* é Nan|*Iar*|
|*y* é Nan|*x*|
|*x* e *y* são NaN|NaN|

A função não faz com que [_matherr](matherr.md) seja invocado, cause qualquer exceção de ponto flutuante ou altere o valor de **errno**.

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **Fmin** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, o **Fmin** sempre pega e retorna um **`double`** .

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**Fmin**, **fminf**, **fminl**|&\<math.h><br />C++: \<math.h> ou\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[fmax, fmaxf, fmaxl](fmax-fmaxf-fmaxl.md)<br/>
