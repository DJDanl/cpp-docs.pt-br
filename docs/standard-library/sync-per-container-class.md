---
title: Classe sync_per_container
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::sync_per_container
- allocators/stdext::sync_per_container::equals
helpviewer_keywords:
- sync_per_container class
ms.assetid: 0b4b2904-b668-4d94-a422-d4f919cbffab
ms.openlocfilehash: d38307c4ae19e5f87d0dbcca8943dc1c3f239917
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232892"
---
# <a name="sync_per_container-class"></a>Classe sync_per_container

Descreve um [filtro de sincronização](../standard-library/allocators-header.md) que fornece um objeto de cache separado para cada objeto alocador.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Cache>
class sync_per_container
    : public Cache
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*Cache*|O tipo de cache associado ao filtro de sincronização. Pode ser [cache_chunklist](../standard-library/cache-chunklist-class.md), [cache_freelist](../standard-library/cache-freelist-class.md) ou [cache_suballoc](../standard-library/cache-suballoc-class.md).|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[equals](#equals)|Compara a igualdade de dois caches.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="sync_per_containerequals"></a><a name="equals"></a>sync_per_container:: Equals

Compara a igualdade de dois caches.

```cpp
bool equals(const sync_per_container<Cache>& Other) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|---------------|-----------------|
|*Cache*|O objeto de cache do filtro de sincronização.|
|*Outros*|O objeto de cache a ser comparado quanto à igualdade.|

### <a name="return-value"></a>Valor retornado

A função de membro sempre retorna **`false`** .

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Confira também

[\<allocators>](../standard-library/allocators-header.md)
