---
title: erf, erff, erfl, erfc, erfcf, erfcl
ms.date: 01/31/2019
api_name:
- erff
- erfl
- erf
- erfc
- erfcf
- erfcl
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
ms.openlocfilehash: df724ed056c02d79b5b51f97ae4aaf8ae267fde5
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70937614"
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

As funções **ERF** retornam a função de erro de magnetização de *x*. As funções **ERFC** retornam a função de erro de magnetização complementar de *x*.

## <a name="remarks"></a>Comentários

As funções **ERF** calculam a função de erro de magnetização de *x*, que é definida como:

![A função Error de x](media/crt_erf_formula.PNG "A função Error de x")

A função de erro de magnetização complementar é definida como 1-ERF (x). As funções **ERF** retornam um valor no intervalo de-1,0 a 1,0. Nenhum erro é retornado. As funções **ERFC** retornam um valor no intervalo de 0 a 2. Se *x* for muito grande para **ERFC**, a variável **errno** será definida como **ERANGE**.

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **ERF** e **ERFC** que levam e retornam tipos **float** e **Long** **duplos** . Em um programa C, **ERF** e **ERFC** sempre assumem e retornam um **Double**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**erf**, **erff**, **erfl**, **erfc**, **erfcf**, **erfcl**|\<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
