---
title: Classe allocator_suballoc
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::allocators::allocator_suballoc
- allocators/stdext::allocator_suballoc
helpviewer_keywords:
- allocator_suballoc class
ms.assetid: 50c6a5c0-d00d-4276-9285-d908fd4f6483
ms.openlocfilehash: 47b82a198a52a61bd5558bd59a38b1d328fa67b2
ms.sourcegitcommit: 1839405b97036891b6e4d37c99def044d6f37eff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/18/2020
ms.locfileid: "88562578"
---
# <a name="allocator_suballoc-class"></a>Classe allocator_suballoc

Descreve um objeto que gerencia a alocação de armazenamento e libera objetos *do tipo Type usando um* cache do tipo [cache_suballoc](cache-suballoc-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_suballoc;
```

### <a name="parameters"></a>Parâmetros

*Escreva*\
O tipo dos elementos alocados pelo alocador.

## <a name="remarks"></a>Comentários

A macro [ALLOCATOR_DECL](allocators-functions.md#allocator_decl) passa essa classe como o parâmetro *Name* na seguinte instrução: `ALLOCATOR_DECL(CACHE_SUBALLOC, SYNC_DEFAULT, allocator_suballoc);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Confira também

[\<allocators>](allocators-header.md)
