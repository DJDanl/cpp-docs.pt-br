---
title: Classe is_error_condition_enum | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: system_error/std::is_error_condition_enum
dev_langs: C++
helpviewer_keywords: is_error_condition_enum class
ms.assetid: 752bb87a-c61c-4304-9254-5aaf228b59c0
caps.latest.revision: "15"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: d26913c9767f35c131605a8f7abee87396e753a2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="iserrorconditionenum-class"></a>Classe is_error_condition_enum
Representa um predicado de tipo que testa a enumeração [error_condition](../standard-library/error-condition-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <_Enum>
class is_error_condition_enum;
```  
  
## <a name="remarks"></a>Comentários  
 Uma instância deste [predicado de tipo](../standard-library/type-traits.md) será verdadeira se o tipo `_Enum` for um valor de enumeração adequado para o armazenamento em um objeto do tipo `error_condition`.  
  
 É permitido adicionar especializações a este tipo para tipos definidos pelo usuário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<system_error>  
  
 **Namespace:** std  
  
## <a name="see-also"></a>Consulte também  
 [<type_traits>](../standard-library/type-traits.md)   
 [<system_error>](../standard-library/system-error.md)



