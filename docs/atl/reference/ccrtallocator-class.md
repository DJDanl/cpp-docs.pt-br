---
title: Classe CCRTAlocador
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
ms.openlocfilehash: 2f6bae3818fa0f1639e0e3cee4e09121580da768
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327179"
---
# <a name="ccrtallocator-class"></a>Classe CCRTAlocador

Esta classe fornece métodos para gerenciar a memória usando rotinas de memória CRT.

## <a name="syntax"></a>Sintaxe

```
class ATL::CCRTAllocator
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CCRTAllocateor::Alocar](#allocate)|(Estática) Chame este método para alocar memória.|
|[CCRTAlocador::Grátis](#free)|(Estática) Chame este método para libertar a memória.|
|[CCRTAlocador::Realocação](#reallocate)|(Estática) Chame este método para realocar a memória.|

## <a name="remarks"></a>Comentários

Esta classe é usada pelo [CHeapPtr](../../atl/reference/cheapptr-class.md) para fornecer as rotinas de alocação de memória CRT. A classe de contrapartida, [CComAllocator,](../../atl/reference/ccomallocator-class.md)fornece os mesmos métodos usando rotinas COM.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlcore.h

## <a name="ccrtallocatorallocate"></a><a name="allocate"></a>CCRTAllocateor::Alocar

Chame esta função estática para alocar memória.

```
static __declspec(allocator) void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
O número de bytes para alocar.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro vazio para o espaço alocado ou NULL se houver memória insuficiente disponível.

### <a name="remarks"></a>Comentários

Aloca memória. Consulte [malloc](../../c-runtime-library/reference/malloc.md) para mais detalhes.

## <a name="ccrtallocatorfree"></a><a name="free"></a>CCRTAlocador::Grátis

Chame esta função estática para liberar a memória.

```
static void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para a memória alocada.

### <a name="remarks"></a>Comentários

Libera a memória alocada. Veja [gratuitamente](../../c-runtime-library/reference/free.md) mais detalhes.

## <a name="ccrtallocatorreallocate"></a><a name="reallocate"></a>CCRTAlocador::Realocação

Chame esta função estática para realocar a memória.

```
static __declspec(allocator) void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para a memória alocada.

*Nbytes*<br/>
O número de bytes para realocar.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro vazio para o espaço alocado, ou NULL se houver memória insuficiente.

### <a name="remarks"></a>Comentários

Redimensiona a quantidade de memória alocada. Consulte [realloc](../../c-runtime-library/reference/realloc.md) para mais detalhes.

## <a name="see-also"></a>Confira também

[Classe CHeapPtr](../../atl/reference/cheapptr-class.md)<br/>
[Classe CComAllocator](../../atl/reference/ccomallocator-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
