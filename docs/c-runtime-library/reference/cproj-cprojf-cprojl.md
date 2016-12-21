---
title: "cproj, cprojf, cprojl | Microsoft Docs"
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
  - "cproj"
  - "cprojf"
  - "cprojl"
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
  - "cproj"
  - "cprojf"
  - "cprojl"
  - "complex/cproj"
  - "complex/cprojf"
  - "complex/cprojl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função cproj"
  - "função cprojf"
  - "função cprojl"
ms.assetid: 32b49623-13bf-4cae-802e-7912d75030fe
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# cproj, cprojf, cprojl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera a projeção de um número complexo na esfera de Reimann.  
  
## Sintaxe  
  
```  
_Dcomplex cproj(   
   _Dcomplex z   
);  
_Fcomplex cproj(   
   _Fcomplex z   
);  // C++ only  
_Lcomplex cproj(   
   _Lcomplex z   
);  // C++ only  
_Fcomplex cprojf(   
   _Fcomplex z   
);  
_Lcomplex cprojl(   
   _Lcomplex z   
);  
```  
  
#### Parâmetros  
 `z`  
 Um número complexo.  
  
## Valor de retorno  
 A projeção de `z` na esfera de Reimann.  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `cproj` que tomam e retornam `_Fcomplex` e `_Lcomplex` valores. Em um programa C, `cproj` sempre toma e retorna um `_Dcomplex` valor.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`cproj`, `cprojf`, `cprojl`|\< Complex. h \>|\< ccomplex \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [norma, normf, norml](../Topic/norm,%20normf,%20norml1.md)   
 [creal, crealf, creall](../../c-runtime-library/reference/creal-crealf-creall.md)   
 [Conj, conjf, conjl](../../c-runtime-library/reference/conj-conjf-conjl.md)   
 [cimag, cimagf, cimagl](../Topic/cimag,%20cimagf,%20cimagl.md)   
 [carg, cargf, cargl](../Topic/carg,%20cargf,%20cargl.md)   
 [arquivos CAB, cabsf, cabsl](../../c-runtime-library/reference/cabs-cabsf-cabsl.md)