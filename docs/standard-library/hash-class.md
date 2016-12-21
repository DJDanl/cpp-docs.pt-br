---
title: "Classe hash | Microsoft Docs"
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
  - "std.hash"
  - "xfunctional/std::hash"
  - "hash"
  - "typeindex/std::hash"
  - "std::hash"
  - "std.tr1.hash"
  - "std::tr1::hash"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe hash"
  - "Classe hash [TR1]"
ms.assetid: e1b500c6-a5c8-4f6f-ad33-7ec52eb8e2e4
caps.latest.revision: 22
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe hash
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Computa o código hash para um valor.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct hash  
        : public unary_function<Ty, size_t> {  
    size_t operator()(Ty _Val) const;  
    };  
```  
  
## Comentários  
 A função de membro define uma função de hash, adequada para mapear valores de tipo `Ty` a uma distribuição de valores de índice.  O operador de membro retorna um código hash para `_Val`, adequado para uso com classes `unordered_map`, `unordered_multimap`, `unordered_set`, e `unordered_multiset`do modelo.  `Ty` pode ser qualquer tipo escalar, `string`, `wstring`, `error_code`, `error_condition`, `u16string`, ou `u32string`.  
  
## Exemplo  
  
```  
// std_tr1__functional__hash.cpp   
// compile with: /EHsc   
#include <functional>   
#include <iostream>   
#include <unordered_set>   
  
int main()   
    {   
    std::unordered_set<int, std::hash<int> > c0;   
    c0.insert(3);   
    std::cout << *c0.find(3) << std::endl;   
  
    return (0);   
    }  
  
```  
  
 **3**   
## Requisitos  
 **Cabeçalho:** \<funcional\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<unordered\_map\>](../standard-library/unordered-map.md)   
 [Classe unordered\_multimap](../standard-library/unordered-multimap-class.md)   
 [Classe unordered\_multiset](../standard-library/unordered-multiset-class.md)   
 [\<unordered\_set\>](../standard-library/unordered-set.md)