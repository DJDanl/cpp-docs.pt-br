---
title: cpow, cpowf, cpowl
ms.date: 11/04/2016
apiname:
- cpow
- cpowf
- cpowl
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
- cpow
- cpowf
- cpowl
- complex/cpow
- complex/cpowf
- complex/copwl
helpviewer_keywords:
- cpow function
- cpowf function
- complex/cpowl function
ms.assetid: 83fe2187-22b7-4295-ab16-4d77abdbb80b
ms.openlocfilehash: 588c437a01237de297e1db31fb2c507eb1145d90
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50562481"
---
# <a name="cpow-cpowf-cpowl"></a>cpow, cpowf, cpowl

Recupera o valor de um número elevado à potência especificada, em que a base e o expoente são números complexos. Essa função contém uma ramificação recortada para o expoente ao longo do eixo real negativo.

## <a name="syntax"></a>Sintaxe

```C
_Dcomplex cpow(
   _Dcomplex x, _Dcomplex y
);
_Fcomplex cpow(
   _Fcomplex x, _Fcomplex y
);  // C++ only
_Lcomplex cpow(
   _Lcomplex x, _Lcomplex y
);  // C++ only
_Fcomplex cpowf(
   _Fcomplex x, _Fcomplex y
);
_Lcomplex cpowl(
   _Lcomplex x, _Lcomplex y
);
```

### <a name="parameters"></a>Parâmetros

*x*<br/>
A base.

*y*<br/>
O expoente.

## <a name="return-value"></a>Valor de retorno

O valor de *x* elevado à potência de *y* com uma ramificação recortada para *x* ao longo do eixo real negativo.

## <a name="remarks"></a>Comentários

Como C++ permite sobrecargas, é possível chamar sobrecargas de **cpow** que usam e retornam **fcomplex** e **_Lcomplex** valores. Em um programa do C **cpow** sempre usa e retorna um **_Dcomplex** valor.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**cpow**, **cpowf**, **cpowl**|\<complex.h>|\<ccomplex>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[cexp, cexpf, cexpl](cexp-cexpf-cexpl.md)<br/>
[clog10, clog10f, clog10l](clog10-clog10f-clog10l.md)<br/>
[clog, clogf, clogl](clog-clogf-clogl.md)<br/>
