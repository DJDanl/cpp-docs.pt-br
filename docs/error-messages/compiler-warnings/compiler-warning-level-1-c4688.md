---
title: "Compilador C4688 de aviso (n&#237;vel 1) | Microsoft Docs"
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
  - "C4688"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4688"
ms.assetid: a027df3c-b2b8-4c49-8539-c2bc42db74e8
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4688 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'restrição de ': lista de restrição contém tipo privado de assembly 'type'  
  
 Uma lista de restrição tem um tipo particular assembly, que significa que ele não estará disponível quando o tipo é acessado de fora do assembly. Para obter mais informações, consulte [Generics](../../windows/generics-cpp-component-extensions.md).  
  
## Exemplo  
 O exemplo a seguir gera C4688.  
  
```  
// C4688.cpp // compile with: /clr /c /W1 ref struct A {};   // private type public ref struct B {}; // Delete the following 3 lines to resolve. generic <class T> where T : A   // C4688 public ref struct M {}; generic <class T> where T : B public ref struct N {};  
```