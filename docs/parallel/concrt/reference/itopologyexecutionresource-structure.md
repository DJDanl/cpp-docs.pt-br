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
ms.openlocfilehash: 4bfb614d5ffd6a399fae33d38a50cee62f17c208
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64339500"
---
# <a name="itopologyexecutionresource-structure"></a>Estrutura ITopologyExecutionResource

Uma interface para um recurso de execução, conforme definido pelo Gerenciador de recursos.

## <a name="syntax"></a>Sintaxe

```
struct ITopologyExecutionResource;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ITopologyExecutionResource::GetId](#getid)|Retorna o identificador exclusivo do Gerenciador de recursos para este recurso de execução.|
|[ITopologyExecutionResource::GetNext](#getnext)|Retorna uma interface para o próximo recurso de execução na ordem de enumeração.|

## <a name="remarks"></a>Comentários

Essa interface é normalmente usada para percorrer a topologia do sistema, conforme observado pelo Gerenciador de recursos.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ITopologyExecutionResource`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="getid"></a>  Método itopologyexecutionresource:: GetID

Retorna o identificador exclusivo do Gerenciador de recursos para este recurso de execução.

```
virtual unsigned int GetId() const = 0;
```

### <a name="return-value"></a>Valor de retorno

O Gerenciador de recursos do identificador exclusivo para este recurso de execução.

##  <a name="getnext"></a>  Método itopologyexecutionresource:: GetNext

Retorna uma interface para o próximo recurso de execução na ordem de enumeração.

```
virtual ITopologyExecutionResource *GetNext() const = 0;
```

### <a name="return-value"></a>Valor de retorno

Uma interface para o próximo recurso de execução na ordem de enumeração. Não se houver mais nenhum nó na ordem de enumeração do nó ao qual pertence este recurso de execução, esse método retornará o valor `NULL`.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
