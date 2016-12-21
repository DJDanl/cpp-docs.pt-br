---
title: "is_trivially_copy_assignable | Microsoft Docs"
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
  - "is_trivially_copy_assignable"
  - "std.is_trivially_copy_assignable"
  - "std::is_trivially_copy_assignable"
  - "type_traits/std::is_trivially_copy_assignable"
dev_langs: 
  - "C++"
ms.assetid: 7410133e-f367-493f-92a7-e34e3ec5e879
caps.latest.revision: 12
caps.handback.revision: 1
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# is_trivially_copy_assignable
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo tem um operador de atribuição de cópia trivial.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_trivially_copy_constructible;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `Ty` é uma classe que tem um cópia trivial operador de atribuição, caso contrário, manterá false.  
  
 Um construtor de atribuição para uma classe `Ty` é trivial se:  
  
 ele é fornecido implicitamente  
  
 a classe `Ty` não tem nenhuma função virtual  
  
 a classe `Ty` não tem nenhum bases virtuais  
  
 as classes de todos os membros de dados não estático do tipo de classe têm operadores de atribuição simples  
  
 as classes de todos os membros de dados não estático de matriz do tipo de classe têm operadores de atribuição simples  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)