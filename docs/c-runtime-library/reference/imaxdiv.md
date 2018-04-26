---
title: imaxdiv | Microsoft Docs
ms.custom: ''
ms.date: 04/05/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- imaxdiv
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
- imaxdiv
dev_langs:
- C++
helpviewer_keywords:
- imaxdiv function
ms.assetid: 7d90126f-fdc2-4986-9cdf-94e4c9123d26
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ab39d68f733fdb7d078efdc058f09e30d0fd907b
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="imaxdiv"></a>imaxdiv

Calcula o quociente e o resto dos dois valores inteiros de qualquer tamanho como uma única operação.

## <a name="syntax"></a>Sintaxe

```C
imaxdiv_t imaxdiv(
   intmax_t numer,
   intmax_t denom
);
```

### <a name="parameters"></a>Parâmetros

*número*<br/>
O numerador.

*denom*<br/>
O denominador.

## <a name="return-value"></a>Valor de retorno

**imaxdiv** chamado com argumentos de tipo [intmax_t](../../c-runtime-library/standard-types.md) retorna uma estrutura de tipo [imaxdiv_t](../../c-runtime-library/standard-types.md) que abrange o quociente e o restante.

## <a name="remarks"></a>Comentários

O **imaxdiv** função divide *número* por *denom* e, portanto, calcula o quociente e o restante. O **imaxdiv_t** estrutura contém o quociente **intmax_t** **quot**e o resto, **intmax_t** **rem**. O sinal do quociente é o mesmo do quociente matemático. Seu valor absoluto é o maior inteiro menor que o valor absoluto do quociente matemático. Se o denominador é 0, o programa é encerrado com uma mensagem de erro.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**imaxdiv**|\<inttypes.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_imaxdiv.c
// Build using: cl /W3 /Tc crt_imaxdiv.c
// This example takes two integers as command-line
// arguments and calls imaxdiv to divide the first
// argument by the second, then displays the results.

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(int argc, char *argv[])
{
   intmax_t x,y;
   imaxdiv_t div_result;

   x = atoll(argv[1]);
   y = atoll(argv[2]);

   printf("The call to imaxdiv(%lld, %lld)\n", x, y);
   div_result = imaxdiv(x, y);
   printf("results in a quotient of %lld, and a remainder of %lld\n\n",
          div_result.quot, div_result.rem);
}
```

Quando compilado e então chamado com parâmetros de linha de comando do `9460730470000000 8766`, o código gera esta saída:

```Output
The call to imaxdiv(9460730470000000, 8766)
results in a quotient of 1079252848505, and a remainder of 5170
```

## <a name="see-also"></a>Consulte também

[Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)<br/>
[div](div.md)<br/>
[ldiv, lldiv](ldiv-lldiv.md)<br/>
