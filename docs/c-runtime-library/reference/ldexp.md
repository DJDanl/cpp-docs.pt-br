---
title: "ldexp | Microsoft Docs"
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
  - "ldexp"
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
  - "ldexp"
  - "_ldexpl"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "calculando números reais"
  - "calculando números reais"
  - "expoente, números de ponto flutuante"
  - "funções de ponto flutuante, mantissa e expoente"
  - "Função ldexp"
  - "mantissas, variáveis de ponto flutuante"
ms.assetid: aa7f5310-3879-4f63-ae74-86a39fbdedfa
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ldexp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Multiplica um número de ponto flutuante por uma potência integral de dois.  
  
## Sintaxe  
  
```  
double ldexp(    double x,    int exp  ); float ldexp(    float x,    int exp );  // C++ only long double ldexp(    long double x,    int exp );  // C++ only  float ldexpf(    float x,    int exp );  long double ldexpl(    long double x,    int exp );   
```  
  
#### Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
 `exp`  
 Expoente inteiro.  
  
## Valor de retorno  
 A função `ldexp` retorna o valor de `x` \* 2<sup>exp</sup> em caso de êxito.  No estouro \(dependendo do sinal de `x`\), `ldexp`, retorna \+\/– `HUGE_VAL`. O valor `errno` é definido para `ERANGE`.  
  
 Para obter mais informações sobre `errno` e possíveis valores de retorno de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Como C\+\+ permite a sobrecarga, você pode chamar sobrecargas de `ldexp` que usam o tipo `float` ou `long double`.  Em um programa C, `ldexp` sempre utiliza um `double` e um `int`, além de retornar um `double`.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`ldexp`, `ldexpf`, `ldexpl`|\<math.h\>|\<cmath\>|  
  
 Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_ldexp.c  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x = 4.0, y;  
   int p = 3;  
  
   y = ldexp( x, p );  
   printf( "%2.1f times two to the power of %d is %2.1f\n", x, p, y );  
}  
```  
  
## Saída  
  
```  
4.0 times two to the power of 3 is 32.0  
```  
  
## Equivalência do .NET Framework  
 [System::Math::Pow](https://msdn.microsoft.com/en-us/library/system.math.pow.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [frexp](../../c-runtime-library/reference/frexp.md)   
 [modf, modff, modfl](../../c-runtime-library/reference/modf-modff-modfl.md)