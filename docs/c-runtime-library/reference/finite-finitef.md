---
title: "Finitas, _finitef | Microsoft Docs"
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
  - "_finite"
  - "_finitef"
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
  - "finite"
  - "_finite"
  - "_finitef"
  - "math/_finite"
  - "math/_finitef"
  - "float/_finite"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função finite"
  - "Função _finite"
  - "função _finitef"
ms.assetid: 5a7d7ca7-befb-4e1f-831d-28713c6eb805
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Finitas, _finitef
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um valor de ponto flutuante é finito.  
  
## Sintaxe  
  
```  
int _finite(   
   double x   
);  
  
int _finitef(   
   float x   
); /* x64 and ARM/ARM64 only */  
```  
  
#### Parâmetros  
 `x`  
 O valor de ponto flutuante para teste.  
  
## Valor de retorno  
 Ambos `_finite` e `_finitef` retornar um valor diferente de zero se o argumento *x* é finita; que é, se – INF \< `x` \< \+ INF. Ele retorna 0 se o argumento for infinito ou um NAN.  
  
## Comentários  
 O `_finite` e `_finitef` funções são específicas da Microsoft. O `_finitef` função só está disponível quando compilado para x86, ARM ou ARM64 plataformas.  
  
## Requisitos  
  
|Função|Cabeçalho necessário \(C\)|Cabeçalho necessário \(C\+\+\)|  
|------------|--------------------------------|------------------------------------|  
|`_finite`|\< float. h \> ou \< Math \>|\< float. h \>, \< Math \>, \< cfloat \> ou \< cmath \>|  
|`_finitef`|\< Math \>|\< Math \> ou \< cmath \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 [System::Double::IsInfinity](https://msdn.microsoft.com/en-us/library/system.double.isinfinity.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [isNaN isNaN, \_isnanf](../../c-runtime-library/reference/isnan-isnan-isnanf.md)   
 [fpclass, \_fpclassf](../../c-runtime-library/reference/fpclass-fpclassf.md)