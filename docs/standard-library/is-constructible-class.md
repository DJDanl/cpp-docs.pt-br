---
title: "Classe is_constructible | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "is_constructible"
  - "std.is_constructible"
  - "std::is_constructible"
  - "type_traits/std::is_constructible"
dev_langs: 
  - "C++"
  - "c++"
helpviewer_keywords: 
  - "is_constructible"
ms.assetid: 7cdec5ff-73cf-4f78-a9db-ced2e9c0fd7f
caps.latest.revision: 14
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_constructible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se um tipo é construível quando são usados os tipos de argumento especificado.  
  
## Sintaxe  
  
```  
template <class T, class... Args>  
    struct is_constructible;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
 `Args`  
 Os tipos de argumento para corresponder a um construtor de `T`.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é construível usando os tipos de argumento em `Args`, caso contrário, manterá false. Tipo `T` é construível se a definição da variável `T t(std::declval<Args>()...);` está bem formado. Ambos `T` e todos os tipos em `Args` devem ser tipos completos, `void`, ou matrizes de associação desconhecida.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)