---
title: Classe CWin32Heap
ms.date: 11/04/2016
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
helpviewer_keywords:
- CWin32Heap class
ms.assetid: 69176022-ed98-4e3b-96d8-116b0c58ac95
ms.openlocfilehash: 2d79de308b1afb3059cf04ad40b63b6e603073c8
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81746038"
---
# <a name="cwin32heap-class"></a>Classe CWin32Heap

Esta classe implementa [o IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de heap Win32.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CWin32Heap : public IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CWin32Heap::CWin32Heap](#cwin32heap)|O construtor.|
|[CWin32Heap::~Cwin32Heap](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CWin32Heap::Alocar](#allocate)|Aloca um bloco de memória do objeto heap.|
|[CWin32Heap::Anexar](#attach)|Anexa o objeto de pilha a um monte existente.|
|[CWin32Heap::Detach](#detach)|Destaca o objeto de pilha de um monte existente.|
|[CWin32Heap::Grátis](#free)|Libera a memória anteriormente alocada do monte.|
|[CWin32Heap::GetSize](#getsize)|Retorna o tamanho de um bloco de memória alocado a partir do objeto heap.|
|[CWin32Heap::Realocação](#reallocate)|Realoca um bloco de memória do objeto heap.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CWin32Heap::m_bOwnHeap](#m_bownheap)|Uma bandeira usada para determinar a propriedade atual da alça de pilha.|
|[CWin32Heap::m_hHeap](#m_hheap)|Manuseie o objeto de pilha.|

## <a name="remarks"></a>Comentários

`CWin32Heap`implementa métodos de alocação de memória usando as funções de alocação de pilha sinuosas do Win32, incluindo [HeapAlloc](/windows/win32/api/heapapi/nf-heapapi-heapalloc) e [HeapFree](/windows/win32/api/heapapi/nf-heapapi-heapfree). Ao contrário de `CWin32Heap` outras classes heap, requer que uma alça de pilha válida seja fornecida antes da memória ser alocada: as outras classes padrão para usar o heap de processo. A alça pode ser fornecida ao construtor ou ao método [CWin32Heap::Attach.](#attach) Consulte o método [CWin32Heap::CWin32Heap](#cwin32heap) para obter mais detalhes.

## <a name="example"></a>Exemplo

Veja o exemplo [de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlMemMgr`

`CWin32Heap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem.h

## <a name="cwin32heapallocate"></a><a name="allocate"></a>CWin32Heap::Alocar

Aloca um bloco de memória do objeto heap.

```
virtual __declspec(allocator) void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o bloco de memória recém-alocado.

### <a name="remarks"></a>Comentários

Ligue para [CWin32Heap:::Free](#free) ou [CWin32Heap::Reallocate](#reallocate) para liberar a memória alocada por este método.

Implementado usando [HeapAlloc](/windows/win32/api/heapapi/nf-heapapi-heapalloc).

## <a name="cwin32heapattach"></a><a name="attach"></a>CWin32Heap::Anexar

Anexa o objeto de pilha a um monte existente.

```cpp
void Attach(HANDLE hHeap, bool bTakeOwnership) throw();
```

### <a name="parameters"></a>Parâmetros

*Hheap*<br/>
Uma alça de pilha existente.

*bTakeOwnership*<br/>
Uma bandeira indicando `CWin32Heap` se o objetivo é tomar posse sobre os recursos da pilha.

### <a name="remarks"></a>Comentários

Se *bTakeOwnership* for `CWin32Heap` TRUE, o objeto será responsável pela exclusão da alça de pilha.

## <a name="cwin32heapcwin32heap"></a><a name="cwin32heap"></a>CWin32Heap::CWin32Heap

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

*Hheap*<br/>
Um objeto existente do heap.

*dwFlags*<br/>
Sinalizadores usados na criação do heap.

*{1&amp;gt;nInitialSize&amp;lt;1}*<br/>
O tamanho inicial do heap.

*nMaxSize*<br/>
O tamanho máximo do heap.

### <a name="remarks"></a>Comentários

Antes de alocar memória, é necessário fornecer o objeto `CWin32Heap` com um identificador de heap válido. A maneira mais simples de fazer isso é usar o heap de processo:

[!code-cpp[NVC_ATL_Utilities#92](../../atl/codesnippet/cpp/cwin32heap-class_1.cpp)]

Também é possível fornecer um identificador de heap existente para o construtor, caso em que o novo objeto não assume a propriedade do heap. O identificador original do heap ainda será válido quando o objeto `CWin32Heap` for excluído.

Um heap existente também pode ser anexado ao novo objeto, usando [CWin32Heap::Attach](#attach).

Se um heap for necessário onde todas as operações são executadas de um único thread, o melhor modo é criar o objeto como segue:

[!code-cpp[NVC_ATL_Utilities#93](../../atl/codesnippet/cpp/cwin32heap-class_2.cpp)]

O parâmetro HEAP_NO_SERIALIZE especifica que a exclusão mútua não será usada quando as funções do heap alocarem e liberarem memória, com um aumento no desempenho consistente.

O terceiro parâmetro é padronizado como 0, o que permite que o heap aumente conforme necessário. Consulte [HeapCreate](/windows/win32/api/heapapi/nf-heapapi-heapcreate) para obter uma explicação sobre os tamanhos e bandeiras da memória.

## <a name="cwin32heapcwin32heap"></a><a name="dtor"></a>CWin32Heap::~Cwin32Heap

O destruidor.

```
~CWin32Heap() throw();
```

### <a name="remarks"></a>Comentários

Destrói a alça do `CWin32Heap` monte se o objeto tiver a posse do monte.

## <a name="cwin32heapdetach"></a><a name="detach"></a>CWin32Heap::Detach

Destaca o objeto de pilha de um monte existente.

```
HANDLE Detach() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna a alça ao heap ao qual o objeto foi previamente anexado.

## <a name="cwin32heapfree"></a><a name="free"></a>CWin32Heap::Grátis

Libera a memória anteriormente alocada do heap por [CWin32Heap::Alocar](#allocate) ou [CWin32Heap::Realocar](#reallocate).

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para o bloco de memória para libertar. NULL é um valor válido e não faz nada.

## <a name="cwin32heapgetsize"></a><a name="getsize"></a>CWin32Heap::GetSize

Retorna o tamanho de um bloco de memória alocado a partir do objeto heap.

```
virtual size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para o bloco de memória cujo tamanho o método obterá. Este é um ponteiro retornado por [CWin32Heap::Alocar](#allocate) ou [CWin32Heap:::Realocar](#reallocate).

### <a name="return-value"></a>Valor retornado

Retorna o tamanho, em bytes, do bloco de memória alocado.

## <a name="cwin32heapm_bownheap"></a><a name="m_bownheap"></a>CWin32Heap::m_bOwnHeap

Uma bandeira usada para determinar a propriedade atual da alça de pilha armazenada em [m_hHeap](#m_hheap).

```
bool m_bOwnHeap;
```

## <a name="cwin32heapm_hheap"></a><a name="m_hheap"></a>CWin32Heap::m_hHeap

Manuseie o objeto de pilha.

```
HANDLE m_hHeap;
```

### <a name="remarks"></a>Comentários

Uma variável usada para armazenar uma alça para o objeto de pilha.

## <a name="cwin32heapreallocate"></a><a name="reallocate"></a>CWin32Heap::Realocação

Realoca um bloco de memória do objeto heap.

```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para o bloco de memória para realocar.

*Nbytes*<br/>
O novo tamanho em bytes do bloco alocado. O bloco pode ser feito maior ou menor.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o bloco de memória recém-alocado.

### <a name="remarks"></a>Comentários

Se *p* for NULL, presume-se que o bloco de memória ainda não foi alocado e [CWin32Heap::Alocar](#allocate) é chamado, com um argumento de *nBytes*.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)<br/>
[Classe CLocalHeap](../../atl/reference/clocalheap-class.md)<br/>
[Classe CglobalHeap](../../atl/reference/cglobalheap-class.md)<br/>
[Classe CCRTHeap](../../atl/reference/ccrtheap-class.md)<br/>
[Classe CcomHeap](../../atl/reference/ccomheap-class.md)
