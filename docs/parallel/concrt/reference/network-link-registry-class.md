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
ms.openlocfilehash: 430190c11ec06a4f26eb9d8c4237552848420ad7
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77138884"
---
# <a name="network_link_registry-class"></a>Classe network_link_registry

A `network_link_registry` classe base abstrata gerencia os links entre os blocos de origem e de destino.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Block>
class network_link_registry;
```

### <a name="parameters"></a>Parâmetros

*_Block*<br/>
O tipo de dados de bloco que está sendo armazenado no `network_link_registry`.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`const_pointer`|Um tipo que fornece um ponteiro para um elemento `const` em um objeto `network_link_registry`.|
|`const_reference`|Um tipo que fornece uma referência a um elemento `const` armazenado em um objeto `network_link_registry` para leitura e execução de operações const.|
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento em um objeto `network_link_registry`.|
|`type`|Um tipo que representa o tipo de bloco armazenado no objeto `network_link_registry`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[adicionar](#add)|Quando substituído em uma classe derivada, adiciona um link ao objeto `network_link_registry`.|
|[begin](#begin)|Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no objeto `network_link_registry`.|
|[contains](#contains)|Quando substituído em uma classe derivada, pesquisa o objeto `network_link_registry` para um bloco especificado.|
|[contagem](#count)|Quando substituído em uma classe derivada, retorna o número de itens no objeto `network_link_registry`.|
|[remove](#remove)|Quando substituído em uma classe derivada, remove um bloco especificado do objeto `network_link_registry`.|

## <a name="remarks"></a>Comentários

O `network link registry` não é seguro para acesso simultâneo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`network_link_registry`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a>agrega

Quando substituído em uma classe derivada, adiciona um link ao objeto `network_link_registry`.

```cpp
virtual void add(_EType _Link) = 0;
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

## <a name="begin"></a>Comece

Quando substituído em uma classe derivada, retorna um iterador para o primeiro elemento no objeto `network_link_registry`.

```cpp
virtual iterator begin() = 0;
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no objeto `network_link_registry`.

### <a name="remarks"></a>Comentários

O estado final do iterador é indicado por um link `NULL`.

## <a name="contains"></a>terá

Quando substituído em uma classe derivada, pesquisa o objeto `network_link_registry` para um bloco especificado.

```cpp
virtual bool contains(_EType _Link) = 0;
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco que está sendo pesquisado no objeto `network_link_registry`.

### <a name="return-value"></a>Valor retornado

**true** se o bloco foi encontrado; caso contrário, **false** .

## <a name="count"></a>contar

Quando substituído em uma classe derivada, retorna o número de itens no objeto `network_link_registry`.

```cpp
virtual size_t count() = 0;
```

### <a name="return-value"></a>Valor retornado

O número de itens no objeto `network_link_registry`.

## <a name="remove"></a>exclu

Quando substituído em uma classe derivada, remove um bloco especificado do objeto `network_link_registry`.

```cpp
virtual bool remove(_EType _Link) = 0;
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**true** se o link foi encontrado e removido; caso contrário, **false** .

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe single_link_registry](single-link-registry-class.md)<br/>
[Classe multi_link_registry](multi-link-registry-class.md)
