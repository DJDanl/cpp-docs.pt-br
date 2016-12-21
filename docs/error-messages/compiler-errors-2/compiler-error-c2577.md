---
title: "Erro do Compilador C2577 | Microsoft Docs"
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
  - "C2577"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2577"
ms.assetid: fc79ef83-8362-40a2-9257-8037c3195ce4
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2577
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“membro”: o destruidor\/finalizador não pode ter um tipo de retorno  
  
 Um destruidor ou um finalizador não podem retornar um valor de `void` ou qualquer outro tipo.  Remova a instrução de `return` de definição de destruidor.  
  
## Exemplo  
 O exemplo a seguir produz C2577.  
  
```  
// C2577.cpp  
// compile with: /c  
class A {  
public:  
   A() {}  
   ~A(){  
      return 0;   // C2577  
   }  
};  
```