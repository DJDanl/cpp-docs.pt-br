---
title: "C3264 de erro do compilador | Microsoft Docs"
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
  - "C3264"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3264"
ms.assetid: 94ece687-2364-4f7a-8ebb-7afd3ae9d63d
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3264 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'class': um construtor de classe não pode ter um tipo de retorno  
  
 Construtores de classe não podem ter tipos de retorno.  
  
 O exemplo a seguir gera C3264:  
  
```  
// C3264_2.cpp // compile with: /clr ref class X { public: static int X()   { // C3264 } /* use the code below to resolve the error static X() { } */ }; int main() { }  
```  
  
 O exemplo a seguir gera C3264:  
  
```  
// C3264.cpp // compile with: /clr:oldSyntax #using <mscorlib.dll> __gc class X { public: static int X()   { // C3264 } /* use the code below to resolve the error static X() { } */ }; int main() { }  
```