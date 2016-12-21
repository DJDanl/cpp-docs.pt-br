---
title: "Compilador C4722 de aviso (n&#237;vel 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4722"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4722"
ms.assetid: d8660710-f67b-4f59-a5fd-59259475529e
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4722 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'function': destruidor nunca retorna, potencial perda de memória  
  
 Encerra o fluxo de controle em um destruidor. O thread ou todo o programa será encerrado e recursos alocados não podem ser liberados.  Além disso, se um destruidor será chamado para desenrolamento de pilha durante o processamento de exceção, o comportamento do executável é indefinido.  
  
 Para resolver, remova a chamada de função que faz com que o destruidor não retornar.  
  
## Exemplo  
 O exemplo a seguir gera C4722:  
  
```  
// C4722.cpp // compile with: /O1 /W1 /c #include <stdlib.h> class C { public: C(); ~C() { exit(1); };   // C4722 }; extern void func (C*); void Test(){ C x; func(&x); // control will not leave Test because destructor will exit }  
```