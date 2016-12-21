---
title: "Classe is_trivially_move_constructible | Microsoft Docs"
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
  - "is_trivially_move_constructible"
  - "std.is_trivially_move_constructible"
  - "std::is_trivially_move_constructible"
  - "type_traits/std::is_trivially_move_constructible"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_trivially_move_constructible"
ms.assetid: 740bdec7-65e5-47b3-b94f-a2479ceac3ec
caps.latest.revision: 11
caps.handback.revision: 1
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_trivially_move_constructible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo tem trivial construtor de movimentação.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct is_trivially_move_constructible;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `Ty` é uma classe que tem um simples construtor de movimentação, caso contrário, manterá false.  
  
 Um construtor de movimentação de uma classe `Ty` é trivial se:  
  
 ele é declarado implicitamente  
  
 seus tipos de parâmetro são equivalentes da declaração implícita  
  
 a classe `Ty` não tem nenhuma função virtual  
  
 a classe `Ty` não tem nenhum bases virtuais  
  
 a classe não possui nenhum membro de dados estático não voláteis  
  
 o direct todas as bases da classe `Ty` têm construtores de movimentação trivial  
  
 as classes de todos os membros de dados não estático do tipo de classe têm construtores de movimentação trivial  
  
 as classes de todos os membros de dados não estático de matriz do tipo de classe têm construtores de movimentação trivial  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)