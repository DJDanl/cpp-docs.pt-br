---
title: Classe single_link_registry
ms.date: 11/04/2016
f1_keywords:
- single_link_registry
- AGENTS/concurrency::single_link_registry
- AGENTS/concurrency::single_link_registry::single_link_registry
- AGENTS/concurrency::single_link_registry::add
- AGENTS/concurrency::single_link_registry::begin
- AGENTS/concurrency::single_link_registry::contains
- AGENTS/concurrency::single_link_registry::count
- AGENTS/concurrency::single_link_registry::remove
helpviewer_keywords:
- single_link_registry class
ms.assetid: 09540a4e-c34e-4ff9-af49-21b8612b6ab3
ms.openlocfilehash: c29caf6d31df316e80b15fe6827c81e34ece8a18
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142718"
---
# <a name="single_link_registry-class"></a>Classe single_link_registry

O objeto `single_link_registry` é um `network_link_registry` que gerencia apenas um único bloco de origem ou de destino.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Block>
class single_link_registry : public network_link_registry<_Block>;
```

### <a name="parameters"></a>Parâmetros

*_Block*<br/>
O tipo de dados de bloco que está sendo armazenado no objeto `single_link_registry`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[single_link_registry](#ctor)|Constrói um objeto `single_link_registry`.|
|[~ single_link_registry destruidor](#dtor)|Destrói o objeto `single_link_registry`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[adicionar](#add)|Adiciona um link ao objeto `single_link_registry`. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|
|[begin](#begin)|Retorna um iterador para o primeiro elemento no objeto `single_link_registry`. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|
|[contains](#contains)|Pesquisa o objeto `single_link_registry` para um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|
|[contagem](#count)|Conta o número de itens no objeto `single_link_registry`. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|
|[remove](#remove)|Remove um link do objeto `single_link_registry`. (Substitui [network_link_registry:: Remove](network-link-registry-class.md#remove).)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[network_link_registry](network-link-registry-class.md)

`single_link_registry`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a>agrega

Adiciona um link ao objeto `single_link_registry`.

```cpp
virtual void add(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_link_target](invalid-link-target-class.md) se já houver um link nesse registro.

## <a name="begin"></a>Comece

Retorna um iterador para o primeiro elemento no objeto `single_link_registry`.

```cpp
virtual iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no objeto `single_link_registry`.

### <a name="remarks"></a>Comentários

O estado final é indicado por um link `NULL`.

## <a name="contains"></a>terá

Pesquisa o objeto `single_link_registry` para um bloco especificado.

```cpp
virtual bool contains(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco que deve ser procurado no objeto `single_link_registry`.

### <a name="return-value"></a>Valor retornado

**true** se o link foi encontrado; caso contrário, **false** .

## <a name="count"></a>contar

Conta o número de itens no objeto `single_link_registry`.

```cpp
virtual size_t count();
```

### <a name="return-value"></a>Valor retornado

O número de itens no objeto `single_link_registry`.

## <a name="remove"></a>exclu

Remove um link do objeto `single_link_registry`.

```cpp
virtual bool remove(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**true** se o link foi encontrado e removido; caso contrário, **false** .

## <a name="ctor"></a>single_link_registry

Constrói um objeto `single_link_registry`.

```cpp
single_link_registry();
```

## <a name="dtor"></a>~ single_link_registry

Destrói o objeto `single_link_registry`.

```cpp
virtual ~single_link_registry();
```

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_operation](invalid-operation-class.md) se for chamado antes de o link ser removido.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe multi_link_registry](multi-link-registry-class.md)
