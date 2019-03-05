---
title: Classe CCRTAllocator
ms.date: 11/04/2016
f1_keywords:
- CCRTAllocator
- ATLCORE/ATL::CCRTAllocator
- ATLCORE/ATL::CCRTAllocator::Allocate
- ATLCORE/ATL::CCRTAllocator::Free
- ATLCORE/ATL::CCRTAllocator::Reallocate
helpviewer_keywords:
- CCRTAllocator class
ms.assetid: 3e1b8cb0-859a-41ab-8e93-6f0b5ceca49d
ms.openlocfilehash: c08d594e1c0f4d532f46961e266bf6ced98c51b2
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57287356"
---
# <a name="ccrtallocator-class"></a>Classe CCRTAllocator

Essa classe fornece métodos para gerenciamento de memória usando rotinas de memória do CRT.

## <a name="syntax"></a>Sintaxe

```
class ATL::CCRTAllocator
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CCRTAllocator::Allocate](#allocate)|(Estático) Chame esse método para alocar memória.|
|[CCRTAllocator::Free](#free)|(Estático) Chame esse método para liberar memória.|
|[CCRTAllocator::Reallocate](#reallocate)|(Estático) Chame esse método para realocar a memória.|

## <a name="remarks"></a>Comentários

Essa classe é usada pelo [CHeapPtr](../../atl/reference/cheapptr-class.md) para fornecer rotinas de alocação de memória CRT. A classe de contraparte [CComAllocator](../../atl/reference/ccomallocator-class.md), fornece os mesmos métodos usando rotinas de COM.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

##  <a name="allocate"></a>  CCRTAllocator::Allocate

Chame essa função estática para alocar memória.

```
static __declspec(allocator) void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*nBytes*<br/>
O número de bytes para alocar.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro nulo para o espaço alocado ou nulo se não houver memória suficiente disponível.

### <a name="remarks"></a>Comentários

Aloca memória. Ver [malloc](../../c-runtime-library/reference/malloc.md) para obter mais detalhes.

##  <a name="free"></a>  CCRTAllocator::Free

Chame essa função estática para liberar memória.

```
static void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada.

### <a name="remarks"></a>Comentários

Libera a memória alocada. Ver [livre](../../c-runtime-library/reference/free.md) para obter mais detalhes.

##  <a name="reallocate"></a>  CCRTAllocator::Reallocate

Chame essa função estática para realocar a memória.

```
static __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro para a memória alocada.

*nBytes*<br/>
O número de bytes para realocar.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro nulo para o espaço alocado ou nulo se não houver memória insuficiente.

### <a name="remarks"></a>Comentários

Redimensiona a quantidade de memória alocada. Ver [realloc](../../c-runtime-library/reference/realloc.md) para obter mais detalhes.

## <a name="see-also"></a>Consulte também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CComAllocator](../../atl/reference/ccomallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
