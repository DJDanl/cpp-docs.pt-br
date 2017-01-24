---
title: "sqrt, sqrtf, sqrtl | Microsoft Docs"
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
  - "sqrtl"
  - "sqrtf"
  - "sqrt"
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
  - "sqrt"
  - "sqrtf"
  - "_sqrtl"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _sqrtl"
  - "calculando raízes quadradas"
  - "Função sqrt"
  - "Função sqrtf"
  - "Função sqrtl"
  - "raízes quadradas, calculando"
ms.assetid: 2ba9467b-f172-41dc-8f10-b86f68fa813c
caps.latest.revision: 18
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# sqrt, sqrtf, sqrtl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula a raiz quadrada.  
  
## Sintaxe  
  
```  
double sqrt(    double x  ); float sqrt(    float x  );  // C++ only long double sqrt(    long double x );  // C++ only float sqrtf(    float x  ); long double sqrtl(    long double x  );  
```  
  
#### Parâmetros  
 `x`  
 Um valor de ponto flutuante não negativo  
  
## Comentários  
 Como C\+\+ permite a sobrecarga, você pode chamar sobrecargas de `sqrt` que usam o tipo `float` ou `long double`.  Em programas C, `sqrt` sempre usa e retorna `double`.  
  
## Valor de retorno  
 A função `sqrt` retorna a raiz quadrada de `x`.  Por padrão, se `x` for um valor negativo, `sqrt` retorna um NaN \(não é um número\) indefinido.  
  
|Entrada|Exceção SEH|Exceção `_matherr`|  
|-------------|-----------------|------------------------|  
|± QNAN,IND|nenhum|\_DOMAIN|  
|\- ∞|nenhum|\_DOMAIN|  
|x\<0|nenhum|\_DOMAIN|  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`sqrt`, `sqrtf`, `sqrtl`|\<math.h\>|\<cmath\>|  
  
 Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_sqrt.c  
// This program calculates a square root.  
  
#include <math.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   double question = 45.35, answer;  
   answer = sqrt( question );  
   if( question < 0 )  
      printf( "Error: sqrt returns %f\n", answer );  
   else  
      printf( "The square root of %.2f is %.2f\n", question, answer );  
}  
```  
  
  **A raiz quadrada de 45,35 é 6,73**   
## Equivalência do .NET Framework  
 [System::Math::Sqrt](https://msdn.microsoft.com/en-us/library/system.math.sqrt.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [exp, expf](../../c-runtime-library/reference/exp-expf.md)   
 [log, logf, log10, log10f](../Topic/log,%20logf,%20log10,%20log10f.md)   
 [pow, powf, powl](../Topic/pow,%20powf,%20powl.md)   
 [\_CIsqrt](../../c-runtime-library/cisqrt.md)