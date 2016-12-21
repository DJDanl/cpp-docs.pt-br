---
title: "clog, clogf, clogl | Microsoft Docs"
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
  - "clog"
  - "clogf"
  - "clogl"
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
  - "clog"
  - "clogf"
  - "clogl"
  - "complex/clog"
  - "complex/clogf"
  - "complex/clogl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "Função clog"
  - "função clogf"
  - "função clogl"
ms.assetid: 870b9b0b-6618-46f3-bfcf-da595cbd5e18
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# clog, clogf, clogl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera o logaritmo natural de um número complexo, com uma ramificação Recortar no eixo negativo real.  
  
## Sintaxe  
  
```  
_Dcomplex clog(   
   _Dcomplex z   
);  
_Fcomplex clog(   
   _Fcomplex z   
);  // C++ only  
_Lcomplex clog(   
   _Lcomplex z   
);  // C++ only  
_Fcomplex clogf(   
   _Fcomplex z   
);  
_Lcomplex clogl(   
   _Lcomplex z   
);  
```  
  
#### Parâmetros  
 `z`  
 A base do logaritmo.  
  
## Valor de retorno  
 O logaritmo natural de `z`. O resultado é ilimitado ao longo do eixo real e no intervalo \[−iπ \+ iπ\] ao longo do eixo imaginário.  
  
 Os valores de retornos possíveis são:  
  
|parâmetro z|Valor de retorno|  
|-----------------|----------------------|  
|Positivo|O logaritmo de base 10 de z|  
|Zero|\- ∞|  
|Negativo|NaN|  
|NaN|NaN|  
|\+ ∞|\+ ∞|  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `clog` que tomam e retornam `_Fcomplex` e `_Lcomplex` valores. Em um programa C, `clog` sempre toma e retorna um `_Dcomplex` valor.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`clog`, `clogf`, `clogl`|\< Complex. h \>|\< ccomplex \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [cexp, cexpf, cexpl](../../c-runtime-library/reference/cexp-cexpf-cexpl.md)   
 [cpow, cpowf, cpowl](../../c-runtime-library/reference/cpow-cpowf-cpowl.md)   
 [clog10, clog10f, clog10l](../Topic/clog10,%20clog10f,%20clog10l.md)