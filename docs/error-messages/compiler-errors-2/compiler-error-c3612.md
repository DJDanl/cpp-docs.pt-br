---
title: "Erro do Compilador C3612 | Microsoft Docs"
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
  - "C3612"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3612"
ms.assetid: aa6e3a2b-4afa-481c-98c1-1b6d1f82f869
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3612
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: uma classe abstrata não pode ser selada  
  
 Os tipos definidos com `value` \(ou [\_\_value](../../misc/value.md)\) são selados por padrão e uma classe são abstratos a menos que implementar todos os métodos de sua base.  Uma classe abstrata selada ou pode ser uma classe base ou ele pode ser criada uma instância.  
  
 Para obter mais informações, consulte [Classes and Structs](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
 O seguinte exemplo gera C3612:  
  
```  
// C3612.cpp  
// compile with: /clr /c  
value struct V: public System::ICloneable {};   // C3612  
  
// OK  
value struct V2: public System::ICloneable {  
   Object^ Clone();  
};  
```