---
title: Classe rts_alloc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::rts_alloc
- allocators/stdext::rts_alloc::allocate
- allocators/stdext::rts_alloc::deallocate
- allocators/stdext::rts_alloc::equals
dev_langs: C++
helpviewer_keywords:
- stdext::rts_alloc
- stdext::rts_alloc [C++], allocate
- stdext::rts_alloc [C++], deallocate
- stdext::rts_alloc [C++], equals
ms.assetid: ab41bffa-83d1-4a1c-87b9-5707d516931f
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2e4870edc0b54a92307ddf88d58dd96ca3fd331e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="rtsalloc-class"></a>Classe rts_alloc
A classe de modelo rts_alloc descreve um [filtro](../standard-library/allocators-header.md) que contém uma matriz de instâncias de cache e determina qual instância será usada para alocação e desalocação no tempo de execução, em vez de no tempo de compilação.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class Cache>  
class rts_alloc
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Cache`|O tipo de instâncias de cache contidas na matriz. Pode ser [cache_chunklist Class](../standard-library/cache-chunklist-class.md), [cache_freelist](../standard-library/cache-freelist-class.md) ou [cache_suballoc](../standard-library/cache-suballoc-class.md).|  
  
## <a name="remarks"></a>Comentários  
 Essa classe de modelo contém diversas instâncias de alocador de bloco e determina qual instância deve ser usada para alocação ou desalocação no tempo de execução, em vez de no tempo de compilação. Ele é usado com os compiladores que não podem compilar reassociação.  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocate](#allocate)|Aloca um bloco de memória.|  
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|  
|[equals](#equals)|Compara a igualdade de dois caches.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="allocate"></a>  rts_alloc::allocate  
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
 A função membro retorna `caches[_IDX].allocate(count)`, em que o índice `_IDX` é determinado pelo tamanho do bloco solicitado `count` ou, se `count` for muito grande, retornará `operator new(count)`. `cache`, que representa o objeto do cache.  
  
##  <a name="deallocate"></a>  rts_alloc::deallocate  
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
 A função membro chama `caches[_IDX].deallocate(ptr, count)`, em que o índice `_IDX` é determinado pelo tamanho do bloco solicitado `count` ou, se `count` for muito grande, retornará `operator delete(ptr)`.  
  
##  <a name="equals"></a>  rts_alloc::equals  
 Compara a igualdade de dois caches.  
  
```
bool equals(const sync<_Cache>& _Other) const;
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`_Cache`|O objeto de cache associado ao filtro.|  
|`_Other`|O objeto de cache a ser comparado quanto à igualdade.|  
  
### <a name="remarks"></a>Comentários  
 `true` se o resultado de `caches[0].equals(other.caches[0])`; caso contrário, `false`. `caches` representa a matriz de objetos do cache.  
  
## <a name="see-also"></a>Consulte também  
 [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl)   
 [\<allocators>](../standard-library/allocators-header.md)



