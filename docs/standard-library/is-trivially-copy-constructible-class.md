---
title: "Classe is_trivially_copy_constructible | Microsoft Docs"
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
  - "is_trivially_copy_constructible"
  - "std.is_trivially_copy_constructible"
  - "std::is_trivially_copy_constructible"
  - "type_traits/std::is_trivially_copy_constructible"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "is_trivially_copy_constructible"
ms.assetid: 4274cef5-afdd-4f2d-bc83-7562e7944ddf
caps.latest.revision: 24
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_trivially_copy_constructible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo tem um construtor de cópia trivial.  
  
## Sintaxe  
  
```  
template<class T>  
    struct is_trivially_copy_constructible;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é uma classe que tem um construtor de cópia trivial, caso contrário, manterá false.  
  
 Um construtor de cópia para uma classe `T` é trivial se ela é declarada implicitamente, a classe `T` não tem funções virtuais ou bases virtuais, todas as bases diretas da classe `T` ter construtores de cópia trivial, as classes de todos os membros de dados não estáticos de tipo de classe têm construtores de cópia trivial e as classes de todos os membros de dados não estáticos de matriz de tipo de classe têm construtores de cópia trivial.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)