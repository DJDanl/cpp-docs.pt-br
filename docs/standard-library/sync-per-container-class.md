---
title: Classe sync_per_container | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- stdext.sync_per_container
- sync_per_container
- stdext::sync_per_container
- allocators/stdext::sync_per_container
dev_langs:
- C++
helpviewer_keywords:
- sync_per_container class
ms.assetid: 0b4b2904-b668-4d94-a422-d4f919cbffab
caps.latest.revision: 21
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 0da4ce3b82517119b9b6ecc08129378b886fea40
ms.lasthandoff: 02/25/2017

---
# <a name="syncpercontainer-class"></a>Classe sync_per_container
Descreve um [filtro de sincronização](../standard-library/allocators-header.md) que fornece um objeto de cache separado para cada objeto alocador.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Cache>  
class sync_per_container
 : public Cache
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Cache`|O tipo de cache associado ao filtro de sincronização. Pode ser [cache_chunklist](../standard-library/cache-chunklist-class.md), [cache_freelist](../standard-library/cache-freelist-class.md) ou [cache_suballoc](../standard-library/cache-suballoc-class.md).|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[equals](#sync_per_container__equals)|Compara a igualdade de dois caches.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="a-namesyncpercontainerequalsa--syncpercontainerequals"></a><a name="sync_per_container__equals"></a>  sync_per_container::equals  
 Compara a igualdade de dois caches.  
  
```
bool equals(const sync_per_container<Cache>& Other) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Cache`|O objeto de cache do filtro de sincronização.|  
|`Other`|O objeto de cache a ser comparado quanto à igualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 A função membro sempre retorna `false`.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




