---
title: Classe CWin32Heap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CWin32Heap
- ATLMEM/ATL::CWin32Heap
- ATLMEM/ATL::CWin32Heap::CWin32Heap
- ATLMEM/ATL::CWin32Heap::Allocate
- ATLMEM/ATL::CWin32Heap::Attach
- ATLMEM/ATL::CWin32Heap::Detach
- ATLMEM/ATL::CWin32Heap::Free
- ATLMEM/ATL::CWin32Heap::GetSize
- ATLMEM/ATL::CWin32Heap::Reallocate
- ATLMEM/ATL::CWin32Heap::m_bOwnHeap
- ATLMEM/ATL::CWin32Heap::m_hHeap
dev_langs:
- C++
helpviewer_keywords:
- CWin32Heap class
ms.assetid: 69176022-ed98-4e3b-96d8-116b0c58ac95
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9b26d979ccb99d3d99bc91af03c4836603d31c01
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="cwin32heap-class"></a>Classe CWin32Heap
Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de heap de Win32.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
class CWin32Heap : public IAtlMemMgr
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWin32Heap::CWin32Heap](#cwin32heap)|O construtor.|  
|[CWin32Heap:: ~ CWin32Heap](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWin32Heap::Allocate](#allocate)|Aloca um bloco de memória do objeto heap.|  
|[CWin32Heap::Attach](#attach)|Anexa o objeto de pilha para um heap existente.|  
|[CWin32Heap::Detach](#detach)|Desanexa o objeto do heap de um heap existente.|  
|[CWin32Heap::Free](#free)|Libera a memória alocada anteriormente do heap.|  
|[CWin32Heap::GetSize](#getsize)|Retorna o tamanho de um bloco de memória alocado do objeto heap.|  
|[CWin32Heap::Reallocate](#reallocate)|Realoca um bloco de memória do objeto heap.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWin32Heap::m_bOwnHeap](#m_bownheap)|Um sinalizador usado para determinar a propriedade atual do identificador de heap.|  
|[CWin32Heap::m_hHeap](#m_hheap)|Identificador para o objeto do heap.|  
  
## <a name="remarks"></a>Comentários  
 `CWin32Heap` implementa métodos de alocação de memória usando as funções de alocação de heap do Win32, incluindo [HeapAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366597) e [HeapFree](http://msdn.microsoft.com/library/windows/desktop/aa366701). Ao contrário de outras classes de Heap `CWin32Heap` requer um identificador de heap válido para ser fornecidas antes que a memória é alocada: a outra classes usam como padrão o heap de processo. O identificador pode ser fornecido ao construtor, ou para o [CWin32Heap::Attach](#attach) método. Consulte o [CWin32Heap::CWin32Heap](#cwin32heap) método para obter mais detalhes.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `IAtlMemMgr`  
  
 `CWin32Heap`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlmem.h  
  
##  <a name="allocate"></a>  CWin32Heap::Allocate  
 Aloca um bloco de memória do objeto heap.  
  
```
virtual __declspec(allocator) void* Allocate(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número solicitado de bytes no novo bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o bloco de memória alocadas recentemente.  
  
### <a name="remarks"></a>Comentários  
 Chamar [CWin32Heap::Free](#free) ou [CWin32Heap::Reallocate](#reallocate) para liberar a memória alocada por esse método.  
  
 Implementado usando [HeapAlloc](http://msdn.microsoft.com/library/windows/desktop/aa366597).  
  
##  <a name="attach"></a>  CWin32Heap::Attach  
 Anexa o objeto de pilha para um heap existente.  
  
```
void Attach(HANDLE hHeap, bool bTakeOwnership) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `hHeap`  
 Um identificador de heap existente.  
  
 `bTakeOwnership`  
 Um caso de sinalizador que indica que o `CWin32Heap` objeto é apropriar-se sobre os recursos do heap.  
  
### <a name="remarks"></a>Comentários  
 Se `bTakeOwnership` for TRUE, o `CWin32Heap` objeto é responsável por excluir a alça de heap.  
  
##  <a name="cwin32heap"></a>  CWin32Heap::CWin32Heap  
 O construtor.  
  
```
CWin32Heap() throw();
CWin32Heap( HANDLE  hHeap) throw();
CWin32Heap(
    DWORD  dwFlags,
    size_t nInitialSize,
    size_t nMaxSize = 0);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hHeap`  
 Um objeto existente do heap.  
  
 `dwFlags`  
 Sinalizadores usados na criação do heap.  
  
 *nInitialSize*  
 O tamanho inicial do heap.  
  
 `nMaxSize`  
 O tamanho máximo do heap.  
  
### <a name="remarks"></a>Comentários  
 Antes de alocar memória, é necessário fornecer o objeto `CWin32Heap` com um identificador de heap válido. A maneira mais simples de fazer isso é usar o heap de processo:  
  
 [!code-cpp[NVC_ATL_Utilities#92](../../atl/codesnippet/cpp/cwin32heap-class_1.cpp)]  
  
 Também é possível fornecer um identificador de heap existente para o construtor, caso em que o novo objeto não assume a propriedade do heap. O identificador original do heap ainda será válido quando o objeto `CWin32Heap` for excluído.  
  
 Também pode ser anexado a um heap existente para o novo objeto, usando [CWin32Heap::Attach](#attach).  
  
 Se um heap for necessário onde todas as operações são executadas de um único thread, o melhor modo é criar o objeto como segue:  
  
 [!code-cpp[NVC_ATL_Utilities#93](../../atl/codesnippet/cpp/cwin32heap-class_2.cpp)]  
  
 O parâmetro **HEAP_NO_SERIALIZE** Especifica que a exclusão mútua não será usada quando as funções de heap alocam e liberar memória, com um acordo aumento no desempenho.  
  
 O terceiro parâmetro é padronizado como 0, o que permite que o heap aumente conforme necessário. Consulte [HeapCreate](http://msdn.microsoft.com/library/windows/desktop/aa366599\(v=vs.85\).aspx) para obter uma explicação dos tamanhos de memória e sinalizadores.  
  
##  <a name="dtor"></a>  CWin32Heap:: ~ CWin32Heap  
 O destruidor.  
  
```
~CWin32Heap() throw();
```  
  
### <a name="remarks"></a>Comentários  
 Destrói o identificador de heap se o `CWin32Heap` objeto tem a propriedade do heap.  
  
##  <a name="detach"></a>  CWin32Heap::Detach  
 Desanexa o objeto do heap de um heap existente.  
  
```
HANDLE Detach() throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o identificador para o heap ao qual o objeto foi anexado anteriormente.  
  
##  <a name="free"></a>  CWin32Heap::Free  
 Libera a memória alocada anteriormente do heap por [CWin32Heap::Allocate](#allocate) ou [CWin32Heap::Reallocate](#reallocate).  
  
```
virtual void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para o bloco de memória livre. NULL é um valor válido e não faz nada.  
  
##  <a name="getsize"></a>  CWin32Heap::GetSize  
 Retorna o tamanho de um bloco de memória alocado do objeto heap.  
  
```
virtual size_t GetSize(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para o bloco de memória cujo tamanho obterá o método. Esse é um ponteiro retornado por [CWin32Heap::Allocate](#allocate) ou [CWin32Heap::Reallocate](#reallocate).  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho, em bytes, do bloco de memória alocada.  
  
##  <a name="m_bownheap"></a>  CWin32Heap::m_bOwnHeap  
 Um sinalizador usado para determinar a propriedade atual do identificador de heap armazenado em [m_hHeap](#m_hheap).  
  
```
bool m_bOwnHeap;
```  
  
##  <a name="m_hheap"></a>  CWin32Heap::m_hHeap  
 Identificador para o objeto do heap.  
  
```
HANDLE m_hHeap;
```  
  
### <a name="remarks"></a>Comentários  
 Uma variável usada para armazenar um identificador para o objeto do heap.  
  
##  <a name="reallocate"></a>  CWin32Heap::Reallocate  
 Realoca um bloco de memória do objeto heap.  
  
```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para o bloco de memória para realocar.  
  
 `nBytes`  
 O novo tamanho em bytes do bloco alocado. O bloco pode ficar maior ou menor.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o bloco de memória alocadas recentemente.  
  
### <a name="remarks"></a>Comentários  
 Se `p` for NULL, presume-se que o bloco de memória ainda não foi alocado e [CWin32Heap::Allocate](#allocate) é chamado com um argumento de `nBytes`.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)   
 [Classe CLocalHeap](../../atl/reference/clocalheap-class.md)   
 [Classe CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
 [Classe CCRTHeap](../../atl/reference/ccrtheap-class.md)   
 [Classe CComHeap](../../atl/reference/ccomheap-class.md)
