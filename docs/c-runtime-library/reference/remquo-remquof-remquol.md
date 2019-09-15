---
title: remquo, remquof, remquol
ms.date: 04/05/2018
api_name:
- remquof
- remquo
- remquol
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
- remquof
- remquol
- remquo
helpviewer_keywords:
- remquol function
- remquof function
- remquo function
ms.assetid: a1d3cb8b-8027-4cd3-8deb-04eb17f299fc
ms.openlocfilehash: c96357dda007e9bf12ddaf6091af47794bfc0630
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949372"
---
# <a name="remquo-remquof-remquol"></a>remquo, remquof, remquol

Calcula o restante dos dois valores inteiros e armazena um valor inteiro com sinal e magnitude aproximada do quociente em um local especificado no parâmetro.

## <a name="syntax"></a>Sintaxe

```C
double remquo( double numer, double denom, int* quo );
float remquof( float numer, float denom, int* quo );
long double remquol( long double numer, long double denom, int* quo );
```

```cpp
float remquo( float numer, float denom, int* quo ); /* C++ only */
long double remquo( long double numer, long double denom, int* quo ); /* C++ only */
```

### <a name="parameters"></a>Parâmetros

*numer*<br/>
O numerador.

*denom*<br/>
O denominador.

*quo*<br/>
Um ponteiro para um inteiro para armazenar um valor que tem o sinal e magnitude aproximada do quociente.

## <a name="return-value"></a>Valor de retorno

**remquo** retorna o restante de ponto flutuante do *x* / *y*. Se o valor de *y* for 0,0, **remquo** retornará Nan silencioso. Para obter informações sobre a representação de um NaN silencioso pela família **printf** , consulte [printf, _printf_l, wprintf, _wprintf_l](printf-printf-l-wprintf-wprintf-l.md).

## <a name="remarks"></a>Comentários

A função **remquo** calcula o restante do ponto flutuante *f* de *x* / *y* de forma que *x* = *i* \* *y* + *f*, onde *eu* é um inteiro, *f* tem o mesmo sinal que *x*e o valor absoluto de *f* é menor que o valor absoluto de *y*.

C++permite sobrecarga, portanto, você pode chamar sobrecargas de **remquo** que levam e retornam valores **duplos** **float** ou **Long** . Em um programa C, **remquo** sempre pega dois argumentos **duplos** e retorna um **Double**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|
|--------------|---------------------|-|
|**remquo**, **remquof**, **remquol**|\<math.h>|\<cmath> ou \<math.h>|

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldiv, lldiv](ldiv-lldiv.md)<br/>
[imaxdiv](imaxdiv.md)<br/>
[fmod, fmodf](fmod-fmodf.md)<br/>
[remainder, remainderf, remainderl](remainder-remainderf-remainderl.md)<br/>
