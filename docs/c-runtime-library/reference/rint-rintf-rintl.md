---
title: "rint, rintf, rintl | Microsoft Docs"
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
  - "rintf"
  - "rintl"
  - "rint"
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
  - "rintf"
  - "rintl"
  - "rint"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "função rintf"
  - "função Imprimir"
  - "função rintl"
ms.assetid: 312ae3e6-278c-459a-9393-11b8f87d9184
caps.latest.revision: 8
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# rint, rintf, rintl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Arredonda um valor de ponto flutuante para o inteiro mais próximo no formato de ponto flutuante.  
  
## Sintaxe  
  
```  
double rint( double x ); float rint( float x );  // C++ only long double rint( long double x );  // C++ only float rintf( float x );  long double rintl( long double x );    
```  
  
#### Parâmetros  
 `x`  
 O valor do ponto flutuante a ser arredondado.  
  
## Valor de retorno  
 As funções `rint` retornam um valor de ponto flutuante que representa o inteiro mais próximo a `x`.  Valores decimais são arredondados de acordo com a configuração atual do modo de arredondamento do ponto flutuante, assim como as funções `nearbyint`.  Diferentemente das funções `nearbyint`, as funções `rint` podem resultar na exceção de ponto flutuante `FE_INEXACT` se o resultado tiver um valor diferente do argumento.  Nenhum erro é retornado.  
  
|Entrada|Exceção SEH|Exceção `_matherr`|  
|-------------|-----------------|------------------------|  
|± ∞, QNAN, IND|nenhum|nenhum|  
|Denormals|EXCEPTION\_FLT\_UNDERFLOW|nenhum|  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `rint` que tomam e retornam valores de `float` e `long double`.  Em um programa C, `rint` sempre toma e retorna um `double`.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`rint`, `rintf`, `rintl`|\<math.h\>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_rint.c  
// Build with: cl /W3 /Tc crt_rint.c  
// This example displays the rounded results of  
// the floating-point values 2.499999, -2.499999,   
// 2.8, -2.8, 2.5 and -2.5.  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x = 2.499999;  
   float y = 2.8f;  
   long double z = 2.5;  
  
   printf("rint(%f) is %.0f\n", x, rint (x));  
   printf("rint(%f) is %.0f\n", -x, rint (-x));  
   printf("rintf(%f) is %.0f\n", y, rintf(y));  
   printf("rintf(%f) is %.0f\n", -y, rintf(-y));  
   printf("rintl(%Lf) is %.0Lf\n", z, rintl(z));  
   printf("rintl(%Lf) is %.0Lf\n", -z, rintl(-z));  
}  
```  
  
  **rint\(2,499999\) é 2**  
**rint\(\-2,499999\) é \-2**  
**rintf\(2,800000\) é 3**  
**rintf\(\-2,800000\) é \-3**  
**rintl\(2,500000\) é 3**  
**rintl\(\-2,500000\) é \-3**   
## Equivalência do .NET Framework  
 [System::Math::Round](https://msdn.microsoft.com/en-us/library/system.math.round.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ceil, ceilf, ceill](../../c-runtime-library/reference/ceil-ceilf-ceill.md)   
 [floor, floorf, floorl](../../c-runtime-library/reference/floor-floorf-floorl.md)   
 [fmod, fmodf](../Topic/fmod,%20fmodf.md)   
 [lrint, lrintf, lrintl, llrint, llrintf, llrintl](http://msdn.microsoft.com/pt-br/312fd869-a9c0-4107-bb23-ab8299d04385)   
 [lround, lroundf, lroundl, llround, llroundf, llroundl](../../c-runtime-library/reference/lround-lroundf-lroundl-llround-llroundf-llroundl.md)   
 [nearbyint, nearbyintf, nearbyintl](http://msdn.microsoft.com/pt-br/15111e73-331d-41d1-81b7-3e10df894848)   
 [rint](../../c-runtime-library/reference/rint-rintf-rintl.md)