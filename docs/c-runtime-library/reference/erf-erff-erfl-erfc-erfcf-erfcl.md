---
title: erf, erff, erfl, erfc, erfcf, erfcl
ms.date: 4/2/2020
api_name:
- erff
- erfl
- erf
- erfc
- erfcf
- erfcl
- _o_erf
- _o_erfc
- _o_erfcf
- _o_erfcl
- _o_erff
- _o_erfl
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
ms.openlocfilehash: 5511e7a7d17c47deaaaf61eedf3c00eec12db119
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234179"
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

### <a name="parameters"></a>parâmetros

*x*<br/>
Um valor de ponto flutuante.

## <a name="return-value"></a>Valor retornado

As funções **ERF** retornam a função de erro de magnetização de *x*. As funções **ERFC** retornam a função de erro de magnetização complementar de *x*.

## <a name="remarks"></a>Comentários

As funções **ERF** calculam a função de erro de magnetização de *x*, que é definida como:

![A função Error de x](media/crt_erf_formula.PNG "A função Error de x")

A função de erro de magnetização complementar é definida como 1-ERF (x). As funções **ERF** retornam um valor no intervalo de-1,0 a 1,0. Nenhum erro é retornado. As funções **ERFC** retornam um valor no intervalo de 0 a 2. Se *x* for muito grande para **ERFC**, a variável **errno** será definida como **ERANGE**.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **ERF** e **ERFC** que levam e retornam **`float`** e **`long double`** digitam. Em um programa C, **ERF** e **ERFC** sempre assumem e retornam um **`double`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**ERF**, **erff**, **erfl**, **ERFC**, **erfcf**, **erfcl**|\<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
