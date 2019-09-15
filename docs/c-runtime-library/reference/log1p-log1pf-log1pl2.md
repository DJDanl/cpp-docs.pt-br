---
title: log1p, log1pf, log1pl2
ms.date: 04/05/2018
api_name:
- log1p
- log1pf
- log1pl
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
ms.openlocfilehash: aad6675a832e1715c505026fe11ffe77f1f6d275
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70953211"
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

Se for bem-sucedido, retorna o log natural (base-*e*) de (*x* + 1).

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

O valor de **errno** é definido como ERANGE Se *x* =-1. O valor de **errno** é definido como **EDOM** se *x* <-1.

## <a name="remarks"></a>Comentários

As funções **log1p** podem ser mais precisas do que `log(x + 1)` usar quando *x* é quase 0.

Como C++ o permite sobrecarga, você pode chamar sobrecargas de **log1p** que usam e retornam tipos **float** e **Long** **duplos** . Em um programa C, **log1p** sempre pega e retorna um **Double**.

Se *x* for um número natural, essa função retornará o logaritmo do fatorial de (*x* -1).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**log1p**, **log1pf**, **log1pl**|\<math.h>|\<cmath>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[log2, log2f, log2l](log2-log2f-log2l.md)<br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md)<br/>
