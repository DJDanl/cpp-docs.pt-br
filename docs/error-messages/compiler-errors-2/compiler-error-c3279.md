---
title: "C3279 de erro do compilador | Microsoft Docs"
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
  - "C3279"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3279"
ms.assetid: 639afc20-984c-4a95-be35-8bf9409f02d5
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3279 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

só são permitidas especializações parciais e explícitas explícitas, bem como instâncias de modelos de classe declaradas no namespace cli  
  
 O `cli` namespace é definida pela Microsoft e contém modelos pseudo. O compilador do Visual C\+\+ não permite especializações definidas pelo usuário, parciais e explícitas e explícitas instanciações de modelos de classe neste namespace.  
  
 O exemplo a seguir gera C3279:  
  
```  
// C3279.cpp // compile with: /clr namespace cli { template <> ref class array<int> {};   // C3279 template <typename T> ref class array<T, 2> {};   // C3279 }  
```