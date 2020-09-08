---
title: remquo, remquof, remquol
description: Referência de API para remquo, remquof e remquol; que calculam o restante de dois valores inteiros e armazena um valor inteiro com o sinal e a magnitude aproximada do quociente em um local especificado em um parâmetro.
ms.date: 9/1/2020
api_name:
- remquof
- remquo
- remquol
- _o_remquo
- _o_remquof
- _o_remquol
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
- remquof
- remquol
- remquo
helpviewer_keywords:
- remquol function
- remquof function
- remquo function
ms.assetid: a1d3cb8b-8027-4cd3-8deb-04eb17f299fc
ms.openlocfilehash: d99204ad9a80c6320869cbb72aee905981a5224d
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89554962"
---
# <a name="remquo-remquof-remquol"></a>remquo, remquof, remquol

Calcula o restante dos dois valores inteiros e armazena um valor inteiro com sinal e magnitude aproximada do quociente em um local especificado no parâmetro.

## <a name="syntax"></a>Sintaxe

```C
double remquo( double numer, double denom, int* quo );
float remquof( float numer, float denom, int* quo );
long double remquol( long double numer, long double denom, int* quo );
#define remquo(X, Y, INT_PTR) // Requires C11 or higher

float remquo( float numer, float denom, int* quo ); /* C++ only */
long double remquo( long double numer, long double denom, int* quo ); /* C++ only */
```

### <a name="parameters"></a>Parâmetros

*número*\
O numerador.

*denom*\
O denominador.

*situação*\
Um ponteiro para um inteiro para armazenar um valor que tem o sinal e magnitude aproximada do quociente.

## <a name="return-value"></a>Valor Retornado

**remquo** retorna o restante de ponto flutuante do *x*  /  *y*. Se o valor de *y* for 0,0, **remquo** retornará Nan silencioso. Para obter informações sobre a representação de um NaN silencioso pela família **printf** , consulte [printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

A função **remquo** calcula o restante do ponto flutuante *f* de *x*  /  *y* de forma que *x*  =  *i* \* *y*  +  *f*, onde *eu* seja um inteiro, *f* tenha o mesmo sinal que *x*e o valor absoluto de *f* seja menor que o valor absoluto de *y*.

O C++ permite sobrecarga, portanto, você pode chamar sobrecargas de **remquo** que usam e retornam **`float`** **`long double`** valores. Em um programa C, a menos que você esteja usando a \<tgmath.h> macro para chamar essa função, **remquo** sempre usa dois **`double`** argumentos e retorna um **`double`** .

Se você usar a \<tgmath.h> `remquo()` macro, o tipo do argumento determinará qual versão da função está selecionada. Consulte [tipo-matemática genérica](../../c-runtime-library/tgmath.md) para obter detalhes.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------|-|
|**remquo**, **remquof**, **remquol**|\<math.h>|\<cmath> ou \<math.h>|
|macro **remquo** | \<tgmath.h> ||

Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_remquo.c
// This program displays a floating-point remainder.

#include <math.h>
#include <stdio.h>

int main( void )
{
   double w = -10.0, x = 3.0, z;
   int quo = 0;

   z = remquo(w, x, &quo);
   printf("The remainder of %.2f / %.2f is %f\n", w, x, z);
   printf("Approximate signed quotient is %d\n", quo);
}
```

```Output
The remainder of -10.00 / 3.00 is -1.000000
Approximate signed quotient is -3
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldiv, lldiv](ldiv-lldiv.md)<br/>
[imaxdiv](imaxdiv.md)<br/>
[fmod, fmodf](fmod-fmodf.md)<br/>
[remainder, remainderf, remainderl](remainder-remainderf-remainderl.md)<br/>
