---
title: Estrutura ITopologyExecutionResource
ms.date: 11/04/2016
f1_keywords:
- ITopologyExecutionResource
- CONCRTRM/concurrency::ITopologyExecutionResource
- CONCRTRM/concurrency::ITopologyExecutionResource::ITopologyExecutionResource::GetId
- CONCRTRM/concurrency::ITopologyExecutionResource::ITopologyExecutionResource::GetNext
helpviewer_keywords:
- ITopologyExecutionResource structure
ms.assetid: e36756f7-4cd9-4fa6-ba60-23fea58ef2bf
ms.openlocfilehash: 82193a9b592cded96f3726cbabd6cf646eaa27c8
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77140075"
---
# <a name="itopologyexecutionresource-structure"></a>Estrutura ITopologyExecutionResource

Uma interface para um recurso de execução, conforme definido pelo Gerenciador de recursos.

## <a name="syntax"></a>Sintaxe

```cpp
struct ITopologyExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[ITopologyExecutionResource:: GetId](#getid)|Retorna o identificador exclusivo do Gerenciador de recursos para este recurso de execução.|
|[ITopologyExecutionResource:: GetNext](#getnext)|Retorna uma interface para o próximo recurso de execução na ordem de enumeração.|

## <a name="remarks"></a>Comentários

Normalmente, essa interface é utilizada para percorrer a topologia do sistema, conforme observado pelo Gerenciador de recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITopologyExecutionResource`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="getid"></a>Método ITopologyExecutionResource:: GetId

Retorna o identificador exclusivo do Gerenciador de recursos para este recurso de execução.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

O identificador exclusivo do Gerenciador de recursos para este recurso de execução.

## <a name="getnext"></a>Método ITopologyExecutionResource:: GetNext

Retorna uma interface para o próximo recurso de execução na ordem de enumeração.

```cpp
virtual ITopologyExecutionResource *GetNext() const = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface para o próximo recurso de execução na ordem de enumeração. Se não houver mais nós na ordem de enumeração do nó ao qual esse recurso de execução pertence, esse método retornará o valor `NULL`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
