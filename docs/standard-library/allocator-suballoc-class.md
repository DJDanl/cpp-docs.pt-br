---
title: Classe allocator_suballoc | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- allocators/stdext::allocators::allocator_suballoc
- allocators/stdext::allocator_suballoc
dev_langs:
- C++
helpviewer_keywords:
- allocator_suballoc class
ms.assetid: 50c6a5c0-d00d-4276-9285-d908fd4f6483
caps.latest.revision: 16
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8ae0783a0fe4042c117a623ab13b2352c2082cbb
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="allocatorsuballoc-class"></a>Classe allocator_suballoc

Descreve um objeto que gerencia a alocação e a liberação de armazenamento para objetos do tipo `Type` usando um cache do tipo [cache_suballoc](../standard-library/cache-suballoc-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <class Type>
class allocator_suballoc;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`Type`|O tipo dos elementos alocados pelo alocador.|

## <a name="remarks"></a>Comentários

A macro [ALLOCATOR_DECL](../standard-library/allocators-functions.md#allocator_decl) passa essa classe como o parâmetro `name` na instrução a seguir: `ALLOCATOR_DECL(CACHE_SUBALLOC, SYNC_DEFAULT, allocator_suballoc);`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<allocators>

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[\<allocators>](../standard-library/allocators-header.md)<br/>
