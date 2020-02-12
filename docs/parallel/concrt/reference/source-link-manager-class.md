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
ms.openlocfilehash: 35c7cc72520cdb0675abf9c15574a49e33741d0b
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77142692"
---
# <a name="source_link_manager-class"></a>Classe source_link_manager

O objeto `source_link_manager` gerencia os links de rede do bloco de mensagens para blocos de `ISource`.

## <a name="syntax"></a>Sintaxe

```cpp
template<class _LinkRegistry>
class source_link_manager;
```

### <a name="parameters"></a>Parâmetros

*_LinkRegistry*<br/>
O registro de link de rede.

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|`const_pointer`|Um tipo que fornece um ponteiro para um elemento `const` em um objeto `source_link_manager`.|
|`const_reference`|Um tipo que fornece uma referência a um elemento `const` armazenado em um objeto `source_link_manager` para leitura e execução de operações const.|
|`iterator`|Um tipo que fornece um iterador que pode ler ou modificar qualquer elemento no objeto `source_link_manager`.|
|`type`|O tipo de registro de link que está sendo gerenciado pelo objeto `source_link_manager`.|

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[source_link_manager](#ctor)|Constrói um objeto `source_link_manager`.|
|[~ source_link_manager destruidor](#dtor)|Destrói o objeto `source_link_manager`.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[adicionar](#add)|Adiciona um link de origem ao objeto `source_link_manager`.|
|[begin](#begin)|Retorna um iterador para o primeiro elemento no objeto `source_link_manager`.|
|[contains](#contains)|Pesquisa o `network_link_registry` dentro deste objeto `source_link_manager` para um bloco especificado.|
|[contagem](#count)|Conta o número de blocos vinculados no objeto `source_link_manager`.|
|[reference](#reference)|Adquire uma referência no objeto `source_link_manager`.|
|[register_target_block](#register_target_block)|Registra o bloco de destino que mantém este `source_link_manager` objeto.|
|[release](#release)|Libera a referência no objeto `source_link_manager`.|
|[remove](#remove)|Remove um link do objeto `source_link_manager`.|
|[set_bound](#set_bound)|Define o número máximo de links de origem que podem ser adicionados a este `source_link_manager` objeto.|

## <a name="remarks"></a>Comentários

Atualmente, os blocos de origem são referências contadas. Esse é um wrapper em um objeto `network_link_registry` que permite o acesso simultâneo aos links e fornece a capacidade de fazer referência aos links por meio de retornos de chamada. Os blocos de mensagens (`target_block`s ou `propagator_block`s) devem usar essa classe para seus links de origem.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`source_link_manager`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

## <a name="add"></a>agrega

Adiciona um link de origem ao objeto `source_link_manager`.

```cpp
void add(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

## <a name="begin"></a>Comece

Retorna um iterador para o primeiro elemento no objeto `source_link_manager`.

```cpp
iterator begin();
```

### <a name="return-value"></a>Valor retornado

Um iterador que aborda o primeiro elemento no objeto `source_link_manager`.

### <a name="remarks"></a>Comentários

O estado final do iterador é indicado por um link `NULL`.

## <a name="contains"></a>terá

Pesquisa o `network_link_registry` dentro deste objeto `source_link_manager` para um bloco especificado.

```cpp
bool contains(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco que deve ser procurado no objeto `source_link_manager`.

### <a name="return-value"></a>Valor retornado

**true** se o bloco especificado foi encontrado; caso contrário, **false** .

## <a name="count"></a>contar

Conta o número de blocos vinculados no objeto `source_link_manager`.

```cpp
size_t count();
```

### <a name="return-value"></a>Valor retornado

O número de blocos vinculados no objeto `source_link_manager`.

## <a name="reference"></a>referência

Adquire uma referência no objeto `source_link_manager`.

```cpp
void reference();
```

## <a name="register_target_block"></a>register_target_block

Registra o bloco de destino que mantém este `source_link_manager` objeto.

```cpp
void register_target_block(_Inout_ ITarget<typename _Block::source_type>* _PTarget);
```

### <a name="parameters"></a>Parâmetros

*_PTarget*<br/>
O bloco de destino que contém este `source_link_manager` objeto.

## <a name="release"></a>liberar

Libera a referência no objeto `source_link_manager`.

```cpp
void release();
```

## <a name="remove"></a>exclu

Remove um link do objeto `source_link_manager`.

```cpp
bool remove(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor retornado

**true** se o link foi encontrado e removido; caso contrário, **false** .

## <a name="set_bound"></a>set_bound

Define o número máximo de links de origem que podem ser adicionados a este `source_link_manager` objeto.

```cpp
void set_bound(size_t _MaxLinks);
```

### <a name="parameters"></a>Parâmetros

*_MaxLinks*<br/>
O número máximo de links.

## <a name="ctor"></a>source_link_manager

Constrói um objeto `source_link_manager`.

```cpp
source_link_manager();
```

## <a name="dtor"></a>~ source_link_manager

Destrói o objeto `source_link_manager`.

```cpp
~source_link_manager();
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe single_link_registry](single-link-registry-class.md)<br/>
[Classe multi_link_registry](multi-link-registry-class.md)
