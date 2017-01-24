---
title: "Classe is_trivially_move_assignable | Microsoft Docs"
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
  - "is_trivially_move_assignable"
  - "std.is_trivially_move_assignable"
  - "std::is_trivially_move_assignable"
  - "type_traits/std::is_trivially_move_assignable"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_trivially_move_assignable"
ms.assetid: 374f7322-0706-4bc1-a1a5-4191d0315e28
caps.latest.revision: 11
caps.handback.revision: 1
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_trivially_move_assignable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo tem um operador de atribuição de movimentação trivial.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_trivially_move_assignable;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `Ty` é uma classe que tem um movimentação trivial operador de atribuição, caso contrário, manterá false.  
  
 Um operador de atribuição de movimentação de uma classe `Ty` é trivial se:  
  
 ele é fornecido implicitamente  
  
 a classe `Ty` não tem nenhuma função virtual  
  
 a classe `Ty` não tem nenhum bases virtuais  
  
 as classes de todos os membros de dados não estático do tipo de classe têm operadores de atribuição de movimentação trivial  
  
 as classes de todos os membros de dados não estático de matriz do tipo de classe têm operadores de atribuição de movimentação trivial  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)