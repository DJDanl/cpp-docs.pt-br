---
title: ldiv, lldiv | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- ldiv
- lldiv
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
- ldiv
- lldiv
dev_langs:
- C++
helpviewer_keywords:
- ldiv function
- lldiv function
- quotients, computing
- computing remainders
- remainder computing
- computing quotients
ms.assetid: 68ab5d83-27a4-479c-9d52-d055eb139eca
caps.latest.revision: 12
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 3e7d21b1b5c6197c43ddc5730953f1a4a6259fc2
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="ldiv-lldiv"></a>ldiv, lldiv
Calcula o quociente e o resto de dois inteiros como uma operação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
ldiv_t ldiv(  
   long numer,  
   long denom   
);  
lldiv_t lldiv(  
   long long numer,  
   long long denom   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `numer`  
 Numerador.  
  
 `denom`  
 Denominador.  
  
## <a name="return-value"></a>Valor de retorno  
 `ldiv` retorna uma estrutura do tipo [ldiv_t](../../c-runtime-library/standard-types.md) que compreende o quociente e o resto. `lldiv` retorna uma estrutura do tipo [lldiv_t](../../c-runtime-library/standard-types.md) que compreende o quociente e o resto.  
  
## <a name="remarks"></a>Comentários  
 As funções `ldiv` e `lldiv` dividem `numer` por `denom` e, assim, calculam o quociente e o restante. O sinal do quociente é o mesmo do quociente matemático. O valor absoluto do quociente é o maior inteiro que é menor que o valor absoluto do quociente matemático. Se o denominador for 0, o programa será encerrado com uma mensagem de erro. `ldiv` e `lldiv` são o mesmo que `div`, exceto pelo fato de que os argumentos de `ldiv` e os membros da estrutura retornada são todos do tipo `long` e os argumentos de `lldiv` e os membros da estrutura retornada são do tipo `long long`.  
  
 As estruturas `ldiv_t` e `lldiv_t` são definidas em \<stdlib.h>.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`ldiv`, `lldiv`|\<stdlib.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_ldiv.c  
  
#include <stdlib.h>  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   long x = 5149627, y = 234879;  
   ldiv_t div_result;  
  
   div_result = ldiv( x, y );  
   printf( "For %ld / %ld, the quotient is ", x, y );  
   printf( "%ld, and the remainder is %ld\n",   
            div_result.quot, div_result.rem );  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
For 5149627 / 234879, the quotient is 21, and the remainder is 217168  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [div](../../c-runtime-library/reference/div.md)   
 [imaxdiv](../../c-runtime-library/reference/imaxdiv.md)
