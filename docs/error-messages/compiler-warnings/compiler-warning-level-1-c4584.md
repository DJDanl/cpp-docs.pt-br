---
title: "Aviso do compilador (n&#237;vel 1) C4584 | Microsoft Docs"
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
  - "C4584"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4584"
ms.assetid: ad86582f-cb8c-4d21-8c4c-a6c800059e25
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4584
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“class1”: o class2 das classes base” já é uma classe base de class3” “  
  
 A classe que você definiu herda de duas classes, uma de que herda do outro.  Por exemplo:  
  
```  
// C4584.cpp  
// compile with: /W1 /LD  
class A {  
};  
  
class B : public A {  
};  
  
class C : public A, public B { // C4584  
};  
```  
  
 Nesse caso, um aviso será emitido na classe C porque ambos herda da classe A e B da classe, que também herda de A classe.  Esse aviso serve como um lembrete que você deve qualificar o uso dos membros dessas classes base ou um erro de compilador será gerado devido à ambiguidade em relação ao membro da classe você se refere.