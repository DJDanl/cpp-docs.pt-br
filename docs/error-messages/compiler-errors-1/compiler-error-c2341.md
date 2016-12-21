---
title: "Erro do Compilador C2341 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2341"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2341"
ms.assetid: aa2a7da5-e1c8-4225-9939-5bdc50158f31
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2341
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

nome de “seção”: o segmento deve ser definida usando o data\_seg, o code\_seg ou a seção de \#pragma antes de uso  
  
 Uma instrução de [aloque](../Topic/allocate.md) se refere a um segmento ainda não foi definido por [code\_seg](../../preprocessor/code-seg.md), por [data\_seg](../../preprocessor/data-seg.md), ou por pragmas de [seção](../../preprocessor/section.md) .  
  
 O seguinte exemplo gera C2341:  
  
```  
// C2341.cpp  
// compile with: /c  
__declspec(allocate(".test"))   // C2341  
int j = 1;  
```  
  
 Solução possível:  
  
```  
// C2341b.cpp  
// compile with: /c  
#pragma data_seg(".test")  
__declspec(allocate(".test"))  
int j = 1;  
```