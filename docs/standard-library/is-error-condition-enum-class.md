---
title: "Classe is_error_condition_enum | Microsoft Docs"
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
  - "std::is_error_condition_enum"
  - "std.is_error_condition_enum"
  - "is_error_condition_enum"
  - "system_error/std::is_error_condition_enum"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe is_error_condition_enum"
ms.assetid: 752bb87a-c61c-4304-9254-5aaf228b59c0
caps.latest.revision: 15
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe is_error_condition_enum
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa um predicado do tipo que teste para a enumeração de [error\_condition](../standard-library/error-condition-class.md) .  
  
## Sintaxe  
  
```  
template<_Enum>  
    class is_error_condition_enum;  
```  
  
## Comentários  
 Uma instância desse [predicado do tipo](../standard-library/type-traits.md) se aplica se o tipo `_Enum` é um valor de enumeração apropriado para armazenar em um objeto do tipo `error_condition`.  
  
 É permitido adicionar especializações a esse tipo para tipos definidos pelo usuário.  
  
## Requisitos  
 system\_error \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\< type\_traits \>](../standard-library/type-traits.md)   
 [\<system\_error\>](../standard-library/system-error.md)