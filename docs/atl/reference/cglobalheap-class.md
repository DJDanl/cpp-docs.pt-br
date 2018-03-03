---
title: Classe CGlobalHeap | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CGlobalHeap
- ATLMEM/ATL::CGlobalHeap
- ATLMEM/ATL::CGlobalHeap::Allocate
- ATLMEM/ATL::CGlobalHeap::Free
- ATLMEM/ATL::CGlobalHeap::GetSize
- ATLMEM/ATL::CGlobalHeap::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- CGlobalHeap class
ms.assetid: e348d838-3aa7-4bee-a1b3-cd000c99f834
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 566d9fac60f082b8dbf46724b463a9ac07732449
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cglobalheap-class"></a>Classe CGlobalHeap
Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de pilha global do Win32.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CGlobalHeap : public IAtlMemMgr
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGlobalHeap::Allocate](#allocate)|Chame esse método para alocar um bloco de memória.|  
|[CGlobalHeap::Free](#free)|Chame este método para liberar um bloco de memória alocada por este Gerenciador de memória.|  
|[CGlobalHeap::GetSize](#getsize)|Chame este método para obter o tamanho alocado de um bloco de memória alocado por esse gerenciador de memória.|  
|[CGlobalHeap::Reallocate](#reallocate)|Chame este método para realocar a memória alocada por esse gerenciador de memória.|  
  
## <a name="remarks"></a>Comentários  
 `CGlobalHeap`implementa funções de alocação de memória usando as funções de pilha global do Win32.  
  
> [!NOTE]
>  As funções de pilha global mais lentas do que outras funções de gerenciamento de memória e não fornecem como muitos recursos. Portanto, os novos aplicativos devem usar o [heap funções](http://msdn.microsoft.com/library/windows/desktop/aa366711). Eles estão disponíveis no [CWin32Heap](../../atl/reference/cwin32heap-class.md) classe. Funções globais ainda são usadas por DDE e as funções de área de transferência.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CGlobalHeap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlmem.h  
  
##  <a name="allocate"></a>CGlobalHeap::Allocate  
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
 Chamar [CGlobalHeap::Free](#free) ou [CGlobalHeap::Reallocate](#reallocate) para liberar a memória alocada por esse método.  
  
 Implementado usando [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574) com um parâmetro de sinalizador de **GMEM_FIXED**.  
  
##  <a name="free"></a>CGlobalHeap::Free  
 Chame este método para liberar um bloco de memória alocada por este Gerenciador de memória.  
  
```
virtual void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória. NULL é um valor válido e não faz nada.  
  
### <a name="remarks"></a>Comentários  
 Implementado usando [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579).  
  
##  <a name="getsize"></a>CGlobalHeap::GetSize  
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
 Implementado usando [GlobalSize](http://msdn.microsoft.com/library/windows/desktop/aa366593).  
  
##  <a name="reallocate"></a>CGlobalHeap::Reallocate  
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
 Chamar [CGlobalHeap::Free](#free) para liberar a memória alocada por esse método.  
  
 Implementado usando [GlobalReAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366590).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComHeap](../../atl/reference/ccomheap-class.md)   
 [Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
