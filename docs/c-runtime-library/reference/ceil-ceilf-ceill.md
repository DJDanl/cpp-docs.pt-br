---
title: "ceil, ceilf, ceill | Microsoft Docs"
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
  - "ceilf"
  - "ceil"
  - "ceill"
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
  - "ceil"
  - "ceilf"
  - "ceill"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "calculando tetos de valores"
  - "Função ceil"
  - "Função ceilf"
  - "Função ceill"
ms.assetid: f4e5acab-5c8f-4b10-9ae2-9561e6453718
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ceil, ceilf, ceill
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O calcula um valor de teto.  
  
## Sintaxe  
  
```  
double ceil(   
   double x   
);  
float ceil(  
   float x  
);  // C++ only  
long double ceil(  
   long double x  
);  // C++ only  
float ceilf(  
   float x  
);  
long double ceill(  
   long double x  
);  
```  
  
#### Parâmetros  
 `x`  
 Valor de ponto flutuante.  
  
## Valor de retorno  
 As funções de `ceil` retornam um valor de ponto flutuante que representa o menor inteiro maior que ou igual a `x`.  Não há nenhum retorno de erro.  
  
|Entrada|Exceção SEH|Exceção Matherr|  
|-------------|-----------------|---------------------|  
|± `QNAN`,`IND`|nenhum|`_DOMAIN`|  
  
 `ceil` tiver uma implementação que usa Streaming SIMD 2 \(SSE2 Extensions\).  Para obter informações e as restrições sobre como usar a implementação SSE2, consulte [\_set\_SSE2\_enable](../Topic/_set_SSE2_enable.md).  
  
## Comentários  
 Como C\+\+ reserva evitada, você pode chamar sobrecargas de `ceil`.  Em um programa em C, `ceil` sempre obterá e retornará um double.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`ceil`, `ceilf`, `ceill`|\<math.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
 Consulte o exemplo de [floor](../../c-runtime-library/reference/floor-floorf-floorl.md).  
  
## Equivalência do .NET Framework  
 [System::Math::Ceiling](https://msdn.microsoft.com/en-us/library/system.math.ceiling.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [floor, floorf, floorl](../../c-runtime-library/reference/floor-floorf-floorl.md)   
 [fmod, fmodf](../Topic/fmod,%20fmodf.md)   
 [round, roundf, roundl](../../c-runtime-library/reference/round-roundf-roundl.md)