---
title: Classe allocator_newdel
ms.date: 11/04/2016
f1_keywords:
- allocators/stdext::allocators::allocator_newdel
- allocators/stdext::allocator_newdel
- stdext::allocators::allocator_newdel
helpviewer_keywords:
- stdext::allocators [C++], allocator_newdel
- stdext::allocator_newdel
ms.assetid: 62666cd2-3afe-49f7-9dd1-9bbbb154da98
ms.openlocfilehash: aa5012f6657b2676756d1d8023274a524b451df3
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617470"
---
# <a name="allocator_newdel-class"></a>Classe allocator_newdel

Implementa um alocador que usa o **operador Delete** para desalocar um bloco de memória e um **operador novo** para alocar um bloco de memória.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_newdel;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Tipo*|O tipo dos elementos alocados pelo alocador.|

## <a name="remarks"></a>Comentários

A macro [ALLOCATOR_DECL](allocators-functions.md#allocator_decl) passa essa classe como o parâmetro *Name* na seguinte instrução:`ALLOCATOR_DECL(CACHE_FREELIST stdext::allocators::max_none), SYNC_DEFAULT, allocator_newdel);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Confira também

[\<allocators>](allocators-header.md)
