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
ms.openlocfilehash: 2c9221cab1ac2d48bd099a769188e4bee797823c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368143"
---
# <a name="itopologyexecutionresource-structure"></a>Estrutura ITopologyExecutionResource

Uma interface para um recurso de execução definida pelo Gerenciador de recursos.

## <a name="syntax"></a>Sintaxe

```cpp
struct ITopologyExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[ITopologyExecutionResource::GetId](#getid)|Retorna o identificador exclusivo do Gerenciador de Recursos para este recurso de execução.|
|[ITopologyExecutionResource::GetNext](#getnext)|Retorna uma interface para o próximo recurso de execução em ordem de enumeração.|

## <a name="remarks"></a>Comentários

Essa interface é normalmente utilizada para andar na topologia do sistema, conforme observado pelo Gerenciador de Recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITopologyExecutionResource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="itopologyexecutionresourcegetid-method"></a><a name="getid"></a>ITopologyExecutionResource::GetId Method

Retorna o identificador exclusivo do Gerenciador de Recursos para este recurso de execução.

```cpp
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor retornado

O identificador exclusivo do Gerenciador de Recursos para este recurso de execução.

## <a name="itopologyexecutionresourcegetnext-method"></a><a name="getnext"></a>ITopologyExecutionResource::GetNext Method

Retorna uma interface para o próximo recurso de execução em ordem de enumeração.

```cpp
virtual ITopologyExecutionResource *GetNext() const = 0;
```

### <a name="return-value"></a>Valor retornado

Uma interface para o próximo recurso de execução em ordem de enumeração. Se não houver mais nós na ordem de enumeração do nó ao qual este `NULL`recurso de execução pertence, este método devolverá o valor .

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)
