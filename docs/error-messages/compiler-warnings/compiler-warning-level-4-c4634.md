---
title: "Compilador C4634 de aviso (n&#237;vel 4) | Microsoft Docs"
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
  - "C4634"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4634"
ms.assetid: 3e3496ce-2ac7-43d0-a48a-f514c950e81d
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4634 de aviso (n&#237;vel 4)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Comentário de documento XML: não pode ser aplicada: motivo  
  
 Marcas de documentação XML não podem ser aplicadas ao C\+\+ todas as construções.  Por exemplo, você não pode adicionar um comentário de documentação para um namespace ou um modelo.  
  
 Para obter mais informações, consulte [A Documentação XML](../../ide/xml-documentation-visual-cpp.md).  
  
## Exemplo  
 O exemplo a seguir gera C4634.  
  
```  
// C4634.cpp // compile with: /W4 /doc /c /// This is a namespace.   // C4634 namespace hello { class MyClass  {}; };  
```  
  
## Exemplo  
 O exemplo a seguir gera C4634.  
  
```  
// C4634_b.cpp // compile with: /W4 /doc /c /// This is a template.   // C4634 template <class T> class MyClass  {};  
```