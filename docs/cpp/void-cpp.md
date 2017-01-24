---
title: "void (C++) | Microsoft Docs"
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
  - "void"
  - "void_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções [C++], void"
  - "ponteiros, void"
  - "palavra-chave void [C++]"
ms.assetid: d203edba-38e6-4056-8b89-011437351057
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# void (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando usado como um tipo de retorno da função, a palavra\-chave `void` especifica que a função não retorna um valor.  Quando usado para a lista de parâmetros de uma função, um item nulo especifica que a função não usa parâmetros.  Quando usado em declaração de um ponteiro nulo, especifica que o ponteiro é “universal”.  
  
 Se o tipo de um ponteiro é **void \***, o ponteiro pode apontar para qualquer variável que não está declarado com a palavra\-chave **const** ou `volatile`.  Um ponteiro nulo não pode ter a referência removida a menos que seja convertido para outro tipo.  Um ponteiro nulo pode ser convertido em outro tipo de ponteiro de dados.  
  
 Um ponteiro nulo pode apontar para uma função, mas não para um membro da classe em C\+\+.  
  
 Você não pode declarar uma variável de tipo nulo.  
  
## Exemplo  
  
```  
// void.cpp  
void vobject;   // C2182  
void *pv;   // okay  
int *pint; int i;  
int main() {  
   pv = &i;  
   // Cast optional in C required in C++  
   pint = (int *)pv;  
}   
```  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Ponteiros para tipo void](../misc/pointers-to-type-void.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)