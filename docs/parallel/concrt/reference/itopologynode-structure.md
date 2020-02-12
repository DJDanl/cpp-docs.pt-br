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
ms.openlocfilehash: 1b4cb6a856d6da7b8eee7f9cba1ad51e375c024d
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140057"
---
# <a name="itopologynode-structure"></a>Estrutura ITopologyNode

Uma interface para um nó de topologia, conforme definido pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.

## <a name="syntax"></a>Sintaxe

```cpp
struct ITopologyNode;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[ITopologyNode::GetExecutionResourceCount](#getexecutionresourcecount)|Retorna o número de recursos de execução agrupados em conjunto neste nó.|
|[ITopologyNode::GetFirstExecutionResource](#getfirstexecutionresource)|Retorna o primeiro recurso de execução agrupado sob este nó na ordem de enumeração.|
|[ITopologyNode:: GetId](#getid)|Retorna o identificador exclusivo do Gerenciador de recursos para este nó.|
|[ITopologyNode:: GetNext](#getnext)|Retorna uma interface para o próximo nó de topologia na ordem de enumeração.|
|[ITopologyNode::GetNumaNode](#getnumanode)|Retorna o número de nó NUMA atribuído pelo Windows ao qual este nó maanger de recurso pertence.|

## <a name="remarks"></a>Comentários

Normalmente, essa interface é utilizada para percorrer a topologia do sistema, conforme observado pelo Gerenciador de recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITopologyNode`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="getexecutionresourcecount"></a>Método ITopologyNode:: GetExecutionResourceCount

Retorna o número de recursos de execução agrupados em conjunto neste nó.

```cpp
virtual unsigned int GetExecutionResourceCount() const = 0;
```

### <a name="return-value"></a>Valor retornado

O número de recursos de execução agrupados em conjunto neste nó.

## <a name="getfirstexecutionresource"></a>Método ITopologyNode:: GetFirstExecutionResource

Retorna o primeiro recurso de execução agrupado sob este nó na ordem de enumeração.

```cpp
virtual ITopologyExecutionResource *GetFirstExecutionResource() const = 0;
```

### <a name="return-value"></a>Valor retornado

O primeiro recurso de execução agrupado sob este nó na ordem de enumeração.

## <a name="getid"></a>Método ITopologyNode:: GetId

Retorna o identificador exclusivo do Gerenciador de recursos para este nó.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

O identificador exclusivo do Gerenciador de recursos para este nó.

### <a name="remarks"></a>Comentários

A Tempo de Execução de Simultaneidade representa os threads de hardware no sistema em grupos de nós de processador. Normalmente, os nós são derivados da topologia de hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó de processador. O Gerenciador de recursos atribui identificadores exclusivos a esses nós, começando com `0` até e incluindo `nodeCount - 1`, em que `nodeCount` representa o número total de nós de processador no sistema.

A contagem de nós pode ser obtida na função [GetProcessorNodeCount](concurrency-namespace-functions.md).

## <a name="getnext"></a>Método ITopologyNode:: GetNext

Retorna uma interface para o próximo nó de topologia na ordem de enumeração.

```cpp
virtual ITopologyNode *GetNext() const = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface para o próximo nó na ordem de enumeração. Se não houver mais nós na ordem de enumeração da topologia do sistema, esse método retornará o valor `NULL`.

## <a name="getnumanode"></a>Método ITopologyNode:: GetNumaNode

Retorna o número de nó NUMA atribuído pelo Windows ao qual este nó maanger de recurso pertence.

```cpp
virtual unsigned long GetNumaNode() const = 0;
```

### <a name="return-value"></a>Valor retornado

O número de nó NUMA atribuído pelo Windows ao qual este nó do Resource Manager pertence.

### <a name="remarks"></a>Comentários

Um proxy de thread em execução em uma raiz de processador virtual que pertence a esse nó terá afinidade com pelo menos o nível de nó NUMA para o nó NUMA retornado por esse método.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
