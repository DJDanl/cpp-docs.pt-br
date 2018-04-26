---
title: erf, erff, erfl, erfc, erfcf, erfcl | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- erff
- erfl
- erf
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
dev_langs:
- C++
helpviewer_keywords:
- erfl function
- erff function
- erf function
ms.assetid: 144d90d3-e437-41c2-a659-cd57596023b5
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1703b4e352fee798a7b38dd16edf6158cd7f53ea
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

O **erf** funções retornam o Gauss função de erro do *x*. O **erfc** funções retornam o Gauss complementar função de erro do *x*.

## <a name="remarks"></a>Comentários

O **erf** funções calculam a função de erro Gauss do *x*, que é definida como:

![A função de erro de x](media/crt_erf_formula.PNG "CRT_erf_formula")

A função de erro Gauss complementar é definida como 1 - erf(x). O **erf** funções retornam um valor no intervalo de -1,0 a 1.0. Nenhum erro é retornado. O **erfc** funções retornam um valor no intervalo de 0 a 2. Se *x* é muito grande para **erfc**, o **errno** variável é definida como **ERANGE**.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **erf** e **erfc** que levar e retornar **float** e **longo** **duplo** tipos. Em um programa C, **erf** e **erfc** sempre levar e retornar um **duplo**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**ERF**, **erff**, **erfl**, **erfc**, **erfcf**, **erfcl**|\<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
