---
title: "frexp | Microsoft Docs"
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
  - "frexp"
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
  - "api-ms-win-crt-math-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "frexp"
  - "_frexpl"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _frexpl"
  - "expoente, números de ponto flutuante"
  - "funções de ponto flutuante, mantissa e expoente"
  - "Função frexp"
  - "Função frexpl"
  - "mantissas, variáveis de ponto flutuante"
ms.assetid: 9b020f2e-3967-45ec-a6a8-d467a071aa55
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# frexp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém a mantissa e o expoente de um número de ponto flutuante.  
  
## Sintaxe  
  
```  
double frexp(  
   double x,  
   int *expptr   
);  
float frexp(  
   float x,  
   int * expptr  
);  // C++ only  
long double frexp(  
   long double x,  
   int * expptr  
);  // C++ only  
```  
  
#### Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
 `expptr`  
 Ponteiro para o expoente armazenado de inteiro.  
  
## Valor de retorno  
 `frexp` retorna a mantissa.  Se `x` for 0, a função retorna 0 para a mantissa e o expoente.  Se `expptr` é `NULL`, o manipulador inválido do parâmetro será invocado como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, conjuntos `errno` dessa função a `EINVAL` e retorna 0.  
  
## Comentários  
 A função de `frexp` divide o valor de ponto flutuante \(`x`\) em uma`m`mantissa \(\) e um expoente \(`n`\), de modo que o valor absoluto de `m` é maior ou igual a 0,5 e menor que 1,0, e `x` \= `m`. \*2.<sup>n</sup> O expoente `n` inteiro é armazenado no local apontado por `expptr`.  
  
 C\+\+ reserva evitada, assim que você pode chamar sobrecargas de `frexp`.  No programa c, `frexp` sempre usa um duplo e um inteiro e retorna um valor double.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`frexp`|\<math.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_frexp.c  
// This program calculates frexp( 16.4, &n )  
// then displays y and n.  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x, y;  
   int n;  
  
   x = 16.4;  
   y = frexp( x, &n );  
   printf( "frexp( %f, &n ) = %f, n = %d\n", x, y, n );  
}  
```  
  
  **frexp \(16,400000\), &n \= 0,512500, n \= 5**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ldexp](../../c-runtime-library/reference/ldexp.md)   
 [modf, modff, modfl](../../c-runtime-library/reference/modf-modff-modfl.md)