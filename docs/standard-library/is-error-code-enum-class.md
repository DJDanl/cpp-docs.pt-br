---
title: Classe is_error_code_enum | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: system_error/std::is_error_code_enum
dev_langs: C++
helpviewer_keywords: is_error_code_enum class
ms.assetid: cee5be2d-7c20-4cec-a352-1ab8b7d32601
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 56f402c938d3e481e9d859d66f383b5f8886df61
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iserrorcodeenum-class"></a>Classe is_error_code_enum
Representa um predicado de tipo que testa a enumeração [error_code](../standard-library/error-code-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <_Enum>
class is_error_code_enum;
```  
  
## <a name="remarks"></a>Comentários  
 Uma instância deste [predicado de tipo](../standard-library/type-traits.md) será verdadeira se o tipo `_Enum` for um valor de enumeração adequado para o armazenamento em um objeto do tipo `error_code`.  
  
 É permitido adicionar especializações a este tipo para tipos definidos pelo usuário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<system_error>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [<system_error>](../standard-library/system-error.md)



