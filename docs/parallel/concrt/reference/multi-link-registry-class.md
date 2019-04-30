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
ms.openlocfilehash: 388cc0082f69041368d1a444179855451d552ce6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62394449"
---
# <a name="multilinkregistry-class"></a>Classe multi_link_registry

O `multi_link_registry` objeto é um `network_link_registry` que gerencia vários blocos de código-fonte ou vários blocos de destino.

## <a name="syntax"></a>Sintaxe

```
template<class _Block>
class multi_link_registry : public network_link_registry<_Block>;
```

#### <a name="parameters"></a>Parâmetros

*_Block*<br/>
O bloco tipo de dados estão sendo armazenadas em do `multi_link_registry` objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[multi_link_registry](#ctor)|Constrói um objeto `multi_link_registry`.|
|[~ multi_link_registry destruidor](#dtor)|Destrói o `multi_link_registry` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[add](#add)|Adiciona um link para o `multi_link_registry` objeto. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|
|[begin](#begin)|Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|
|[contains](#contains)|Pesquisas de `multi_link_registry` objeto para um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|
|[count](#count)|Conta o número de itens no `multi_link_registry` objeto. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|
|[remove](#remove)|Remove um link do `multi_link_registry` objeto. (Substitui [network_link_registry:: remove](network-link-registry-class.md#remove).)|
|[set_bound](#set_bound)|Define um limite superior no número de links que o `multi_link_registry` objeto pode conter.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[network_link_registry](network-link-registry-class.md)

`multi_link_registry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="add"></a> Adicionar

Adiciona um link para o `multi_link_registry` objeto.

```
virtual void add(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser adicionado.

### <a name="remarks"></a>Comentários

O método lança um [invalid_link_target](invalid-link-target-class.md) exceção se o link já está presente no registro, ou se um limite já foi definida com o `set_bound` função e um link já foi removido.

##  <a name="begin"></a> começar

Retorna um iterador para o primeiro elemento no `multi_link_registry` objeto.

```
virtual iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador que trata o primeiro elemento no `multi_link_registry` objeto.

### <a name="remarks"></a>Comentários

O estado final é indicado por um `NULL` link.

##  <a name="contains"></a> contains

Pesquisas de `multi_link_registry` objeto para um bloco especificado.

```
virtual bool contains(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco que deve ser pesquisado no `multi_link_registry` objeto.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o bloco especificado foi encontrado, **falso** caso contrário.

##  <a name="count"></a> Contagem

Conta o número de itens no `multi_link_registry` objeto.

```
virtual size_t count();
```

### <a name="return-value"></a>Valor de retorno

O número de itens no objeto `multi_link_registry`.

##  <a name="ctor"></a> multi_link_registry

Constrói um objeto `multi_link_registry`.

```
multi_link_registry();
```

##  <a name="dtor"></a> ~multi_link_registry

Destrói o `multi_link_registry` objeto.

```
virtual ~multi_link_registry();
```

### <a name="remarks"></a>Comentários

O método lança um [invalid_operation](invalid-operation-class.md) exceção se for chamado antes de todos os links são removidos.

##  <a name="remove"></a> Remover

Remove um link do `multi_link_registry` objeto.

```
virtual bool remove(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*_Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor de retorno

**Verdadeiro** se o link foi encontrado e removido, **falso** caso contrário.

##  <a name="set_bound"></a> set_bound

Define um limite superior no número de links que o `multi_link_registry` objeto pode conter.

```
void set_bound(size_t _MaxLinks);
```

### <a name="parameters"></a>Parâmetros

*_MaxLinks*<br/>
O número máximo de links que o `multi_link_registry` objeto pode conter.

### <a name="remarks"></a>Comentários

Após definir um limite, desvincular uma entrada fará com que o `multi_link_registry` objeto para entrar em um estado imutável em que nenhuma chamada para `add` lançará um `invalid_link_target` exceção.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe single_link_registry](single-link-registry-class.md)
