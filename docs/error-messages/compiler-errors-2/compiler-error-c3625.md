---
title: "Erro do Compilador C3625 | Microsoft Docs"
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
  - "C3625"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3625"
ms.assetid: fdf49f21-d6b1-42f4-9eec-23b04ae8b4aa
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3625
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'native\_type': um tipo nativo não pode derivar de gerenciada ou WinRT digite 'type'  
  
 Uma classe nativa não pode herdar de gerenciada ou WinRT classe.  Para obter mais informações, consulte [Classes and Structs](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
 O exemplo a seguir gera C3625:  
  
```  
// C3625.cpp  
// compile with: /clr /c  
ref class B {};  
class D : public B {};   // C3625 cannot inherit from a managed class  
```  
  
 O exemplo a seguir gera C3625:  
  
```  
// C3625_b.cpp  
// compile with: /clr:oldSyntax /c  
__gc class B {};  
class D : public B {};   // C3625  cannot inherit from a managed class  
```