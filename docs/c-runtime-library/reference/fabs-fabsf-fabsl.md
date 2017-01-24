---
title: "fabs, fabsf, fabsl | Microsoft Docs"
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
  - "fabsf"
  - "fabs"
  - "fabsl"
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
  - "fabs"
  - "fabsf"
  - "fabsl"
  - "math\fabs"
  - "math\fabsf"
  - "math\fabsl"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "valores absolutos"
  - "Função fabsf"
  - "calculando valores absolutos"
  - "Função fabs"
  - "função fabsl"
ms.assetid: 23bca210-f408-4f5e-b46b-0ccaaec31e36
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fabs, fabsf, fabsl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Calcula o valor absoluto do argumento de ponto flutuante.  
  
## Sintaxe  
  
```  
double fabs(   
   double x   
);  
float fabs(  
   float x   
); // C++ only  
long double fabs(  
   long double x  
); // C++ only  
float fabsf(   
   float x   
);  
long double fabsl(  
   long double x  
);  
```  
  
#### Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
## Valor de retorno  
 O `fabs` funções retornam o valor absoluto do argumento `x`. Não há nenhum retorno de erro.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-------------|-----------------|---------------------|  
|± QNAN, IND|nenhum|DOMAIN|  
  
## Comentários  
 C\+\+ permite sobrecargas, para que você possa chamar sobrecargas de `fabs` se você incluir o cabeçalho \< cmath \>. Em um programa C, `fabs` sempre toma e retorna um double.  
  
## Requisitos  
  
|Função|Cabeçalho C necessário|Cabeçalho C\+\+ necessário|  
|------------|----------------------------|--------------------------------|  
|`fabs`, `fabsf`, `fabsl`|\< Math \>|\< cmath \> ou \< Math \>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Exemplo  
 Consulte o exemplo para [abs](../../c-runtime-library/reference/abs-labs-llabs-abs64.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [Abs, laboratórios, llabs, abs64](../../c-runtime-library/reference/abs-labs-llabs-abs64.md)   
 [\_cabs](../Topic/_cabs.md)   
 [labs, llabs](../../misc/labs-llabs.md)