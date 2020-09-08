---
title: ldexp, ldexpf, ldexpl
description: Referência de API para ldexp, ldexpf e ldexpl; que multiplica um número de ponto flutuante por uma potência integral de dois.
ms.date: 9/1/2020
api_name:
- ldexp
- ldexpf
- ldexpl
- _ldexpl
- _o_ldexp
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
- ldexp
- ldexpf
- ldexpl
- _ldexpl
helpviewer_keywords:
- calculating real numbers
- computing real numbers
- mantissas, floating-point variables
- ldexp function
- ldexpf function
- ldexpl function
- exponent, floating-point numbers
- floating-point functions, mantissa and exponent
ms.assetid: aa7f5310-3879-4f63-ae74-86a39fbdedfa
ms.openlocfilehash: 6ce6bcbc8adbc62e8d8598b97a6f77e04fee1511
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89555443"
---
# <a name="ldexp-ldexpf-ldexpl"></a>ldexp, ldexpf, ldexpl

Multiplica um número de ponto flutuante por uma potência integral de dois.

## <a name="syntax"></a>Sintaxe

```C
double ldexp(
   double x,
   int exp
);
float ldexpf(
   float x,
   int exp
);
long double ldexpl(
   long double x,
   int exp
);
#define ldexp(X, INT) // Requires C11 or higher

float ldexp(
   float x,
   int exp
);  // C++ only
long double ldexp(
   long double x,
   int exp
);  // C++ only
```

### <a name="parameters"></a>Parâmetros

*w.x.y.*\
Valor de ponto flutuante.

*exp*\
Expoente inteiro.

## <a name="return-value"></a>Valor Retornado

As funções **ldexp** retornarão o valor de *x* \* 2<sup>*exp*</sup> se for bem-sucedido. Em estouro, e dependendo do sinal de *x*, **ldexp** retorna +/- **HUGE_VAL**; o valor **errno** é definido como **ERANGE**.

Para obter mais informações sobre **errno** e possíveis valores de retorno de erro, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **ldexp** que usam **`float`** ou **`long double`** digitam. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **ldexp** sempre pega um **`double`** e um **`int`** e retorna um **`double`** .

Se você usar a \<tgmath.h> `ldexp()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C|Cabeçalho C++|
|-------------|--------------|------------------|
|**ldexp**, **ldexpf**, **ldexpl**|\<math.h>|\<cmath>|
|macro **ldexp** | \<tgmath.h> ||

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_ldexp.c

#include <math.h>
#include <stdio.h>

int main( void )
{
   double x = 4.0, y;
   int p = 3;

   y = ldexp( x, p );
   printf( "%2.1f times two to the power of %d is %2.1f\n", x, p, y );
}
```

## <a name="output"></a>Saída

```Output
4.0 times two to the power of 3 is 32.0
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[frexp](frexp.md)<br/>
[modf, modff, modfl](modf-modff-modfl.md)<br/>
