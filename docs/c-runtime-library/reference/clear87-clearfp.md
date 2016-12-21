---
title: "_clear87, _clearfp | Microsoft Docs"
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
  - "_clearfp"
  - "_clear87"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "clearfp"
  - "_clearfp"
  - "_clear87"
  - "clear87"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _clear87"
  - "Função _clearfp"
  - "Função clear87"
  - "Função clearfp"
  - "limpando a palavra de status de ponto flutuante"
ms.assetid: 72d24a70-7688-4793-ae09-c96d33fcca52
caps.latest.revision: 17
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _clear87, _clearfp
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém e limpa a palavra de status de ponto flutuante.  
  
## Sintaxe  
  
```  
unsigned int _clear87( void );  
unsigned int _clearfp( void );  
```  
  
## Valor de retorno  
 Os bits no valor retornado indicam o status de ponto flutuante antes da chamada para `_clear87` ou `_clearfp`.  Para obter uma definição completa dos bits retornados por `_clear87`, consulte float.  Muitas das funções de biblioteca de matemática modificar a palavra de status 8087\/80287, com resultados imprevisíveis.  Retornar valores de `_clear87` e `_status87` se tornar mais confiáveis como menos operações de ponto flutuante são executadas entre estados conhecidos da palavra de status de ponto flutuante.  
  
## Comentários  
 O `_clear87` função limpa os sinalizadores de exceção da palavra de status de ponto flutuante, define o bit ocupado como 0 e retorna a palavra de status.  A palavra de status de ponto flutuante é uma combinação de palavra 8087\/80287 status e outras condições detectadas pelo manipulador de exceção 8087\/80287, como estouro de pilha de ponto flutuante e estouro negativo.  
  
 `_clearfp` é uma versão portátil, independente de plataforma do `_clear87` rotina.  Ele é idêntico ao `_clear87` em plataformas Intel \(x86\) e também possui suporte a plataformas x64 e ARM.  Para garantir que seu código de ponto flutuante é portátil para x64 e ARM, use `_clearfp`.  Se você estiver direcionando apenas x86 plataformas, você pode usar um `_clear87` ou `_clearfp`.  
  
 Essas funções são substituídas durante a compilação com [\/clr \(compilação do Common Language Runtime\)](../../build/reference/clr-common-language-runtime-compilation.md) ou `/clr:pure` como o common language runtime suporta apenas a precisão de ponto flutuante padrão.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_clear87`|\< float \>|  
|`_clearfp`|\< float \>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_clear87.c  
// compile with: /Od  
  
// This program creates various floating-point   
// problems, then uses _clear87 to report on these problems.  
// Compile this program with Optimizations disabled (/Od).   
// Otherwise the optimizer will remove the code associated with   
// the unused floating-point values.  
//  
  
#include <stdio.h>  
#include <float.h>  
  
int main( void )  
{  
   double a = 1e-40, b;  
   float x, y;  
  
   printf( "Status: %.4x - clear\n", _clear87()  );  
  
   // Store into y is inexact and underflows:  
   y = a;  
   printf( "Status: %.4x - inexact, underflow\n", _clear87() );  
  
   // y is denormal:   
   b = y;  
   printf( "Status: %.4x - denormal\n", _clear87() );  
}  
```  
  
  **Status: 0000 \- claro**  
**Status: estouro negativo inexatos, 0003\-**  
**Status: desnormalizado de 80000\-**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md)   
 [\_status87, \_statusfp, \_statusfp2](../../c-runtime-library/reference/status87-statusfp-statusfp2.md)