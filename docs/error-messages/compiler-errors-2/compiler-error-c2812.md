---
title: "Erro do Compilador C2812 | Microsoft Docs"
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
  - "C2812"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2812"
ms.assetid: 22aadb8c-7232-489d-a3ad-60662dda30a8
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2812
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

o \#import não tem suporte com \/clr:pure e \/clr:safe  
  
 [Diretiva \#import](../Topic/%23import%20Directive%20\(C++\).md) não tem suporte com **\/clr:pure** e **\/clr:safe** porque `#import` requer o uso de bibliotecas de suporte do compilador nativo.  
  
## Exemplo  
 O exemplo a seguir produz C2812.  
  
```  
// C2812.cpp  
// compile with: /clr:pure /c  
#import "importlib.tlb"   // C2812  
```