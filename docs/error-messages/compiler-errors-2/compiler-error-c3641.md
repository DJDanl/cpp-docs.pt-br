---
title: "Erro do Compilador C3641 | Microsoft Docs"
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
  - "C3641"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3641"
ms.assetid: e8d3613e-5e8d-46fe-a516-eb7d1de7cd21
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3641
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: convenção inválido “calling\_convention” da chamada para a função compilada com \/clr:pure ou \/clr:safe  
  
 Somente [\_\_clrcall](../../cpp/clrcall.md) que chama a convenção é permitida com [\/clr: puro](../../build/reference/clr-common-language-runtime-compilation.md).  
  
 O seguinte exemplo gera C3641:  
  
```  
// C3641.cpp  
// compile with: /clr:pure /c  
void __cdecl f() {}   // C3641  
```