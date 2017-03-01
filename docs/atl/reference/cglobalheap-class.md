---
title: Classe CGlobalHeap | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL.CGlobalHeap
- ATL::CGlobalHeap
- CGlobalHeap
dev_langs:
- C++
helpviewer_keywords:
- CGlobalHeap class
ms.assetid: e348d838-3aa7-4bee-a1b3-cd000c99f834
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
translationtype: Machine Translation
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: f8b4276202a507e2afeb05d10a37fa16565870e8
ms.lasthandoff: 02/25/2017

---
# <a name="cglobalheap-class"></a>Classe CGlobalHeap
Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap global do Win32.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CGlobalHeap : public IAtlMemMgr
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CGlobalHeap::Allocate](#allocate)|Chame esse método para alocar um bloco de memória.|  
|[CGlobalHeap::Free](#free)|Chame esse método para liberar um bloco de memória alocada por esse gerenciador de memória.|  
|[CGlobalHeap::GetSize](#getsize)|Chame esse método para obter o tamanho alocado de um bloco de memória alocado por esse gerenciador de memória.|  
|[CGlobalHeap::Reallocate](#reallocate)|Chame esse método para realocar a memória alocada por esse gerenciador de memória.|  
  
## <a name="remarks"></a>Comentários  
 `CGlobalHeap`implementa as funções de alocação de memória usando as funções de heap global do Win32.  
  
> [!NOTE]
>  As funções de heap global são mais lentas que outras funções de gerenciamento de memória e não oferecem tantos recursos. Portanto, os novos aplicativos devem usar o [heap funções](http://msdn.microsoft.com/library/windows/desktop/aa366711). Eles estão disponíveis na [CWin32Heap](../../atl/reference/cwin32heap-class.md) classe. Funções globais ainda são usadas por DDE e as funções da área de transferência.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CGlobalHeap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlmem. h  
  
##  <a name="a-nameallocatea--cglobalheapallocate"></a><a name="allocate"></a>CGlobalHeap::Allocate  
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
 Chamar [CGlobalHeap::Free](#free) ou [CGlobalHeap::Reallocate](#reallocate) para liberar a memória alocada por esse método.  
  
 Implementado usando [GlobalAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366574) com um parâmetro de sinalizador de **GMEM_FIXED**.  
  
##  <a name="a-namefreea--cglobalheapfree"></a><a name="free"></a>CGlobalHeap::Free  
 Chame esse método para liberar um bloco de memória alocada por esse gerenciador de memória.  
  
```
virtual void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro de memória alocado anteriormente por este Gerenciador de memória. NULL é um valor válido e não faz nada.  
  
### <a name="remarks"></a>Comentários  
 Implementado usando [GlobalFree](http://msdn.microsoft.com/library/windows/desktop/aa366579).  
  
##  <a name="a-namegetsizea--cglobalheapgetsize"></a><a name="getsize"></a>CGlobalHeap::GetSize  
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
 Implementado usando [GlobalSize](http://msdn.microsoft.com/library/windows/desktop/aa366593).  
  
##  <a name="a-namereallocatea--cglobalheapreallocate"></a><a name="reallocate"></a>CGlobalHeap::Reallocate  
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
 Chamar [CGlobalHeap::Free](#free) para liberar a memória alocada por esse método.  
  
 Implementado usando [GlobalReAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366590).  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe CComHeap](../../atl/reference/ccomheap-class.md)   
 [Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)   
 [Classe CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)

