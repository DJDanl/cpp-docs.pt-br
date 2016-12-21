---
title: "Classe is_nothrow_move_assignable | Microsoft Docs"
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
  - "is_nothrow_move_assignable"
  - "std.is_nothrow_move_assignable"
  - "std::is_nothrow_move_assignable"
  - "type_traits/std::is_nothrow_move_assignable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_nothrow_move_assignable"
ms.assetid: 000baa02-cbba-49de-9870-af730033348e
caps.latest.revision: 11
caps.handback.revision: 1
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_nothrow_move_assignable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo tem um [nothrow](../Topic/nothrow%20\(C++\).md) mover o operador de atribuição.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_nothrow_move_assignable;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `Ty` tem um nothrow mover operador de atribuição, caso contrário, manterá false.  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)