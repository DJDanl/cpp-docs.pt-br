---
title: "log2, log2f, log2l | Microsoft Docs"
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
  - "log2"
  - "log2l"
  - "log2f"
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
dev_langs: 
  - "C"
  - "C++"
ms.assetid: 94d11b38-70b7-4d3a-94ac-523153c92b2e
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# log2, log2f, log2l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina o logaritmo binário \(base 2\) do valor especificado.  
  
## Sintaxe  
  
```  
double log2(  
   double x  
);  
  
float log2(  
   float x  
); //C++ only  
  
long double log2(  
   long double x  
); //C++ only  
  
float log2f(  
   float x  
);  
  
long double log2l(  
   long double x  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O valor para determinar o logaritmo de base 2 de.  
  
## Valor de retorno  
 Em caso de sucesso, retorna retorna log2 `x`.  
  
 Caso contrário, pode retornar um dos seguintes valores:  
  
|Problema|Retornar|  
|--------------|--------------|  
|`x` \< 0|NaN|  
|`x` \= ±0|\-INFINITY|  
|`x` \= 1|\+0|  
|\+ INFINITY|\+ INFINITY|  
|NaN|NaN|  
|Erro de domínio|NaN|  
|Erro de pólo|\-HUGE\_VAL, \- HUGE\_VALF, ou \- HUGE\_VALL|  
  
 Os erros são relatados como especificado em [\_matherr](../../c-runtime-library/reference/matherr.md).  
  
## Comentários  
 Se x for um número inteiro, esta função essencialmente retorna o índice baseado em zero do 1 bit mais significativo de `x`.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`log2`, `log2f`,  `log2l`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [exp2, exp2f, exp2l](../../c-runtime-library/reference/exp2-exp2f-exp2l.md)   
 [log, logf, log10, log10f](../Topic/log,%20logf,%20log10,%20log10f.md)