---
title: "Classe decay | Microsoft Docs"
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
  - "decay"
  - "std.tr1.decay"
  - "std::tr1::decay"
  - "std.decay"
  - "std::decay"
  - "type_traits/std::decay"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe decay [TR1]"
ms.assetid: 96baa2fd-c8e0-49af-be91-ba375ba7f9dc
caps.latest.revision: 20
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe decay
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Produz o tipo como passado por valor. Faz referência sem tipo não const, não volátil ou cria um ponteiro para o tipo de uma função ou um tipo de matriz.  
  
## Sintaxe  
  
```  
template<class T>  
    struct decay;  
  
template<class T> using decay_t = typename decay<T>::type;  
```  
  
#### Parâmetros  
 `T`  
 O tipo para modificar.  
  
## Comentários  
 Use o modelo de decay para produzir o tipo resultante como se o tipo passado por valor como um argumento. A definição de membro de classe de modelo `type` mantém um tipo modificado que é definido nos seguintes estágios:  
  
-   O tipo `U` é definido como `remove_reference<T>::type`.  
  
-   Se `is_array<U>::value` for true, o tipo modificado `type` é `remove_extent<U>::type *`.  
  
-   Caso contrário, se `is_function<U>::value` for true, o tipo modificado `type` é `add_pointer<U>::type`.  
  
-   Caso contrário, o tipo modificado `type` é `remove_cv<U>::type`.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)