---
title: Classe allocator_suballoc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::allocators::allocator_suballoc
- allocators/stdext::allocator_suballoc
dev_langs:
- C++
helpviewer_keywords:
- allocator_suballoc class
ms.assetid: 50c6a5c0-d00d-4276-9285-d908fd4f6483
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: MT
ms.sourcegitcommit: 65f4e356ad0d46333b0d443d0fd6ac0b9f2b6f58
ms.openlocfilehash: 68708216ec3b9c0dda017d01641a303ab3ffd247
ms.contentlocale: pt-br
ms.lasthandoff: 10/03/2017

---
# <a name="allocatorsuballoc-class"></a>Classe allocator_suballoc
Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type` usando um cache do tipo [cache_suballoc](../standard-library/cache-suballoc-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Type>  
class allocator_suballoc;
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Type`|O tipo dos elementos alocados pelo alocador.|  
  
## <a name="remarks"></a>Comentários  
 A macro [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) passa essa classe como o parâmetro `name` na instrução a seguir: `ALLOCATOR_DECL(CACHE_SUBALLOC, SYNC_DEFAULT, allocator_suballoc);`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




