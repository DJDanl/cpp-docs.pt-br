---
title: Classe CNonStatelessWorker
ms.date: 11/04/2016
f1_keywords:
- CNonStatelessWorker
- ATLUTIL/ATL::CNonStatelessWorker
- ATLUTIL/ATL::CNonStatelessWorker::RequestType
- ATLUTIL/ATL::CNonStatelessWorker::Execute
- ATLUTIL/ATL::CNonStatelessWorker::Initialize
- ATLUTIL/ATL::CNonStatelessWorker::Terminate
helpviewer_keywords:
- CNonStatelessWorker class
ms.assetid: d00936c6-9e7d-49fb-b87d-417b963367d1
ms.openlocfilehash: f3604f95c8217c7407c100671265140bbadbab78
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81326729"
---
# <a name="cnonstatelessworker-class"></a>Classe CNonStatelessWorker

Recebe solicitações de um pool de segmentos e as repassa para um objeto de trabalhador que é criado e destruído em cada solicitação.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class Worker>
class CNonStatelessWorker
```

#### <a name="parameters"></a>Parâmetros

*Trabalho*<br/>
Uma classe de segmento de trabalhador em conformidade com o [arquétipo](../../atl/reference/worker-archetype.md) do trabalhador adequado para lidar com solicitações enfileiradas no [CThreadPool](../../atl/reference/cthreadpool-class.md).

## <a name="members"></a>Membros

### <a name="public-typedefs"></a>Typedefs públicos

|Nome|Descrição|
|----------|-----------------|
|[CNonStateworker::RequestType](#requesttype)|Implementação do [WorkerArchetype::RequestType](worker-archetype.md#requesttype).|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CNonStateWorker::Execute](#execute)|Implementação do [WorkerArchetype::Execute](worker-archetype.md#execute).|
|[CNonStatelessWorker::Initialize](#initialize)|Implementação do [WorkerArchetype::Initialize](worker-archetype.md#initialize).|
|[CNonStateworker::Terminate](#terminate)|Implementação [do WorkerArchetype::Terminate](worker-archetype.md#terminate).|

## <a name="remarks"></a>Comentários

Esta classe é um simples segmento de trabalho para uso com [CThreadPool](../../atl/reference/cthreadpool-class.md). Esta classe não fornece nenhuma capacidade de tratamento de solicitações própria. Em vez disso, instancia uma instância do *Trabalhador* por solicitação e delega a implementação de seus métodos para essa instância.

O benefício dessa classe é que ela fornece uma maneira conveniente de mudar o modelo de estado para as classes de segmentos de trabalhadores existentes. `CThreadPool`criará um único trabalhador durante toda a vida útil do segmento, portanto, se a classe trabalhadora mantiver o estado, ele irá mantê-lo em várias solicitações. Simplesmente embrulhar essa `CNonStatelessWorker` classe no modelo `CThreadPool`antes de usá-la com , a vida útil do trabalhador e do estado que ele possui está limitada a uma única solicitação.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlutil.h

## <a name="cnonstatelessworkerexecute"></a><a name="execute"></a>CNonStateWorker::Execute

Implementação do [WorkerArchetype::Execute](worker-archetype.md#execute).

```
void Execute(
    Worker::RequestType request,
    void* pvWorkerParam,
    OVERLAPPED* pOverlapped);
```

### <a name="remarks"></a>Comentários

Esse método cria uma instância da classe *Trabalhador* na pilha e chama [Inicialize](worker-archetype.md#initialize) nesse objeto. Se a inicialização for bem sucedida, este método também [chamará Executar](worker-archetype.md#execute) e [Terminar](worker-archetype.md#terminate) no mesmo objeto.

## <a name="cnonstatelessworkerinitialize"></a><a name="initialize"></a>CNonStatelessWorker::Initialize

Implementação do [WorkerArchetype::Initialize](worker-archetype.md#initialize).

```
BOOL Initialize(void* /* pvParam */) throw();
```

### <a name="return-value"></a>Valor retornado

Sempre retorna TRUE.

### <a name="remarks"></a>Comentários

Esta classe não faz nenhuma `Initialize`inicialização em .

## <a name="cnonstatelessworkerrequesttype"></a><a name="requesttype"></a>CNonStateworker::RequestType

Implementação do [WorkerArchetype::RequestType](worker-archetype.md#requesttype).

```
typedef Worker::RequestType RequestType;
```

### <a name="remarks"></a>Comentários

Esta classe lida com o mesmo tipo de item de trabalho que a classe usada para o parâmetro de modelo *trabalhador.* Consulte [cnonstatelessworker visão geral](../../atl/reference/cnonstatelessworker-class.md) para obter detalhes.

## <a name="cnonstatelessworkerterminate"></a><a name="terminate"></a>CNonStateworker::Terminate

Implementação [do WorkerArchetype::Terminate](worker-archetype.md#terminate).

```
void Terminate(void* /* pvParam */) throw();
```

### <a name="remarks"></a>Comentários

Esta classe não faz nenhuma `Terminate`limpeza em .

## <a name="see-also"></a>Confira também

[Classe CThreadPool](../../atl/reference/cthreadpool-class.md)<br/>
[Arquétipo operário](../../atl/reference/worker-archetype.md)<br/>
[Classes](../../atl/reference/atl-classes.md)
