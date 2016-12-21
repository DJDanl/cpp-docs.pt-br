---
title: "erf, erff, erfl, erfc, erfcf, erfcl | Microsoft Docs"
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
  - "erff"
  - "erfl"
  - "erf"
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
  - "erfl"
  - "erf"
  - "erff"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função erf"
  - "Função erff"
  - "Função erfl"
ms.assetid: 144d90d3-e437-41c2-a659-cd57596023b5
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# erf, erff, erfl, erfc, erfcf, erfcl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Computa a função de erro ou a função de erro complementar de um valor.  
  
## Sintaxe  
  
```  
double erf(    double x ); float erf(    float x ); // C++ only long double erf(    long double x ); // C++ only float erff(    float x ); long double erfl(    long double x ); double erfc(    double x ); float erfc(    float x ); // C++ only long double erfc(    long double x ); // C++ only float erfcf(    float x ); long double erfcl(    long double x );  
```  
  
#### Parâmetros  
 `x`  
 Um valor de ponto flutuante.  
  
## Valor de retorno  
 As funções `erf` retornam a função de erro em Gauss de `x`.  As funções `erfc` retornam a função de erro complementar em Gauss de `x`.  
  
## Comentários  
 As funções `erf` calculam a função de erro em Gauss de x, definida como:  
  
 ![The error function of x](../../c-runtime-library/reference/media/crt_erf_formula.PNG "CRT\_erf\_formula")  
  
 A função de erro complementar em Gauss é definida como 1 – erf\(x\).  As funções `erf` retornam um valor no intervalo de \-1,0 a 1,0.  Nenhum erro é retornado.  As funções `erfc` retornam um valor no intervalo de 0 a 2.  Se `x` for grande demais para `erfc`, a variável `errno` é definida como `ERANGE`.  
  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `erf` e `erfc` que tomam e retornam tipos `float` e `long double`.  Em um programa C, `erf` e `erfc` sempre tomam e retornam um `double`.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`erf`, `erff`, `erfl`, `erfc`, `erfcf`, `erfcl`|\<math.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)