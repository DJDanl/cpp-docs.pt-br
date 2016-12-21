---
title: "Erro do Compilador C3648 | Microsoft Docs"
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
  - "C3648"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3648"
ms.assetid: 5d042989-41cb-4cd0-aa50-976b70146aaf
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3648
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

essa sintaxe explícita de substituição requer \/clr:oldSyntax  
  
 Ao criar para a sintaxe gerenciado a última, o compilador localizado a sintaxe explícita de substituição para versões anteriores.  
  
 Para obter mais informações, consulte [Substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).  Para obter mais informações sobre a sintaxe mais antigo, consulte [Substituições explícitas](../../cpp/explicit-overrides-cpp.md).  
  
 O seguinte exemplo gera C3648:  
  
```  
// C3648.cpp  
// compile with: /clr  
public interface struct I {  
   void f();  
};  
  
public ref struct R : I {  
   virtual void I::f() {}   // C3648  
   // try the following line instead  
   // virtual void f() = I::f{}  
};  
```