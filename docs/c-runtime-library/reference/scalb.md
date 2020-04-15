---
title: _scalb, _scalbf
ms.date: 4/2/2020
api_name:
- _scalb
- _scalbf
- _o__scalb
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- scalb
- _scalb
- _scalbf
helpviewer_keywords:
- exponential calculations
- _scalb function
- _scalbf function
- scalb function
ms.assetid: 148cf5a8-b405-44bf-a1f0-7487adba2421
ms.openlocfilehash: 6501fe53e67d0f277fa64c08e0edbff1d7eeb61a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332680"
---
# <a name="_scalb-_scalbf"></a>_scalb, _scalbf

Dimensiona o argumento por uma potência de 2.

## <a name="syntax"></a>Sintaxe

```C
double _scalb(
   double x,
   long exp
);
float _scalbf(
   float x,
   long exp
); /* x64 only */
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
Valor de ponto flutuante de precisão dupla.

*Exp*<br/>
Expoente inteiro longo.

## <a name="return-value"></a>Valor retornado

Retornará um valor exponencial se for bem-sucedido. No estouro (dependendo do sinal de *x),* **_scalb** retorna +/- **HUGE_VAL**; a variável **errno** é definida **como ERANGE**.

Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_scalb** calcula o valor de *x* \* 2<sup>*exp*</sup>.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_scalb** **_scalbf.**|\<float.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldexp](ldexp.md)<br/>
