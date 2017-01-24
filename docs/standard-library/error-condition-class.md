---
title: "Classe error_condition | Microsoft Docs"
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
  - "system_error/std::error_condition"
  - "std::error_condition"
  - "error_condition"
  - "std.error_condition"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe error_condition"
ms.assetid: 6690f481-97c9-4554-a0ff-851dc96b7a06
caps.latest.revision: 16
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe error_condition
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa códigos de erro definidas pelo usuário.  
  
## Sintaxe  
  
```  
class error_condition;  
```  
  
## Comentários  
 Um objeto do tipo armazena uma `error_condition` valor do código de erro e um ponteiro para um objeto que representa [categoria](../standard-library/error-category-class.md) os códigos de erro usados para erros definidos pelo usuário relatados.  
  
### Construtores  
  
|||  
|-|-|  
|[error\_condition](../Topic/error_condition::error_condition.md)|Constrói um objeto de tipo `error_condition`.|  
  
### Typedefs  
  
|||  
|-|-|  
|[tipo de valor](../Topic/error_condition::value_type.md)|Um tipo que representa o valor de código de erro armazenada.|  
  
### Funções de membro  
  
|||  
|-|-|  
|[atribuir](../Topic/error_condition::assign.md)|Atribui uma representação codificada e uma categoria de código de erro a uma condição de erro.|  
|[categoria](../Topic/error_condition::category.md)|Retorna a categoria de erro.|  
|[limpar](../Topic/error_condition::clear.md)|Limpa o valor e a categoria de código do erro.|  
|[mensagem](../Topic/error_condition::message.md)|Retorna o nome do código de erro.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador\=\=](../Topic/error_condition::operator==.md)|Testa a igualdade entre objetos de `error_condition` .|  
|[operador \!\=](../Topic/error_condition::operator!=.md)|Testa a desigualdade entre objetos de `error_condition` .|  
|[operador\<](../Topic/error_condition::operator%3C.md)|Testa se o objeto de `error_condition` for menor que o objeto de `error_code` passado para comparação.|  
|[operador\=](../Topic/error_condition::operator=.md)|Aloca um novo valor de enumeração ao objeto de `error_condition` .|  
|[bool do operador](../Topic/error_condition::operator%20bool.md)|Converte uma variável de tipo `error_condition`.|  
  
## Requisitos  
 system\_error \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe error\_category](../standard-library/error-category-class.md)   
 [\<system\_error\>](../standard-library/system-error.md)