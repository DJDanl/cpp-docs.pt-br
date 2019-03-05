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
ms.openlocfilehash: cba15421fd0329df7a66a35979ed54b863b7cca0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278295"
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
|[CGlobalHeap::Free](#free)|Chame esse método para liberar um bloco de memória alocada por este Gerenciador de memória.|
|[CGlobalHeap::GetSize](#getsize)|Chame esse método para obter o tamanho alocado de um bloco de memória alocado por este Gerenciador de memória.|
|[CGlobalHeap::Reallocate](#reallocate)|Chame esse método para realocar a memória alocada por este Gerenciador de memória.|

## <a name="remarks"></a>Comentários

`CGlobalHeap` implementa as funções de alocação de memória usando as funções de heap global do Win32.

> [!NOTE]
>  As funções de heap global mais lentas do que outras funções de gerenciamento de memória e não fornecem o máximo de recursos. Portanto, os novos aplicativos devem usar o [funções de heap](/windows/desktop/Memory/heap-functions). Eles estão disponíveis na [CWin32Heap](../../atl/reference/cwin32heap-class.md) classe. Funções globais ainda são usadas por DDE e as funções da área de transferência.

## <a name="example"></a>Exemplo

Veja o exemplo de [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

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
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória recém-alocada.

### <a name="remarks"></a>Comentários

Chame [CGlobalHeap::Free](#free) ou [CGlobalHeap::Reallocate](#reallocate) para liberar a memória alocada por esse método.

Implementado usando [GlobalAlloc](/windows/desktop/api/winbase/nf-winbase-globalalloc) com um parâmetro de sinalizador de GMEM_FIXED.

##  <a name="free"></a>  CGlobalHeap::Free

Chame esse método para liberar um bloco de memória alocada por este Gerenciador de memória.

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro de memória alocado anteriormente por este Gerenciador de memória. NULL é um valor válido e não faz nada.

### <a name="remarks"></a>Comentários

Implementado usando [GlobalFree](/windows/desktop/api/winbase/nf-winbase-globalfree).

##  <a name="getsize"></a>  CGlobalHeap::GetSize

Chame esse método para obter o tamanho alocado de um bloco de memória alocado por este Gerenciador de memória.

```
virtual size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro de memória alocado anteriormente por este Gerenciador de memória.

### <a name="return-value"></a>Valor de retorno

Retorna o tamanho do bloco de memória alocada em bytes.

### <a name="remarks"></a>Comentários

Implementado usando [GlobalSize](/windows/desktop/api/winbase/nf-winbase-globalsize).

##  <a name="reallocate"></a>  CGlobalHeap::Reallocate

Chame esse método para realocar a memória alocada por este Gerenciador de memória.

```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro de memória alocado anteriormente por este Gerenciador de memória.

*nBytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória recém-alocada.

### <a name="remarks"></a>Comentários

Chame [CGlobalHeap::Free](#free) para liberar a memória alocada por esse método.

Implementado usando [GlobalReAlloc](/windows/desktop/api/winbase/nf-winbase-globalrealloc).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComHeap](../../atl/reference/ccomheap-class.md)<br/>
[Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)<br/>
[Classe CLocalHeap](../../atl/reference/clocalheap-class.md)<br/>
[Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)<br/>
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
