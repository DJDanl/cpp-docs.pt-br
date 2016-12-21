---
title: "Erro do Compilador C3653 | Microsoft Docs"
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
  - "C3653"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3653"
ms.assetid: 316549d7-f7ef-4578-a2ba-57adc8aac527
caps.latest.revision: 12
caps.handback.revision: 12
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3653
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

função “”: não pode ser usado como uma substituição nomeada: uma função que está sendo substituída não encontrada; você esqueceu nomear explicitamente a função, usando a:: operador?  
  
 Uma substituição explícita especificou uma função que não foi localizada em nenhuma interface.  Para obter mais informações, consulte [Substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md).  
  
 O seguinte exemplo gera C3653:  
  
```  
// C3653.cpp  
// compile with: /clr  
public interface struct I {  
   void h();  
};  
  
public ref struct X : public I {  
   virtual void f() new sealed = J {};   // C3653 no J in scope  
   virtual void g() {}   // OK  
   virtual void h() new sealed = I::h {};   // OK  
};  
```