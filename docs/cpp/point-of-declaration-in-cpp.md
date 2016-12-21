---
title: "Ponto de declara&#231;&#227;o em C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ponto de declaração"
ms.assetid: 92ea8707-80cb-497c-b479-f907b8401859
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Ponto de declara&#231;&#227;o em C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um nome é considerado declarado imediatamente após seu declarator, mas antes de seu inicializador \(opcional\).  \(Para obter mais informações sobre declaradores, consulte [Declaradores](http://msdn.microsoft.com/pt-br/8a7b9b51-92bd-4ac0-b3fe-0c4abe771838).\)  
  
 Considere este exemplo:  
  
```  
// point_of_declaration1.cpp  
// compile with: /W1   
double dVar = 7.0;  
int main()  
{  
   double dVar = dVar;   // C4700  
}  
```  
  
 Se o ponto de declaração fosse *depois* da inicialização, o `dVar` local seria inicializado como 7.0, o valor da variável global `dVar`.  No entanto, como não é esse o caso, `dVar` é inicializado como um valor indefinido.  
  
## Consulte também  
 [Escopo](../cpp/scope-visual-cpp.md)