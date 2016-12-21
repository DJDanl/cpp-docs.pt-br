---
title: "Classe is_destructible | Microsoft Docs"
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
  - "is_destructible"
  - "std.is_destructible"
  - "std::is_destructible"
  - "type_traits/std::is_destructible"
dev_langs: 
  - "C++"
  - "c++"
helpviewer_keywords: 
  - "is_destructible"
ms.assetid: 3bb9b718-1ad5-49ae-93cc-92b93b546b4d
caps.latest.revision: 16
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_destructible
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo é destructible.  
  
## Sintaxe  
  
```  
template <class T>  
    struct is_destructible;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é um tipo destructible, de outra forma, manterá false. Tipos de destructible são tipos de referência, objeto tipos e tipos de onde de algum tipo `U` igual a `remove_all_extents_t<T>` o operando não avaliado `std::declval<U&>.~U()` está bem formado. Outros tipos, incluindo tipos incompletos, `void`, e tipos de função, não são tipos destructible.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)