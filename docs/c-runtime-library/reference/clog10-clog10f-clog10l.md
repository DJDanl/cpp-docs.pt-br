---
title: clog10, clog10f, clog10l
ms.date: 11/04/2016
apiname:
- clog10
- clog10f
- clog10l
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
- clog10
- clog10f
- clog10l
- complex/clog10
- complex/clog10f
- complex/clog10l
helpviewer_keywords:
- clog10 function
- clog10f function
- clog10l function
ms.assetid: 2ddae00d-ef93-4441-add3-f4d58358401b
ms.openlocfilehash: 195f4be80f0320e83cc9455a598185ce281bbf59
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50506906"
---
# <a name="clog10-clog10f-clog10l"></a>clog10, clog10f, clog10l

Recupera o logaritmo de base 10 de um número complexo.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex clog10( _Dcomplex z );
_Fcomplex clog10f( _Fcomplex z );
_Lcomplex clog10l( _Lcomplex z );
```

```cpp
_Fcomplex clog10( _Fcomplex z );  // C++ only
_Lcomplex clog10( _Lcomplex z );  // C++ only
```

### <a name="parameters"></a>Parâmetros

*z*<br/>
A base do logaritmo.

## <a name="return-value"></a>Valor de retorno

Os valores de retorno possíveis são:

|Parâmetro z|Valor retornado|
|-----------------|------------------|
|Positivo|O logaritmo de base 10 de z|
|Zero|- ∞|
|Negativo|NaN|
|NaN|NaN|
|+ ∞|+ ∞|

## <a name="remarks"></a>Comentários

Como C++ permite sobrecargas, é possível chamar sobrecargas de **clog10** que usam e retornam **fcomplex** e **_Lcomplex** valores. Em um programa do C **clog10** sempre usa e retorna um **_Dcomplex** valor.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**clog10**, **clog10f**, **clogl**|\<complex.h>|\<ccomplex>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[cexp, cexpf, cexpl](cexp-cexpf-cexpl.md)<br/>
[cpow, cpowf, cpowl](cpow-cpowf-cpowl.md)<br/>
[clog, clogf, clogl](clog-clogf-clogl.md)<br/>
