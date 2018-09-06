---
title: Classe CLocalHeap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CLocalHeap
- ATLMEM/ATL::CLocalHeap
- ATLMEM/ATL::CLocalHeap::Allocate
- ATLMEM/ATL::CLocalHeap::Free
- ATLMEM/ATL::CLocalHeap::GetSize
- ATLMEM/ATL::CLocalHeap::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- CLocalHeap class
ms.assetid: 1ffa87a5-5fc8-4f8d-8809-58e87e963bd2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 54ded1ccb86a7580cf8f004c1f61a82c876eccbe
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43760900"
---
# <a name="clocalheap-class"></a>Classe CLocalHeap

Essa classe implementa [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md) usando as funções de heap local do Win32.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
class CLocalHeap : public IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CLocalHeap::Allocate](#allocate)|Chame esse método para alocar um bloco de memória.|
|[CLocalHeap::Free](#free)|Chame esse método para liberar um bloco de memória alocada por este Gerenciador de memória.|
|[CLocalHeap::GetSize](#getsize)|Chame esse método para obter o tamanho alocado de um bloco de memória alocado por este Gerenciador de memória.|
|[CLocalHeap::Reallocate](#reallocate)|Chame esse método para realocar a memória alocada por este Gerenciador de memória.|

## <a name="remarks"></a>Comentários

`CLocalHeap` implementa as funções de alocação de memória usando as funções de heap local do Win32.

> [!NOTE]
>  As funções de heap local são mais lentas do que outras funções de gerenciamento de memória e não fornecem o máximo de recursos. Portanto, os novos aplicativos devem usar o [funções de heap](/windows/desktop/Memory/heap-functions). Eles estão disponíveis na [CWin32Heap](../../atl/reference/cwin32heap-class.md) classe.

## <a name="example"></a>Exemplo

Veja o exemplo de [IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`IAtlMemMgr`

`CLocalHeap`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem. h

##  <a name="allocate"></a>  CLocalHeap::Allocate

Chame esse método para alocar um bloco de memória.

```
virtual __declspec(allocator) void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*nBytes*  
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória recém-alocada.

### <a name="remarks"></a>Comentários

Chame [CLocalHeap::Free](#free) ou [CLocalHeap::Reallocate](#reallocate) para liberar a memória alocada por esse método.

Implementado usando [LocalAlloc](/windows/desktop/api/winbase/nf-winbase-localalloc) com um parâmetro de sinalizador de LMEM_FIXED.

##  <a name="free"></a>  CLocalHeap::Free

Chame esse método para liberar um bloco de memória alocada por este Gerenciador de memória.

```
virtual void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*  
Ponteiro de memória alocado anteriormente por este Gerenciador de memória. NULL é um valor válido e não faz nada.

### <a name="remarks"></a>Comentários

Implementado usando [LocalFree](/windows/desktop/api/winbase/nf-winbase-localfree).

##  <a name="getsize"></a>  CLocalHeap::GetSize

Chame esse método para obter o tamanho alocado de um bloco de memória alocado por este Gerenciador de memória.

```
virtual size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*  
Ponteiro de memória alocado anteriormente por este Gerenciador de memória.

### <a name="return-value"></a>Valor de retorno

Retorna o tamanho do bloco de memória alocada em bytes.

### <a name="remarks"></a>Comentários

Implementado usando [LocalSize](/windows/desktop/api/winbase/nf-winbase-localsize).

##  <a name="reallocate"></a>  CLocalHeap::Reallocate

Chame esse método para realocar a memória alocada por este Gerenciador de memória.

```
virtual __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*p*  
Ponteiro de memória alocado anteriormente por este Gerenciador de memória.

*nBytes*  
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória recém-alocada.

### <a name="remarks"></a>Comentários

Chame [CLocalHeap::Free](#free) para liberar a memória alocada por esse método.

Implementado usando [LocalReAlloc](/windows/desktop/api/winbase/nf-winbase-localrealloc).

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)   
[Classe CComHeap](../../atl/reference/ccomheap-class.md)   
[Classe CWin32Heap](../../atl/reference/cwin32heap-class.md)   
[Classe CGlobalHeap](../../atl/reference/cglobalheap-class.md)   
[Classe de CCRTHeap](../../atl/reference/ccrtheap-class.md)   
[Classe IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md)
