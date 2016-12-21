---
title: "fmax, fmaxf, fmaxl | Microsoft Docs"
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
  - "fmax"
  - "fmaxf"
  - "fmaxl"
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
  - "fmax"
  - "fmaxf"
  - "fmaxl"
  - "math/fmax"
  - "math/fmaxf"
  - "math/fmaxl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função fmax"
  - "Função fmaxf"
  - "função fmaxl"
ms.assetid: a773ccf7-495e-4a9a-8c6d-dfb53e341e35
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fmax, fmaxf, fmaxl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determine o maior dos dois valores numéricos especificados.  
  
## Sintaxe  
  
```  
double fmax(  
   double x,   
   double y  
);  
  
float fmax(  
   float x,   
   float y  
); //C++ only  
  
long double fmax(  
   long double x,   
   long double y  
); //C++ only  
  
float fmaxf(  
   float x,   
   float y  
);  
  
long double fmaxl(  
   long double x,   
   long double y  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O primeiro valor a ser comparado.  
  
 \[in\] `y`  
 O segundo valor a ser comparado.  
  
## Valor de retorno  
 Se for bem\-sucedido, retorna o maior de `x` ou `y`. O valor retornado é exato e não depende de qualquer forma de arredondamento.  
  
 Caso contrário, pode retornar um dos seguintes valores:  
  
|Problema|Retornar|  
|--------------|--------------|  
|`x` \= NaN|`y`|  
|`y` \= NaN|`x`|  
|`x` e `y` \= NaN|NaN|  
  
 Essa função não usa os erros especificados em  [\_matherr](../../c-runtime-library/reference/matherr.md).  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de fmax que tomam e retornam tipos float e double longo. Em um programa C, fmax sempre toma e retorna um double.  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`fmax`, `fmaxf`, `fmaxl`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fmin, fminf, fminl](../Topic/fmin,%20fminf,%20fminl1.md)