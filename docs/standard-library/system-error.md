---
title: "&lt;system_error&gt; | Microsoft Docs"
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
  - "std.<system_error>"
  - "std::<system_error>"
  - "<system_error>"
  - "system_error"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Cabeçalho system_error"
ms.assetid: 5e046c6e-48d9-4740-8c8a-05f3727c1215
caps.latest.revision: 15
caps.handback.revision: 5
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# &lt;system_error&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Inclui o cabeçalho `<system_error>` para definir a classe `system_error` a exceção e modelos relacionados para processar erros do sistema de baixo nível.  
  
## Sintaxe  
  
```  
#include <system_error>  
```  
  
### Objetos  
  
|||  
|-|-|  
|[generic\_category](../Topic/generic_category.md)|Representa a categoria de erros genéricas.|  
|[system\_category](../Topic/system_category.md)|Representa a categoria dos erros causados por estouros de baixo nível do sistema.|  
  
### Typedefs  
  
|||  
|-|-|  
|[generic\_errno](../Topic/generic_errno.md)|Um tipo que representa a enumeração que fornece os nomes simbólicos para todos os macros do código de erro definido por Posix em `<errno.h>`.|  
  
### Funções  
  
|||  
|-|-|  
|[make\_error\_code](../Topic/make_error_code.md)|Cria um objeto de `error_code` .|  
|[make\_error\_condition](../Topic/make_error_condition.md)|Cria um objeto de `error_condition` .|  
  
### Operadores  
  
|||  
|-|-|  
|[operador\=\=](../Topic/operator==%20\(%3Csystem_error%3E\).md)|Testa se o objeto no lado esquerdo do operador é igual ao objeto no lado direito.|  
|[operador \!\=](../Topic/operator!=%20\(%3Csystem_error%3E\).md)|Testa se o objeto no lado esquerdo do operador não é igual ao objeto no lado direito.|  
|[operador\<](../Topic/operator%3C%20\(%3Csystem_error%3E\).md)|Testa se um objeto é menor que o objeto passado para comparação.|  
  
### Enumerações  
  
|||  
|-|-|  
|[errc](../Topic/errc%20Enumeration.md)|Fornece nomes simbólicos para todos os macros do código de erro definidas por Posix em `<errno.h>`.|  
  
### Classes e Estruturas  
  
|||  
|-|-|  
|[error\_category](../standard-library/error-category-class.md)|Representa o sumário, a base comum de objetos que descreve uma categoria de códigos de erro.|  
|[error\_code](../standard-library/error-code-class.md)|Representa os erros de sistema de baixo nível que são específicos de implementação.|  
|[error\_condition](../standard-library/error-condition-class.md)|Representa códigos de erro definidas pelo usuário.|  
|[is\_error\_code\_enum](../standard-library/is-error-code-enum-class.md)|Representa um predicado do tipo que teste para a enumeração de [Classe error\_code](../standard-library/error-code-class.md) .|  
|[is\_error\_condition\_enum](../standard-library/is-error-condition-enum-class.md)|Representa um predicado do tipo que teste para a enumeração de [Classe error\_condition](../standard-library/error-condition-class.md) .|  
|[system\_error](../standard-library/system-error-class.md)|Representa a classe base para todas as exceções lançadas para relatar um estouro de baixo nível do sistema.|  
  
## Requisitos  
 system\_error \<de**Cabeçalho:** \>  
  
 **Namespace:** std  
  
## Consulte também  
 [Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)