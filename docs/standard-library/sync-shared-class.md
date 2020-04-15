---
title: Classe sync_shared
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::sync_shared
- allocators/stdext::sync_shared::allocate
- allocators/stdext::sync_shared::deallocate
- allocators/stdext::sync_shared::equals
helpviewer_keywords:
- stdext::sync_shared
- stdext::sync_shared [C++], allocate
- stdext::sync_shared [C++], deallocate
- stdext::sync_shared [C++], equals
ms.assetid: cab3af9e-3d1a-4f2c-8580-0f89e5687d8e
ms.openlocfilehash: 029edea59f29534491232d5d99353ccb093447bd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376529"
---
# <a name="sync_shared-class"></a>Classe sync_shared

Descreve um [filtro de sincronização](../standard-library/allocators-header.md) que usa um mutex para controlar o acesso a um objeto de cache que é compartilhado por todos os alocadores.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Cache>
class sync_shared
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Cache*|O tipo de cache associado ao filtro de sincronização. Pode ser [cache_chunklist](../standard-library/cache-chunklist-class.md), [cache_freelist](../standard-library/cache-freelist-class.md) ou [cache_suballoc](../standard-library/cache-suballoc-class.md).|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Alocar](#allocate)|Aloca um bloco de memória.|
|[Desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[equals](#equals)|Compara a igualdade de dois caches.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="sync_sharedallocate"></a><a name="allocate"></a>sync_shared:alocar

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

A função membro bloqueia o mutex, chama `cache.allocate(count)`, desbloqueia o mutex e retorna o resultado da chamada anterior a `cache.allocate(count)`. `cache` representa o objeto de cache atual.

## <a name="sync_shareddeallocate"></a><a name="deallocate"></a>sync_shared::deallocate

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

Essa função membro bloqueia o mutex, chama `cache.deallocate(ptr, count)`, em que `cache` representa o objeto de cache e, em seguida, desbloqueia o mutex.

## <a name="sync_sharedequals"></a><a name="equals"></a>sync_shared::iguais

Compara a igualdade de dois caches.

```cpp
bool equals(const sync_shared<Cache>& Other) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Cache*|O tipo de cache associado ao filtro de sincronização.|
|*Outros*|O cache a ser comparado quanto à igualdade.|

### <a name="return-value"></a>Valor retornado

**verdade** se o `cache.equals(Other.cache)`resultado `cache` de , onde representa o objeto cache, é **verdadeiro;** caso contrário, **falso**.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[\<alocadores>](../standard-library/allocators-header.md)
