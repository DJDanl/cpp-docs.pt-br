---
title: Classe sync_shared | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- sync_shared
- allocators/stdext::sync_shared
- stdext.sync_shared
- stdext::sync_shared
dev_langs:
- C++
helpviewer_keywords:
- sync_shared class
ms.assetid: cab3af9e-3d1a-4f2c-8580-0f89e5687d8e
caps.latest.revision: 19
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b510fbe0b93f97222a093007300a3b3d054d1505
ms.lasthandoff: 02/25/2017

---
# <a name="syncshared-class"></a>Classe sync_shared
Descreve um [filtro de sincronização](../standard-library/allocators-header.md) que usa um mutex para controlar o acesso a um objeto de cache que é compartilhado por todos os alocadores.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Cache>  
class sync_shared
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Cache`|O tipo de cache associado ao filtro de sincronização. Pode ser [cache_chunklist](../standard-library/cache-chunklist-class.md), [cache_freelist](../standard-library/cache-freelist-class.md) ou [cache_suballoc](../standard-library/cache-suballoc-class.md).|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocate](#sync_shared__allocate)|Aloca um bloco de memória.|  
|[deallocate](#sync_shared__deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|  
|[equals](#sync_shared__equals)|Compara a igualdade de dois caches.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="a-namesyncsharedallocatea--syncsharedallocate"></a><a name="sync_shared__allocate"></a>  sync_shared::allocate  
 Aloca um bloco de memória.  
  
```
void *allocate(std::size_t count);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`count`|O número de elementos na matriz a serem alocados.|  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o objeto alocado.  
  
### <a name="remarks"></a>Comentários  
 A função membro bloqueia o mutex, chama `cache.allocate(count)`, desbloqueia o mutex e retorna o resultado da chamada anterior a `cache.allocate(count)`. `cache` representa o objeto de cache atual.  
  
##  <a name="a-namesyncshareddeallocatea--syncshareddeallocate"></a><a name="sync_shared__deallocate"></a>  sync_shared::deallocate  
 Libera um número especificado de objetos do armazenamento começando em uma posição especificada.  
  
```
void deallocate(void* ptr, std::size_t count);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`ptr`|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|  
|`count`|O número de objetos a serem desalocados do armazenamento.|  
  
### <a name="remarks"></a>Comentários  
 Essa função membro bloqueia o mutex, chama `cache.deallocate(ptr, count)`, em que `cache` representa o objeto de cache e, em seguida, desbloqueia o mutex.  
  
##  <a name="a-namesyncsharedequalsa--syncsharedequals"></a><a name="sync_shared__equals"></a>  sync_shared::equals  
 Compara a igualdade de dois caches.  
  
```
bool equals(const sync_shared<Cache>& Other) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Cache`|O tipo de cache associado ao filtro de sincronização.|  
|`Other`|O cache a ser comparado quanto à igualdade.|  
  
### <a name="return-value"></a>Valor de retorno  
 `true` se o resultado de `cache.equals(Other.cache)`, em que `cache` representa o objeto de cache, for `true`; caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)




