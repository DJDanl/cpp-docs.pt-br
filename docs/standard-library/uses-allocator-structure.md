---
title: Estrutura uses_allocator
ms.date: 11/04/2016
f1_keywords:
- future/std::uses_allocator
ms.assetid: c418f002-62e9-4806-b70c-41c663cae583
ms.openlocfilehash: 4dc0094d46c005e4af62924bc785a05b3ca43090
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68454663"
---
# <a name="usesallocator-structure"></a>Estrutura uses_allocator

Especializações que sempre se aplicam.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Ty, class Alloc>
struct uses_allocator<promise<Ty>, Alloc> : true_type;
template <class Ty, class Alloc>
struct uses_allocator<packaged_task<Ty>, Alloc> : true_type;
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> futuro

**Namespace:** std

## <a name="specializations"></a>Especializações

### <a name="tuple"></a>\<> de tupla

```cpp
template <class... Types, class Alloc>
struct uses_allocator<tuple<Types...>, Alloc>;
```

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[\<future>](../standard-library/future.md)
