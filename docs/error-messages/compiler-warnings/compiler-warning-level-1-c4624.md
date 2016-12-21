---
title: "Aviso do compilador (n&#237;vel 1) C4624 | Microsoft Docs"
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
  - "C4624"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4624"
ms.assetid: 14f61769-d92e-482b-9515-debd87b30a66
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4624
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'derived class': destruidor foi definido implicitamente como excluído porque um destruidor de classe base está inacessível ou excluído  
  
 Um destruidor não estava acessível ou excluídos em uma classe base e, portanto, não foi gerado para uma classe derivada.  Qualquer tentativa de criar um objeto desse tipo na pilha causará um erro do compilador.  
  
 O exemplo a seguir gera C4624 e mostra como corrigi\-lo:  
  
```  
// C4624.cpp  
// compile with: /W1 /c  
class B {  
// Uncomment the following line to fix.  
// public:  
   ~B();  
};  
  
class D : public B {};   // C4624 B's destructor not public  
```