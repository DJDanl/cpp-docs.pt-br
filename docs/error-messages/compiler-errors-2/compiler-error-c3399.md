---
title: "C3399 de erro do compilador | Microsoft Docs"
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
  - "C3399"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3399"
ms.assetid: 306ad199-d150-4f6c-bcf1-24a7948b93be
caps.latest.revision: 3
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3399 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': não é possível fornecer argumentos ao criar uma instância de um parâmetro genérico  
  
 Quando você especifica o `gcnew()` restrição, você especificar que o tipo de restrição terá um construtor sem parâmetros. Portanto, é um erro ao tentar criar uma instância desse tipo e passar um parâmetro.  
  
 Consulte [Constraints on Generic Type Parameters \(C\+\+\/CLI\)](../Topic/Constraints%20on%20Generic%20Type%20Parameters%20\(C++-CLI\).md) para obter mais informações.  
  
## Exemplo  
 O exemplo a seguir gera C3399.  
  
```  
// C3399.cpp // compile with: /clr /c generic <class T> where T : gcnew() void f() { T t = gcnew T(1);   // C3399 T t2 = gcnew T();   // OK }  
```