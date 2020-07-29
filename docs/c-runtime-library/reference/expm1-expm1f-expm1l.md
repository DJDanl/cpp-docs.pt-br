---
title: expm1, expm1f, expm1l
ms.date: 04/05/2018
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
ms.openlocfilehash: 63e984f2228ac6896cd9d2ea959b491565bfb8d8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87234127"
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
```

### <a name="parameters"></a>parâmetros

*x*<br/>
O valor de exponencial do ponto flutuante.

## <a name="return-value"></a>Valor retornado

As funções **expm1** retornam um valor de ponto flutuante que representa e<sup>x</sup> -1, se for bem-sucedido. Em Overflow, **expm1** retorna **HUGE_VAL**, **expm1f** retorna **HUGE_VALF**, **expm1l** retorna **HUGE_VALL**e **errno** é definido como **ERANGE**. Para obter mais informações sobre os códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **expm1** que usam e retornam **`float`** **`long double`** valores. Em um programa C, o **expm1** sempre pega e retorna um **`double`** .

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**expm1**, **expm1f**, **expm1l**|\<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[exp2, exp2f, exp2l](exp2-exp2f-exp2l.md)<br/>
[pow, powf, powl](pow-powf-powl.md)<br/>
