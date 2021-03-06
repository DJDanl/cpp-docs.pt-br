---
title: cexp, cexpf, cexpl
description: Referência de API para cexp, cexpf e cexpl; que calculam o exponencial de base e de um número complexo.
ms.date: 11/04/2016
api_name:
- cexp
- cexpf
- cexpl
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
- cexp
- cexpf
- cexpl
- complex/cepx
- complex/cexpf
- complex/cexpl
helpviewer_keywords:
- cexp function
- cexpl function
- cexpf function
ms.assetid: f27fd5a9-70c7-4957-a7ee-5256d19bd1da
ms.openlocfilehash: 66f7b687e8da12473abef4dbc44831e175956ac0
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555209"
---
# <a name="cexp-cexpf-cexpl"></a>cexp, cexpf, cexpl

Calcule o exponencial de base e de um número complexo.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex cexp( _Dcomplex z );
_Fcomplex cexpf( _Fcomplex z );
_Lcomplex cexpl( _Lcomplex z );

_Fcomplex cexp( _Fcomplex z );  // C++ only
_Lcomplex cexp( _Lcomplex z );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*z*\
Um número complexo que representa o expoente.

## <a name="return-value"></a>Valor Retornado

O valor de **e** elevado à potência de *z*.

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **cexp** que usam e retornam valores **_Fcomplex** e **_Lcomplex** . Em um programa C, **cexp** sempre pega e retorna um valor **_Dcomplex** .

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**cexp**, **cexpf**, **cexpl**|\<complex.h>|\<complex.h>|

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência de função alfabética](crt-alphabetical-function-reference.md)\
[cpow, cpowf, cpowl](cpow-cpowf-cpowl.md)\
[clog10, clog10f, clog10l](clog10-clog10f-clog10l.md)\
[clog, clogf, clogl](clog-clogf-clogl.md)
