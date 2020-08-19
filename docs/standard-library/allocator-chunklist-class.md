---
title: Classe allocator_chunklist
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::allocator_chunklist
- allocators/stdext::allocators::allocator_chunklist
helpviewer_keywords:
- stdext::allocator_chunklist
- stdext::allocators [C++], allocator_chunklist
ms.assetid: ea72ed0a-dfdb-4c8b-8096-e4baf567b80f
ms.openlocfilehash: 64b419b2565609d8f6018facdbe25d5dee9d94aa
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562617"
---
# <a name="allocator_chunklist-class"></a>Classe allocator_chunklist

Descreve um objeto que gerencia a alocação de armazenamento e a liberação de objetos usando um cache do tipo [cache_chunklist](cache-chunklist-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_chunklist;
```

### <a name="parameters"></a>Parâmetros

*Escreva*\
O tipo dos elementos alocados pelo alocador.

## <a name="remarks"></a>Comentários

A macro [ALLOCATOR_DECL](allocators-functions.md#allocator_decl) passa essa classe como o parâmetro *Name* na seguinte instrução: `ALLOCATOR_DECL(CACHE_CHUNKLIST, SYNC_DEFAULT, allocator_chunklist);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Confira também

[\<allocators>](allocators-header.md)
