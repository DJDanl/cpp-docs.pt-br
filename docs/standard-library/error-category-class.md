---
title: "Classe error_category | Microsoft Docs"
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
  - "std::error_category"
  - "system_error/std::error_category"
  - "error_category"
  - "std.error_category"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe error_category"
ms.assetid: e0a71e14-852d-4905-acd6-5f8ed426706d
caps.latest.revision: 15
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe error_category
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa a base abstrata, comum para objetos que descreve uma categoria de códigos de erro.  
  
## Sintaxe  
  
```  
class error_category;  
```  
  
## Comentários  
 Dois objetos predefinidos implementam `error_category`: [generic\_category](../Topic/generic_category.md) e [system\_category](../Topic/system_category.md).  
  
### Definições de tipo  
  
|||  
|-|-|  
|[value\_type](../Topic/error_category::value_type.md)|Um tipo que representa o valor do código de erro armazenado.|  
  
### Funções membro  
  
|||  
|-|-|  
|[default\_error\_condition](../Topic/error_category::default_error_condition.md)|Armazena o valor de código de erro para um objeto de condição de erro.|  
|[equivalente](../Topic/error_category::equivalent.md)|Retorna um valor que especifica se os objetos de erro são equivalentes.|  
|[mensagem](../Topic/error_category::message.md)|Retorna o nome do código de erro especificado.|  
|[name](../Topic/error_category::name.md)|Retorna o nome da categoria.|  
  
### Operadores  
  
|||  
|-|-|  
|[operator\=\=](../Topic/error_category::operator==.md)|Testa a igualdade entre `error_category` objetos.|  
|[operator\!\=](../Topic/error_category::operator!=.md)|Testa a desigualdade entre `error_category` objetos.|  
|[Operador \<](../Topic/error_category::operator%3C.md)|Testa se o [error\_category](../standard-library/error-category-class.md) objeto é menor do que o `error_category` objeto passado para comparação.|  
  
## Requisitos  
 **Cabeçalho:** \< system\_error \>  
  
 **Namespace:** std  
  
## Consulte também  
 [\<system\_error\>](../standard-library/system-error.md)