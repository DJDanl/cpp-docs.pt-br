---
title: "Como usar gcnew para criar tipos de valor e usar convers&#227;o boxing impl&#237;cita | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "boxing, implícito"
  - "palavra-chave gcnew [C++], criando tipos de valor"
  - "tipos de valor, criando"
ms.assetid: ceb48841-d6bd-47be-a167-57f44c961603
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar gcnew para criar tipos de valor e usar convers&#227;o boxing impl&#237;cita
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usar [gcnew](../windows/ref-new-gcnew-cpp-component-extensions.md) em um tipo de valor criará um tipo de valor encaixotado, que pode ser colocado em gerenciado, heap com coletados.  
  
## Exemplo  
  
```  
// vcmcppv2_explicit_boxing4.cpp  
// compile with: /clr  
public value class V {  
public:  
   int m_i;  
   V(int i) : m_i(i) {}  
};  
  
public ref struct TC {  
   void do_test(V^ v) {  
      if (v != nullptr)  
         ;  
      else  
         ;  
   }  
};  
  
int main() {  
   V^ v = gcnew V(42);  
   TC^ tc = gcnew TC;  
   tc->do_test(v);  
}  
```  
  
## Consulte também  
 [Boxing](../windows/boxing-cpp-component-extensions.md)