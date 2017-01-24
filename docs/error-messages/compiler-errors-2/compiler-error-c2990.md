---
title: "Erro do Compilador C2990 | Microsoft Docs"
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
  - "C2990"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2990"
ms.assetid: 674e9f6a-6743-4af0-a7ed-cbe11103a2f8
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2990
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“classes: tipo de classe não tão já declarado como um tipo de classe  
  
 A classe do não genérico ou modelo redefinirá uma classe genérico ou modelo.  Arquivos de cabeçalho de verificação de conflitos.  
  
 O seguinte exemplo gera C2990:  
  
```  
// C2990.cpp  
// compile with: /c  
template <class T>  
class C{};  
class C{};   // C2990  
```  
  
 C2990 também pode ocorrer ao usar produtos genéricas:  
  
```  
// C2990b.cpp  
// compile with: /clr /c  
generic <class T>  
ref struct GC;  
  
ref struct GC {};   // C2990  
```  
  
 C2990 também pode ocorrer devido a uma alteração no compilador do Visual C\+\+ para Visual C\+\+ 2005; o compilador agora requer que várias declarações para o mesmo tipo sejam idênticas em relação à especificação do modelo.  
  
 O seguinte exemplo gera C2990:  
  
```  
// C2990c.cpp  
// compile with: /c  
template<class T>  
class A;  
  
template<class T>  
struct A2 {  
   friend class A;   // C2990  
};  
  
// OK  
template<class T>  
struct B {  
   template<class T>  
   friend class A;  
};  
```