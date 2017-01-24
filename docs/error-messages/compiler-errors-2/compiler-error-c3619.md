---
title: "Erro do Compilador C3619 | Microsoft Docs"
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
  - "C3619"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3619"
ms.assetid: 76ae80d0-9fbe-4297-a1ef-b1503377fdcf
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3619
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

um modelo não pode ser declarado dentro de um gerenciado ou WinRT tipo  
  
 Modelos de classe não são permitidos no gerenciada ou WinRT classe ou interface.  
  
 C3619 só está acessível com **\/clr:oldSyntax**.  
  
 O exemplo a seguir gera C3619:  
  
```  
// C3619.cpp  
// compile with: /clr:oldSyntax  
#using <mscorlib.dll>  
  
__gc class X {  
   template<typename T> class Y {   // C3619  
   };  
};  
```