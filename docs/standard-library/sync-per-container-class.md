---
title: Classe sync_per_container | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- allocators/stdext::sync_per_container
- allocators/stdext::sync_per_container::equals
dev_langs:
- C++
helpviewer_keywords:
- sync_per_container class
ms.assetid: 0b4b2904-b668-4d94-a422-d4f919cbffab
caps.latest.revision: 21
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d917fcae71f5e3c152082e4ecdac27626f6637f7
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="syncpercontainer-class"></a>Classe sync_per_container

Descreve um [filtro de sincronização](../standard-library/allocators-header.md) que fornece um objeto de cache separado para cada objeto alocador.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Cache>
class sync_per_container
 : public Cache
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Cache`|O tipo de cache associado ao filtro de sincronização. Pode ser [cache_chunklist](../standard-library/cache-chunklist-class.md), [cache_freelist](../standard-library/cache-freelist-class.md) ou [cache_suballoc](../standard-library/cache-suballoc-class.md).|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[equals](#equals)|Compara a igualdade de dois caches.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="equals"></a>  sync_per_container::equals

Compara a igualdade de dois caches.

```cpp
bool equals(const sync_per_container<Cache>& Other) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Cache`|O objeto de cache do filtro de sincronização.|
|`Other`|O objeto de cache a ser comparado quanto à igualdade.|

### <a name="return-value"></a>Valor de retorno

A função membro sempre retorna `false`.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
