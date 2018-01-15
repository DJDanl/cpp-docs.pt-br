---
title: Classe CComHeap | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CComHeap
- ATLCOMMEM/ATL::CComHeap
- ATLCOMMEM/ATL::CComHeap::Allocate
- ATLCOMMEM/ATL::CComHeap::Free
- ATLCOMMEM/ATL::CComHeap::GetSize
- ATLCOMMEM/ATL::CComHeap::Reallocate
dev_langs: C++
helpviewer_keywords: CComHeap class
ms.assetid: c74183ce-98ae-46fb-b186-93ea4cf0222b
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 3cf86ebe45cdb0a70af6eebaaed90690e83e8db7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ccomheap-class"></a>Classe CComHeap
Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de memória COM.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CComHeap : public IAtlMemMgr
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComHeap::Allocate](#allocate)|Chame esse método para alocar um bloco de memória.|  
|[CComHeap::Free](#free)|Chame este método para liberar um bloco de memória alocada por este Gerenciador de memória.|  
|[CComHeap::GetSize](#getsize)|Chame este método para obter o tamanho alocado de um bloco de memória alocado por esse gerenciador de memória.|  
|[CComHeap::Reallocate](#reallocate)|Chame este método para realocar a memória alocada por esse gerenciador de memória.|  
  
## <a name="remarks"></a>Comentários  
 `CComHeap`implementa as funções de alocação de memória usando as funções de alocação COM, incluindo [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727), [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722), [IMalloc::GetSize](http://msdn.microsoft.com/library/windows/desktop/ms691226)e [CoTaskMemRealloc](http://msdn.microsoft.com/library/windows/desktop/ms687280). A quantidade máxima de memória que pode ser alocada é igual a **INT_MAX** (2147483647) bytes.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CComHeap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** ATLComMem.h  
  
##  <a name="allocate"></a>CComHeap::Allocate  
 Chame esse método para alocar um bloco de memória.  
  
```
virtual __declspec(allocator) void* Allocate(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número solicitado de bytes no novo bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o início do bloco de memória alocadas recentemente.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CComHeap::Free](#free) ou [CComHeap::Reallocate](#reallocate) para liberar a memória alocada por esse método.  
  
 Implementado usando [CoTaskMemAlloc](http://msdn.microsoft.com/library/windows/desktop/ms692727).  
  
##  <a name="free"></a>CComHeap::Free  
 Chame este método para liberar um bloco de memória alocada por este Gerenciador de memória.  
  
```
virtual void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória. NULL é um valor válido e não faz nada.  
  
### <a name="remarks"></a>Comentários  
 Implementado usando [CoTaskMemFree](http://msdn.microsoft.com/library/windows/desktop/ms680722).  
  
##  <a name="getsize"></a>CComHeap::GetSize  
 Chame este método para obter o tamanho alocado de um bloco de memória alocado por esse gerenciador de memória.  
  
```
virtual size_t GetSize(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho do bloco de memória alocada em bytes.  
  
### <a name="remarks"></a>Comentários  
 Implementado usando [IMalloc::GetSize](http://msdn.microsoft.com/library/windows/desktop/ms691226).  
  
##  <a name="reallocate"></a>CComHeap::Reallocate  
 Chame este método para realocar a memória alocada por esse gerenciador de memória.  
  
```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória.  
  
 `nBytes`  
 O número solicitado de bytes no novo bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o início do bloco de memória alocadas recentemente.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CComHeap::Free](#free) para liberar a memória alocada por esse método.  
  
 Implementado usando [CoTaskMemRealloc](http://msdn.microsoft.com/library/windows/desktop/ms687280).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de DynamicConsumer](../../visual-cpp-samples.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
 [Classe CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
