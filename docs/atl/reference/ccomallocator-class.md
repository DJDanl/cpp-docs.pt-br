---
title: Classe CComAllocator | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CComAllocator
- ATLBASE/ATL::CComAllocator
- ATLBASE/ATL::CComAllocator::Allocate
- ATLBASE/ATL::CComAllocator::Free
- ATLBASE/ATL::CComAllocator::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- CComAllocator class
ms.assetid: 0cd706fd-0c7b-42d3-9054-febe2966fc8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f867d3a7ca81d190ee363c7539e56a62004eb377
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46088937"
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
