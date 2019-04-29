---
title: Classe CComAllocator
ms.date: 11/04/2016
f1_keywords:
- CComAllocator
- ATLBASE/ATL::CComAllocator
- ATLBASE/ATL::CComAllocator::Allocate
- ATLBASE/ATL::CComAllocator::Free
- ATLBASE/ATL::CComAllocator::Reallocate
helpviewer_keywords:
- CComAllocator class
ms.assetid: 0cd706fd-0c7b-42d3-9054-febe2966fc8e
ms.openlocfilehash: 9f1c005262d25b1ff5e900377c229afe1573e6d3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62259697"
---
# <a name="ccomallocator-class"></a>Classe CComAllocator

Essa classe fornece métodos para gerenciamento de memória usando COM rotinas de memória.

## <a name="syntax"></a>Sintaxe

```
class CComAllocator
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAllocator::Allocate](#allocate)|Chame esse método estático para alocar memória.|
|[CComAllocator::Free](#free)|Chame esse método estático para liberar a memória alocada.|
|[CComAllocator::Reallocate](#reallocate)|Chame esse método estático para realocar a memória.|

## <a name="remarks"></a>Comentários

Essa classe é usada pelo [CComHeapPtr](../../atl/reference/ccomheapptr-class.md) para fornecer a memória COM rotinas de alocação. A classe de contraparte [CCRTAllocator](../../atl/reference/ccrtallocator-class.md), fornece os mesmos métodos usando rotinas de CRT.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="allocate"></a>  CComAllocator::Allocate

Chame essa função estática para alocar memória.

```
static void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*nBytes*<br/>
O número de bytes para alocar.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro nulo para o espaço alocado ou nulo se não houver memória suficiente disponível.

### <a name="remarks"></a>Comentários

Aloca memória. Ver [CoTaskMemAlloc](/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) para obter mais detalhes.

##  <a name="free"></a>  CComAllocator::Free

Chame essa função estática para liberar a memória alocada.

```
static void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada.

### <a name="remarks"></a>Comentários

Libera a memória alocada. Ver [CoTaskMemFree](/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) para obter mais detalhes.

##  <a name="reallocate"></a>  CComAllocator::Reallocate

Chame essa função estática para realocar a memória.

```
static void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada.

*nBytes*<br/>
O número de bytes para realocar.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro nulo para o espaço alocado ou nulo se não houver memória insuficiente

### <a name="remarks"></a>Comentários

Redimensiona a quantidade de memória alocada. Ver [CoTaskMemRealloc](/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemrealloc) para obter mais detalhes.

## <a name="see-also"></a>Consulte também

[Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)<br/>
[Classe CCRTAllocator](../../atl/reference/ccrtallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
