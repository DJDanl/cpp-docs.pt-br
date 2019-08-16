---
title: Classe CComHeap
ms.date: 11/04/2016
f1_keywords:
- CComHeap
- ATLCOMMEM/ATL::CComHeap
- ATLCOMMEM/ATL::CComHeap::Allocate
- ATLCOMMEM/ATL::CComHeap::Free
- ATLCOMMEM/ATL::CComHeap::GetSize
- ATLCOMMEM/ATL::CComHeap::Reallocate
helpviewer_keywords:
- CComHeap class
ms.assetid: c74183ce-98ae-46fb-b186-93ea4cf0222b
ms.openlocfilehash: 1ded73047b895a44a22bdd5730886f7fc088c77a
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497342"
---
# <a name="ccomheap-class"></a>Classe CComHeap

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de alocação de memória com.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
class CComHeap : public IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComHeap::Allocate](#allocate)|Chame esse método para alocar um bloco de memória.|
|[CComHeap::Free](#free)|Chame esse método para liberar um bloco de memória alocado por esse Gerenciador de memória.|
|[CComHeap::GetSize](#getsize)|Chame esse método para obter o tamanho alocado de um bloco de memória alocado por esse Gerenciador de memória.|
|[CComHeap::Reallocate](#reallocate)|Chame esse método para realocar memória alocada por esse Gerenciador de memória.|

## <a name="remarks"></a>Comentários

`CComHeap`implementa as funções de alocação de memória usando as funções de alocação COM, incluindo [CoTaskMemAlloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc), [CoTaskMemFree](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree), [IMalloc:: GetSize](/windows/win32/api/objidlbase/nf-objidlbase-imalloc-getsize)e [CoTaskMemRealloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemrealloc). A quantidade máxima de memória que pode ser alocada é igual a INT_MAX (2147483647) bytes.

## <a name="example"></a>Exemplo

Consulte o exemplo de [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlMemMgr`

`CComHeap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ATLComMem.h

##  <a name="allocate"></a>  CComHeap::Allocate

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

Chame [CComHeap:: Free](#free) ou [CComHeap:: realoque](#reallocate) para liberar a memória alocada por esse método.

Implementado usando [CoTaskMemAlloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc).

##  <a name="free"></a>  CComHeap::Free

Chame esse método para liberar um bloco de memória alocado por esse Gerenciador de memória.

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória. NULL é um valor válido e não faz nada.

### <a name="remarks"></a>Comentários

Implementado usando [CoTaskMemFree](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

##  <a name="getsize"></a>  CComHeap::GetSize

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

Implementado usando [IMalloc:: GetSize](/windows/win32/api/objidlbase/nf-objidlbase-imalloc-getsize).

##  <a name="reallocate"></a>  CComHeap::Reallocate

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

Chame [CComHeap:: Free](#free) para liberar a memória alocada por este método.

Implementado usando [CoTaskMemRealloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemrealloc).

## <a name="see-also"></a>Consulte também

[Exemplo de DynamicConsumer](../../overview/visual-cpp-samples.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)<br/>
[Classe CLocalHeap](../../atl/reference/clocalheap-class.md)<br/>
[Classe CGlobalHeap](../../atl/reference/cglobalheap-class.md)<br/>
[Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)<br/>
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
