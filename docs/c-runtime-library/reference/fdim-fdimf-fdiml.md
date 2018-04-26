---
title: fdim, fdimf, fdiml | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- fdim
- fdimf
- fdiml
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
- fdim
- fdimf
- fdiml
- math/fdim
- math/fdimf
- math/fdiml
dev_langs:
- C++
helpviewer_keywords:
- fdim function
- fdimf function
- fdiml function
ms.assetid: 2d4ac639-51e9-462d-84ab-fb03b06971a0
caps.latest.revision: 11
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8cf0036bc35f6e3b87daecf47225e59d2dc8f087
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="fdim-fdimf-fdiml"></a>fdim, fdimf, fdiml

Determina a diferença positiva entre os primeiros e segundos valores.

## <a name="syntax"></a>Sintaxe

```C
double fdim(
   double x,
   double y
);

float fdim(
   float x,
   float y
); //C++ only

long double fdim(
   long double x,
   long double y
); //C++ only

float fdimf(
   float x,
   float y
);

long double fdiml(
   long double x,
   long double y
);

```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O primeiro valor.

*y*<br/>
O segundo valor.

## <a name="return-value"></a>Valor de retorno

Retorna a diferença positiva entre *x* e *y*:

|Valor retornado|Cenário|
|------------------|--------------|
|x-y|se x > y|
|0|se x <= y|

Caso contrário, pode retornar um dos seguintes erros:

|Problema|Valor de|
|-----------|------------|
|Erro de intervalo de estouro|+HUGE_VAL, +HUGE_VALF ou +HUGE_VALL|
|Erro de intervalo de estouro negativo|valor correto (após o arredondamento)|
|*x* ou *y* é NaN|NaN|

Os erros são relatados conforme especificado em [_matherr](matherr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **fdim** que levar e retornar **float** e **longo** **duplo** tipos. Em um programa C, **fdim** sempre usa e retorna um **duplo**.

Exceto para a manipulação de NaN, essa função é equivalente a `fmax(x - y, 0)`.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**fdim**, **fdimf**, **fdiml**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[fmax, fmaxf, fmaxl](fmax-fmaxf-fmaxl.md)<br/>
[abs, labs, llabs, _abs64](abs-labs-llabs-abs64.md)<br/>
