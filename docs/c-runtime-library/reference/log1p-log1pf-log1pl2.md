---
title: log1p, log1pf, log1pl2
ms.date: 4/2/2020
api_name:
- log1p
- log1pf
- log1pl
- _o_log1p
- _o_log1pf
- _o_log1pl
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
ms.openlocfilehash: d599567e38d216e78720a3d6b330310095acdd11
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218579"
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

### <a name="parameters"></a>parâmetros

*x*<br/>
O argumento de ponto flutuante.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, retorna o log natural (base-*e*) de (*x* + 1).

Caso contrário, pode retornar um dos seguintes valores:

|Entrada|Result|Exceção SEH|errno|
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

As funções **log1p** podem ser mais precisas do que usar `log(x + 1)` quando *x* é quase 0.

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **log1p** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, o **log1p** sempre pega e retorna um **`double`** .

Se *x* for um número natural, essa função retornará o logaritmo do fatorial de (*x* -1).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**log1p**, **log1pf**, **log1pl**|\<math.h>|\<cmath>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)<br/>
[log2, log2f, log2l](log2-log2f-log2l.md)<br/>
[log, logf, log10, log10f](log-logf-log10-log10f.md)<br/>
