---
title: "tgamma, tgammaf, tgammal | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "tgamma"
  - "tgammaf"
  - "tgammal"
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
  - "tgamma"
  - "tgammaf"
  - "tgammal"
  - "math/tgamma"
  - "math/tgammaf"
  - "math/tgammal"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função tgamma"
  - "Função tgammaf"
  - "função tgammal"
ms.assetid: f1bd2681-8af2-48a9-919d-5358fd068acd
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# tgamma, tgammaf, tgammal
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina a função gama do valor especificado.  
  
## Sintaxe  
  
```  
double tgamma(  
   double x  
);  
  
float tgamma(  
   float x  
); //C++ only  
  
long double tgamma(  
   long double x  
); //C++ only  
  
float tgammaf(  
   float x  
);  
  
long double tgammal(  
   long double x  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O valor para localizar o gama de.  
  
## Valor de retorno  
 Se for bem\-sucedido, retornará a gama de `x`.  
  
 Pode ocorrer um erro de intervalo se a magnitude do `x` é muito grande ou muito pequeno para o tipo de dados. Erro de intervalo ou um erro de domínio pode ocorrer se `x` \< \= 0.  
  
|Problema|Retornar|  
|--------------|--------------|  
|x \= ±0|±INFINITY|  
|x \= número inteiro negativo|NaN|  
|x \= \- INFINITY|NaN|  
|x \= \+ INFINITY|\+ INFINITY|  
|x \= NaN|NaN|  
|Erro de domínio|NaN|  
|Erro de pólo|±HUGE\_VAL, ±HUGE\_VALF ou ±HUGE\_VALL|  
|Erro de estouro do intervalo|±HUGE\_VAL, ±HUGE\_VALF ou ±HUGE\_VALL|  
|Erro de intervalo de estouro negativo|o valor correto, após o arredondamento.|  
  
 Os erros são relatados como especificado em [\_matherr](../../c-runtime-library/reference/matherr.md).  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de tgamma que tomam e retornam tipos float e double longo. Em um programa C, tgamma sempre toma e retorna um double.  
  
 Se x for um número natural, essa função retorna o fatorial de \(x\-1\).  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`tgamma`, `tgammaf`,  `tgammal`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [lgamma, lgammaf, lgammal](../../c-runtime-library/reference/lgamma-lgammaf-lgammal.md)