---
title: fmod, fmodf, fmodl
description: Referência de API para fmod, fmodf e fmodl; que calcula o restante do ponto flutuante.
ms.date: 9/1/2020
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
ms.openlocfilehash: 2b610dec79c98b973af09f8efb147ad6797f7946
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556080"
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

#define fmod(X, Y) // Requires C11 or higher
```

### <a name="parameters"></a>Parâmetros

*x*, *y*\
Valores de ponto flutuante.

## <a name="return-value"></a>Valor Retornado

**fmod** retorna o restante de ponto flutuante do *x*  /  *y*. Se o valor de *y* for 0,0, **fmod** retornará Nan silencioso. Para obter informações sobre a representação de um NaN silencioso pela família **printf** , consulte [printf](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

A função **fmod** calcula o restante do ponto flutuante *f* de *x*  /  *y* de forma que *x*  =  *i* \* *y*  +  *f*, onde *eu* seja um inteiro, *f* tenha o mesmo sinal que *x*e o valor absoluto de *f* seja menor que o valor absoluto de *y*.

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **fmod** que levam e retornam **`float`** **`long double`** valores. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **fmod** sempre usa dois **`double`** argumentos e retorna um **`double`** .

Se você usar a \<tgmath.h> `fmod()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fmod**, **fmodf**, **fmodl**|\<math.h>|
|macro **fmod** | \<tgmath.h> |

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
