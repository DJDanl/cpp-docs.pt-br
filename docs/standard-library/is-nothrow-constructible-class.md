---
title: "Classe is_nothrow_constructible | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "is_nothrow_constructible"
  - "std.is_nothrow_constructible"
  - "std::is_nothrow_constructible"
  - "type_traits/std::is_nothrow_constructible"
dev_langs: 
  - "C++"
  - "c++"
helpviewer_keywords: 
  - "is_nothrow_constructible"
ms.assetid: 8be3f927-283e-4d67-95a5-8bf5dc4e7a3d
caps.latest.revision: 12
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_nothrow_constructible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se um tipo é construível e não puder emitir quando os tipos de argumento especificado são usados.  
  
## Sintaxe  
  
```  
template <class T, class... Args>  
    struct is_nothrow_constructible;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
 `Args`  
 Os tipos de argumento para corresponder a um construtor de `T`.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é construível usando os tipos de argumento em `Args`, e o construtor é conhecido pelo compilador não lançar; caso contrário, manterá false. Tipo `T` é construível se a definição da variável `T t(std::declval<Args>()...);` está bem formado. Ambos `T` e todos os tipos em `Args` devem ser tipos completos, `void`, ou matrizes de associação desconhecida.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)