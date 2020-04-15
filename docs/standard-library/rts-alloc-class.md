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
ms.openlocfilehash: 6ed84d906944a09fa355e281640e9480f3173554
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373420"
---
# <a name="rts_alloc-class"></a>Classe rts_alloc

O modelo de classe rts_alloc descreve um [filtro](../standard-library/allocators-header.md) que contém uma matriz de instâncias de cache e determina qual instância usar para alocação e desalocação em tempo de execução, em vez de em tempo de compilação.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Cache>
class rts_alloc
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Cache*|O tipo de instâncias de cache contidas na matriz. Pode ser [cache_chunklist Class](../standard-library/cache-chunklist-class.md), [cache_freelist](../standard-library/cache-freelist-class.md) ou [cache_suballoc](../standard-library/cache-suballoc-class.md).|

## <a name="remarks"></a>Comentários

Este modelo de classe contém várias instâncias de alocação de blocos e determina qual instância usar para alocação ou desalocação em tempo de execução, em vez de no tempo de compilação. Ele é usado com os compiladores que não podem compilar reassociação.

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Alocar](#allocate)|Aloca um bloco de memória.|
|[Desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[equals](#equals)|Compara a igualdade de dois caches.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="rts_allocallocate"></a><a name="allocate"></a>rts_alloc:alocar

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*contagem*|O número de elementos na matriz a serem alocados.|

### <a name="return-value"></a>Valor retornado

Um ponteiro para o objeto alocado.

### <a name="remarks"></a>Comentários

A função `caches[_IDX].allocate(count)`do membro `_IDX` retorna, onde o índice é determinado pela *contagem*de tamanho `operator new(count)`do bloco solicitado, ou, se a *contagem* for muito grande, ela retorna . `cache`, que representa o objeto do cache.

## <a name="rts_allocdeallocate"></a><a name="deallocate"></a>rts_alloc::deallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(void* ptr, std::size_t count);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Ptr*|Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.|
|*contagem*|O número de objetos a serem desalocados do armazenamento.|

### <a name="remarks"></a>Comentários

A função `caches[_IDX].deallocate(ptr, count)`do membro `_IDX` chama , quando o índice é determinado pela *contagem*de `operator delete(ptr)`tamanho do bloco solicitado , ou, se a *contagem* for muito grande, ela retorna .

## <a name="rts_allocequals"></a><a name="equals"></a>rts_alloc::é igual

Compara a igualdade de dois caches.

```cpp
bool equals(const sync<_Cache>& _Other) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*_Cache*|O objeto de cache associado ao filtro.|
|*_Other*|O objeto de cache a ser comparado quanto à igualdade.|

### <a name="remarks"></a>Comentários

**verdade** se o `caches[0].equals(other.caches[0])`resultado de; caso contrário, **falso**. `caches` representa a matriz de objetos do cache.

## <a name="see-also"></a>Confira também

[ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl)\
[\<alocadores>](../standard-library/allocators-header.md)
