---
title: '&lt;system_error&gt; | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- std.<system_error>
- std::<system_error>
- <system_error>
- system_error
dev_langs:
- C++
helpviewer_keywords:
- system_error header
ms.assetid: 5e046c6e-48d9-4740-8c8a-05f3727c1215
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 51fbd09793071631985720550007dddbe16f598f
ms.openlocfilehash: ad53550cce165587057910e3cd4c77427fb1cd55
ms.lasthandoff: 02/25/2017

---
# <a name="ltsystemerrorgt"></a>&lt;system_error&gt;
Inclua o cabeçalho `<system_error>` para definir a classe de exceção `system_error` e modelos relacionados para o processamento de erros de nível inferior do sistema.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
#include <system_error>  
```  
  
### <a name="objects"></a>Objetos  
  
|||  
|-|-|  
|[generic_category](../standard-library/system-error-functions.md#generic_category)|Representa a categoria de erros genéricos.|  
|[system_category](../standard-library/system-error-functions.md#system_category)|Representa a categoria de erros causados por estouros de nível inferior do sistema.|  
  
### <a name="typedefs"></a>Typedefs  
  
|||  
|-|-|  
|[generic_errno](../standard-library/system-error-typedefs.md#generic_errno)|Um tipo que representa a enumeração que fornece os nomes simbólicos para todas as macros de código de erro definidas pelo Posix em `<errno.h>`.|  
  
### <a name="functions"></a>Funções  
  
|||  
|-|-|  
|[make_error_code](../standard-library/system-error-functions.md#make_error_code)|Cria um objeto de `error_code` .|  
|[make_error_condition](../standard-library/system-error-functions.md#make_error_condition)|Cria um objeto de `error_condition` .|  
  
### <a name="operators"></a>Operadores  
  
|||  
|-|-|  
|[operator==](../standard-library/system-error-operators.md#operator_eq_eq)|Testa se o objeto à esquerda do operador é igual ao objeto à direita.|  
|[operator!=](../standard-library/system-error-operators.md#operator_neq)|Testa se o objeto à esquerda do operador é diferente do objeto à direita.|  
|[operator<](../standard-library/system-error-operators.md#operator_lt_)|Testa se um objeto é menor que o objeto passado para comparação.|  
  
### <a name="enumerations"></a>Enumerações  
  
|||  
|-|-|  
|[errc](../standard-library/system-error-enums.md#errc_enumeration)|Fornece nomes simbólicos para todas as macros de código de erro definidas pelo Posix em `<errno.h>`.|  
  
### <a name="classes-and-structs"></a>Classes e structs  
  
|||  
|-|-|  
|[error_category](../standard-library/error-category-class.md)|Representa a base abstrata e comum para objetos e descreve uma categoria de códigos de erro.|  
|[error_code](../standard-library/error-code-class.md)|Representa os erros de sistema de nível inferior específicos à implementação.|  
|[error_condition](../standard-library/error-condition-class.md)|Representa códigos de erro definidos pelo usuário.|  
|[is_error_code_enum](../standard-library/is-error-code-enum-class.md)|Representa um predicado de tipo que testa a enumeração [Classe error_code](../standard-library/error-code-class.md).|  
|[is_error_condition_enum](../standard-library/is-error-condition-enum-class.md)|Representa um predicado de tipo que testa a enumeração [Classe error_condition](../standard-library/error-condition-class.md).|  
|[system_error](../standard-library/system-error-class.md)|Representa a classe base para todas as exceções geradas para relatar um estouro de nível inferior do sistema.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<system_error>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)




