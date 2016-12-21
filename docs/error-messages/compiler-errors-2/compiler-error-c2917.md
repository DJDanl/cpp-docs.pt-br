---
title: "C2917 de erro do compilador | Microsoft Docs"
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
  - "C2917"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2917"
ms.assetid: ec9da9ee-0f37-47b3-87dd-19ef5a14dc4c
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2917 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'name': parâmetro de modelo inválido  
  
 Uma lista de parâmetros de modelo contém um identificador que não era um parâmetro de modelo.  
  
## Exemplo  
 O exemplo a seguir gera C2917.  
  
```  
// C2917.cpp // compile with: /c template<class T> class Vector { void sort(); }; template<class T*> void Vector<T>::sort() {}   // C2917 // try the following line instead // template<class T> void Vector<T>::sort() {}  
```