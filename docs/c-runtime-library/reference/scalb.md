---
title: scalb, _scalbf | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _scalb
- _scalbf
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
- scalb
- _scalb
- _scalbf
dev_langs:
- C++
helpviewer_keywords:
- exponential calculations
- _scalb function
- _scalbf function
- scalb function
ms.assetid: 148cf5a8-b405-44bf-a1f0-7487adba2421
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a465ca74af72a5114eac949439ab8493f89bcb39
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32406258"
---
# <a name="scalb-scalbf"></a>scalb, _scalbf

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

*exp*<br/>
Expoente inteiro longo.

## <a name="return-value"></a>Valor de retorno

Retornará um valor exponencial se for bem-sucedido. No estouro (dependendo do sinal de *x*), **scalb** retorna + /- **HUGE_VAL**; o **errno** variável é definida como  **ERANGE**.

Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **scalb** função calcula o valor de *x* * 2<sup>*exp*</sup>.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**scalb**, **_scalbf**|\<float.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldexp](ldexp.md)<br/>
