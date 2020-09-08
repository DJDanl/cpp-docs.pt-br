---
title: lrint, lrintf, lrintl, llrint, llrintf, llrintl
description: Referência de API para lrint (), lrintf (), lrintl (), llrint (), llrintf () e llrintl (); que arredonda o valor de ponto flutuante especificado para o valor integral mais próximo, usando o modo de arredondamento e a direção atuais.
ms.date: 9/1/2020
api_name:
- lrint
- lrintl
- lrintf
- llrint
- llrintf
- llrintl
- _o_llrint
- _o_llrintf
- _o_llrintl
- _o_lrint
- _o_lrintf
- _o_lrintl
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
- lrint
- lrintf
- lrintl
- llrint
- llrintf
- llrintl
- math/lrint
- math/lrintf
- math/lrintl
- math/llrint
- math/llrintf
- math/llrintl
helpviewer_keywords:
- lrint function
- lrintf function
- lrintl function
- llrint function
- llrintf function
- llrintl function
ms.assetid: 28ccd5b3-5e6f-434f-997d-a21d51b8ce7f
ms.openlocfilehash: f208c183400aac7a110bb6fd87398d4377fe8f06
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555014"
---
# <a name="lrint-lrintf-lrintl-llrint-llrintf-llrintl"></a>lrint, lrintf, lrintl, llrint, llrintf, llrintl

Arredonda o valor de ponto flutuante especificado para o valor inteiro mais próximo, usando o modo de arredondamento atual e a direção.

## <a name="syntax"></a>Sintaxe

```C
long int lrint(
   double x
);

long int lrint(
   float x
); //C++ only

long int lrint(
   long double x
); //C++ only

long int lrintf(
   float x
);

long int lrintl(
   long double x
);

long long int llrint(
   double x
);

long long int llrint(
   float x
); //C++ only

long long int llrint(
   long double x
); //C++ only

long long int llrintf(
   float x
);

long long int llrintl(
   long double x
);

#define lrint(X) // Requires C11 or higher
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O valor a ser arredondado.

## <a name="return-value"></a>Valor Retornado

Se for bem-sucedido, retorna o valor integral arredondado de *x*.

|Problema|Retorno|
|-----------|------------|
|*x* está fora do intervalo do tipo de retorno<br /><br /> *x* = ± ∞<br /><br /> *x* = Nan|Gera **FE_INVALID** e retorna zero (0).|

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **lrint** e **llrint** que usam **`float`** e os **`long double`** tipos. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **lrint** e **llrint** sempre tomam um **`double`** .

Se você usar a \<tgmath.h> `llrint()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Se *x* não representar o equivalente de ponto flutuante de um valor integral, essas funções aumentarão **FE_INEXACT**.

**Específico da Microsoft**: quando o resultado está fora do intervalo do tipo de retorno, ou quando o parâmetro é um Nan ou infinito, o valor de retorno é definido como implementação. O compilador da Microsoft retorna um valor zero (0).

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho C|Cabeçalho C++|
|--------------|--------------|------------------|
|**lrint**, **lrintf**, **lrintl**, **llrint**, **llrintf**, **llrintl**|\<math.h>|\<cmath>|
|macro **lrint** | \<tgmath.h> ||

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)
