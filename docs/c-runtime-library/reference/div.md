---
title: div, ldiv, lldiv
ms.date: 04/05/2018
api_name:
- div
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
- div
helpviewer_keywords:
- div function
- quotients, computing
- quotients
- dividing integers
- remainder computing
ms.assetid: 8ae80d97-54fd-499e-b14c-e30993b58119
ms.openlocfilehash: e0c87ad44986363e871d68bccde757214f5e2c45
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91509895"
---
# <a name="div-ldiv-lldiv"></a>div, ldiv, lldiv

Calcula o quociente e o resto dos dois valores inteiros.

## <a name="syntax"></a>Sintaxe

```C
div_t div(
   int numer,
   int denom
);
ldiv_t ldiv(
   long numer,
   long denom
);
lldiv_t lldiv(
   long long numer,
   long long denom
);
```

```cpp
ldiv_t div(
   long numer,
   long denom
); /* C++ only */
lldiv_t div(
   long long numer,
   long long denom
); /* C++ only */
```

### <a name="parameters"></a>Parâmetros

*número*<br/>
O numerador.

*denom*<br/>
O denominador.

## <a name="return-value"></a>Valor Retornado

a **div** chamada usando argumentos do tipo **`int`** retorna uma estrutura do tipo **div_t**, que compreende o quociente e o resto. O valor de retorno com argumentos do tipo **`long`** é **ldiv_t**e o valor de retorno com argumentos do tipo **`long long`** é **lldiv_t**. **div_t**, **ldiv_t**e **lldiv_t** são definidos em \<stdlib.h> .

## <a name="remarks"></a>Comentários

A função **div** divide *número* por *denom* e, portanto, computa o quociente e o resto. A estrutura de [div_t](../../c-runtime-library/standard-types.md) contém o quociente, **quot**e o resto, **REM**. O sinal do quociente é o mesmo do quociente matemático. Seu valor absoluto é o maior inteiro menor que o valor absoluto do quociente matemático. Se o denominador for 0, o programa será encerrado com uma mensagem de erro.

As sobrecargas de **div** que usam argumentos do tipo **`long`** ou **`long long`** estão disponíveis apenas para código C++. Os tipos de retorno [ldiv_t](../../c-runtime-library/standard-types.md) e [lldiv_t](../../c-runtime-library/standard-types.md) contêm os membros **quot** e **REM**, que têm os mesmos significados que os membros de **div_t**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**div**, **ldiv**, **lldiv**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_div.c
// arguments: 876 13

// This example takes two integers as command-line
// arguments and displays the results of the integer
// division. This program accepts two arguments on the
// command line following the program name, then calls
// div to divide the first argument by the second.
// Finally, it prints the structure members quot and rem.
//

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main( int argc, char *argv[] )
{
   int x,y;
   div_t div_result;

   x = atoi( argv[1] );
   y = atoi( argv[2] );

   printf( "x is %d, y is %d\n", x, y );
   div_result = div( x, y );
   printf( "The quotient is %d, and the remainder is %d\n",
           div_result.quot, div_result.rem );
}
```

```Output
x is 876, y is 13
The quotient is 67, and the remainder is 5
```

## <a name="see-also"></a>Confira também

[Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldiv, lldiv]()<br/>
[imaxdiv](imaxdiv.md)<br/>
