---
title: logb, logbf, logbl, _logb, _logbf | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- logb
- _logb
- _logbl
- logbf
- logbl
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
- logb
- logbl
- _logb
- _logbf
- logbf
dev_langs:
- C++
helpviewer_keywords:
- _logbf function
- mantissas, floating-point variables
- logbf function
- _logb function
- exponent, floating-point numbers
- logbl function
- logb function
- floating-point functions
- floating-point functions, mantissa and exponent
- exponents and mantissas
ms.assetid: 780c4daa-6fe6-4fbc-9412-4c1ba1a1766f
caps.latest.revision: 13
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5f279d2b31ba9a40dd3d5c0e5d3c50e5a9a4b170
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="logb-logbf-logbl-logb-logbf"></a>logb, logbf, logbl, _logb, _logbf

Extrai o valor exponencial de um argumento de ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
double logb(
   double x
);
float logb(
   float x
); // C++ only
long double logb(
   long double x
); // C++ only
float logbf(
   float x
);
long double logbl(
   long double x
);
double _logb(
   double x
);
float _logbf(
   float x
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Um valor de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

**logb** retorna o valor exponencial não polarizado de *x* como um inteiro com sinal representado como um valor de ponto flutuante.

## <a name="remarks"></a>Comentários

O **logb** funções extrair o valor exponencial do argumento ponto flutuante *x*, como se *x* são representados com intervalo infinito. Se o argumento *x* é desnormalizada, ele será tratado como se ele foi normalizado.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **logb** que levar e retornar **float** ou **longo** **duplo** valores. Em um programa C, **logb** sempre usa e retorna um **duplo**.

|Entrada|Exceção SEH|Exceção Matherr|
|-----------|-------------------|-----------------------|
|± QNAN,IND|Nenhum|_DOMAIN|
|± 0|ZERODIVIDE|_SING|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_logb**|\<float.h>|
|**logb**, **logbf**, **logbl**, **logbf**|\<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[frexp](frexp.md)<br/>
