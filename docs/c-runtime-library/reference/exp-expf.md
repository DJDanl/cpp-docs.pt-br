---
title: "exp, expf | Microsoft Docs"
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
  - "expf"
  - "exp"
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
  - "_expl"
  - "expf"
  - "exp"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "cálculos exponenciais"
  - "Função expf"
  - "calculando exponenciais"
  - "Função exp"
ms.assetid: 7070016d-1143-407e-9e9a-6b059bb88867
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# exp, expf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o exponencial.  
  
## Sintaxe  
  
```  
double exp(   
   double x  
);  
float exp(  
   float x  
);  // C++ only  
long double exp(  
   long double x  
);  // C++ only  
float expf(   
   float x  
);  
```  
  
#### Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
## Valor de retorno  
 A função de `exp` retorna o valor exponencial de parâmetro de ponto flutuante, `x`, se com êxito.  Isto é, o resultado é e à potência `x`, e onde é a base do logaritmo natural.  No estouro, a função retornará INF \(infinitos\) e no estouro negativo, retorna 0 de `exp` .  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-------------|-----------------|---------------------|  
|± QNAN,IND|Nenhum|\_DOMAIN|  
|± ∞|INVÁLIDO|\_DOMAIN|  
|x ≥ 7.097827e\+002|INEXACT\+OVERFLOW|ESTOURO|  
|X ≤ \-7.083964e\+002|INEXACT\+UNDERFLOW|ESTOURO NEGATIVO|  
  
 `exp` tiver uma implementação que usa Streaming SIMD 2 \(SSE2 Extensions\).  Consulte [\_set\_SSE2\_enable](../Topic/_set_SSE2_enable.md) para obter informações e as restrições para usar a implementação SSE2.  
  
## Comentários  
 C\+\+ reserva evitada, assim que você pode chamar sobrecargas de `exp`.  Em um programa em C, `exp` sempre obterá e retornará um double.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`exp`, `expf`|\<math.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_exp.c  
  
#include <math.h>  
#include <stdio.h>  
  
int main( void )  
{  
   double x = 2.302585093, y;  
  
   y = exp( x );  
   printf( "exp( %f ) = %f\n", x, y );  
}  
```  
  
  **EXP \(2,302585\) \= 10,000000**   
## Equivalência do .NET Framework  
 [System::Math::Exp](https://msdn.microsoft.com/en-us/library/system.math.exp.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [log, logf, log10, log10f](../Topic/log,%20logf,%20log10,%20log10f.md)   
 [\_CIexp](../Topic/_CIexp.md)