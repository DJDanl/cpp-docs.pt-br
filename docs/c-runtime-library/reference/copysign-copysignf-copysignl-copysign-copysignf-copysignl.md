---
title: copysign, copysignf, copysignl, _copysign, _copysignf, _copysignl | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- copysignf
- copysignl
- _copysignl
- _copysign
- _copysignf
- copysign
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
- _copysignl
- copysign
- copysignf
- _copysign
- copysignl
- _copysignf
dev_langs:
- C++
helpviewer_keywords:
- copysignl function
- _copysignl function
- copysign function
- _copysignf function
- _copysign function
- copysignf function
ms.assetid: 009216d6-72a2-402d-aa6c-91d924b2c9e4
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d52802914fee97f7c8df1472998ae5c8d7b139cb
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="copysign-copysignf-copysignl-copysign-copysignf-copysignl"></a>copysign, copysignf, copysignl, _copysign, _copysignf, _copysignl

Retorna um valor que tem a magnitude de um argumento e o sinal de outro.

## <a name="syntax"></a>Sintaxe

```C
double copysign(
   double x,
   double y
);
float copysign(
   float x,
   float y
); // C++ only
long double copysign(
   long double x,
   long double y
); // C++ only
float copysignf(
   float x,
   float y
); // C++ only
long double copysignl(
   long double x,
   long double y
); // C++ only
double _copysign(
   double x,
   double y
);
long double _copysignl(
   long double x,
   long double y
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
O valor de ponto flutuante retornado como a magnitude do resultado.

*y*<br/>
O valor de ponto flutuante retornado como o sinal do resultado.

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)

## <a name="return-value"></a>Valor de retorno

O **copysign** funções retornam um valor de ponto flutuante que combina a magnitude do *x* e o sinal de *y*. Nenhum erro é retornado.

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **copysign** que levar e retornar **float** ou **longo** **duplo** valores. Em um programa C, **copysign** sempre usa e retorna um **duplo**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_copysign**|\<float.h>|
|**copysign**, **copysignf**, **copysignl**, **copysignf**, **copysignl**|\<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[fabs, fabsf, fabsl](fabs-fabsf-fabsl.md)<br/>
[_chgsign, _chgsignf, _chgsignl](chgsign-chgsignf-chgsignl.md)<br/>
