---
title: '&lt;memory_resource&gt;'
ms.date: 04/04/2019
f1_keywords:
- <memory_resource>
helpviewer_keywords:
- memory_resource header
ms.openlocfilehash: de88feb691d0ec1bc9bf9b9dc2bc40cbc31a1cfe
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88831041"
---
# <a name="ltmemory_resourcegt"></a>&lt;memory_resource&gt;

Define o modelo de classe de contêiner memory_resource e seus modelos de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <memory_resource>
```

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador! =](../standard-library/memory-resource-operators.md#op_neq)|Testa se o objeto memory_resource no lado esquerdo do operador não é igual ao objeto memory_resource no lado direito.|
|[operador = =](../standard-library/memory-resource-operators.md#op_eq_eq)|Testa se o objeto memory_resource no lado esquerdo do operador é igual ao objeto memory_resource no lado direito.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|Nome|Descrição|
|-|-|
|[polymorphic_allocator](../standard-library/memory-resource-functions.md#poly_alloc)||

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[get_default_resource](../standard-library/memory-resource-functions.md#get_default)||
|[new_delete_resource](../standard-library/memory-resource-functions.md#new_delete)||
|[null_memory_resource](../standard-library/memory-resource-functions.md#null_memory)||
|[set_default_resource](../standard-library/memory-resource-functions.md#set_default)||

### <a name="classes-and-structs"></a>Classes e structs

|Nome|Descrição|
|-|-|
|[Classe memory_resource](../standard-library/memory-resource-class.md)||
|[Classe monotonic_buffer_resource](../standard-library/monotonic-buffer-resource-class.md)||
|[pool_options struct](../standard-library/pool-options-structure.md)||
|[Classe synchronized_pool_resource](../standard-library/synchronized-pool-resource-class.md)||
|[Classe unsynchronized_pool_resource](../standard-library/unsynchronized-pool-resource-class.md)||

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
