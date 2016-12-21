---
title: "exp2, exp2f, exp2l | Microsoft Docs"
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
  - "exp2"
  - "exp2f"
  - "exp2l"
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
  - "exp2"
  - "math/exp2"
  - "exp2f"
  - "math/exp2f"
  - "exp2l"
  - "math/exp2l"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função exp2"
  - "Função exp2f"
  - "função exp2l"
ms.assetid: 526e3e10-201a-4610-a886-533f44ece344
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# exp2, exp2f, exp2l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Computa 2 elevado ao valor especificado \(ou seja, 2ˣ\).  
  
## Sintaxe  
  
```  
double exp2(  
   double x  
);  
  
float exp2(  
   float x  
);  // C++ only  
  
long double exp2(  
   long double x  
); // C++ only  
  
float exp2f(  
   float x  
);  
  
long double exp2l(  
   long double x  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O valor do expoente.  
  
## Valor de retorno  
 Se for bem\-sucedido, retorna o expoente de base 2 de `x` \(2ˣ\). Caso contrário, pode retornar um dos seguintes valores:  
  
|Problema|Retornar|  
|--------------|--------------|  
|`x` \= ±0|1|  
|`x` \= \- INFINITY|\+0|  
|`x` \= \+ INFINITY|\+ INFINITY|  
|`x` \= NaN|NaN|  
|Erro de estouro do intervalo|\+ HUGE\_VAL \+ HUGE\_VALF, ou \+ HUGE\_VALL|  
|Erro de intervalo de estouro negativo|resultado correto, após o arredondamento|  
  
 Os erros são relatados como especificado em [\_matherr](../../c-runtime-library/reference/matherr.md).  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `exp2` que tomam e retornam tipos float e double longo. Em um programa C, `exp2` sempre toma e retorna um double.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`exp`, `expf`, `expl`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [exp, expf](../../c-runtime-library/reference/exp-expf.md)   
 [log2, log2f, log2l](../../c-runtime-library/reference/log2-log2f-log2l.md)