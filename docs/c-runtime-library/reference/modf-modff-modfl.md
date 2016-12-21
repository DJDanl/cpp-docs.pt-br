---
title: "modf, modff, modfl | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "modff"
  - "modf"
  - "modfl"
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
  - "modff"
  - "_modfl"
  - "modf"
  - "modfl"
  - "math/modf"
  - "math/modff"
  - "math/modfl"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função modf"
  - "Função modff"
  - "função modfl"
ms.assetid: b1c7abf5-d476-43ca-a03c-02072a86e32d
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# modf, modff, modfl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Divide um valor de ponto flutuante em frações e partes do inteiro.  
  
## Sintaxe  
  
```  
double modf(  
   double x,  
   double * intptr   
);  
float modf(  
   float x,  
   float * intptr  
);  // C++ only  
long double modf(  
   long double x,  
   long double * intptr  
);  // C++ only  
float modff(  
   float x,  
   float * intptr   
);  
long double modfl(  
   long double x,  
   long double * intptr  
);  
```  
  
#### Parâmetros  
 *x*  
 Valor de ponto flutuante.  
  
 `intptr`  
 Ponteiro para a parte inteira armazenado.  
  
## Valor de retorno  
 Esta função retorna a parte fracionária assinada de *x*. Não há nenhum retorno de erro.  
  
## Comentários  
 O `modf` funções dividir o valor de ponto flutuante `x` em frações e partes do inteiro, cada um deles tem o mesmo sinal `x`. A parte fracionária assinada de `x` é retornado. A parte inteira é armazenada como um valor de ponto flutuante no `intptr.`  
  
 `modf` tem uma implementação que usa o Streaming SIMD Extensions 2 \(SSE2\). Consulte [\_set\_SSE2\_enable](../Topic/_set_SSE2_enable.md) para obter informações e restrições sobre como usar a implementação SSE2.  
  
 C\+\+ permite sobrecargas, para que você possa chamar sobrecargas de `modf` que tomam e retornam `float` ou `long double` parâmetros. Em um programa C, `modf` sempre usa dois valores double e retorna um valor double.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`modf`, `modff`, `modfl`|C: \< Math \><br /><br /> C\+\+:, \< cmath \> ou \< Math \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_modf.c  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x, y, n;  
  
   x = -14.87654321;      /* Divide x into its fractional */  
   y = modf( x, &n );     /* and integer parts            */  
  
   printf( "For %f, the fraction is %f and the integer is %.f\n",   
           x, y, n );  
}  
```  
  
## Saída  
  
```  
For -14.876543, the fraction is -0.876543 and the integer is -14  
```  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [frexp](../../c-runtime-library/reference/frexp.md)   
 [ldexp](../../c-runtime-library/reference/ldexp.md)