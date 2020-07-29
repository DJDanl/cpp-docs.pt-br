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
ms.openlocfilehash: 777b3f5206b4a595b5dcac653d608255e92f4ef6
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87231696"
---
# <a name="multi_link_registry-class"></a>Classe multi_link_registry

O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de origem ou vários blocos de destino.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Block>
class multi_link_registry : public network_link_registry<_Block>;
```

### <a name="parameters"></a>parâmetros

*_Block*<br/>
O tipo de dados de bloco que está sendo armazenado no `multi_link_registry` objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[multi_link_registry](#ctor)|Constrói um objeto `multi_link_registry`.|
|[~ multi_link_registry destruidor](#dtor)|Destrói o `multi_link_registry` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[add](#add)|Adiciona um link ao `multi_link_registry` objeto. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|
|[Comece](#begin)|Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|
|[contains](#contains)|Pesquisa o `multi_link_registry` objeto em busca de um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|
|[contagem](#count)|Conta o número de itens no `multi_link_registry` objeto. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|
|[remove](#remove)|Remove um link do `multi_link_registry` objeto. (Substitui [network_link_registry:: Remove](network-link-registry-class.md#remove).)|
|[set_bound](#set_bound)|Define um limite superior no número de links que o `multi_link_registry` objeto pode conter.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[network_link_registry](network-link-registry-class.md)

`multi_link_registry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a><a name="add"></a>agrega

Adiciona um link ao `multi_link_registry` objeto.

```cpp
virtual void add(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_link_target](invalid-link-target-class.md) se o link já estiver presente no registro ou se um associado já tiver sido definido com a `set_bound` função e um link tiver sido removido.

## <a name="begin"></a><a name="begin"></a>Comece

Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto.

```cpp
virtual iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no `multi_link_registry` objeto.

### <a name="remarks"></a>Comentários

O estado final é indicado por um `NULL` link.

## <a name="contains"></a><a name="contains"></a>terá

Pesquisa o `multi_link_registry` objeto em busca de um bloco especificado.

```cpp
virtual bool contains(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco que deve ser procurado no `multi_link_registry` objeto.

### <a name="return-value"></a>Valor retornado

**`true`** caso contrário, o bloco especificado foi encontrado **`false`** .

## <a name="count"></a><a name="count"></a>contar

Conta o número de itens no `multi_link_registry` objeto.

```cpp
virtual size_t count();
```

### <a name="return-value"></a>Valor retornado

O número de itens no objeto `multi_link_registry`.

## <a name="multi_link_registry"></a><a name="ctor"></a>multi_link_registry

Constrói um objeto `multi_link_registry`.

```cpp
multi_link_registry();
```

## <a name="multi_link_registry"></a><a name="dtor"></a>~ multi_link_registry

Destrói o `multi_link_registry` objeto.

```cpp
virtual ~multi_link_registry();
```

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_operation](invalid-operation-class.md) se chamado antes que todos os links sejam removidos.

## <a name="remove"></a><a name="remove"></a>exclu

Remove um link do `multi_link_registry` objeto.

```cpp
virtual bool remove(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**`true`** Se o link foi encontrado e removido, **`false`** caso contrário.

## <a name="set_bound"></a><a name="set_bound"></a>set_bound

Define um limite superior no número de links que o `multi_link_registry` objeto pode conter.

```cpp
void set_bound(size_t _MaxLinks);
```

### <a name="parameters"></a>parâmetros

*_MaxLinks*<br/>
O número máximo de links que o `multi_link_registry` objeto pode conter.

### <a name="remarks"></a>Comentários

Depois que um limite é definido, desvincular uma entrada fará com que o `multi_link_registry` objeto Insira um estado imutável em que outras chamadas para gerarão `add` uma `invalid_link_target` exceção.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe single_link_registry](single-link-registry-class.md)
