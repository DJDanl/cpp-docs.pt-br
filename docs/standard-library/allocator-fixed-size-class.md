---
title: Classe allocator_fixed_size
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::allocators::allocator_fixed_size
- allocators/stdext::allocator_fixed_size
- stdext::allocators::allocator_fixed_size
helpviewer_keywords:
- stdext::allocators [C++], allocator_fixed_size
- stdext::allocator_fixed_size
ms.assetid: 138f3ef8-b0b3-49c3-9486-58f2213c172f
ms.openlocfilehash: 340a4e51c82f1799ebea138ce230393825b9e636
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562604"
---
# <a name="allocator_fixed_size-class"></a>Classe allocator_fixed_size

Descreve um objeto que gerencia a alocação de armazenamento e libera objetos *do tipo Type usando um* cache do tipo [cache_freelist](cache-freelist-class.md) com um comprimento gerenciado pelo [max_fixed_size](max-fixed-size-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_fixed_size;
```

### <a name="parameters"></a>Parâmetros

*Escreva*\
O tipo dos elementos alocados pelo alocador.

## <a name="remarks"></a>Comentários

A macro [ALLOCATOR_DECL](allocators-functions.md#allocator_decl) passa essa classe como o parâmetro *Name* na seguinte instrução: `ALLOCATOR_DECL(CACHE_FREELIST(stdext::allocators::max_fixed_size<10>), SYNC_DEFAULT, allocator_fixed_size);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Confira também

[\<allocators>](allocators-header.md)
