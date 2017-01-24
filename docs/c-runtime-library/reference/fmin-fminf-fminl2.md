---
title: "fmin, fminf, fminl | Microsoft Docs"
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
  - "fmin"
  - "fminf"
  - "fminl"
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
  - "fmin"
  - "fminf"
  - "fminl"
  - "math/fmin"
  - "math/fminf"
  - "math/fminl"
helpviewer_keywords: 
  - "Função fmin"
  - "Função fminf"
  - "função fminl"
ms.assetid: 1916dfb5-99c1-4b0d-aefb-513525c3f2ac
caps.latest.revision: 5
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fmin, fminf, fminl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina o menor dos dois valores especificados.  
  
## Sintaxe  
  
```  
double fmin(  
   double x,   
   double y  
);  
  
float fmin(  
   float x,   
   float y  
); //C++ only  
  
long double fmin(  
   long double x,   
   long double y  
); //C++ only  
  
float fminf(  
   float x,   
   float y  
);  
  
long double fminl(  
   long double x,   
   long double y  
);  
  
```  
  
#### Parâmetros  
 `x`  
 O primeiro valor a ser comparado.  
  
 `y`  
 O segundo valor a ser comparado.  
  
## Valor de retorno  
 Se for bem\-sucedido, retorna o menor dos `x` ou `y`.  
  
|Entrada|Resultado|  
|-------------|---------------|  
|`x` é NaN|`y`|  
|`y` é NaN|`x`|  
|`x` e `y` são NaN|NaN|  
  
 Não faz com que a função [\_matherr](../../c-runtime-library/reference/matherr.md) para ser chamado, fazer com que as exceções de ponto flutuantes ou alterar o valor de `errno`.  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `fmin` que tomam e retornam tipos float e double longo. Em um programa C, `fmin` sempre toma e retorna um double.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`fmin`, `fminf`,  `fminl`|C: \< Math \><br /><br /> C\+\+: \< Math \> ou \< cmath \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)