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
ms.openlocfilehash: 24f89a6b2fb998ba5e5a82dbb470accb45d0fd9f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219541"
---
# <a name="single_link_registry-class"></a>Classe single_link_registry

O `single_link_registry` objeto é um `network_link_registry` que gerencia apenas um único bloco de origem ou de destino.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _Block>
class single_link_registry : public network_link_registry<_Block>;
```

### <a name="parameters"></a>parâmetros

*_Block*<br/>
O tipo de dados de bloco que está sendo armazenado no `single_link_registry` objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[single_link_registry](#ctor)|Constrói um objeto `single_link_registry`.|
|[~ single_link_registry destruidor](#dtor)|Destrói o `single_link_registry` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[add](#add)|Adiciona um link ao `single_link_registry` objeto. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|
|[Comece](#begin)|Retorna um iterador para o primeiro elemento no `single_link_registry` objeto. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|
|[contains](#contains)|Pesquisa o `single_link_registry` objeto em busca de um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|
|[contagem](#count)|Conta o número de itens no `single_link_registry` objeto. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|
|[remove](#remove)|Remove um link do `single_link_registry` objeto. (Substitui [network_link_registry:: Remove](network-link-registry-class.md#remove).)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[network_link_registry](network-link-registry-class.md)

`single_link_registry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a><a name="add"></a>agrega

Adiciona um link ao `single_link_registry` objeto.

```cpp
virtual void add(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_link_target](invalid-link-target-class.md) se já houver um link nesse registro.

## <a name="begin"></a><a name="begin"></a>Comece

Retorna um iterador para o primeiro elemento no `single_link_registry` objeto.

```cpp
virtual iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no `single_link_registry` objeto.

### <a name="remarks"></a>Comentários

O estado final é indicado por um `NULL` link.

## <a name="contains"></a><a name="contains"></a>terá

Pesquisa o `single_link_registry` objeto em busca de um bloco especificado.

```cpp
virtual bool contains(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco que deve ser procurado no `single_link_registry` objeto.

### <a name="return-value"></a>Valor retornado

**`true`** Se o link foi encontrado, **`false`** caso contrário.

## <a name="count"></a><a name="count"></a>contar

Conta o número de itens no `single_link_registry` objeto.

```cpp
virtual size_t count();
```

### <a name="return-value"></a>Valor retornado

O número de itens no objeto `single_link_registry`.

## <a name="remove"></a><a name="remove"></a>exclu

Remove um link do `single_link_registry` objeto.

```cpp
virtual bool remove(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**`true`** Se o link foi encontrado e removido, **`false`** caso contrário.

## <a name="single_link_registry"></a><a name="ctor"></a>single_link_registry

Constrói um objeto `single_link_registry`.

```cpp
single_link_registry();
```

## <a name="single_link_registry"></a><a name="dtor"></a>~ single_link_registry

Destrói o `single_link_registry` objeto.

```cpp
virtual ~single_link_registry();
```

### <a name="remarks"></a>Comentários

O método gera uma exceção [invalid_operation](invalid-operation-class.md) se for chamado antes de o link ser removido.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe multi_link_registry](multi-link-registry-class.md)
