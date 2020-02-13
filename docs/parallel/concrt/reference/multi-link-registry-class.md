---
title: Classe multi_link_registry
ms.date: 11/04/2016
f1_keywords:
- multi_link_registry
- AGENTS/concurrency::multi_link_registry
- AGENTS/concurrency::multi_link_registry::multi_link_registry
- AGENTS/concurrency::multi_link_registry::add
- AGENTS/concurrency::multi_link_registry::begin
- AGENTS/concurrency::multi_link_registry::contains
- AGENTS/concurrency::multi_link_registry::count
- AGENTS/concurrency::multi_link_registry::remove
- AGENTS/concurrency::multi_link_registry::set_bound
helpviewer_keywords:
- multi_link_registry class
ms.assetid: b2aa73a8-e8a6-4255-b117-d07530c328b2
ms.openlocfilehash: e22df5ee65d0219a46065044385dca46aac297a3
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142367"
---
# <a name="multi_link_registry-class"></a>Classe multi_link_registry

O objeto `multi_link_registry` é um `network_link_registry` que gerencia vários blocos de origem ou vários blocos de destino.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Block>
class multi_link_registry : public network_link_registry<_Block>;
```

### <a name="parameters"></a>Parâmetros

*_Block*<br/>
O tipo de dados de bloco que está sendo armazenado no objeto `multi_link_registry`.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[multi_link_registry](#ctor)|Constrói um objeto `multi_link_registry`.|
|[~ multi_link_registry destruidor](#dtor)|Destrói o objeto `multi_link_registry`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[adicionar](#add)|Adiciona um link ao objeto `multi_link_registry`. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|
|[begin](#begin)|Retorna um iterador para o primeiro elemento no objeto `multi_link_registry`. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|
|[contains](#contains)|Pesquisa o objeto `multi_link_registry` para um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|
|[contagem](#count)|Conta o número de itens no objeto `multi_link_registry`. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|
|[remove](#remove)|Remove um link do objeto `multi_link_registry`. (Substitui [network_link_registry:: Remove](network-link-registry-class.md#remove).)|
|[set_bound](#set_bound)|Define um limite superior no número de links que o objeto `multi_link_registry` pode conter.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[network_link_registry](network-link-registry-class.md)

`multi_link_registry`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a>agrega

Adiciona um link ao objeto `multi_link_registry`.

```cpp
virtual void add(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_link_target](invalid-link-target-class.md) se o link já estiver presente no registro ou se um associado já tiver sido definido com a função `set_bound` e um link tiver sido removido.

## <a name="begin"></a>Comece

Retorna um iterador para o primeiro elemento no objeto `multi_link_registry`.

```cpp
virtual iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no objeto `multi_link_registry`.

### <a name="remarks"></a>Comentários

O estado final é indicado por um link `NULL`.

## <a name="contains"></a>terá

Pesquisa o objeto `multi_link_registry` para um bloco especificado.

```cpp
virtual bool contains(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco que deve ser procurado no objeto `multi_link_registry`.

### <a name="return-value"></a>Valor retornado

**true** se o bloco especificado foi encontrado; caso contrário, **false** .

## <a name="count"></a>contar

Conta o número de itens no objeto `multi_link_registry`.

```cpp
virtual size_t count();
```

### <a name="return-value"></a>Valor retornado

O número de itens no objeto `multi_link_registry`.

## <a name="ctor"></a>multi_link_registry

Constrói um objeto `multi_link_registry`.

```cpp
multi_link_registry();
```

## <a name="dtor"></a>~ multi_link_registry

Destrói o objeto `multi_link_registry`.

```cpp
virtual ~multi_link_registry();
```

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_operation](invalid-operation-class.md) se chamado antes que todos os links sejam removidos.

## <a name="remove"></a>exclu

Remove um link do objeto `multi_link_registry`.

```cpp
virtual bool remove(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**true** se o link foi encontrado e removido; caso contrário, **false** .

## <a name="set_bound"></a>set_bound

Define um limite superior no número de links que o objeto `multi_link_registry` pode conter.

```cpp
void set_bound(size_t _MaxLinks);
```

### <a name="parameters"></a>Parâmetros

*_MaxLinks*<br/>
O número máximo de links que o objeto de `multi_link_registry` pode conter.

### <a name="remarks"></a>Comentários

Depois que um limite é definido, desvincular uma entrada fará com que o objeto `multi_link_registry` Insira um estado imutável em que outras chamadas para `add` gerarão uma exceção `invalid_link_target`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe single_link_registry](single-link-registry-class.md)
