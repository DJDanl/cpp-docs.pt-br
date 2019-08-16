---
title: Classe CGlobalHeap
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
ms.openlocfilehash: 2b5aa09357ddcc77b6b10de58545bea86eff2488
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69496757"
---
# <a name="cglobalheap-class"></a>Classe CGlobalHeap

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap global do Win32.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CGlobalHeap : public IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CGlobalHeap::Allocate](#allocate)|Chame esse método para alocar um bloco de memória.|
|[CGlobalHeap::Free](#free)|Chame esse método para liberar um bloco de memória alocado por esse Gerenciador de memória.|
|[CGlobalHeap::GetSize](#getsize)|Chame esse método para obter o tamanho alocado de um bloco de memória alocado por esse Gerenciador de memória.|
|[CGlobalHeap::Reallocate](#reallocate)|Chame esse método para realocar memória alocada por esse Gerenciador de memória.|

## <a name="remarks"></a>Comentários

`CGlobalHeap`implementa funções de alocação de memória usando as funções de heap global do Win32.

> [!NOTE]
>  As funções de heap global são mais lentas do que outras funções de gerenciamento de memória e não fornecem quantos recursos. Portanto, novos aplicativos devem usar as [funções de heap](/windows/win32/Memory/heap-functions). Eles estão disponíveis na classe [CWin32Heap](../../atl/reference/cwin32heap-class.md) . As funções globais ainda são usadas pelo DDE e pelas funções da área de transferência.

## <a name="example"></a>Exemplo

Consulte o exemplo de [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlMemMgr`

`CGlobalHeap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem. h

##  <a name="allocate"></a>  CGlobalHeap::Allocate

Chame esse método para alocar um bloco de memória.

```
virtual __declspec(allocator) void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*nBytes*<br/>
O número de bytes solicitado no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória alocado recentemente.

### <a name="remarks"></a>Comentários

Chame [CGlobalHeap:: Free](#free) ou [CGlobalHeap:: realoque](#reallocate) para liberar a memória alocada por esse método.

Implementado usando [GlobalAlloc](/windows/win32/api/winbase/nf-winbase-globalalloc) com um parâmetro de sinalizador de GMEM_FIXED.

##  <a name="free"></a>  CGlobalHeap::Free

Chame esse método para liberar um bloco de memória alocado por esse Gerenciador de memória.

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória. NULL é um valor válido e não faz nada.

### <a name="remarks"></a>Comentários

Implementado usando [GlobalFree](/windows/win32/api/winbase/nf-winbase-globalfree).

##  <a name="getsize"></a>  CGlobalHeap::GetSize

Chame esse método para obter o tamanho alocado de um bloco de memória alocado por esse Gerenciador de memória.

```
virtual size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória.

### <a name="return-value"></a>Valor de retorno

Retorna o tamanho do bloco de memória alocado em bytes.

### <a name="remarks"></a>Comentários

Implementado usando [GlobalSize](/windows/win32/api/winbase/nf-winbase-globalsize).

##  <a name="reallocate"></a>  CGlobalHeap::Reallocate

Chame esse método para realocar memória alocada por esse Gerenciador de memória.

```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória.

*nBytes*<br/>
O número de bytes solicitado no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória alocado recentemente.

### <a name="remarks"></a>Comentários

Chame [CGlobalHeap:: Free](#free) para liberar a memória alocada por este método.

Implementado usando [GlobalRealloc](/windows/win32/api/winbase/nf-winbase-globalrealloc).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComHeap](../../atl/reference/ccomheap-class.md)<br/>
[Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)<br/>
[Classe CLocalHeap](../../atl/reference/clocalheap-class.md)<br/>
[Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)<br/>
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
