---
title: "div | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "div"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-utility-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "div"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função div"
  - "dividindo inteiros"
  - "quocientes"
  - "quocientes, calculando"
  - "cálculo do restante"
ms.assetid: 8ae80d97-54fd-499e-b14c-e30993b58119
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# div
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o quociente e o restante de dois valores inteiros.  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `numer`  
 O numerador.  
  
 `denom`  
 O denominador.  
  
## Valor de retorno  
 `div` chamado com argumentos do tipo `int` retorna uma estrutura do tipo `div_t`, que compacta o quociente e o resto.  O valor de retorno da sobrecarga com argumentos do tipo `long` é `ldiv_t`.  `div_t` e `ldiv_t` são definidos em STDLIB.H.  
  
## Comentários  
 A função de `div` divide `numer` por `denom` e calcula assim o quociente e o restante.  A estrutura de [div\_t](../../c-runtime-library/standard-types.md) contém o quociente, `int` `quot`, e o resto, `int` `rem`.  O sinal do quociente é o mesmo que o do quociente matemático.  Seu valor absoluto é o maior número inteiro menor do que o valor absoluto do quociente matemático.  Se o denominador é 0, o programa termina com uma mensagem de erro.  
  
 As sobrecargas que usam argumentos do tipo `long` ou `long long` estão disponíveis apenas para o código C\+\+.  O tipo de retorno [ldiv\_t](../../c-runtime-library/standard-types.md) contém os membros `long` `quot` e `long` `rem`, e o tipo de retorno [lldiv\_t](../../c-runtime-library/standard-types.md) contém os membros `long long quot` e `long long rem`, que têm os mesmos significados que os membros de `div_t`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`div`|\<stdlib.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
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
  
  **x é 876, y é 13**  
**O quociente é 67 e o restante é 5**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ldiv, lldiv](../Topic/ldiv,%20lldiv.md)   
 [imaxdiv](../../c-runtime-library/reference/imaxdiv.md)