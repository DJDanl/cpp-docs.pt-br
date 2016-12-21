---
title: "fdim, fdimf, fdiml | Microsoft Docs"
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
  - "fdim"
  - "fdimf"
  - "fdiml"
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
  - "fdim"
  - "fdimf"
  - "fdiml"
  - "math/fdim"
  - "math/fdimf"
  - "math/fdiml"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função fdim"
  - "Função fdimf"
  - "função fdiml"
ms.assetid: 2d4ac639-51e9-462d-84ab-fb03b06971a0
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fdim, fdimf, fdiml
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina a diferença entre os valores do primeiro e segundo positiva.  
  
## Sintaxe  
  
```  
double fdim(  
   double x,   
   double y  
);  
  
float fdim(  
   float x,   
   float y  
); //C++ only  
  
long double fdim(  
   long double x,   
   long double y  
); //C++ only  
  
float fdimf(  
   float x,   
   float y  
);  
  
long double fdiml(  
   long double x,   
   long double y  
);  
  
```  
  
#### Parâmetros  
 \[in\] `x`  
 O primeiro valor.  
  
 \[in\] `y`  
 O segundo valor.  
  
## Valor de retorno  
 Retorna a diferença positiva entre `x` e `y`:  
  
|Valor de retorno|Cenário|  
|----------------------|-------------|  
|x\-y|Se x \> y|  
|0|Se x \< \= s|  
  
 Caso contrário, pode retornar um dos seguintes erros:  
  
|Problema|Retornar|  
|--------------|--------------|  
|Erro de estouro do intervalo|\+ HUGE\_VAL \+ HUGE\_VALF, ou \+ HUGE\_VALL|  
|Erro de intervalo de estouro negativo|valor correto \(após o arredondamento\)|  
|`x` ou `y` é NaN|NaN|  
  
 Os erros são relatados como especificado em [\_matherr](../../c-runtime-library/reference/matherr.md).  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `fdim` que tomam e retornam tipos float e double longo. Em um programa C, `fdim` sempre toma e retorna um double.  
  
 Exceto para o tratamento de NaN, essa função é equivalente a [fmax, fmaxf, fmaxl](../../c-runtime-library/reference/fmax-fmaxf-fmaxl.md)\(`x`\-`y,` 0\).  
  
## Requisitos  
  
|Função|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`fdim`, `fdimf`,  `fdiml`|\< Math \>|\<cmath\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [fmax, fmaxf, fmaxl](../../c-runtime-library/reference/fmax-fmaxf-fmaxl.md)   
 [Abs, laboratórios, llabs, abs64](../../c-runtime-library/reference/abs-labs-llabs-abs64.md)