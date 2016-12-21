---
title: "Classe error_code | Microsoft Docs"
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
  - "error_code"
  - "std.error_code"
  - "std::error_code"
  - "system_error/std::error_code"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe error_code"
ms.assetid: c09b4a96-cb14-4281-a319-63543f9b2b4a
caps.latest.revision: 17
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe error_code
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Representa os erros de sistema de baixo nível que são específicos de implementação.  
  
## Sintaxe  
  
```  
class error_code;  
```  
  
## Comentários  
 Um objeto da classe de `error_code` de tipo armazena uma representação codificada do código de erro e um ponteiro para um objeto que representa [categoria](../standard-library/error-category-class.md) os códigos de erro que descrevem erros de sistema de baixo nível relatados.  
  
### Construtores  
  
|||  
|-|-|  
|[error\_code](../Topic/error_code::error_code.md)|Constrói um objeto de tipo `error_code`.|  
  
### Typedefs  
  
|||  
|-|-|  
|[tipo de valor](../Topic/error_code::value_type.md)|Um tipo que representa o valor de código de erro armazenada.|  
  
### Funções de membro  
  
|||  
|-|-|  
|[atribuir](../Topic/error_code::assign.md)|Atribui uma representação codificada e uma categoria do código de erro em um código de erro.|  
|[categoria](../Topic/error_code::category.md)|Retorna a categoria de erro.|  
|[limpar](../Topic/error_code::clear.md)|Limpa o valor e a categoria de código do erro.|  
|[default\_error\_condition](../Topic/error_code::default_error_condition.md)|Retorna a condição de erro padrão.|  
|[mensagem](../Topic/error_code::message.md)|Retorna o nome do código de erro.|  
  
### Operadores  
  
|||  
|-|-|  
|[operador\=\=](../Topic/error_code::operator==.md)|Testa a igualdade entre objetos de `error_code` .|  
|[operador \!\=](../Topic/error_code::operator!=.md)|Testa a desigualdade entre objetos de `error_code` .|  
|[operador\<](../Topic/error_code::operator%3C.md)|Testa se o objeto de `error_code` for menor que o objeto de `error_code` passado para comparação.|  
|[operador\=](../Topic/error_code::operator=.md)|Aloca um novo valor de enumeração ao objeto de `error_code` .|  
|[bool do operador](../Topic/error_code::operator%20bool.md)|Converte uma variável de tipo `error_code`.|  
  
## Requisitos  
 system\_error \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Classe error\_category](../standard-library/error-category-class.md)   
 [\<system\_error\>](../standard-library/system-error.md)