---
title: Classe allocator_newdel | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::allocators::allocator_newdel
- allocators/stdext::allocator_newdel
- stdext::allocators::allocator_newdel
dev_langs: C++
helpviewer_keywords:
- stdext::allocators [C++], allocator_newdel
- stdext::allocator_newdel
ms.assetid: 62666cd2-3afe-49f7-9dd1-9bbbb154da98
caps.latest.revision: "18"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 430e55c1252eb1f1dabbdd39a6a72c76a14459a4
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="allocatornewdel-class"></a>Classe allocator_newdel
Implementa um alocador que usa `operator delete` para desalocar um bloco de memória e `operator new` para alocar um bloco de memória.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Type>  
class allocator_newdel;
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Type`|O tipo dos elementos alocados pelo alocador.|  
  
## <a name="remarks"></a>Comentários  
 A macro [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) passa essa classe como o parâmetro `name` na instrução a seguir: `ALLOCATOR_DECL(CACHE_FREELIST stdext::allocators::max_none), SYNC_DEFAULT, allocator_newdel);`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)



