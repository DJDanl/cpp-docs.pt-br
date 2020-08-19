---
title: Classe sync_none
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::sync_none
- allocators/stdext::sync_none::allocate
- allocators/stdext::sync_none::deallocate
- allocators/stdext::sync_none::equals
helpviewer_keywords:
- stdext::sync_none
- stdext::sync_none [C++], allocate
- stdext::sync_none [C++], deallocate
- stdext::sync_none [C++], equals
ms.assetid: f7473cee-14f3-4fe1-88bc-68cd085e59e1
ms.openlocfilehash: dac4dc1182de32af485d37a00ff96370ea8d8943
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562110"
---
# <a name="sync_none-class"></a>Classe sync_none

Descreve um [filtro de sincronização](../standard-library/allocators-header.md) que não fornece nenhuma sincronização.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Cache>
class sync_none
```

### <a name="parameters"></a>Parâmetros

`Cache`\
O tipo de cache associado ao filtro de sincronização. Pode ser [`cache_chunklist`](../standard-library/cache-chunklist-class.md) , [`cache_freelist`](../standard-library/cache-freelist-class.md) ou [`cache_suballoc`](../standard-library/cache-suballoc-class.md) .

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[aloca](#allocate)|Aloca um bloco de memória.|
|[desalocar](#deallocate)|Libera um número especificado de objetos do armazenamento começando em uma posição especificada.|
|[equals](#equals)|Compara a igualdade de dois caches.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="sync_noneallocate"></a><a name="allocate"></a> sync_none:: Allocate

Aloca um bloco de memória.

```cpp
void *allocate(std::size_t count);
```

### <a name="parameters"></a>Parâmetros

*contar*\
O número de elementos na matriz a serem alocados.

### <a name="remarks"></a>Comentários

A função membro retorna `cache.allocate(count)`, em que `cache` é o objeto de cache.

## <a name="sync_nonedeallocate"></a><a name="deallocate"></a> sync_none::d eallocate

Libera um número especificado de objetos do armazenamento começando em uma posição especificada.

```cpp
void deallocate(void* ptr, std::size_t count);
```

### <a name="parameters"></a>Parâmetros

*PTR*\
Um ponteiro para o primeiro objeto a ser desalocado do armazenamento.

*contar*\
O número de objetos a serem desalocados do armazenamento.

### <a name="remarks"></a>Comentários

A função membro chama `cache.deallocate(ptr, count)`, em que `cache` representa o objeto de cache.

## <a name="sync_noneequals"></a><a name="equals"></a> sync_none:: Equals

Compara a igualdade de dois caches.

```cpp
bool equals(const sync<Cache>& Other) const;
```

### <a name="parameters"></a>Parâmetros

*Armazenar*\
O objeto de cache do filtro de sincronização.

*Outros*\
O objeto de cache a ser comparado quanto à igualdade.

### <a name="return-value"></a>Valor retornado

A função de membro sempre retorna **`true`** .

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)
