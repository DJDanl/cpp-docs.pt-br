---
title: fmod, fmodf, fmodl
ms.date: 04/05/2018
apiname:
- fmod
- fmodf
- fmodl
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
ms.openlocfilehash: 78677be1a0c9921c35e54d43a00b8956a9d858b6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50605306"
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

## <a name="return-value"></a>Valor de retorno

**fmod** retorna o restante do ponto flutuante *x* / *y*. Se o valor de *y* é 0.0, **fmod** retorna um NaN silencioso. Para obter informações sobre a representação de um NaN silencioso pela **printf** família, consulte [printf](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

O **fmod** função calcula o restante do ponto flutuante *f* dos *x* / *y* que *x*  =  *eu* \* *y* + *f*, onde *eu* é um inteiro, *f* tem o mesmo sinal *x*e o valor absoluto do *f* é menor que o valor absoluto do *y*.

C++ permite sobrecargas, portanto, é possível chamar sobrecargas de **fmod** que usam e retornam **float** e **longo** **double** valores. Em um programa do C **fmod** sempre pega dois **duplo** argumentos e retorna um **double**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fmod**, **fmodf**, **fmodl**|\<math.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ceil, ceilf, ceill](ceil-ceilf-ceill.md)<br/>
[fabs, fabsf, fabsl](fabs-fabsf-fabsl.md)<br/>
[floor, floorf, floorl](floor-floorf-floorl.md)<br/>
[_CIfmod](../../c-runtime-library/cifmod.md)<br/>
