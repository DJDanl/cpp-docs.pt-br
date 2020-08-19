---
title: Classe rts_alloc
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::rts_alloc
- allocators/stdext::rts_alloc::allocate
- allocators/stdext::rts_alloc::deallocate
- allocators/stdext::rts_alloc::equals
helpviewer_keywords:
- stdext::rts_alloc
- stdext::rts_alloc [C++], allocate
- stdext::rts_alloc [C++], deallocate
- stdext::rts_alloc [C++], equals
ms.assetid: ab41bffa-83d1-4a1c-87b9-5707d516931f
ms.openlocfilehash: 04a6578c7abd07ff84f4c0a5cee68cfd7ec8ef04
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88560550"
---
# <a name="rts_alloc-class"></a>Classe rts_alloc

O modelo de classe rts_alloc descreve um [filtro](../standard-library/allocators-header.md) que contém uma matriz de instâncias de cache e determina qual instância usar para alocação e desalocação em tempo de execução em vez de em tempo de compilação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Cache>
class rts_alloc
```

### <a name="parameters"></a>parâmetros

*Armazenar*\
O tipo de instâncias de cache contidas na matriz. Pode ser [`cache_chunklist`](../standard-library/cache-chunklist-class.md) , [`cache_freelist`](../standard-library/cache-freelist-class.md) ou [`cache_suballoc`](../standard-library/cache-suballoc-class.md) .

## <a name="remarks"></a>Comentários

Esse modelo de classe contém várias instâncias de alocador de bloco e determina qual instância usar para alocação ou desalocação em tempo de execução em vez de em tempo de compilação. Ele é usado com os compiladores que não podem compilar reassociação.

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[aloca](#allocate)|Aloca um bloco de memória.|
|[desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[equals](#equals)|Compara a igualdade de dois caches.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="rts_allocallocate"></a><a name="allocate"></a> rts_alloc:: Allocate

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>parâmetros

*contar*\
O número de elementos na matriz a serem alocados.

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

A função membro retorna `caches[_IDX].allocate(count)` , em que o índice `_IDX` é determinado pela *contagem*de tamanho de bloco solicitada ou, se *Count* for muito grande, retorna `operator new(count)` . `cache`, que representa o objeto do cache.

## <a name="rts_allocdeallocate"></a><a name="deallocate"></a> rts_alloc::d eallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(void* ptr, std::size_t count);
```

### <a name="parameters"></a>parâmetros

*PTR*\
Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.

*contar*\
O número de objetos a serem desalocados do armazenamento.

### <a name="remarks"></a>Comentários

As chamadas de função de membro `caches[_IDX].deallocate(ptr, count)` , em que o índice `_IDX` é determinado pela *contagem*de tamanho de bloco solicitada ou, se *Count* for muito grande, retorna `operator delete(ptr)` .

## <a name="rts_allocequals"></a><a name="equals"></a> rts_alloc:: Equals

Compara a igualdade de dois caches.

```cpp
bool equals(const sync<_Cache>& _Other) const;
```

### <a name="parameters"></a>parâmetros

*_Cache*\
O objeto de cache associado ao filtro.

*_Other*\
O objeto de cache a ser comparado quanto à igualdade.

### <a name="remarks"></a>Comentários

**`true`** Se for o resultado de `caches[0].equals(other.caches[0])` ; caso contrário, **`false`** . `caches` representa a matriz de objetos do cache.

## <a name="see-also"></a>Confira também

[ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl)\
[\<allocators>](../standard-library/allocators-header.md)
