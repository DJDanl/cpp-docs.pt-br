---
title: "Estrutura hash | Microsoft Docs"
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
  - "typeindex/std::hash"
dev_langs: 
  - "C++"
ms.assetid: e5a41202-ef3b-45d0-b3a7-4c2dbdc0487a
caps.latest.revision: 13
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Estrutura hash
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe de modelo define o método como retornando `val.hash_code()`. O método define uma função de hash que é usada para mapear os valores do tipo [type\_index](../standard-library/type-index-class.md) para uma distribuição de valores de índice.  
  
## Sintaxe  
  
```vb  
template<>  
    struct hash<type_index>  
        : public unary_function<type_index, size_t>  
    { // hashes a typeinfo object  
    size_t operator()(type_index val) const;  
    };  
```  
  
## Consulte também  
 [\<typeindex\>](../standard-library/typeindex.md)