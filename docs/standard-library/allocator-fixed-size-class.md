---
title: Classe allocator_fixed_size | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- allocators/stdext::allocators::allocator_fixed_size
- allocators/stdext::allocator_fixed_size
- stdext::allocators::allocator_fixed_size
dev_langs:
- C++
helpviewer_keywords:
- stdext::allocators [C++], allocator_fixed_size
- stdext::allocator_fixed_size
ms.assetid: 138f3ef8-b0b3-49c3-9486-58f2213c172f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc1b13fefbb48ebd28b27f87e0a5622fd3cd5ec4
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33849854"
---
# <a name="allocatorfixedsize-class"></a>Classe allocator_fixed_size

Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type` usando um cache do tipo [cache_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max_fixed_size](../standard-library/max-fixed-size-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_fixed_size;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Type`|O tipo dos elementos alocados pelo alocador.|

## <a name="remarks"></a>Comentários

A macro [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) passa essa classe como o parâmetro `name` na instrução a seguir: `ALLOCATOR_DECL(CACHE_FREELIST(stdext::allocators::max_fixed_size<10>), SYNC_DEFAULT, allocator_fixed_size);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
