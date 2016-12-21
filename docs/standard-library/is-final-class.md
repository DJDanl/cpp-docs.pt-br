---
title: "Classe is_final | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "cpp"
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "is_final"
  - "std.is_final"
  - "std::is_final"
  - "type_traits/std::is_final"
dev_langs: 
  - "C++"
  - "c++"
helpviewer_keywords: 
  - "is_final"
ms.assetid: 9dbad82f-6685-4909-94e8-98e4a93994b9
caps.latest.revision: 12
caps.handback.revision: 2
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_final
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Testa se o tipo é marcado como um tipo de classe `final`.  
  
## Sintaxe  
  
```  
template<class T>  
    struct is_final;  
```  
  
#### Parâmetros  
 `T`  
 O tipo de consulta.  
  
## Comentários  
 Uma instância do predicado do tipo manterá true se o tipo `T` é marcado como um tipo de classe `final`, caso contrário, manterá false. Se `T` for um tipo de classe, ele deve ser um tipo completo.  
  
## Requisitos  
 **Cabeçalho:** \< type\_traits \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [especificador final](../cpp/final-specifier.md)