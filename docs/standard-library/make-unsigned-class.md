---
title: "Classe make_unsigned | Microsoft Docs"
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
  - "std.tr1.make_unsigned"
  - "make_unsigned"
  - "std::tr1::make_unsigned"
  - "std.make_unsigned"
  - "std::make_unsigned"
  - "type_traits/std::make_unsigned"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe make_unsigned [TR1]"
  - "make_unsigned"
ms.assetid: 7a6a3c4f-1a4c-47e8-9ee2-ac1f7b669353
caps.latest.revision: 18
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe make_unsigned
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cria o tipo ou o menor tipo sem sinal maior ou igual em tamanho ao tipo.  
  
## Sintaxe  
  
```  
template<class T>  
    struct make_unsigned;  
  
template<class T>  
    using make_unsigned_t = typename make_unsigned<T>::type;  
  
```  
  
#### Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|---------------|  
|`T`|O tipo a ser modificado.|  
  
## Comentários  
 Uma instância do modificador de tipo mantém um tipo modificado que é`T`se`is_unsigned<T>`for verdadeira.  Caso contrário, é o menor tipo com sinal`ST`para o qual`sizeof (T) <= sizeof (ST)`.  
  
## Requisitos  
 **Cabeçalho:** \<type\_traits\>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)