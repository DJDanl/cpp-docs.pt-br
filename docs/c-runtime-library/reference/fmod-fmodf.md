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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 4fa3df46358932b8a62a6b8529baed4a5c9e5c49
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87216967"
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

### <a name="parameters"></a>parâmetros

*x*, *y*<br/>
Valores de ponto flutuante.

## <a name="return-value"></a>Valor retornado

**fmod** retorna o restante de ponto flutuante do *x*  /  *y*. Se o valor de *y* for 0,0, **fmod** retornará Nan silencioso. Para obter informações sobre a representação de um NaN silencioso pela família **printf** , consulte [printf](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

A função **fmod** calcula o restante do ponto flutuante *f* de *x*  /  *y* de forma que *x*  =  *i* \* *y*  +  *f*, onde *eu* seja um inteiro, *f* tenha o mesmo sinal que *x*e o valor absoluto de *f* seja menor que o valor absoluto de *y*.

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **fmod** que levam e retornam **`float`** **`long double`** valores. Em um programa C, **fmod** sempre usa dois **`double`** argumentos e retorna um **`double`** .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fmod**, **fmodf**, **fmodl**|\<math.h>|

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

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ceil, ceilf, ceill](ceil-ceilf-ceill.md)<br/>
[fabs, fabsf, fabsl](fabs-fabsf-fabsl.md)<br/>
[floor, floorf, floorl](floor-floorf-floorl.md)<br/>
[_CIfmod](../../c-runtime-library/cifmod.md)<br/>
