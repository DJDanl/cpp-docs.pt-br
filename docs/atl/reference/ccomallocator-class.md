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
ms.openlocfilehash: 165cdb8b0b16a4872214f4556c26ee141e6a4d89
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81321148"
---
# <a name="ccomallocator-class"></a>Classe CComAllocator

Esta classe fornece métodos para gerenciar a memória usando rotinas de memória COM.

## <a name="syntax"></a>Sintaxe

```
class CComAllocator
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComAllocateor::Alocar](#allocate)|Chame este método estático para alocar memória.|
|[CComAllocator::Grátis](#free)|Chame este método estático para liberar a memória alocada.|
|[CComAllocator::Realocação](#reallocate)|Chame este método estático para realocar a memória.|

## <a name="remarks"></a>Comentários

Esta classe é usada pelo [CComHeapPtr](../../atl/reference/ccomheapptr-class.md) para fornecer as rotinas de alocação de memória COM. A classe de contrapartida, [CCRTAllocator,](../../atl/reference/ccrtallocator-class.md)fornece os mesmos métodos usando rotinas DE CRT.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlbase.h

## <a name="ccomallocatorallocate"></a><a name="allocate"></a>CComAllocateor::Alocar

Chame esta função estática para alocar memória.

```
static void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
O número de bytes para alocar.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro vazio para o espaço alocado ou NULL se houver memória insuficiente disponível.

### <a name="remarks"></a>Comentários

Aloca memória. Consulte [CoTaskMemAlloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemalloc) para obter mais detalhes.

## <a name="ccomallocatorfree"></a><a name="free"></a>CComAllocator::Grátis

Chame esta função estática para liberar a memória alocada.

```
static void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para a memória alocada.

### <a name="remarks"></a>Comentários

Libera a memória alocada. Consulte [CoTaskMemFree](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree) para obter mais detalhes.

## <a name="ccomallocatorreallocate"></a><a name="reallocate"></a>CComAllocator::Realocação

Chame esta função estática para realocar a memória.

```
static void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para a memória alocada.

*Nbytes*<br/>
O número de bytes para realocar.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro vazio para o espaço alocado, ou NULL se houver memória insuficiente

### <a name="remarks"></a>Comentários

Redimensiona a quantidade de memória alocada. Consulte [CoTaskMemRealloc](/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemrealloc) para obter mais detalhes.

## <a name="see-also"></a>Confira também

[Classe CComHeapPtr](../../atl/reference/ccomheapptr-class.md)<br/>
[Classe CCRTAlocador](../../atl/reference/ccrtallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
