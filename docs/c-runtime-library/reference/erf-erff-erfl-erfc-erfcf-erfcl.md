---
title: erf, erff, erfl, erfc, erfcf, erfcl
ms.date: 01/31/2019
apiname:
- erff
- erfl
- erf
- erfc
- erfcf
- erfcl
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
- erfl
- erf
- erff
- erfc
- erfcf
- erfcl
helpviewer_keywords:
- erfl function
- erff function
- erf function
- erfcl function
- erfcf function
- erfc function
ms.assetid: 144d90d3-e437-41c2-a659-cd57596023b5
ms.openlocfilehash: 4270d8366686ea282a4dd37741d9f8e37991b88f
ms.sourcegitcommit: e98671a4f741b69d6277da02e6b4c9b1fd3c0ae5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/04/2019
ms.locfileid: "55702655"
---
# <a name="erf-erff-erfl-erfc-erfcf-erfcl"></a>erf, erff, erfl, erfc, erfcf, erfcl

Computa a função de erro ou a função de erro complementar de um valor.

## <a name="syntax"></a>Sintaxe

```C
double erf(
   double x
);
float erf(
   float x
); // C++ only
long double erf(
   long double x
); // C++ only
float erff(
   float x
);
long double erfl(
   long double x
);
double erfc(
   double x
);
float erfc(
   float x
); // C++ only
long double erfc(
   long double x
); // C++ only
float erfcf(
   float x
);
long double erfcl(
   long double x
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Um valor de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

O **erf** funções retornam o Gauss função de erro de *x*. O **erfc** funções retornam o complementar em Gauss de função de erro de *x*.

## <a name="remarks"></a>Comentários

O **erf** funções calculam a função de erro em Gauss de *x*, que é definida como:

![A função de erro de x](media/crt_erf_formula.PNG "a função de erro de x")

A função de erro complementar em Gauss é definida como 1 – ERF (x). O **erf** funções retornam um valor no intervalo de -1,0 a 1,0. Nenhum erro é retornado. O **erfc** funções retornam um valor no intervalo de 0 a 2. Se *x* é muito grande para **erfc**, o **errno** variável é definida como **ERANGE**.

Como C++ permite sobrecargas, é possível chamar sobrecargas de **erf** e **erfc** que tomam e retornam **float** e **longo** **duplas** tipos. Em um programa do C **erf** e **erfc** sempre tomam e retornam uma **double**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**erf**, **erff**, **erfl**, **erfc**, **erfcf**, **erfcl**|\<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
