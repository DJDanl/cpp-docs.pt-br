---
title: Estrutura ITopologyNode
ms.date: 11/04/2016
f1_keywords:
- ITopologyNode
- CONCRTRM/concurrency::ITopologyNode
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetExecutionResourceCount
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetFirstExecutionResource
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetId
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetNext
- CONCRTRM/concurrency::ITopologyNode::ITopologyNode::GetNumaNode
helpviewer_keywords:
- ITopologyNode structure
ms.assetid: 92e7e032-04f6-4c7c-be36-8f9a35fc4734
ms.openlocfilehash: 7cb815c4f7dc5ad09e8d352abc3f3375b8d9e205
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368103"
---
# <a name="itopologynode-structure"></a>Estrutura ITopologyNode

Uma interface para um nó de topologia definida pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.

## <a name="syntax"></a>Sintaxe

```cpp
struct ITopologyNode;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ITopologyNode::GetExecutionResourceCount](#getexecutionresourcecount)|Retorna o número de recursos de execução agrupados sob este nó.|
|[ITopologyNode::GetFirstExecutionResource](#getfirstexecutionresource)|Retorna o primeiro recurso de execução agrupado sob este nó em ordem de enumeração.|
|[ITopologiaNode::GetId](#getid)|Retorna o identificador exclusivo do Gerenciador de recursos para este nó.|
|[ITopologyNode::GetNext](#getnext)|Retorna uma interface para o próximo nó de topologia em ordem de enumeração.|
|[ITopologiaNode::GetNumaNode](#getnumanode)|Retorna o número de nó NUMA atribuído ao Windows ao qual este nó de Maanger de recurso pertence.|

## <a name="remarks"></a>Comentários

Essa interface é normalmente utilizada para andar na topologia do sistema, conforme observado pelo Gerenciador de Recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITopologyNode`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="itopologynodegetexecutionresourcecount-method"></a><a name="getexecutionresourcecount"></a>ITopologyNode::GetExecutionResourceCount Method

Retorna o número de recursos de execução agrupados sob este nó.

```cpp
virtual unsigned int GetExecutionResourceCount() const = 0;
```

### <a name="return-value"></a>Valor retornado

O número de recursos de execução agrupados sob este nó.

## <a name="itopologynodegetfirstexecutionresource-method"></a><a name="getfirstexecutionresource"></a>ITopologyNode::GetFirstExecutionResource Method

Retorna o primeiro recurso de execução agrupado sob este nó em ordem de enumeração.

```cpp
virtual ITopologyExecutionResource *GetFirstExecutionResource() const = 0;
```

### <a name="return-value"></a>Valor retornado

O primeiro recurso de execução agrupado sob este nó em ordem de enumeração.

## <a name="itopologynodegetid-method"></a><a name="getid"></a>ITopologiaNode::Método GetId

Retorna o identificador exclusivo do Gerenciador de recursos para este nó.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

O identificador exclusivo do Gerenciador de Recursos para este nó.

### <a name="remarks"></a>Comentários

O Tempo de Execução de Concorrência representa threads de hardware no sistema em grupos de nós do processador. Os nós são geralmente derivados da topologia de hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó do processador. O Gerenciador de recursos atribui identificadores exclusivos a esses nós, começando `0` com e incluindo, `nodeCount - 1`onde `nodeCount` representa o número total de nós do processador no sistema.

A contagem de nós pode ser obtida a partir da função [GetProcessorNodeCount](concurrency-namespace-functions.md).

## <a name="itopologynodegetnext-method"></a><a name="getnext"></a>ITopologiaNode::GetNext Method

Retorna uma interface para o próximo nó de topologia em ordem de enumeração.

```cpp
virtual ITopologyNode *GetNext() const = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface para o próximo nó em ordem de enumeração. Se não houver mais nós na ordem de enumeração da topologia `NULL`do sistema, este método devolverá o valor .

## <a name="itopologynodegetnumanode-method"></a><a name="getnumanode"></a>ITopologiaNode::Método GetNumaNode

Retorna o número de nó NUMA atribuído ao Windows ao qual este nó de Maanger de recurso pertence.

```cpp
virtual unsigned long GetNumaNode() const = 0;
```

### <a name="return-value"></a>Valor retornado

O Windows atribuiu o número do nó NUMA ao qual este nó do Gerenciador de recursos pertence.

### <a name="remarks"></a>Comentários

Um proxy de thread em execução em uma raiz de processador virtual pertencente a este nó terá afinidade com pelo menos o nível de nó NUMA para o nó NUMA retornado por este método.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
