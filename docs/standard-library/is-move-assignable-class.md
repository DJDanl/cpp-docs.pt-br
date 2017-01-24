---
title: "Classe is_move_assignable | Microsoft Docs"
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
  - "is_move_assignable"
  - "std.is_move_assignable"
  - "std::is_move_assignable"
  - "type_traits/std::is_move_assignable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_move_assignable"
ms.assetid: f33137f2-0639-4912-8745-bc0f9fd18d28
caps.latest.revision: 13
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_move_assignable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo pode ser move atribuído.  
  
## Sintaxe  
  
```  
template<class T>  
    struct is_move_assignable;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
## Comentários  
 Um tipo é mover atribuível se uma referência rvalue para o tipo pode ser atribuída a uma referência para o tipo. O predicado de tipo é equivalente a `is_assignable<T&, T&&>`. Mova tipos atribuíveis incluem tipos escalares pode ser referenciados e tipos de classe que tenha gerado pelo compilador ou definidas pelo usuário mover operadores de atribuição.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)