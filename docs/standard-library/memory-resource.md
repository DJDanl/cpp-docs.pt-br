---
title: '&lt;memory_resource&gt;'
ms.date: 04/04/2019
f1_keywords:
- <memory_resource>
helpviewer_keywords:
- memory_resource header
ms.openlocfilehash: d4b25c6ee575191f1e17b0202d33298e2e9e67f0
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68451897"
---
# <a name="ltmemoryresourcegt"></a>&lt;memory_resource&gt;

Define a classe de modelo de contêiner memory_resource e seus modelos de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <memory_resource>
```

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!=](../standard-library/memory-resource-operators.md#op_neq)|Testa se o objeto memory_resource no lado esquerdo do operador não é igual ao objeto memory_resource no lado direito.|
|[operator==](../standard-library/memory-resource-operators.md#op_eq_eq)|Testa se o objeto memory_resource no lado esquerdo do operador é igual ao objeto memory_resource no lado direito.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|||
|-|-|
|[polymorphic_allocator](../standard-library/memory-resource-functions.md#poly_alloc)||

### <a name="functions"></a>Funções

|||
|-|-|
|[get_default_resource](../standard-library/memory-resource-functions.md#get_default)||
|[new_delete_resource](../standard-library/memory-resource-functions.md#new_delete)||
|[null_memory_resource](../standard-library/memory-resource-functions.md#null_memory)||
|[set_default_resource](../standard-library/memory-resource-functions.md#set_default)||

### <a name="classes-and-structs"></a>Classes e structs

|||
|-|-|
|[Classe memory_resource](../standard-library/memory-resource-class.md)||
|[Classe monotonic_buffer_resource](../standard-library/monotonic-buffer-resource-class.md)||
|[Estrutura pool_options](../standard-library/pool-options-structure.md)||
|[Classe synchronized_pool_resource](../standard-library/synchronized-pool-resource-class.md)||
|[Classe unsynchronized_pool_resource](../standard-library/unsynchronized-pool-resource-class.md)||

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
