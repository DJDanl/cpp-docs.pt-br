---
title: "Classe underlying_type | Microsoft Docs"
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
  - "underlying_type"
  - "std.underlying_type"
  - "std::underlying_type"
  - "type_traits/std::underlying_type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "underlying_type"
ms.assetid: 691ddce3-2677-4480-bd35-d933fab85d3e
caps.latest.revision: 13
caps.handback.revision: 3
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe underlying_type
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Produz o tipo integral subjacente para um tipo de enumeração.  
  
## Sintaxe  
  
```  
template <class T>  
    struct underlying_type;  
```  
  
#### Parâmetros  
 `T`  
 O tipo para modificar.  
  
## Comentários  
 O `type` typedef do membro da classe modelo nomeia o tipo integral subjacente de `T`, quando `T` é um tipo de enumeração, caso contrário, não há nenhum membro typedef `type`.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)