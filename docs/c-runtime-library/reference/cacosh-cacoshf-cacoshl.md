---
title: "cacosh, cacoshf, cacoshl | Microsoft Docs"
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
  - "cacosh"
  - "cacoshf"
  - "cacoshl"
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
  - "cacosh"
  - "cacoshf"
  - "cacoshl"
  - "complex/cacosh"
  - "complex/cacoshf"
  - "complex/cacoshl"
dev_langs: 
  - "C"
  - "C++"
helpviewer_keywords: 
  - "função cacosh"
  - "função cacoshf"
  - "função cacoshl"
ms.assetid: 83fd05eb-3587-4741-9be6-589a830a1703
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# cacosh, cacoshf, cacoshl
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Recupera o cosseno hiperbólico inverso de um número complexo com uma ramificação cortada valores menores do que 1 ao longo do eixo real. .  
  
## Sintaxe  
  
```  
_Dcomplex cacosh(   
   _Dcomplex z   
);  
_Fcomplex cacosh(   
   _Fcomplex z   
);  // C++ only  
_Lcomplex cacosh(   
   _Lcomplex z   
);  // C++ only  
_Fcomplex cacoshf(   
   _Fcomplex z   
);  
_Lcomplex cacoshl(   
   _Lcomplex z   
);  
```  
  
#### Parâmetros  
 `z`  
 Um número complexo que representa um ângulo em radianos.  
  
## Valor de retorno  
 O cosseno hiperbólico inverso de `z`, em radianos. O resultado é ilimitada e negativo ao longo do eixo real e no intervalo \[−iπ \+ iπ\] ao longo do eixo imaginário.  
  
## Comentários  
 Como C\+\+ permite sobrecargas, é possível chamar sobrecargas de `cacosh` que tomam e retornam `_Fcomplex` e `_Lcomplex` valores. Em um programa C, `cacosh` sempre toma e retorna um `_Dcomplex` valor.  
  
## Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C\+\+|  
|------------|-----------------|---------------------|  
|`cacosh`, `cacoshf`, `cacoshl`|\< Complex. h \>|\< ccomplex \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Referência da função alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [catanh, catanhf, catanhl](../../c-runtime-library/reference/catanh-catanhf-catanhl.md)   
 [ctanh, ctanhf, ctanhl](../../c-runtime-library/reference/ctanh-ctanhf-ctanhl.md)   
 [catan, catanf, catanl](../../c-runtime-library/reference/catan-catanf-catanl.md)   
 [csinh, csinhf, csinhl](../Topic/csinh,%20csinhf,%20csinhl.md)   
 [casinh, casinhf, casinhl](../Topic/casinh,%20casinhf,%20casinhl.md)   
 [ccosh, ccoshf, ccoshl](../Topic/ccosh,%20ccoshf,%20ccoshl.md)   
 [cacos, cacosf, cacosl](../../c-runtime-library/reference/cacos-cacosf-cacosl.md)   
 [ctan, ctanf, ctanl](../../c-runtime-library/reference/ctan-ctanf-ctanl.md)   
 [csin, csinf, csinl](../../c-runtime-library/reference/csin-csinf-csinl.md)   
 [casin, casinf, casinl](../../c-runtime-library/reference/casin-casinf-casinl.md)   
 [ccos, ccosf, ccosl](../../c-runtime-library/reference/ccos-ccosf-ccosl.md)   
 [csqrt, csqrtf, csqrtl](../../c-runtime-library/reference/csqrt-csqrtf-csqrtl.md)