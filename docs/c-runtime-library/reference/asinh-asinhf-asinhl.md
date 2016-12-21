---
title: "asinh, asinhf, asinhl | Microsoft Docs"
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
  - "asinh"
  - "asinhf"
  - "asinhl"
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
  - "asinhf"
  - "asinhl"
  - "asinh"
dev_langs: 
  - "C++"
ms.assetid: 4488babe-1a7e-44ca-8b7b-c2db0a70084f
caps.latest.revision: 7
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# asinh, asinhf, asinhl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o seno hiperbólico inverso.  
  
## Sintaxe  
  
```  
double asinh(    double x  ); float asinh(    float x  );  // C++ only long double asinh(    long double x );  // C++ only float asinhf(    float x  ); long double asinhl(    long double x );  
```  
  
#### Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
## Valor de retorno  
 As funções `asinh` retornam o seno hiperbólico inverno \(seno hiperbólico do arco\) de `x`.  Essa função é válida no domínio de ponto flutuante.  Se `x` for um NaN silencioso, indefinido ou de infinidade, será retornado o mesmo valor.  
  
|Entrada|Exceção SEH|Exceção `_matherr`|  
|-------------|-----------------|------------------------|  
|± QNAN, IND, INF|nenhum|nenhum|  
  
## Comentários  
 Ao usar C\+\+, é possível chamar sobrecargas de `asinh` que usam e retornam os valores `float` ou `long double`.  Em programas C, `asinh` sempre usa e retorna `double`.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`asinh`, `asinhf`, `asinhl`|\<math.h\>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```c  
// crt_asinh.c  
// Compile by using: cl /W4 crt_asinh.c  
// This program displays the hyperbolic sine of pi / 4  
// and the arc hyperbolic sine of the result.  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double pi = 3.1415926535;  
   double x, y;  
  
   x = sinh( pi / 4 );  
   y = asinh( x );  
   printf( "sinh( %f ) = %f\n", pi/4, x );  
   printf( "asinh( %f ) = %f\n", x, y );  
}  
```  
  
  **sinh\( 0.785398 \) \= 0.868671**  
**asinh\( 0.868671 \) \= 0.785398**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Duplo longo](../../misc/long-double.md)   
 [cos, cosf, cosl, cosh, coshf, coshl](../../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)   
 [acosh, acoshf, acoshl](../../c-runtime-library/reference/acosh-acoshf-acoshl.md)   
 [sin, sinf, sinl, sinh, sinhf, sinhl](../../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)   
 [tan, tanf, tanl, tanh, tanhf, tanhl](../../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)   
 [atanh, atanhf, atanhl](../Topic/atanh,%20atanhf,%20atanhl.md)   
 [\_CItan](../../c-runtime-library/citan.md)