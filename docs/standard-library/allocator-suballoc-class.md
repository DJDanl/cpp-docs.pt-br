---
title: Classe allocator_suballoc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- allocators/stdext::allocators::allocator_suballoc
- allocators/stdext::allocator_suballoc
dev_langs:
- C++
helpviewer_keywords:
- allocator_suballoc class
ms.assetid: 50c6a5c0-d00d-4276-9285-d908fd4f6483
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a6238aeada530a8fc33fc98b79cba969353796ae
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953082"
---
# <a name="allocatorsuballoc-class"></a>Classe allocator_suballoc

Descreve um objeto que gerencia a alocação de armazenamento e a liberação de objetos do tipo *tipo* usando um cache do tipo [cache_suballoc](../standard-library/cache-suballoc-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_suballoc;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|*Tipo*|O tipo dos elementos alocados pelo alocador.|

## <a name="remarks"></a>Comentários

O [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) macro passa essa classe como o *nome* parâmetro na instrução a seguir: `ALLOCATOR_DECL(CACHE_SUBALLOC, SYNC_DEFAULT, allocator_suballoc);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
