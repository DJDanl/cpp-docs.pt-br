---
title: "Erro do Compilador C2533 | Microsoft Docs"
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
  - "C2533"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2533"
ms.assetid: 5b335652-076c-4824-87c8-a741f64a3ce0
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2533
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'identifier': os construtores não permitidos um tipo de retorno  
  
 Um construtor não pode ter um tipo de retorno \(nem mesmo um `void` tipo de retorno\).  
  
 Uma origem comum desse erro é um ponto e vírgula ausente entre o final de uma definição de classe e a primeira implementação do construtor.  O compilador considera a classe como uma definição de tipo de retorno da função de construtor e gera C2533.  
  
 O exemplo a seguir gera C2533 e mostra como corrigi\-lo:  
  
```  
// C2533.cpp  
// compile with: /c  
class X {  
public:  
   X();     
};  
  
int X::X() {}   // C2533 - constructor return type not allowed  
X::X() {}   // OK - fix by using no return type  
```