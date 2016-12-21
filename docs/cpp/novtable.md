---
title: "novtable | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "novtable"
  - "novtable_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], novtable"
  - "palavra-chave novtable __declspec"
ms.assetid: cfef09c5-8c1e-4b14-8a72-7d726ded4484
caps.latest.revision: 11
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# novtable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 Esse é um atributo `__declspec` estendido.  
  
 Essa forma de `__declspec` pode ser aplicada a qualquer declaração de classe, mas só deve ser aplicada às classes puras da interface, ou seja, classes que nunca serão instanciadas por conta própria.  `__declspec` impede que o compilador gere códigos para inicializar vfptr nos construtores e destruidores da classe.  Em diversos casos, isso remove as únicas referências para vtable que estão associadas à classe. Portanto, o vinculador as removerá.  Usar esta forma de `__declspec` pode resultar em uma redução significativa do tamanho do código.  
  
 Se você tentar instanciar uma classe marcada com `novtable` e, em seguida, acessar em um membro da classe, você receberá uma violação de acesso \(AV\).  
  
## Exemplo  
  
```  
// novtable.cpp  
#include <stdio.h>  
  
struct __declspec(novtable) X {  
   virtual void mf();  
};  
  
struct Y : public X {  
   void mf() {  
      printf_s("In Y\n");  
   }  
};  
  
int main() {  
   // X *pX = new X();  
   // pX->mf();   // Causes a runtime access violation.  
  
   Y *pY = new Y();  
   pY->mf();  
}  
```  
  
  **Em Y**   
## FIM de Específico da Microsoft  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)