---
title: Estrutura IUMSThreadProxy
ms.date: 11/04/2016
f1_keywords:
- IUMSThreadProxy
- CONCRTRM/concurrency::IUMSThreadProxy
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::EnterCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::EnterHyperCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::ExitCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::ExitHyperCriticalRegion
- CONCRTRM/concurrency::IUMSThreadProxy::IUMSThreadProxy::GetCriticalRegionType
helpviewer_keywords:
- IUMSThreadProxy structure
ms.assetid: 61c69b7e-5c37-4048-bcb4-e75c536afd86
ms.openlocfilehash: 9a0fca40f353f64799c4df9001952cb668cd0678
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50657114"
---
# <a name="iumsthreadproxy-structure"></a>Estrutura IUMSThreadProxy

Uma abstração para um thread de execução. Se você quiser que seu Agendador para ser concedida a threads agendáveis no modo de usuário (UMS), defina o valor para o elemento de política de Agendador `SchedulerKind` à `UmsThreadDefault`e implementar o `IUMSScheduler` interface. Threads UMS são apenas com suporte em sistemas operacionais de 64 bits com a versão do Windows 7 e superior.

## <a name="syntax"></a>Sintaxe

```
struct IUMSThreadProxy : public IThreadProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[IUMSThreadProxy::EnterCriticalRegion](#entercriticalregion)|Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não obedecerão bloqueio de operações assíncrona que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para falhas de página, suspensões do thread, chamadas de procedimento assíncrono (APCs) do kernel e assim por diante, para um thread UMS.|
|[IUMSThreadProxy::EnterHyperCriticalRegion](#enterhypercriticalregion)|Chamado para entrar em uma região de hyper-crítica. Quando dentro de uma região de hyper-crítica, o Agendador não obedecerão bloqueio de operações que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para bloqueio de chamadas de função, tentativas de aquisição de bloqueio qual bloco, falhas de página, suspensões, chamadas de procedimento assíncrono (APCs) do kernel do thread e assim por diante, para um UMS thread.|
|[IUMSThreadProxy::ExitCriticalRegion](#exitcriticalregion)|Chamado para sair de uma região crítica.|
|[IUMSThreadProxy::ExitHyperCriticalRegion](#exithypercriticalregion)|Chamado para sair de uma região hyper crítica.|
|[IUMSThreadProxy::GetCriticalRegionType](#getcriticalregiontype)|Retorna o tipo de região crítica, o proxy de thread está dentro do. Como regiões hyper críticas são um superconjunto de regiões críticas, se o código entrou em uma região crítica e, em seguida, uma região de hyper-crítica, `InsideHyperCriticalRegion` será retornado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[IThreadProxy](ithreadproxy-structure.md)

`IUMSThreadProxy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

##  <a name="entercriticalregion"></a>  Método iumsthreadproxy:: Entercriticalregion

Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não obedecerão bloqueio de operações assíncrona que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para falhas de página, suspensões do thread, chamadas de procedimento assíncrono (APCs) do kernel e assim por diante, para um thread UMS.

```
virtual int EnterCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor de retorno

A nova profundidade da região crítica. Regiões críticas são reentrantes.

##  <a name="enterhypercriticalregion"></a>  Método iumsthreadproxy:: Enterhypercriticalregion

Chamado para entrar em uma região de hyper-crítica. Quando dentro de uma região de hyper-crítica, o Agendador não obedecerão bloqueio de operações que ocorrem durante a região. Isso significa que o Agendador não será ser reinserido para bloqueio de chamadas de função, tentativas de aquisição de bloqueio qual bloco, falhas de página, suspensões, chamadas de procedimento assíncrono (APCs) do kernel do thread e assim por diante, para um UMS thread.

```
virtual int EnterHyperCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor de retorno

A profundidade de novo da região hyper crítica. Regiões Hyper críticas são reentrantes.

### <a name="remarks"></a>Comentários

O Agendador deve ser extraordinariamente cuidado em relação a quais métodos chamados por ele e o que bloqueia-adquire em tais regiões. Se o código em tal região bloqueia um bloqueio é mantido por algo que o Agendador é responsável por agendar, pode surgir deadlock.

##  <a name="exitcriticalregion"></a>  Método iumsthreadproxy:: Exitcriticalregion

Chamado para sair de uma região crítica.

```
virtual int ExitCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor de retorno

A nova profundidade da região crítica. Regiões críticas são reentrantes.

##  <a name="exithypercriticalregion"></a>  Método iumsthreadproxy:: Exithypercriticalregion

Chamado para sair de uma região hyper crítica.

```
virtual int ExitHyperCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor de retorno

A profundidade de novo da região hyper crítica. Regiões Hyper críticas são reentrantes.

##  <a name="getcriticalregiontype"></a>  Método iumsthreadproxy:: Getcriticalregiontype

Retorna o tipo de região crítica, o proxy de thread está dentro do. Como regiões hyper críticas são um superconjunto de regiões críticas, se o código entrou em uma região crítica e, em seguida, uma região de hyper-crítica, `InsideHyperCriticalRegion` será retornado.

```
virtual CriticalRegionType GetCriticalRegionType() const = 0;
```

### <a name="return-value"></a>Valor de retorno

O tipo de região crítica, que o proxy de thread está dentro do.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)
