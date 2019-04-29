---
title: fmin, fminf, fminl
ms.date: 04/05/2018
apiname:
- fmin
- fminf
- fminl
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
ms.openlocfilehash: f73853e18bd5d7f699cd2c3109fe5fb830859bf1
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62333372"
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

### <a name="parameters"></a>Parâmetros

*x*<br/>
O primeiro valor a ser comparado.

*y*<br/>
O segundo valor a ser comparado.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retorna o menor dos *x* ou *y*.

|Entrada|Resultado|
|-----------|------------|
|*x* é NaN|*y*|
|*y* é NaN|*x*|
|*x* e *y* são NaN|NaN|

A função não causa [matherr](matherr.md) seja invocado, fazer com que todas as exceções de ponto flutuantes ou alterar o valor de **errno**.

## <a name="remarks"></a>Comentários

Como C++ permite sobrecargas, é possível chamar sobrecargas de **fmin** que usam e retornam **float** e **longo** **double** tipos. Em um programa do C **fmin** sempre usa e retorna um **duplo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**fmin**, **fminf**, **fminl**|C: \<math.h><br />C++: \<math.h> ou \<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fmax, fmaxf, fmaxl](fmax-fmaxf-fmaxl.md)<br/>
