---
title: log1p, log1pf, log1pl2
description: Referência de API para log1p, log1pf, log1pl2; que computa o logaritmo natural de 1 mais o valor especificado.
ms.date: 9/1/2020
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
ms.openlocfilehash: 8858d761428d4dad6e3fe836b82041ae92f1827a
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556224"
---
# <a name="log1p-log1pf-log1pl"></a>log1p, log1pf, log1pl

Calcula o logaritmo natural de 1 mais o valor especificado.

## <a name="syntax"></a>Sintaxe

```C
double log1p(
   double x
);
float log1pf(
   float x
);
long double log1pl(
   long double x
);

#define log1p(X) // Requires C11 or higher

float log1p(
   float x
); //C++ only

long double log1p(
   long double x
); //C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O argumento de ponto flutuante.

## <a name="return-value"></a>Valor Retornado

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

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **log1p** que usam e retornam **`float`** **`long double`** tipos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **log1p** sempre pega e retorna um **`double`** .

Se você usar a \<tgmath.h> `log1p()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Se *x* for um número natural, essa função retornará o logaritmo do fatorial de (*x* -1).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**log1p**, **log1pf**, **log1pl**|\<math.h>|\<cmath>|
|macro **log1p** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)\
[log2, log2f, log2l](log2-log2f-log2l.md)\
[log, logf, log10, log10f](log-logf-log10-log10f.md)
