---
title: "csin, csinf, csinl | Microsoft Docs"
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
  - "csin"
  - "csinf"
  - "csinl"
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
  - "csin"
  - "csinf"
  - "csinl"
  - "complex/csin"
  - "complex/csinf"
  - "complex/csinl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função csin"
  - "função csinf"
  - "função csinl"
ms.assetid: 3ed475e8-9aae-42ba-a25c-7ae656a0fd4d
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# csin, csinf, csinl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera o seno de um número complexo.  
  
## Sintaxe  
  
```  
_Dcomplex csin(   
   _Dcomplex z   
);  
_Fcomplex csin(   
   _Fcomplex z   
);  // C++ only  
_Lcomplex csin(   
   _Lcomplex z   
);  // C++ only  
_Fcomplex csinf(   
   _Fcomplex z   
);  
_Lcomplex csinl(   
   _Lcomplex z   
);  
```  
  
#### Parâmetros  
 `z`  
 Um número complexo que representa um ângulo em radianos.  
  
## Valor de retorno  
 O seno de `z`, em radianos.  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `csin` que tomam e retornam `_Fcomplex` e `_Lcomplex` valores. Em um programa C, `csin` sempre toma e retorna um `_Dcomplex` valor.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`csin`, `csinf`, `csinl`|\< Complex. h \>|\< ccomplex \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [catanh, catanhf, catanhl](../../c-runtime-library/reference/catanh-catanhf-catanhl.md)   
 [ctanh, ctanhf, ctanhl](../../c-runtime-library/reference/ctanh-ctanhf-ctanhl.md)   
 [catan, catanf, catanl](../../c-runtime-library/reference/catan-catanf-catanl.md)   
 [csinh, csinhf, csinhl](../Topic/csinh,%20csinhf,%20csinhl.md)   
 [casinh, casinhf, casinhl](../Topic/casinh,%20casinhf,%20casinhl.md)   
 [ccosh, ccoshf, ccoshl](../Topic/ccosh,%20ccoshf,%20ccoshl.md)   
 [cacosh, cacoshf, cacoshl](../../c-runtime-library/reference/cacosh-cacoshf-cacoshl.md)   
 [cacos, cacosf, cacosl](../../c-runtime-library/reference/cacos-cacosf-cacosl.md)   
 [ctan, ctanf, ctanl](../../c-runtime-library/reference/ctan-ctanf-ctanl.md)   
 [casin, casinf, casinl](../../c-runtime-library/reference/casin-casinf-casinl.md)   
 [ccos, ccosf, ccosl](../../c-runtime-library/reference/ccos-ccosf-ccosl.md)   
 [csqrt, csqrtf, csqrtl](../../c-runtime-library/reference/csqrt-csqrtf-csqrtl.md)