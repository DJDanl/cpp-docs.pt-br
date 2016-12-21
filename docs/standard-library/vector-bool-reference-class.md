---
title: "Classe vector&lt;bool&gt;::reference | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vector<bool>::reference"
  - "std::vector<bool>::reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de referência vector<bool>"
ms.assetid: f27854f9-0ef0-4e7e-ad2e-cd53b6cb3334
caps.latest.revision: 22
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe vector&lt;bool&gt;::reference
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe `vector<bool>::reference` é uma classe proxy fornecida pela classe [vector\<bool\>](../Topic/vector%3Cbool%3E%20Class.md) para simular `bool&`.  
  
## Comentários  
 Uma referência simulada é necessária porque o C\+\+ não permite nativamente referências diretas aos bits.  `vector<bool>` usa apenas um bit por elemento, que pode ser referenciado usando essa classe proxy.  No entanto, a simulação de referência não é concluída porque determinadas atribuições não são válidas.  Por exemplo, como o endereço do objeto `vector<bool>::reference` não pode ser usado, o código a seguir que usa [vector\<bool\>::operator&#91;&#93;](../Topic/vector%3Cbool%3E::operator.md) não está correto:  
  
```cpp  
    vector<bool> vb;  
...  
    bool* pb = &vb[1]; // conversion error - do not use  
    bool& refb = vb[1];   // conversion error - do not use  
  
```  
  
### Funções membro  
  
|||  
|-|-|  
|[flip](../standard-library/vector-bool-reference-flip.md)|Inverte o valor booliano de um elemento de vetor.|  
|[operator bool](../Topic/vector%3Cbool%3E::reference::operator%20bool.md)|Fornece uma conversão implícita de `vector<bool>::reference` em `bool`.|  
|[operator\=](../standard-library/vector-bool-reference-operator-assign.md)|Atribui um valor booliano a um bit ou o valor mantido por um elemento referenciado para um bit.|  
  
## Requisitos  
 **Cabeçalho**: \<vector\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<vector\>](../standard-library/vector.md)   
 [Segurança de threads na Biblioteca Padrão C\+\+](../standard-library/thread-safety-in-the-cpp-standard-library.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)