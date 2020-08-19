---
title: Classe allocator_unbounded
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::allocator_unbounded
- allocators/stdext::allocators::allocator_unbounded
helpviewer_keywords:
- allocator_unbounded class
ms.assetid: facbaea1-b320-4d99-96da-039b2642f352
ms.openlocfilehash: d9d82dd29ab86654020e13b39a8c9588ee0732e8
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88561538"
---
# <a name="allocator_unbounded-class"></a>Classe allocator_unbounded

Descreve um objeto que gerencia a alocação de armazenamento e libera objetos *do tipo Type usando um* cache do tipo [cache_freelist](cache-freelist-class.md) com um comprimento gerenciado pelo [max_unbounded](max-unbounded-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_unbounded;
```

### <a name="parameters"></a>Parâmetros

*Escreva*\
O tipo dos elementos alocados pelo alocador.

## <a name="remarks"></a>Comentários

A macro [ALLOCATOR_DECL](allocators-functions.md#allocator_decl) passa essa classe como o parâmetro *Name* na seguinte instrução: `ALLOCATOR_DECL(CACHE_FREELIST(stdext::allocators::max_unbounded), SYNC_DEFAULT, allocator_unbounded);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Confira também

[\<allocators>](allocators-header.md)
