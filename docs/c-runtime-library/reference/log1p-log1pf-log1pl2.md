---
title: log1p, log1pf, log1pl2 | Microsoft Docs
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
- log1p
- log1pf
- log1pl
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
- log1p
- log1pf
- log1pl
- math/log1p
- math/log1pf
- math/log1pl
helpviewer_keywords:
- log1p function
- log1pf function
- log1pl function
ms.assetid: a40d965d-b4f6-42f4-ba27-2395546f7c12
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: cf512bcf898a202eee771318afb022642d432b4f
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="log1p-log1pf-log1pl"></a>log1p, log1pf, log1pl

Calcula o logaritmo natural de 1 mais o valor especificado.

## <a name="syntax"></a>Sintaxe

```C
double log1p(
   double x
);

float log1p(
   float x
); //C++ only

long double log1p(
   long double x
); //C++ only

float log1pf(
   float x
);

long double log1pl(
   long double x
);

```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O argumento de ponto flutuante.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, retorna o natural (base -*e*) de log da (*x* + 1).

Caso contrário, pode retornar um dos seguintes valores:

|Entrada|Resultado|Exceção SEH|errno|
|-----------|------------|-------------------|-----------|
|+inf|+inf|||
|Desnormalizado|Igual à entrada|UNDERFLOW||
|±0|Igual à entrada|||
|-1|-inf|DIVBYZERO|ERANGE|
|< -1|nan|INVALID|EDOM|
|-inf|nan|INVALID|EDOM|
|±SNaN|Igual à entrada|INVALID||
|±QNaN, indefinido|Igual à entrada|||

O **errno** valor é definido como ERANGE se *x* = -1. O **errno** valor é definido como **EDOM** se *x* < -1.

## <a name="remarks"></a>Comentários

O **log1p** funções podem ser mais precisas do que usando `log(x + 1)` quando *x* está próximo de 0.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **log1p** que levar e retornar **float** e **longo** **duplo** tipos. Em um programa C, **log1p** sempre usa e retorna um **duplo**.

Se *x* é um número natural, essa função retorna o logaritmo de fatorial (*x* - 1).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**log1p**, **log1pf**, **log1pl**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[log2, log2f, log2l](log2-log2f-log2l.md)<br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md)<br/>
