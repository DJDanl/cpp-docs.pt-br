---
title: Classe source_link_manager
ms.date: 11/04/2016
f1_keywords:
- source_link_manager
- AGENTS/concurrency::source_link_manager
- AGENTS/concurrency::source_link_manager::source_link_manager
- AGENTS/concurrency::source_link_manager::add
- AGENTS/concurrency::source_link_manager::begin
- AGENTS/concurrency::source_link_manager::contains
- AGENTS/concurrency::source_link_manager::count
- AGENTS/concurrency::source_link_manager::reference
- AGENTS/concurrency::source_link_manager::register_target_block
- AGENTS/concurrency::source_link_manager::release
- AGENTS/concurrency::source_link_manager::remove
- AGENTS/concurrency::source_link_manager::set_bound
helpviewer_keywords:
- source_link_manager class
ms.assetid: 287487cf-e0fe-4c35-aa3c-24f081d1ddae
ms.openlocfilehash: 98f99bb5aec85a640eaf83a07fae3a1b667f7d91
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228421"
---
# <a name="source_link_manager-class"></a>Classe source_link_manager

O `source_link_manager` objeto gerencia os links de rede do bloco de mensagens para `ISource` blocos.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _LinkRegistry>
class source_link_manager;
```

### <a name="parameters"></a>parâmetros

*_LinkRegistry*<br/>
O registro de link de rede.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|`const_pointer`|Um tipo que fornece um ponteiro para um **`const`** elemento em um `source_link_manager` objeto.|
|`const_reference`|Um tipo que fornece uma referência a um **`const`** elemento armazenado em um `source_link_manager` objeto para leitura e execução de operações const.|
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento no `source_link_manager` objeto.|
|`type`|O tipo de registro de link que está sendo gerenciado pelo `source_link_manager` objeto.|

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[source_link_manager](#ctor)|Constrói um objeto `source_link_manager`.|
|[~ source_link_manager destruidor](#dtor)|Destrói o `source_link_manager` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[add](#add)|Adiciona um link de origem ao `source_link_manager` objeto.|
|[Comece](#begin)|Retorna um iterador para o primeiro elemento no `source_link_manager` objeto.|
|[contains](#contains)|Pesquisa o `network_link_registry` dentro deste `source_link_manager` objeto em busca de um bloco especificado.|
|[contagem](#count)|Conta o número de blocos vinculados no `source_link_manager` objeto.|
|[reference](#reference)|Adquire uma referência no `source_link_manager` objeto.|
|[register_target_block](#register_target_block)|Registra o bloco de destino que contém esse `source_link_manager` objeto.|
|[liberar](#release)|Libera a referência no `source_link_manager` objeto.|
|[remove](#remove)|Remove um link do `source_link_manager` objeto.|
|[set_bound](#set_bound)|Define o número máximo de links de origem que podem ser adicionados a esse `source_link_manager` objeto.|

## <a name="remarks"></a>Comentários

Atualmente, os blocos de origem são referências contadas. Esse é um wrapper em um `network_link_registry` objeto que permite o acesso simultâneo aos links e fornece a capacidade de fazer referência aos links por meio de retornos de chamada. `target_block` `propagator_block` Os blocos de mensagens devem usar essa classe para seus links de origem.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`source_link_manager`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a><a name="add"></a>agrega

Adiciona um link de origem ao `source_link_manager` objeto.

```cpp
void add(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

## <a name="begin"></a><a name="begin"></a>Comece

Retorna um iterador para o primeiro elemento no `source_link_manager` objeto.

```cpp
iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no `source_link_manager` objeto.

### <a name="remarks"></a>Comentários

O estado final do iterador é indicado por um `NULL` link.

## <a name="contains"></a><a name="contains"></a>terá

Pesquisa o `network_link_registry` dentro deste `source_link_manager` objeto em busca de um bloco especificado.

```cpp
bool contains(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco que deve ser procurado no `source_link_manager` objeto.

### <a name="return-value"></a>Valor retornado

**`true`** caso contrário, o bloco especificado foi encontrado **`false`** .

## <a name="count"></a><a name="count"></a>contar

Conta o número de blocos vinculados no `source_link_manager` objeto.

```cpp
size_t count();
```

### <a name="return-value"></a>Valor retornado

O número de blocos vinculados no `source_link_manager` objeto.

## <a name="reference"></a><a name="reference"></a>referência

Adquire uma referência no `source_link_manager` objeto.

```cpp
void reference();
```

## <a name="register_target_block"></a><a name="register_target_block"></a>register_target_block

Registra o bloco de destino que contém esse `source_link_manager` objeto.

```cpp
void register_target_block(_Inout_ ITarget<typename _Block::source_type>* _PTarget);
```

### <a name="parameters"></a>parâmetros

*_PTarget*<br/>
O bloco de destino que retém este `source_link_manager` objeto.

## <a name="release"></a><a name="release"></a>liberar

Libera a referência no `source_link_manager` objeto.

```cpp
void release();
```

## <a name="remove"></a><a name="remove"></a>exclu

Remove um link do `source_link_manager` objeto.

```cpp
bool remove(_EType _Link);
```

### <a name="parameters"></a>parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**`true`** Se o link foi encontrado e removido, **`false`** caso contrário.

## <a name="set_bound"></a><a name="set_bound"></a>set_bound

Define o número máximo de links de origem que podem ser adicionados a esse `source_link_manager` objeto.

```cpp
void set_bound(size_t _MaxLinks);
```

### <a name="parameters"></a>parâmetros

*_MaxLinks*<br/>
O número máximo de links.

## <a name="source_link_manager"></a><a name="ctor"></a>source_link_manager

Constrói um objeto `source_link_manager`.

```cpp
source_link_manager();
```

## <a name="source_link_manager"></a><a name="dtor"></a>~ source_link_manager

Destrói o `source_link_manager` objeto.

```cpp
~source_link_manager();
```

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe single_link_registry](single-link-registry-class.md)<br/>
[Classe multi_link_registry](multi-link-registry-class.md)
