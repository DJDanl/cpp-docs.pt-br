---
title: div, ldiv, lldiv | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- div
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
- api-ms-win-crt-utility-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- div
dev_langs:
- C++
helpviewer_keywords:
- div function
- quotients, computing
- quotients
- dividing integers
- remainder computing
ms.assetid: 8ae80d97-54fd-499e-b14c-e30993b58119
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b3a0e28030b62f68d478cb976b1f89d91904655a
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
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

## <a name="return-value"></a>Valor de retorno

**div** chamado com argumentos de tipo **int** retorna uma estrutura de tipo **div_t**, que abrange o quociente e o restante. O valor de retorno com argumentos de tipo **longo** é **ldiv_t**e o valor de retorno com argumentos de tipo **longo** **longo** é **lldiv_t**. **div_t**, **ldiv_t**, e **lldiv_t** são definidos no \<stdlib.h >.

## <a name="remarks"></a>Comentários

O **div** função divide *número* por *denom* e, portanto, calcula o quociente e o restante. O [div_t](../../c-runtime-library/standard-types.md) estrutura contém o quociente **quot**e o resto, **rem**. O sinal do quociente é o mesmo do quociente matemático. Seu valor absoluto é o maior inteiro menor que o valor absoluto do quociente matemático. Se o denominador é 0, o programa é encerrado com uma mensagem de erro.

As sobrecargas de **div** que usam argumentos de tipo **longo** ou **longo** **longo** só estão disponíveis para o código C++. Os tipos de retorno [ldiv_t](../../c-runtime-library/standard-types.md) e [lldiv_t](../../c-runtime-library/standard-types.md) contém membros **quot** e **rem**, que possuem os significados mesmo como os membros de **div_t**.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**div**, **ldiv**, **lldiv**|\<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[ldiv, lldiv](ldiv-lldiv.md)<br/>
[imaxdiv](imaxdiv.md)<br/>
