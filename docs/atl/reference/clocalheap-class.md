---
title: Classe CLocalHeap
ms.date: 11/04/2016
f1_keywords:
- CLocalHeap
- ATLMEM/ATL::CLocalHeap
- ATLMEM/ATL::CLocalHeap::Allocate
- ATLMEM/ATL::CLocalHeap::Free
- ATLMEM/ATL::CLocalHeap::GetSize
- ATLMEM/ATL::CLocalHeap::Reallocate
helpviewer_keywords:
- CLocalHeap class
ms.assetid: 1ffa87a5-5fc8-4f8d-8809-58e87e963bd2
ms.openlocfilehash: 303e3b85ad11c309f862f59d6ec610701c4ef6db
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326752"
---
# <a name="clocalheap-class"></a>Classe CLocalHeap

Esta classe implementa [o IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de pilha local Win32.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CLocalHeap : public IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CLocalHeap::Alocar](#allocate)|Chame este método para alocar um bloco de memória.|
|[CLocalHeap::Grátis](#free)|Chame este método para liberar um bloco de memória alocado por este gerenciador de memória.|
|[CLocalHeap::GetSize](#getsize)|Chame este método para obter o tamanho alocado de um bloco de memória alocado por este gerenciador de memória.|
|[CLocalHeap::Realocação](#reallocate)|Chame este método para realocar a memória alocada por este gerenciador de memória.|

## <a name="remarks"></a>Comentários

`CLocalHeap`implementa funções de alocação de memória usando as funções de heap locais Win32.

> [!NOTE]
> As funções de pilha local são mais lentas do que outras funções de gerenciamento de memória e não fornecem tantos recursos. Portanto, novas aplicações devem usar as [funções de pilha.](/windows/win32/Memory/heap-functions) Estes estão disponíveis na classe [CWin32Heap.](../../atl/reference/cwin32heap-class.md)

## <a name="example"></a>Exemplo

Veja o exemplo [de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlMemMgr`

`CLocalHeap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem.h

## <a name="clocalheapallocate"></a><a name="allocate"></a>CLocalHeap::Alocar

Chame este método para alocar um bloco de memória.

```
virtual __declspec(allocator) void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória recém-alocado.

### <a name="remarks"></a>Comentários

Ligue para [CLocalHeap::Free](#free) ou [CLocalHeap::Reallocate](#reallocate) para liberar a memória alocada por este método.

Implementado usando [LocalAlloc](/windows/win32/api/winbase/nf-winbase-localalloc) com um parâmetro de bandeira de LMEM_FIXED.

## <a name="clocalheapfree"></a><a name="free"></a>CLocalHeap::Grátis

Chame este método para liberar um bloco de memória alocado por este gerenciador de memória.

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória. NULL é um valor válido e não faz nada.

### <a name="remarks"></a>Comentários

Implementado usando [LocalFree](/windows/win32/api/winbase/nf-winbase-localfree).

## <a name="clocalheapgetsize"></a><a name="getsize"></a>CLocalHeap::GetSize

Chame este método para obter o tamanho alocado de um bloco de memória alocado por este gerenciador de memória.

```
virtual size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória.

### <a name="return-value"></a>Valor retornado

Retorna o tamanho do bloco de memória alocado em bytes.

### <a name="remarks"></a>Comentários

Implementado usando [localsize](/windows/win32/api/winbase/nf-winbase-localsize).

## <a name="clocalheapreallocate"></a><a name="reallocate"></a>CLocalHeap::Realocação

Chame este método para realocar a memória alocada por este gerenciador de memória.

```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória.

*Nbytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória recém-alocado.

### <a name="remarks"></a>Comentários

Ligue para [CLocalHeap:::Grátis](#free) para liberar a memória alocada por este método.

Implementado usando [LocalReAlloc](/windows/win32/api/winbase/nf-winbase-localrealloc).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CcomHeap](../../atl/reference/ccomheap-class.md)<br/>
[Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)<br/>
[Classe CglobalHeap](../../atl/reference/cglobalheap-class.md)<br/>
[Classe CCRTHeap](../../atl/reference/ccrtheap-class.md)<br/>
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
