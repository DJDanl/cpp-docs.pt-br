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
ms.openlocfilehash: d050a127fe3e62bf8f4eb4ce56fe25e33f88c041
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50535870"
---
# <a name="allocatorfixedsize-class"></a>Classe allocator_fixed_size

Descreve um objeto que gerencia a alocação de armazenamento e a liberação de objetos do tipo *tipo* usando um cache do tipo [cache_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max_fixed_size](../standard-library/max-fixed-size-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_fixed_size;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Tipo*|O tipo dos elementos alocados pelo alocador.|

## <a name="remarks"></a>Comentários

O [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) macro passa essa classe como o *nome* parâmetro na instrução a seguir: `ALLOCATOR_DECL(CACHE_FREELIST(stdext::allocators::max_fixed_size<10>), SYNC_DEFAULT, allocator_fixed_size);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
