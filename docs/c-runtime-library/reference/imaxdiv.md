---
title: "imaxdiv | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "imaxdiv"
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
  - "imaxdiv"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função imaxdiv"
ms.assetid: 7d90126f-fdc2-4986-9cdf-94e4c9123d26
caps.latest.revision: 7
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# imaxdiv
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o quociente e o restante de dois valores inteiros de qualquer tamanho como uma única operação.  
  
## Sintaxe  
  
```  
imaxdiv_t imaxdiv(   
   intmax_t numer,  
   intmax_t denom   
);   
```  
  
#### Parâmetros  
 `numer`  
 O numerador.  
  
 `denom`  
 O denominador.  
  
## Valor de retorno  
 `imaxdiv` chamado com argumentos do tipo [intmax\_t](../../c-runtime-library/standard-types.md) retorna uma estrutura do tipo [imaxdiv\_t](../../c-runtime-library/standard-types.md) que compreende o quociente e o resto.  
  
## Comentários  
 A função de `imaxdiv` divide `numer` por `denom` e calcula assim o quociente e o restante.  A estrutura de `imaxdiv_t` contém o quociente, `intmax_t` `quot` e o restante, `intmax_t` `rem`.  O sinal do quociente é o mesmo que o do quociente matemático.  Seu valor absoluto é o maior número inteiro menor do que o valor absoluto do quociente matemático.  Se o denominador é 0, o programa termina com uma mensagem de erro.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`imaxdiv`|\<inttypes.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
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
  
 Quando compilado e então chamado com os parâmetros de linha de comando de `9460730470000000 8766`, o código gera essa saída:  
  
  **A chamada para imaxdiv\(9460730470000000, 8766\)**  
**resultados em um quociente de 1079252848505, e resto 5170**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [div](../../c-runtime-library/reference/div.md)   
 [ldiv, lldiv](../Topic/ldiv,%20lldiv.md)