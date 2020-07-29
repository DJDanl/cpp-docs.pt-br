---
title: Classe network_link_registry
ms.date: 11/04/2016
f1_keywords:
- network_link_registry
- AGENTS/concurrency::network_link_registry
- AGENTS/concurrency::network_link_registry::add
- AGENTS/concurrency::network_link_registry::begin
- AGENTS/concurrency::network_link_registry::contains
- AGENTS/concurrency::network_link_registry::count
- AGENTS/concurrency::network_link_registry::remove
helpviewer_keywords:
- network_link_registry class
ms.assetid: 3e7b4097-09f1-4252-964e-b15b8f7f7fc6
ms.openlocfilehash: 18fabd0e741c144201f299271cdd01eb9ac55fac
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222674"
---
# <a name="network_link_registry-class"></a>Classe network_link_registry

A `network_link_registry` classe base abstrata gerencia os links entre os blocos de origem e de destino.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Block>
class network_link_registry;
```

### <a name="parameters"></a>parâmetros

*_Block*<br/>
O tipo de dados de bloco que está sendo armazenado no `network_link_registry` .

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`const_pointer`|Um tipo que fornece um ponteiro para um **`const`** elemento em um `network_link_registry` objeto.|
|`const_reference`|Um tipo que fornece uma referência a um **`const`** elemento armazenado em um `network_link_registry` objeto para leitura e execução de operações const.|
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento em um `network_link_registry` objeto.|
|`type`|Um tipo que representa o tipo de bloco armazenado no `network_link_registry` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[add](#add)|Quando substituído em uma classe derivada, adiciona um link para o `network_link_registry` objeto.|
|[Comece](#begin)|Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no `network_link_registry` objeto.|
|[contains](#contains)|Quando substituído em uma classe derivada, pesquisa o `network_link_registry` objeto em busca de um bloco especificado.|
|[contagem](#count)|Quando substituído em uma classe derivada, retorna o número de itens no `network_link_registry` objeto.|
|[remove](#remove)|Quando substituído em uma classe derivada, remove um bloco especificado do `network_link_registry` objeto.|

## <a name="remarks"></a>Comentários

O `network link registry` não é seguro para acesso simultâneo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`network_link_registry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a><a name="add"></a>agrega

Quando substituído em uma classe derivada, adiciona um link para o `network_link_registry` objeto.

```cpp
virtual void add(_EType _Link) = 0;
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

## <a name="begin"></a><a name="begin"></a>Comece

Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no `network_link_registry` objeto.

```cpp
virtual iterator begin() = 0;
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no `network_link_registry` objeto.

### <a name="remarks"></a>Comentários

O estado final do iterador é indicado por um `NULL` link.

## <a name="contains"></a><a name="contains"></a>terá

Quando substituído em uma classe derivada, pesquisa o `network_link_registry` objeto em busca de um bloco especificado.

```cpp
virtual bool contains(_EType _Link) = 0;
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco que está sendo pesquisado no `network_link_registry` objeto.

### <a name="return-value"></a>Valor retornado

**`true`** Se o bloco foi encontrado, **`false`** caso contrário.

## <a name="count"></a><a name="count"></a>contar

Quando substituído em uma classe derivada, retorna o número de itens no `network_link_registry` objeto.

```cpp
virtual size_t count() = 0;
```

### <a name="return-value"></a>Valor retornado

O número de itens no objeto `network_link_registry`.

## <a name="remove"></a><a name="remove"></a>exclu

Quando substituído em uma classe derivada, remove um bloco especificado do `network_link_registry` objeto.

```cpp
virtual bool remove(_EType _Link) = 0;
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**`true`** Se o link foi encontrado e removido, **`false`** caso contrário.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe single_link_registry](single-link-registry-class.md)<br/>
[Classe multi_link_registry](multi-link-registry-class.md)
