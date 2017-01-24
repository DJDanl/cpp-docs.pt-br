---
title: "Classe is_trivially_constructible | Microsoft Docs"
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
  - "is_trivially_constructible"
  - "std.is_trivially_constructible"
  - "std::is_trivially_constructible"
  - "type_traits/std::is_trivially_constructible"
dev_langs: 
  - "C++"
  - "c++"
helpviewer_keywords: 
  - "is_trivially_constructible"
ms.assetid: 3fa918c1-e66f-4d0e-a11b-be1fb2c02e7b
caps.latest.revision: 12
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_trivially_constructible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se um tipo é muito construível quando são usados os tipos de argumento especificado.  
  
## Sintaxe  
  
```  
template <class T, class... Args>  
    struct is_trivially_constructible;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
 `Args`  
 Os tipos de argumento para corresponder a um construtor de `T`.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é muito construível usando os tipos de argumento em `Args`, caso contrário, manterá false. Tipo `T` é muito construível se a definição da variável `T t(std::declval<Args>()...);` está bem formado e é conhecido para chamar operações não incomum. Ambos `T` e todos os tipos em `Args` devem ser tipos completos, `void`, ou matrizes de associação desconhecida.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)