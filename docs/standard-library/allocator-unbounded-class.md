---
title: Classe allocator_unbounded | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- allocators/stdext::allocator_unbounded
- allocators/stdext::allocators::allocator_unbounded
dev_langs:
- C++
helpviewer_keywords:
- allocator_unbounded class
ms.assetid: facbaea1-b320-4d99-96da-039b2642f352
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 321737f62d0e2506ef6582f80bed7f398ad5977b
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38959898"
---
# <a name="allocatorunbounded-class"></a>Classe allocator_unbounded

Descreve um objeto que gerencia a alocação de armazenamento e a liberação de objetos do tipo *tipo* usando um cache do tipo [cache_freelist](../standard-library/cache-freelist-class.md) com um comprimento gerenciado por [max_unbounded](../standard-library/max-unbounded-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_unbounded;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Tipo*|O tipo dos elementos alocados pelo alocador.|

## <a name="remarks"></a>Comentários

O [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) macro passa essa classe como o *nome* parâmetro na instrução a seguir: `ALLOCATOR_DECL(CACHE_FREELIST(stdext::allocators::max_unbounded), SYNC_DEFAULT, allocator_unbounded);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
