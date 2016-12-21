---
title: "C3214 de erro do compilador | Microsoft Docs"
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
  - "C3214"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3214"
ms.assetid: 49ee4a9a-2549-4adb-9d3a-38e154303c2e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3214 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'type': argumento de tipo inválido para parâmetro genérico param de genérico 'generic\_type', não atender a restrição 'restrição'  
  
 O tipo foi especificado para uma instanciação de uma classe genérica que não atenda a restrição da classe genérica.  
  
 O exemplo a seguir gera C3214:  
  
```  
// C3214.cpp // compile with: /clr interface struct A {}; generic <class T> where T : A ref class C {}; ref class X : public A {}; int main() { C<int>^ c = new C<int>;   // C3214 C<X ^> ^ c2 = new C<X^>;   // OK }  
```