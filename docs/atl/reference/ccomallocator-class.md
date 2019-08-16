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
ms.openlocfilehash: de302c7a58bf1b15e63e7cd391621ed9558e5a70
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497591"
---
# <a name="ccomallocator-class"></a>Classe CComAllocator

Essa classe fornece métodos para gerenciar a memória usando rotinas de memória COM.

## <a name="syntax"></a>Sintaxe

```
class CComAllocator
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAllocator:: Allocate](#allocate)|Chame esse método estático para alocar memória.|
|[CComAllocator:: Free](#free)|Chame esse método estático para liberar memória alocada.|
|[CComAllocator::Reallocate](#reallocate)|Chame esse método estático para realocar memória.|

## <a name="remarks"></a>Comentários

Essa classe é usada pelo [CComHeapPtr](../../atl/reference/ccomheapptr-class.md) para fornecer as rotinas de alocação de memória com. A classe equivalente, [CCRTAllocator](../../atl/reference/ccrtallocator-class.md), fornece os mesmos métodos usando rotinas CRT.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase. h

##  <a name="allocate"></a>  CComAllocator::Allocate

Chame essa função estática para alocar memória.

```
static void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*nBytes*<br/>
O número de bytes a serem alocados.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro void para o espaço alocado ou NULL se não houver memória suficiente disponível.

### <a name="remarks"></a>Comentários

Aloca memória. Consulte [CoTaskMemAlloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc) para obter mais detalhes.

##  <a name="free"></a>CComAllocator:: Free

Chame essa função estática para liberar memória alocada.

```
static void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada.

### <a name="remarks"></a>Comentários

Libera a memória alocada. Consulte [CoTaskMemFree](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) para obter mais detalhes.

##  <a name="reallocate"></a>  CComAllocator::Reallocate

Chame essa função estática para realocar memória.

```
static void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada.

*nBytes*<br/>
O número de bytes a serem realocados.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro void para o espaço alocado ou NULL se não houver memória suficiente

### <a name="remarks"></a>Comentários

Redimensiona a quantidade de memória alocada. Consulte [CoTaskMemRealloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemrealloc) para obter mais detalhes.

## <a name="see-also"></a>Consulte também

[Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)<br/>
[Classe CCRTAllocator](../../atl/reference/ccrtallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
