---
title: expm1, expm1f, expm1l
description: Referência de API para expm1, expm1f e expm1; que computa o exponencial de base e de um valor, menos um.
ms.date: 9/1/2020
api_name:
- expm1l
- expm1
- expm1f
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
- expm1l
- expm1
- expm1f
helpviewer_keywords:
- expm1f function
- expm1l function
- expm1 function
ms.assetid: 2a4dd2d9-370c-42b0-9067-0625efa272e0
ms.openlocfilehash: 6d352e91d895cd63c7134faff90bc1bc43a50708
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556496"
---
# <a name="expm1-expm1f-expm1l"></a>expm1, expm1f, expm1l

Calcula o exponencial de base e de um valor, menos um.

## <a name="syntax"></a>Sintaxe

```C
double expm1(
   double x
);
float expm1(
   float x
);  // C++ only
long double expm1(
   long double x
);  // C++ only
float expm1f(
   float x
);
long double expm1l(
   long double x
);
#define expm1(X) // Requires C11 or higher
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
O valor de exponencial do ponto flutuante.

## <a name="return-value"></a>Valor Retornado

As funções **expm1** retornam um valor de ponto flutuante que representa e<sup>x</sup> -1, se for bem-sucedido. Em Overflow, **expm1** retorna **HUGE_VAL**, **expm1f** retorna **HUGE_VALF**, **expm1l** retorna **HUGE_VALL**e **errno** é definido como **ERANGE**. Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **expm1** que usam e retornam **`float`** **`long double`** valores. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **expm1** sempre pega e retorna um **`double`** .

Se você usar a \<tgmath.h> `expm1()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**expm1**, **expm1f**, **expm1l**|\<math.h>|
|macro **expm1** | \<tgmath.h> |

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[exp2, exp2f, exp2l](exp2-exp2f-exp2l.md)<br/>
[pow, powf, powl](pow-powf-powl.md)<br/>
