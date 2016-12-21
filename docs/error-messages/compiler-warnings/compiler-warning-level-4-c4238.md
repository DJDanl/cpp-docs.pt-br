---
title: "Compilador C4238 de aviso (n&#237;vel 4) | Microsoft Docs"
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
  - "C4238"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4238"
ms.assetid: 5d4051d3-7b0f-43ea-8c8d-d194bfdceb71
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4238 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

extensão não padrão usada: rvalue classe usada como l\-value  
  
 Para compatibilidade com versões anteriores do Visual C\+\+, extensões da Microsoft \(**\/Ze**\) permitem que você use um tipo de classe como um rvalue em um contexto que implicitamente ou explicitamente usa seu endereço. Em alguns casos, como no exemplo abaixo, isso pode ser perigoso.  
  
## Exemplo  
  
```  
// C4238.cpp  
// compile with: /W4 /c  
struct C {  
   C() {}  
};  
  
C * pC = &C();   // C4238  
```  
  
 Esse uso causa um erro em compatibilidade com ANSI \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\).