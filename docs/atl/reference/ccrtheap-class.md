---
title: Classe CCRTHeap | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCRTHeap
- ATLMEM/ATL::CCRTHeap
- ATLMEM/ATL::CCRTHeap::Allocate
- ATLMEM/ATL::CCRTHeap::Free
- ATLMEM/ATL::CCRTHeap::GetSize
- ATLMEM/ATL::CCRTHeap::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- CCRTHeap class
ms.assetid: 321bd6c5-1856-4ff7-8590-95044a1209f7
caps.latest.revision: 19
author: mikeblome
ms.author: mblome
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 1b4df6949794981867051437835d043196613afa
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="ccrtheap-class"></a>Classe CCRTHeap
Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap CRT.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CCRTHeap : public IAtlMemMgr
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CCRTHeap::Allocate](#allocate)|Chame esse método para alocar um bloco de memória.|  
|[CCRTHeap::Free](#free)|Chame esse método para liberar um bloco de memória alocada por esse gerenciador de memória.|  
|[CCRTHeap::GetSize](#getsize)|Chame esse método para obter o tamanho alocado de um bloco de memória alocado por esse gerenciador de memória.|  
|[CCRTHeap::Reallocate](#reallocate)|Chame esse método para realocar a memória alocada por esse gerenciador de memória.|  
  
## <a name="remarks"></a>Comentários  
 `CCRTHeap`implementa funções, inclusive de pilha usando o CRT de funções de alocação de memória [malloc](../../c-runtime-library/reference/malloc.md), [livre](../../c-runtime-library/reference/free.md), [realloc](../../c-runtime-library/reference/realloc.md), e [msize](../../c-runtime-library/reference/msize.md).  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CCRTHeap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlmem. h  
  
##  <a name="allocate"></a>CCRTHeap::Allocate  
 Chame esse método para alocar um bloco de memória.  
  
```
virtual __declspec(allocator) void* Allocate(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número solicitado de bytes no novo bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o início do bloco de memória recém-alocada.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CCRTHeap::Free](#free) ou [CCRTHeap::Reallocate](#reallocate) para liberar a memória alocada por esse método.  
  
 Implementado usando [malloc](../../c-runtime-library/reference/malloc.md).  
  
##  <a name="free"></a>CCRTHeap::Free  
 Chame esse método para liberar um bloco de memória alocada por esse gerenciador de memória.  
  
```
virtual void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro de memória alocado anteriormente por este Gerenciador de memória. NULL é um valor válido e não faz nada.  
  
### <a name="remarks"></a>Comentários  
 Implementado usando [livre](../../c-runtime-library/reference/free.md).  
  
##  <a name="getsize"></a>CCRTHeap::GetSize  
 Chame esse método para obter o tamanho alocado de um bloco de memória alocado por esse gerenciador de memória.  
  
```
virtual size_t GetSize(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro de memória alocado anteriormente por este Gerenciador de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho do bloco de memória alocada em bytes.  
  
### <a name="remarks"></a>Comentários  
 Implementado usando [msize](../../c-runtime-library/reference/msize.md).  
  
##  <a name="reallocate"></a>CCRTHeap::Reallocate  
 Chame esse método para realocar a memória alocada por esse gerenciador de memória.  
  
```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro de memória alocado anteriormente por este Gerenciador de memória.  
  
 `nBytes`  
 O número solicitado de bytes no novo bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o início do bloco de memória recém-alocada.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CCRTHeap::Free](#free) para liberar a memória alocada por esse método. Implementado usando [realloc](../../c-runtime-library/reference/realloc.md).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComHeap](../../atl/reference/ccomheap-class.md)   
 [Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
 [Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)

