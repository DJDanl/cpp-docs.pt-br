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
ms.openlocfilehash: 867e0543d1b9f2810a3fe761f038947c4d88da4d
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57268623"
---
# <a name="itopologynode-structure"></a>Estrutura ITopologyNode

Uma interface para um nó da topologia conforme definido pelo Gerenciador de recursos. Um nó contém um ou mais recursos de execução.

## <a name="syntax"></a>Sintaxe

```
struct ITopologyNode;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ITopologyNode::GetExecutionResourceCount](#getexecutionresourcecount)|Retorna o número de recursos de execução agrupados sob este nó.|
|[ITopologyNode::GetFirstExecutionResource](#getfirstexecutionresource)|Retorna o primeiro recurso de execução agrupado sob esse nó na ordem de enumeração.|
|[ITopologyNode::GetId](#getid)|Retorna o identificador exclusivo do Resource Manager deste nó.|
|[ITopologyNode::GetNext](#getnext)|Retorna uma interface para o próximo nó de topologia na ordem de enumeração.|
|[ITopologyNode::GetNumaNode](#getnumanode)|Retorna o Windows atribuído o número do nó ao qual pertence esse nó do Gerenciador de recursos.|

## <a name="remarks"></a>Comentários

Essa interface é normalmente usada para percorrer a topologia do sistema, conforme observado pelo Gerenciador de recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITopologyNode`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="getexecutionresourcecount"></a>  Método itopologynode:: Getexecutionresourcecount

Retorna o número de recursos de execução agrupados sob este nó.

```
virtual unsigned int GetExecutionResourceCount() const = 0;
```

### <a name="return-value"></a>Valor de retorno

O número de recursos de execução agrupados sob este nó.

##  <a name="getfirstexecutionresource"></a>  Método itopologynode:: Getfirstexecutionresource

Retorna o primeiro recurso de execução agrupado sob esse nó na ordem de enumeração.

```
virtual ITopologyExecutionResource *GetFirstExecutionResource() const = 0;
```

### <a name="return-value"></a>Valor de retorno

O primeiro recurso de execução agrupados sob esse nó na ordem de enumeração.

##  <a name="getid"></a>  Método itopologynode:: GetID

Retorna o identificador exclusivo do Resource Manager deste nó.

```
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

O Gerenciador de recursos do identificador exclusivo para este nó.

### <a name="remarks"></a>Comentários

O tempo de execução de simultaneidade representa threads de hardware no sistema em grupos de nós de processador. Nós geralmente são derivados da topologia do hardware do sistema. Por exemplo, todos os processadores em um soquete específico ou um nó NUMA específico podem pertencer ao mesmo nó de processador. O Gerenciador de recursos atribui identificadores exclusivos para esses nós começando com `0` até e incluindo `nodeCount - 1`, onde `nodeCount` representa o número total de nós de processador no sistema.

A contagem de nós pode ser obtida da função [GetProcessorNodeCount](concurrency-namespace-functions.md).

##  <a name="getnext"></a>  Método itopologynode:: GetNext

Retorna uma interface para o próximo nó de topologia na ordem de enumeração.

```
virtual ITopologyNode *GetNext() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Uma interface para o próximo nó na ordem de enumeração. Não se houver mais nenhum nó na ordem de enumeração da topologia do sistema, esse método retornará o valor `NULL`.

##  <a name="getnumanode"></a>  Método itopologynode:: Getnumanode

Retorna o Windows atribuído o número do nó ao qual pertence esse nó do Gerenciador de recursos.

```
virtual unsigned long GetNumaNode() const = 0;
```

### <a name="return-value"></a>Valor de retorno

O Windows atribuído o número do nó ao qual pertence este nó do Gerenciador de recursos.

### <a name="remarks"></a>Comentários

Um proxy de thread em execução em uma raiz de processador virtual que pertencem a esse nó terá afinidade com pelo menos o nível de nó para o nó NUMA retornado por esse método.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
