---
title: "Classe is_trivially_default_constructible | Microsoft Docs"
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
  - "is_trivially_default_constructible"
  - "std.is_trivially_default_constructible"
  - "std::is_trivially_default_constructible"
  - "type_traits/std::is_trivially_default_constructible"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_trivially_default_constructible"
ms.assetid: 653ecd73-909f-4dd8-b95a-d1164d1c2da4
caps.latest.revision: 17
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_trivially_default_constructible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo tem um construtor padrão trivial.  
  
## Sintaxe  
  
```  
template<class Ty>  
    struct  is_trivially_default_constructible;  
```  
  
#### Parâmetros  
 `Ty`  
 O tipo a ser consultado.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `Ty` é uma classe que tem um construtor simples, de outra forma, manterá false.  
  
 Um construtor padrão para uma classe `Ty` é trivial se:  
  
-   é um construtor padrão declarada implicitamente  
  
-   a classe `Ty` não tem nenhuma função virtual  
  
-   a classe `Ty` não tem nenhum bases virtuais  
  
-   o direct todas as bases da classe `Ty` ter construtores triviais  
  
-   as classes de todos os membros de dados não estático do tipo de classe têm construtores triviais  
  
-   as classes de todos os membros de dados não estático de matriz do tipo de classe têm construtores triviais  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)