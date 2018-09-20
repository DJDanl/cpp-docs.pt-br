---
title: Classe single_link_registry | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- single_link_registry
- AGENTS/concurrency::single_link_registry
- AGENTS/concurrency::single_link_registry::single_link_registry
- AGENTS/concurrency::single_link_registry::add
- AGENTS/concurrency::single_link_registry::begin
- AGENTS/concurrency::single_link_registry::contains
- AGENTS/concurrency::single_link_registry::count
- AGENTS/concurrency::single_link_registry::remove
dev_langs:
- C++
helpviewer_keywords:
- single_link_registry class
ms.assetid: 09540a4e-c34e-4ff9-af49-21b8612b6ab3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 30efbfa9c7c9b4be0c9b92e4ec5300a9c4313cb4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46448305"
---
# <a name="singlelinkregistry-class"></a>Classe single_link_registry

O `single_link_registry` objeto é um `network_link_registry` que gerencia apenas um único bloco de origem ou destino.

## <a name="syntax"></a>Sintaxe

```
template<class _Block>
class single_link_registry : public network_link_registry<_Block>;
```

#### <a name="parameters"></a>Parâmetros

*Bloco*<br/>
O bloco tipo de dados estão sendo armazenadas em do `single_link_registry` objeto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[single_link_registry](#ctor)|Constrói um objeto `single_link_registry`.|
|[~ single_link_registry destruidor](#dtor)|Destrói o `single_link_registry` objeto.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[add](#add)|Adiciona um link para o `single_link_registry` objeto. (Substitui [network_link_registry:: Add](network-link-registry-class.md#add).)|
|[begin](#begin)|Retorna um iterador para o primeiro elemento no `single_link_registry` objeto. (Substitui [network_link_registry:: Begin](network-link-registry-class.md#begin).)|
|[Contém](#contains)|Pesquisas de `single_link_registry` objeto para um bloco especificado. (Substitui [network_link_registry:: Contains](network-link-registry-class.md#contains).)|
|[count](#count)|Conta o número de itens no `single_link_registry` objeto. (Substitui [network_link_registry:: Count](network-link-registry-class.md#count).)|
|[remove](#remove)|Remove um link do `single_link_registry` objeto. (Substitui [network_link_registry:: remove](network-link-registry-class.md#remove).)|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[network_link_registry](network-link-registry-class.md)

`single_link_registry`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Agents. h

**Namespace:** simultaneidade

##  <a name="add"></a> Adicionar

Adiciona um link para o `single_link_registry` objeto.

```
virtual void add(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*Link*<br/>
Um ponteiro para um bloco a ser adicionado.

### <a name="remarks"></a>Comentários

O método lança um [invalid_link_target](invalid-link-target-class.md) exceção se já houver um link nesse registro.

##  <a name="begin"></a> começar

Retorna um iterador para o primeiro elemento no `single_link_registry` objeto.

```
virtual iterator begin();
```

### <a name="return-value"></a>Valor de retorno

Um iterador que trata o primeiro elemento no `single_link_registry` objeto.

### <a name="remarks"></a>Comentários

O estado final é indicado por um `NULL` link.

##  <a name="contains"></a> Contém

Pesquisas de `single_link_registry` objeto para um bloco especificado.

```
virtual bool contains(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*Link*<br/>
Um ponteiro para um bloco que deve ser pesquisado no `single_link_registry` objeto.

### <a name="return-value"></a>Valor de retorno

`true` Se o link foi encontrado, `false` caso contrário.

##  <a name="count"></a> Contagem

Conta o número de itens no `single_link_registry` objeto.

```
virtual size_t count();
```

### <a name="return-value"></a>Valor de retorno

O número de itens no objeto `single_link_registry`.

##  <a name="remove"></a> Remover

Remove um link do `single_link_registry` objeto.

```
virtual bool remove(_EType _Link);
```

### <a name="parameters"></a>Parâmetros

*Link*<br/>
Um ponteiro para um bloco a ser removido, se encontrado.

### <a name="return-value"></a>Valor de retorno

`true` Se o link foi encontrado e removido, `false` caso contrário.

##  <a name="ctor"></a> single_link_registry

Constrói um objeto `single_link_registry`.

```
single_link_registry();
```

##  <a name="dtor"></a> ~ single_link_registry

Destrói o `single_link_registry` objeto.

```
virtual ~single_link_registry();
```

### <a name="remarks"></a>Comentários

O método lança um [invalid_operation](invalid-operation-class.md) exceção se for chamado antes que o link seja removido.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Classe multi_link_registry](multi-link-registry-class.md)
