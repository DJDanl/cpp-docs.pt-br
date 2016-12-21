---
title: "Classe is_assignable | Microsoft Docs"
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
  - "is_assignable"
  - "std.is_assignable"
  - "std::is_assignable"
  - "type_traits/std::is_assignable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_assignable"
ms.assetid: 53444287-c8be-4ad2-9487-a85c066a4f84
caps.latest.revision: 14
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_assignable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se um valor de `From` tipo pode ser atribuído a um `To` tipo.  
  
## Sintaxe  
  
```  
template <class To, class From>  
    struct is_assignable;  
```  
  
#### Parâmetros  
 Para  
 O tipo do objeto que recebe a atribuição.  
  
 De  
 O tipo do objeto que fornece o valor.  
  
## Comentários  
 A expressão não avaliada `declval<To>() = declval<From>()` deve ser bem formado. Ambos `From` e `To` devem ser tipos completos, `void`, ou matrizes de associação desconhecida.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)