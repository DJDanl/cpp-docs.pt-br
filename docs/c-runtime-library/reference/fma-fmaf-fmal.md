---
title: "FMA, fmaf, fmal | Microsoft Docs"
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
  - "fma"
  - "fmaf"
  - "fmal"
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
  - "fma"
  - "fmaf"
  - "fmal"
  - "math/fma"
  - "math/fmaf"
  - "math/fmal"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função fma"
  - "Função fmaf"
  - "função fmal"
ms.assetid: 584a6037-da1e-4e86-9f0c-97aae86de0c0
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# FMA, fmaf, fmal
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Multiplica dois valores juntos, adiciona um terceiro valor e, em seguida, Arredonda o resultado, sem perder qualquer precisão devido a um arredondamento intermediário.  
  
## Sintaxe  
  
```  
double fma(  
   double x,   
   double y,   
   double z  
);  
  
float fma(  
   float  x,   
   float  y,   
   float z  
); //C++ only  
  
long double fma(  
   long double  x,   
   long double  y,   
   long double z  
); //C++ only  
  
float fmaf(  
   float  x,   
   float  y,   
   float z  
);  
  
long double fmal(  
   long double  x,   
   long double  y,   
   long double z  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O primeiro valor para multiplicar.  
  
 \[in\] `y`  
 O segundo valor para multiplicar.  
  
 \[in\] `z`  
 O valor a ser adicionado.  
  
## Valor de retorno  
 Returns \(`x` ×    `y`\) \+ `z`. O valor de retorno é arredondado, em seguida, usando o formato de arredondamento atual.  
  
 Caso contrário, pode retornar um dos seguintes valores:  
  
|Problema|Retornar|  
|--------------|--------------|  
|`x` \= INFINITO, `y` \= 0 ou<br /><br /> `x` \= 0, `y` \= INFINITO|NaN|  
|`x` ou `y` \= exato ± infinito, `z` \= infinito com o sinal oposto|NaN|  
|`x` ou `y` \= NaN|NaN|  
|não \(`x` \= 0, `y`\= indefinido\) e `z` \= NaN<br /><br /> não \(`x`\= indefinido, `y`\= 0\) e `z` \= NaN|NaN|  
|Erro de estouro do intervalo|±HUGE\_VAL, ±HUGE\_VALF ou ±HUGE\_VALL|  
|Erro de intervalo de estouro negativo|valor correto após o arredondamento.|  
  
 Os erros são relatados como especificado em [\_matherr](../../c-runtime-library/reference/matherr.md).  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `fma` que tomam e retornam tipos float e double longo. Em um programa C, `fma` sempre toma e retorna um double.  
  
 Esta função calcula o valor como se ele foram seguidas para precisão infinito e, em seguida, Arredonda o resultado final.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`fma`, `fmaf`,  `fmal`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [remainder, remainderf, remainderl](../../c-runtime-library/reference/remainder-remainderf-remainderl.md)   
 [remquo, remquof, remquol](../Topic/remquo,%20remquof,%20remquol.md)