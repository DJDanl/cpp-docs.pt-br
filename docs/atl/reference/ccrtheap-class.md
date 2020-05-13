---
title: Classe CCRTHeap
ms.date: 11/04/2016
f1_keywords:
- CCRTHeap
- ATLMEM/ATL::CCRTHeap
- ATLMEM/ATL::CCRTHeap::Allocate
- ATLMEM/ATL::CCRTHeap::Free
- ATLMEM/ATL::CCRTHeap::GetSize
- ATLMEM/ATL::CCRTHeap::Reallocate
helpviewer_keywords:
- CCRTHeap class
ms.assetid: 321bd6c5-1856-4ff7-8590-95044a1209f7
ms.openlocfilehash: caf5508079332689c2fff42f130951375dc35512
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327157"
---
# <a name="ccrtheap-class"></a>Classe CCRTHeap

Esta classe [implementa o IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap CRT.

## <a name="syntax"></a>Sintaxe

```
class CCRTHeap : public IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCRTHeap::Alocar](#allocate)|Chame este método para alocar um bloco de memória.|
|[CCRTHeap::Grátis](#free)|Chame este método para liberar um bloco de memória alocado por este gerenciador de memória.|
|[CCRTHeap::getSize](#getsize)|Chame este método para obter o tamanho alocado de um bloco de memória alocado por este gerenciador de memória.|
|[CCRTHeap:::Realocação](#reallocate)|Chame este método para realocar a memória alocada por este gerenciador de memória.|

## <a name="remarks"></a>Comentários

`CCRTHeap`implementa funções de alocação de memória usando as funções de pilha CRT, incluindo [malloc](../../c-runtime-library/reference/malloc.md), [free](../../c-runtime-library/reference/free.md), [realloc](../../c-runtime-library/reference/realloc.md)e [_msize](../../c-runtime-library/reference/msize.md).

## <a name="example"></a>Exemplo

Veja o exemplo [de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlMemMgr`

`CCRTHeap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem.h

## <a name="ccrtheapallocate"></a><a name="allocate"></a>CCRTHeap::Alocar

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

Ligue para [o CCRTHeap::Free](#free) ou [CCRTHeap::Reallocate](#reallocate) para liberar a memória alocada por este método.

Implementado usando [malloc](../../c-runtime-library/reference/malloc.md).

## <a name="ccrtheapfree"></a><a name="free"></a>CCRTHeap::Grátis

Chame este método para liberar um bloco de memória alocado por este gerenciador de memória.

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória. NULL é um valor válido e não faz nada.

### <a name="remarks"></a>Comentários

Implementado usando [gratuitamente](../../c-runtime-library/reference/free.md).

## <a name="ccrtheapgetsize"></a><a name="getsize"></a>CCRTHeap::getSize

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

Implementado com [_msize](../../c-runtime-library/reference/msize.md).

## <a name="ccrtheapreallocate"></a><a name="reallocate"></a>CCRTHeap:::Realocação

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

Ligue para [o CCRTHeap::Grátis](#free) para liberar a memória alocada por este método. Implementado usando [realloc](../../c-runtime-library/reference/realloc.md).

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CcomHeap](../../atl/reference/ccomheap-class.md)<br/>
[Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)<br/>
[Classe CLocalHeap](../../atl/reference/clocalheap-class.md)<br/>
[Classe CglobalHeap](../../atl/reference/cglobalheap-class.md)<br/>
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
