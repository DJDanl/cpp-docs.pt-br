---
title: "Aviso do compilador (n&#237;vel 1) C4540 | Microsoft Docs"
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
  - "C4540"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4540"
ms.assetid: 8085e748-5f4d-43c2-b06d-eaf794edbf72
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Aviso do compilador (n&#237;vel 1) C4540
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

dynamic\_cast usado para converter na base inacessível ou ambígua; o teste de tempo de execução falhará tipo \(“\- 1 " para digitar “\- 2 "\)  
  
 Você usou `dynamic_cast` para converter de um tipo para outro.  O compilador determinou que a conversão falhará **nulo**de retorno sempre \(\) porque uma classe base é inacessível \(`private`, por exemplo\) ou ambígua \(aparecer mais de uma vez na hierarquia da classe, por exemplo\).  
  
 O exemplo a seguir mostra um exemplo desse aviso.  A classe **B** é derivada de A classe.  O programa usa `dynamic_cast` para conversão da classe **B** \(a classe derivada\) para classificar **A**, sempre que podem falhar porque a classe **B** é `private` e assim inacessível.  Alterando o acesso de à **public** resolverá o aviso.  
  
```  
// C4540.cpp  
// compile with: /W1  
  
struct A {   
   virtual void g() {}  
};  
  
struct B : private A {  
   virtual void g() {}  
};  
  
int main() {  
   B b;  
   A * ap = dynamic_cast<A*>(&b);   // C4540  
}  
```