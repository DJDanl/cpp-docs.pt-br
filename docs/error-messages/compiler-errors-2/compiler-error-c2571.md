---
title: "Erro do Compilador C2571 | Microsoft Docs"
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
  - "C2571"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2571"
ms.assetid: c6522616-dee9-4d7d-9bf8-30a7e1deaadf
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2571
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: a função virtual não pode estar na união “união”  
  
 Uma união é declarada com uma função virtual.  Você pode declarar uma função virtual somente em uma classe ou estrutura.  Resoluções possíveis:  
  
1.  Alterar a união a uma classe ou estrutura.  
  
2.  Crie a função nonvirtual.  
  
 O seguinte exemplo gera C2571:  
  
```  
// C2571.cpp  
// compile with: /c  
union A {  
   virtual void func1();   // C2571  
   void func2();   // OK  
};  
```