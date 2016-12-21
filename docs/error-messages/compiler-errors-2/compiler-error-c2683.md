---
title: "Erro do Compilador C2683 | Microsoft Docs"
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
  - "C2683"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2683"
ms.assetid: db605e4f-601b-4d05-92a1-c43ca24de08d
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2683
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“cast”: o tipo “” não é um tipo polimórfica  
  
 Você não pode usar [dynamic\_cast](../../cpp/dynamic-cast-operator.md) para converter de uma classe não polimórfica \(uma classe sem funções virtuais\).  
  
 Você pode usar [static\_cast](../../cpp/static-cast-operator.md) para executar conversões de tipos não polimorfos.  No entanto, `static_cast` não executa uma verificação de tempo de execução.  
  
 O seguinte exemplo gera C2683:  
  
```  
// C2683.cpp  
// compile with: /c  
class B { };  
class D : public B { };  
  
void f(B* pb) {  
   D* pd1 = dynamic_cast<D*>(pb);  // C2683  
   D* pd1 = static_cast<D*>(pb);   // OK  
}  
```