---
title: "atan, atanf, atanl, atan2, atan2f, atan2l | Microsoft Docs"
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
  - "atan2f"
  - "atan2l"
  - "atan2"
  - "atanf"
  - "atan"
  - "atanl"
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
  - "atan"
  - "atan2l"
  - "atan2"
  - "atanl"
  - "atanf"
  - "atan2f"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função arctangent"
  - "Função atan"
  - "Função atan2"
  - "Função atan2f"
  - "Função atan2l"
  - "Função atanf"
  - "Função atanl"
  - "Funções trigonométricas"
ms.assetid: 7a87a18e-c94d-4727-9cb1-1bb5c2725ae4
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# atan, atanf, atanl, atan2, atan2f, atan2l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o arco tangente de `x` \(`atan`, `atanf`, e `atanl`\) ou o arco tangente de `y`\/`x` \(`atan2`, `atan2f`, e `atan2l`\).  
  
## Sintaxe  
  
```  
double atan(   
   double x   
);  
float atan(  
   float x   
);  // C++ only  
long double atan(  
   long double x  
);  // C++ only  
double atan2(   
   double y,   
   double x   
);  
float atan2(  
   float y,  
   float x  
);  // C++ only  
long double atan2(  
   long double y,  
   long double x  
);  // C++ only  
float atanf(   
   float x   
);  
long double atanl(  
   long double x  
);  
float atan2f(  
   float y,  
   float x  
);  
long double atan2l(  
   long double y,  
   long double x  
);  
```  
  
#### Parâmetros  
 `x`, `y`  
 Alguns números.  
  
## Valor de retorno  
 `atan` retorna o arco tangente de `x` no intervalo – π\/2 em radianos π\/2.  `atan2` retorna o arco tangente de `y/x` no intervalo – π em radianos de π.  Se `x` for 0, retornará 0 de `atan` .  Se ambos os parâmetros de `atan2` for 0, a função retornará 0.  Todos os resultados estão em radianos.  
  
 `atan2` usa sinais de ambos os parâmetros determinar o quadrante do valor de retorno.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-------------|-----------------|---------------------|  
|± `QNAN`,`IND`|nenhum|`_DOMAIN`|  
  
## Comentários  
 A função de `atan` calcula o arco tangente \(inversa da função tangente\) de `x`.  `atan2` calcula o arco tangente de `y`\/`x` \(se `x` é igual a 0, `atan2` retorna π\/2 se `y` for positivo, \- π\/2 se `y` for negativo, ou 0 se `y` é 0.\)  
  
 `atan` tiver uma implementação que usa Streaming SIMD 2 \(SSE2 Extensions\).  Para obter informações e as restrições sobre como usar a implementação SSE2, consulte [\_set\_SSE2\_enable](../Topic/_set_SSE2_enable.md).  
  
 Como C\+\+ reserva evitada, você pode chamar sobrecargas de `atan` e de `atan2`.  No programa c, `atan` e `atan2` sempre levam e retornam duplas.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`atan`, `atan2`, `atanf`, `atan2f`, `atanl`, `atan2l`|\<math.h\>|  
  
## Exemplo  
  
```  
// crt_atan.c  
// arguments: 5 0.5  
#include <math.h>  
#include <stdio.h>  
#include <errno.h>  
  
int main( int ac, char* av[] )   
{  
   double x, y, theta;  
   if( ac != 3 ){  
      fprintf( stderr, "Usage: %s <x> <y>\n", av[0] );  
      return 1;  
   }  
   x = atof( av[1] );  
   theta = atan( x );  
   printf( "Arctangent of %f: %f\n", x, theta );  
   y = atof( av[2] );  
   theta = atan2( y, x );  
   printf( "Arctangent of %f / %f: %f\n", y, x, theta );   
   return 0;  
}  
```  
  
  **Arco tangente de 5,000000: 1,373401**  
**Arco tangente de 0,500000 e 5,000000: 0,099669**   
## Equivalência do .NET Framework  
  
-   [System::Math::Atan](https://msdn.microsoft.com/en-us/library/system.math.atan.aspx)  
  
-   [System::Math::Atan2](https://msdn.microsoft.com/en-us/library/system.math.atan2.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [acos, acosf, acosl](../../c-runtime-library/reference/acos-acosf-acosl.md)   
 [asin, asinf, asinl](../../c-runtime-library/reference/asin-asinf-asinl.md)   
 [cos, cosf, cosl, cosh, coshf, coshl](../../c-runtime-library/reference/cos-cosf-cosl-cosh-coshf-coshl.md)   
 [\_matherr](../../c-runtime-library/reference/matherr.md)   
 [sin, sinf, sinl, sinh, sinhf, sinhl](../../c-runtime-library/reference/sin-sinf-sinl-sinh-sinhf-sinhl.md)   
 [tan, tanf, tanl, tanh, tanhf, tanhl](../../c-runtime-library/reference/tan-tanf-tanl-tanh-tanhf-tanhl.md)   
 [\_CIatan](../Topic/_CIatan.md)   
 [\_CIatan2](../../c-runtime-library/ciatan2.md)