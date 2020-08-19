---
title: Classe sync_per_thread
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::sync_per_thread
- allocators/stdext::sync_per_thread::allocate
- allocators/stdext::sync_per_thread::deallocate
- allocators/stdext::sync_per_thread::equals
helpviewer_keywords:
- stdext::sync_per_thread
- stdext::sync_per_thread [C++], allocate
- stdext::sync_per_thread [C++], deallocate
- stdext::sync_per_thread [C++], equals
ms.assetid: 47bf75f8-5b02-4760-b1d3-3099d08fe14c
ms.openlocfilehash: 24c5463dc9fb80703361e374efb99fae9e103e7c
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562084"
---
# <a name="sync_per_thread-class"></a>Classe sync_per_thread

Descreve um [filtro de sincronização](../standard-library/allocators-header.md) que fornece um objeto de cache separado para cada thread.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Cache>
class sync_per_thread
```

### <a name="parameters"></a>parâmetros

*Armazenar*\
O tipo de cache associado ao filtro de sincronização. Pode ser [`cache_chunklist`](../standard-library/cache-chunklist-class.md) , [`cache_freelist`](../standard-library/cache-freelist-class.md) ou [`cache_suballoc`](../standard-library/cache-suballoc-class.md) .

## <a name="remarks"></a>Comentários

Os alocadores que usam `sync_per_thread` podem ser comparados como iguais mesmo se os blocos alocados em um thread não podem ser desalocados de outro thread. Ao usar um desses alocadores, os blocos de memória alocados em um thread não devem ficar visíveis para outros threads. Na prática, isso significa que um contêiner que usa um desses alocadores deve ser acessado somente por um único thread.

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[aloca](#allocate)|Aloca um bloco de memória.|
|[desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[equals](#equals)|Compara a igualdade de dois caches.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="sync_per_threadallocate"></a><a name="allocate"></a> sync_per_thread:: Allocate

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>parâmetros

*contar*\
O número de elementos na matriz a serem alocados.

### <a name="remarks"></a>Comentários

A função membro retorna o resultado de uma chamada a `cache::allocate(count)` no objeto de cache que pertence ao thread atual. Se nenhum objeto de cache tiver sido alocado para o thread atual, ele primeiro alocará um.

## <a name="sync_per_threaddeallocate"></a><a name="deallocate"></a> sync_per_thread::d eallocate

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

A função membro chama `deallocate` no objeto de cache que pertence ao thread atual. Se nenhum objeto de cache tiver sido alocado para o thread atual, ele primeiro alocará um.

## <a name="sync_per_threadequals"></a><a name="equals"></a> sync_per_thread:: Equals

Compara a igualdade de dois caches.

```cpp
bool equals(const sync<Cache>& Other) const;
```

### <a name="parameters"></a>parâmetros

*Armazenar*\
O objeto de cache do filtro de sincronização.

*Outros*\
O objeto de cache a ser comparado quanto à igualdade.

### <a name="return-value"></a>Valor retornado

**`false`** Se nenhum objeto de cache tiver sido alocado para esse objeto ou para *outro* no thread atual. Caso contrário, retornará o resultado da aplicação de `operator==` aos dois objetos de cache.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)
