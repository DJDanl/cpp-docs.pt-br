---
title: "fpclass, _fpclassf | Microsoft Docs"
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
  - "_fpclass"
  - "_fpclassf"
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
  - "fpclass"
  - "_fpclass"
  - "_fpclassf"
  - "math/_fpclass"
  - "float/_fpclass"
  - "math/_fpclassf"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função fpclass"
  - "números de ponto flutuante, representação IEEE"
  - "Função _fpclass"
  - "função _fpclassf"
ms.assetid: 2774872d-3543-446f-bc72-db85f8b95a6b
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fpclass, _fpclassf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Retorna um valor que indica a classificação de ponto flutuante do argumento.  
  
## Sintaxe  
  
```  
int _fpclass(   
   double x   
);  
  
int _fpclassf(   
   float x   
); /* x64 only */  
```  
  
#### Parâmetros  
 `x`  
 O valor de ponto flutuante para teste.  
  
## Valor de retorno  
 O `_fpclass` e `_fpclassf` funções retornam um valor inteiro que indica a classificação de ponto flutuante do argumento `x`. A classificação pode ter um dos valores a seguir, definidos em \< float. h \>.  
  
|Valor|Descrição|  
|-----------|---------------|  
|`_FPCLASS_SNAN`|Sinalização NaN|  
|`_FPCLASS_QNAN`|NaN silencioso|  
|`_FPCLASS_NINF`|Infinito negativo \(\-INF\)|  
|`_FPCLASS_NN`|Negativo normalizados diferente de zero|  
|`_FPCLASS_ND`|Negativo desnormalizado|  
|`_FPCLASS_NZ`|Zero negativo \(\-0\)|  
|`_FPCLASS_PZ`|0 positivo \(\+ 0\)|  
|`_FPCLASS_PD`|Positivo desnormalizado|  
|`_FPCLASS_PN`|Positivo normalizados diferente de zero|  
|`_FPCLASS_PINF`|Infinito positivo \(\+ INF\)|  
  
## Comentários  
 O `_fpclass` e `_fpclassf` funções são específicas da Microsoft. Eles são semelhantes aos [fpclassify](../Topic/fpclassify.md), mas retornar informações mais detalhadas sobre o argumento. O `_fpclassf` função só está disponível quando compilado para o x64 plataforma.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fpclass`|\< float. h \>|  
  
 Para obter informações de compatibilidade e conformidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [isNaN isNaN, \_isnanf](../../c-runtime-library/reference/isnan-isnan-isnanf.md)   
 [fpclassify](../Topic/fpclassify.md)