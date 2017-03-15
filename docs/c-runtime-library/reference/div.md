---
title: div | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 9e1389e2d8623e7e96ef3ad6af8772ee7026ec76
ms.lasthandoff: 02/25/2017

---
# <a name="div"></a>div
Calcula o quociente e o resto dos dois valores inteiros.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
div_t div(   
   int numer,  
   int denom   
);  
ldiv_t div(  
   long numer,  
   long denom  
); /* C++ only */   
lldiv_t div(  
   long long numer,  
   long long denom  
); /* C++ only */  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `numer`  
 O numerador.  
  
 `denom`  
 O denominador.  
  
## <a name="return-value"></a>Valor de retorno  
 `div` chamado por meio de argumentos do tipo `int` retorna uma estrutura do tipo `div_t`, que inclui o quociente e o resto. O valor retornado da sobrecarga com argumentos de tipo `long` é `ldiv_t`. `div_t` e `ldiv_t` são definidos em STDLIB.H.  
  
## <a name="remarks"></a>Comentários  
 A função `div` divide `numer` por `denom` e, portanto, calcula o quociente e o resto. A estrutura [div_t](../../c-runtime-library/standard-types.md) contém o quociente, `int``quot` e o resto, `int``rem`. O sinal do quociente é o mesmo do quociente matemático. Seu valor absoluto é o maior inteiro menor que o valor absoluto do quociente matemático. Se o denominador for 0, o programa será encerrado com uma mensagem de erro.  
  
 As sobrecargas que usam argumentos de tipo `long` ou `long long` só estão disponíveis para o código C++. O tipo de retorno [ldiv_t](../../c-runtime-library/standard-types.md) contém os membros `long``quot` e `long``rem` e o tipo de retorno [lldiv_t](../../c-runtime-library/standard-types.md) contém os membros `long long quot` e `long long rem`, que têm o mesmo significado que os membros do `div_t`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`div`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ldiv, lldiv](../../c-runtime-library/reference/ldiv-lldiv.md)   
 [imaxdiv](../../c-runtime-library/reference/imaxdiv.md)
