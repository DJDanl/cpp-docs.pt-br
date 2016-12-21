---
title: "cexp, cexpf, cexpl | Microsoft Docs"
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
  - "cexp"
  - "cexpf"
  - "cexpl"
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
  - "cexp"
  - "cexpf"
  - "cexpl"
  - "complex/cepx"
  - "complex/cexpf"
  - "complex/cexpl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função cexp"
  - "função cexpl"
  - "função cexpf"
ms.assetid: f27fd5a9-70c7-4957-a7ee-5256d19bd1da
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# cexp, cexpf, cexpl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Exponencial de um número complexo de base e de computação.  
  
## Sintaxe  
  
```  
_Dcomplex cexp(   
   _Dcomplex z   
);  
_Fcomplex cexp(   
   _Fcomplex z   
);  // C++ only  
_Lcomplex cexp(   
   _Lcomplex z   
);  // C++ only  
_Fcomplex cexpf(   
  _Fcomplex z   
);  
_Lcomplex cexpl(   
   _Lcomplex z   
);  
```  
  
#### Parâmetros  
 `z`  
 Um número complexo que representa o expoente.  
  
## Valor de retorno  
 O valor de `e` elevado à potência de `z`.  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `cexp` que tomam e retornam `_Fcomplex` e `_Lcomplex` valores. Em um programa C, `cexp` sempre toma e retorna um `_Dcomplex` valor.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`cexp`, `cexpf`, `cexpl`|\< Complex. h \>|\< Complex. h \>|  
  
 Para informações sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [cpow, cpowf, cpowl](../../c-runtime-library/reference/cpow-cpowf-cpowl.md)   
 [clog10, clog10f, clog10l](../Topic/clog10,%20clog10f,%20clog10l.md)   
 [clog, clogf, clogl](../../c-runtime-library/reference/clog-clogf-clogl.md)