---
title: abs, labs, llabs, _abs64
description: Referência de API para ABS, Labs, llabs e _abs64; que calcula o valor absoluto de um valor.
ms.date: 04/05/2018
api_name:
- abs
- _abs64
- labs
- llabs
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
- api-ms-win-crt-utility-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- stdlib/_abs64
- math/abs
- _abs64
- abs
- labs
- math/labs
- llabs
- math/llabs
- cmath/abs
helpviewer_keywords:
- absolute values
- abs function
- abs64 function
- _abs64 function
- calculating absolute values
ms.assetid: 60f789d1-4a1e-49f5-9e4e-0bdb277ea26a
ms.openlocfilehash: 4527950e4f5577b9285d12309742accb64b9a24a
ms.sourcegitcommit: 4ed2d68634eb2fb77e18110a2d26bc0008be369c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/08/2020
ms.locfileid: "89556743"
---
# <a name="abs-labs-llabs-_abs64"></a>abs, labs, llabs, _abs64

Calcula o valor absoluto do argumento.

## <a name="syntax"></a>Sintaxe

```C
int abs( int n );
long labs( long n );
long long llabs( long long n );
__int64 _abs64( __int64 n );
```

```cpp
long abs( long n );   // C++ only
long long abs( long long n );   // C++ only
double abs( double n );   // C++ only
long double abs( long double n );   // C++ only
float abs( float n );   // C++ only
```

### <a name="parameters"></a>Parâmetros

*p*\
Valor numérico.

## <a name="return-value"></a>Valor Retornado

As funções **ABS**, **Labs**, **llabs**e **_abs64** retornam o valor absoluto do parâmetro *n*. Não há nenhum retorno de erro.

## <a name="remarks"></a>Comentários

Como o C++ permite sobrecarga, você pode chamar sobrecargas de **ABS** que pegam e retornam **`long`** **`long long`** valores,,, **`float`** **`double`** e **`long double`** . Essas sobrecargas são definidas no \<cmath> cabeçalho. Em um programa C, o **ABS** sempre pega e retorna um **`int`** .

**Específico da Microsoft**: como o intervalo de inteiros negativos que podem ser representados usando qualquer tipo integral é maior do que o intervalo de inteiros positivos que podem ser representados usando esse tipo, é possível fornecer um argumento para essas funções que não podem ser convertidas. Se o valor absoluto do argumento não puder ser representado pelo tipo de retorno, as funções **ABS** retornarão o valor do argumento inalterado. Especificamente, `abs(INT_MIN)` retorna `INT_MIN`, `labs(LONG_MIN)` retorna `LONG_MIN`, `llabs(LLONG_MIN)` retorna `LLONG_MIN` e `_abs64(_I64_MIN)` retorna `_I64_MIN`. Isso significa que as funções **ABS** não podem ser usadas para garantir um valor positivo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho C necessário|Cabeçalho C++ necessário|
|-------------|-----------------------|---------------------------|
|**ABS**, **laboratórios**, **llabs**|\<math.h> ou \<stdlib.h>|\<cmath>, \<cstdlib>, \<stdlib.h> ou \<math.h>|
|**_abs64**|\<stdlib.h>|\<cstdlib> ou \<stdlib.h>|

Para usar as versões sobrecarregadas do **ABS** em C++, você deve incluir o \<cmath> cabeçalho.

## <a name="example"></a>Exemplo

O programa calcula e exibe os valores absolutos de vários números.

```C
// crt_abs.c
// Build: cl /W3 /TC crt_abs.c
// This program demonstrates the use of the abs function
// by computing and displaying the absolute values of
// several numbers.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int main( void )
{
    int ix = -4;
    long lx = -41567L;
    long long llx = -9876543210LL;
    __int64 wx = -1;

    // absolute 32 bit integer value
    printf_s("The absolute value of %d is %d\n", ix, abs(ix));

    // absolute long integer value
    printf_s("The absolute value of %ld is %ld\n", lx, labs(lx));

    // absolute long long integer value
    printf_s("The absolute value of %lld is %lld\n", llx, llabs(llx));

    // absolute 64 bit integer value
    printf_s("The absolute value of 0x%.16I64x is 0x%.16I64x\n", wx,
        _abs64(wx));

    // Integer error cases:
    printf_s("Microsoft implementation-specific results:\n");
    printf_s(" abs(INT_MIN) returns %d\n", abs(INT_MIN));
    printf_s(" labs(LONG_MIN) returns %ld\n", labs(LONG_MIN));
    printf_s(" llabs(LLONG_MIN) returns %lld\n", llabs(LLONG_MIN));
    printf_s(" _abs64(_I64_MIN) returns 0x%.16I64x\n", _abs64(_I64_MIN));
}
```

```Output
The absolute value of -4 is 4
The absolute value of -41567 is 41567
The absolute value of -9876543210 is 9876543210
The absolute value of 0xffffffffffffffff is 0x0000000000000001
Microsoft implementation-specific results:
abs(INT_MIN) returns -2147483648
labs(LONG_MIN) returns -2147483648
llabs(LLONG_MIN) returns -9223372036854775808
_abs64(_I64_MIN) returns 0x8000000000000000
```

## <a name="see-also"></a>Confira também

[Conversão de Dados](../../c-runtime-library/data-conversion.md)<br/>
[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[_cabs](cabs.md)<br/>
[fabs, fabsf, fabsl](fabs-fabsf-fabsl.md)<br/>
[imaxabs](imaxabs.md)
