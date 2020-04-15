---
title: Classe CglobalHeap
ms.date: 11/04/2016
f1_keywords:
- CGlobalHeap
- ATLMEM/ATL::CGlobalHeap
- ATLMEM/ATL::CGlobalHeap::Allocate
- ATLMEM/ATL::CGlobalHeap::Free
- ATLMEM/ATL::CGlobalHeap::GetSize
- ATLMEM/ATL::CGlobalHeap::Reallocate
helpviewer_keywords:
- CGlobalHeap class
ms.assetid: e348d838-3aa7-4bee-a1b3-cd000c99f834
ms.openlocfilehash: d596fd51c1bf33f606c1f14c9e8dbd2f1926c7f8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326934"
---
# <a name="cglobalheap-class"></a>Classe CglobalHeap

Esta classe implementa [o IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap global Win32.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CGlobalHeap : public IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CGlobalHeap::Alocar](#allocate)|Chame este método para alocar um bloco de memória.|
|[CGlobalHeap::Grátis](#free)|Chame este método para liberar um bloco de memória alocado por este gerenciador de memória.|
|[CglobalHeap::getSize](#getsize)|Chame este método para obter o tamanho alocado de um bloco de memória alocado por este gerenciador de memória.|
|[CGlobalHeap::Realocação](#reallocate)|Chame este método para realocar a memória alocada por este gerenciador de memória.|

## <a name="remarks"></a>Comentários

`CGlobalHeap`implementa funções de alocação de memória usando as funções de heap global Win32.

> [!NOTE]
> As funções globais de pilha são mais lentas do que outras funções de gerenciamento de memória e não fornecem tantos recursos. Portanto, novas aplicações devem usar as [funções de pilha.](/windows/win32/Memory/heap-functions) Estes estão disponíveis na classe [CWin32Heap.](../../atl/reference/cwin32heap-class.md) As funções globais ainda são usadas pelo DDE e pelas funções da área de transferência.

## <a name="example"></a>Exemplo

Veja o exemplo [de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlMemMgr`

`CGlobalHeap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem.h

## <a name="cglobalheapallocate"></a><a name="allocate"></a>CGlobalHeap::Alocar

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

Ligue para [CGlobalHeap::Free](#free) ou [CGlobalHeap::Reallocate](#reallocate) para liberar a memória alocada por este método.

Implementado usando [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) com um parâmetro de bandeira de GMEM_FIXED.

## <a name="cglobalheapfree"></a><a name="free"></a>CGlobalHeap::Grátis

Chame este método para liberar um bloco de memória alocado por este gerenciador de memória.

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória. NULL é um valor válido e não faz nada.

### <a name="remarks"></a>Comentários

Implementado usando [globalfree](/windows/win32/api/winbase/nf-winbase-globalfree).

## <a name="cglobalheapgetsize"></a><a name="getsize"></a>CglobalHeap::getSize

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

Implementado usando [o GlobalSize](/windows/win32/api/winbase/nf-winbase-globalsize).

## <a name="cglobalheapreallocate"></a><a name="reallocate"></a>CGlobalHeap::Realocação

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

Ligue para [CGlobalHeap:::Grátis](#free) para liberar a memória alocada por este método.

Implementado usando [GlobalReAlloc](/windows/win32/api/winbase/nf-winbase-globalrealloc).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CcomHeap](../../atl/reference/ccomheap-class.md)<br/>
[Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)<br/>
[Classe CLocalHeap](../../atl/reference/clocalheap-class.md)<br/>
[Classe CCRTHeap](../../atl/reference/ccrtheap-class.md)<br/>
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
