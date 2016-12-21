---
title: "vector&lt;bool&gt;::reference::flip | Microsoft Docs"
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
  - "vector<bool>::reference::flip"
  - "std::vector<bool>::reference::flip"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método reference::flip"
ms.assetid: ef940365-cbe4-4a87-a3e2-1f3cfa357e29
caps.latest.revision: 21
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vector&lt;bool&gt;::reference::flip
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inverte o valor booliano de um elemento [vector\<bool\>](../Topic/vector%3Cbool%3E%20Class.md) referenciado.  
  
## Sintaxe  
  
```  
void flip();  
```  
  
## Exemplo  
  
```cpp  
// vector_bool_ref_flip.cpp  
// compile with: /EHsc /W4  
#include <vector>  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
    cout << boolalpha;  
  
    vector<bool> vb = { true, false, false, true, true };  
  
    cout << "The vector is: " << endl << "    ";  
    for (const auto& b : vb) {  
        cout << b << " ";  
    }  
    cout << endl;  
  
    vector<bool>::reference vbref = vb.front();  
    vbref.flip();  
  
    cout << "The vector with first element flipped is: " << endl << "    ";  
    for (const auto& b : vb) {  
        cout << b << " ";  
    }  
    cout << endl;  
}  
  
```  
  
## Saída  
  
```  
The vector is:  
    true false false true true  
The vector with first element flipped is:  
    false false false true true  
```  
  
## Requisitos  
 **Cabeçalho:** \<vector\>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe vector\<bool\>::reference](../standard-library/vector-bool-reference-class.md)   
 [Biblioteca de Modelos Padrão](../misc/standard-template-library.md)