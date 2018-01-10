---
title: Classe allocator_chunklist | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::allocator_chunklist
- allocators/stdext::allocators::allocator_chunklist
dev_langs: C++
helpviewer_keywords:
- stdext::allocator_chunklist
- stdext::allocators [C++], allocator_chunklist
ms.assetid: ea72ed0a-dfdb-4c8b-8096-e4baf567b80f
caps.latest.revision: "20"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 70d882c98b3cfc14a536721d92a748487eabbeb2
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="allocatorchunklist-class"></a>Classe allocator_chunklist
Descreve um objeto que gerencia a alocação de armazenamento e a liberação de objetos usando um cache do tipo [cache_chunklist](../standard-library/cache-chunklist-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Type>  
class allocator_chunklist;
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Type`|O tipo dos elementos alocados pelo alocador.|  
  
## <a name="remarks"></a>Comentários  
 A macro [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) passa essa classe como o parâmetro `name` na instrução a seguir: `ALLOCATOR_DECL(CACHE_CHUNKLIST, SYNC_DEFAULT, allocator_chunklist);`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)



