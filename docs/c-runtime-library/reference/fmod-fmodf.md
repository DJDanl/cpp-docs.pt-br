---
title: fmod, fmodf, fmodl
ms.date: 4/2/2020
api_name:
- fmod
- fmodf
- fmodl
- _o_fmod
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
- fmod
- _fmodl
- fmodf
helpviewer_keywords:
- calculating floating-point remainders
- fmodf function
- fmodl function
- fmod function
- floating-point numbers, calculating remainders
ms.assetid: 6962d369-d11f-40b1-a6d7-6f67239f8a23
ms.openlocfilehash: 0cf25e2029f06c2e02a24ca84926e1a8b8f30159
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81346548"
---
# <a name="fmod-fmodf-fmodl"></a>fmod, fmodf, fmodl

Calcula o restante do ponto flutuante.

## <a name="syntax"></a>Sintaxe

```C
double fmod(
   double x,
   double y
);
float fmod(
   float x,
   float y
);  // C++ only
long double fmod(
   long double x,
   long double y
);  // C++ only
float fmodf(
   float x,
   float y
);
long double fmodl(
   long double x,
   long double y
);
```

### <a name="parameters"></a>Parâmetros

*x*, *y*<br/>
Valores de ponto flutuante.

## <a name="return-value"></a>Valor retornado

**fmod** retorna o restante do ponto flutuante de *x* / *y*. Se o valor de *y* for 0.0, **fmod** retorna um NaN tranquilo. Para obter informações sobre a representação de uma NaN tranquila pela família **printf,** consulte [printf](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

A função **fmod** calcula o ponto flutuante restante *f* de *x* / *y* tal que *x* = *i* \* *y* + *f*, onde *i* é um inteiro, *f* tem o mesmo sinal que *x*, e o valor absoluto de *f* é menor do que o valor absoluto de *y*.

C++ permite sobrecarga, para que você possa chamar sobrecargas de **fmod** que pegam e retornam **flutuam** e **longos** valores **duplos.** Em um programa C, **fmod** sempre pega dois **argumentos duplos** e retorna um **duplo**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fmod,** **fmodf,** **fmodl**|\<math.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fmod.c
// This program displays a floating-point remainder.

#include <math.h>
#include <stdio.h>

int main( void )
{
   double w = -10.0, x = 3.0, z;

   z = fmod( w, x );
   printf( "The remainder of %.2f / %.2f is %f\n", w, x, z );
}
```

```Output
The remainder of -10.00 / 3.00 is -1.000000
```

## <a name="see-also"></a>Confira também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ceil, ceilf, ceill](ceil-ceilf-ceill.md)<br/>
[fabs, fabsf, fabsl](fabs-fabsf-fabsl.md)<br/>
[floor, floorf, floorl](floor-floorf-floorl.md)<br/>
[_CIfmod](../../c-runtime-library/cifmod.md)<br/>
