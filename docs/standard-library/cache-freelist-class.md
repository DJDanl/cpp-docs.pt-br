---
title: cache_freelist Class | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- allocators/stdext::cache_freelist
- allocators/stdext::cache_freelist::allocate
- allocators/stdext::cache_freelist::deallocate
dev_langs: C++
helpviewer_keywords:
- stdext::cache_freelist
- stdext::cache_freelist [C++], allocate
- stdext::cache_freelist [C++], deallocate
ms.assetid: 840694de-36ba-470f-8dae-2b723d5a8cd9
caps.latest.revision: "19"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: c971a4aebcd0f0a7c0baa59a445059f681f7e8af
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cachefreelist-class"></a>Classe cache_freelist
Define um [alocador de blocos](../standard-library/allocators-header.md) que aloca e desaloca os blocos de memória de um único tamanho.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <std::size_t Sz, class Max>  
class cache_freelist
```  
  
#### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|`Sz`|O número de elementos na matriz a serem alocados.|  
|`Max`|A classe max que representa o tamanho máximo da lista livre. Isso pode ser [max_fixed_size](../standard-library/max-fixed-size-class.md), [max_none](../standard-library/max-none-class.md), [max_unbounded](../standard-library/max-unbounded-class.md) ou [max_variable_size](../standard-library/max-variable-size-class.md).|  
  
## <a name="remarks"></a>Comentários  
 A classe de modelo cache_freelist mantém uma lista livre de blocos de memória do tamanho `Sz`. Quando a lista livre estiver cheia, ele usará `operator delete` para desalocar blocos de memória. Quando a lista livre estiver vazia, ela usará `operator new` para alocar novos blocos de memória. O tamanho máximo da lista livre é determinado pela classe de classe máxima passado no parâmetro `Max`.  
  
 Cada bloco de memória contém `Sz` bytes de memória utilizável e os dados que `operator new` e `operator delete` exigem.  
  
### <a name="constructors"></a>Construtores  
  
|||  
|-|-|  
|[cache_freelist](#cache_freelist)|Constrói um objeto do tipo `cache_freelist`.|  
  
### <a name="member-functions"></a>Funções membro  
  
|||  
|-|-|  
|[allocate](#allocate)|Aloca um bloco de memória.|  
|[deallocate](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<allocators>  
  
 **Namespace:** stdext  
  
##  <a name="allocate"></a>  cache_freelist::allocate  
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
  
##  <a name="cache_freelist"></a>  cache_freelist::cache_freelist  
 Constrói um objeto do tipo `cache_freelist`.  
  
```
cache_freelist();
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="deallocate"></a>  cache_freelist::deallocate  
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
  
## <a name="see-also"></a>Consulte também  
 [\<allocators>](../standard-library/allocators-header.md)



