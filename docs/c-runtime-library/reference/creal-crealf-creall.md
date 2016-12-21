---
title: "creal, crealf, creall | Microsoft Docs"
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
  - "creal"
  - "crealf"
  - "creall"
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
  - "creal"
  - "crealf"
  - "creall"
  - "complex/creal"
  - "complex/crealf"
  - "complex/creall"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função creal"
  - "função crealf"
  - "função creall"
ms.assetid: fa3ac62f-7aa3-4238-a71f-d6b00cd0c7c8
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# creal, crealf, creall
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera a parte real de um número complexo.  
  
## Sintaxe  
  
```  
double creal(   
   _Dcomplex z   
);  
float creal(   
   _Fcomplex z   
);  // C++ only  
long double creal(   
   _Lcomplex z   
);  // C++ only  
float crealf(   
   _Fcomplex z   
);  
long double creall(   
  _Lcomplex z   
);  
```  
  
#### Parâmetros  
 `z`  
 Um número complexo.  
  
## Valor de retorno  
 A parte real do `z`.  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `creal` que utilizam `_Fcomplex` ou `_Lcomplex` valores e retornar `float` ou `long double` valores. Em um programa C, `creal` sempre leva um `_Dcomplex` valor e retorna um `double` valor.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`creal`, `crealf`, `creall`|\< Complex. h \>|\< ccomplex \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [norma, normf, norml](../Topic/norm,%20normf,%20norml1.md)   
 [cproj, cprojf, cprojl](../../c-runtime-library/reference/cproj-cprojf-cprojl.md)   
 [Conj, conjf, conjl](../../c-runtime-library/reference/conj-conjf-conjl.md)   
 [cimag, cimagf, cimagl](../Topic/cimag,%20cimagf,%20cimagl.md)   
 [carg, cargf, cargl](../Topic/carg,%20cargf,%20cargl.md)   
 [arquivos CAB, cabsf, cabsl](../../c-runtime-library/reference/cabs-cabsf-cabsl.md)