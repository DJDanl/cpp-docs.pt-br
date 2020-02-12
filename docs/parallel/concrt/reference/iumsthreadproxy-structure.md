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
ms.openlocfilehash: f4fb43a4223cad8cc63049d2a0f8345e48b90f17
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77139972"
---
# <a name="iumsthreadproxy-structure"></a>Estrutura IUMSThreadProxy

Uma abstração para um thread de execução. Se você quiser que o Agendador receba threads de agendáveis (UMS) no modo de usuário, defina o valor do elemento de política do Agendador `SchedulerKind` como `UmsThreadDefault`e implemente a interface `IUMSScheduler`. Os threads UMS têm suporte apenas em sistemas operacionais de 64 bits com versão Windows 7 e superior.

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSThreadProxy : public IThreadProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[IUMSThreadProxy::EnterCriticalRegion](#entercriticalregion)|Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não observará operações de bloqueio assíncronas que ocorrem durante a região. Isso significa que o Agendador não será reinserido para falhas de página, suspensões de thread, chamadas de procedimento assíncrono de kernel (APCs) e assim por diante, para um thread UMS.|
|[IUMSThreadProxy::EnterHyperCriticalRegion](#enterhypercriticalregion)|Chamado para inserir uma região do Hyper-Critical. Quando dentro de uma região do Hyper-Critical, o Agendador não observará nenhuma operação de bloqueio que ocorra durante a região. Isso significa que o Agendador não será reinserido para bloquear chamadas de função, bloquear tentativas de aquisição de bloqueio, falhas de página, suspensões de thread, chamadas de procedimento assíncrono de kernel (APCs) e assim por diante, para um thread UMS.|
|[IUMSThreadProxy::ExitCriticalRegion](#exitcriticalregion)|Chamado para sair de uma região crítica.|
|[IUMSThreadProxy::ExitHyperCriticalRegion](#exithypercriticalregion)|Chamado para sair de uma região do Hyper-Critical.|
|[IUMSThreadProxy::GetCriticalRegionType](#getcriticalregiontype)|Retorna o tipo de região crítica em que o proxy de thread está. Como as regiões do Hyper-Critical são um superconjunto de regiões críticas, se o código tiver inserido uma região crítica e, em seguida, uma região do Hyper-Critical, `InsideHyperCriticalRegion` será retornado.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[IThreadProxy](ithreadproxy-structure.md)

`IUMSThreadProxy`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** concrtrm. h

**Namespace:** simultaneidade

## <a name="entercriticalregion"></a>Método IUMSThreadProxy:: EnterCriticalRegion

Chamado para inserir uma região crítica. Quando dentro de uma região crítica, o Agendador não observará operações de bloqueio assíncronas que ocorrem durante a região. Isso significa que o Agendador não será reinserido para falhas de página, suspensões de thread, chamadas de procedimento assíncrono de kernel (APCs) e assim por diante, para um thread UMS.

```cpp
virtual int EnterCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região crítica. Regiões críticas são reentrante.

## <a name="enterhypercriticalregion"></a>Método IUMSThreadProxy:: EnterHyperCriticalRegion

Chamado para inserir uma região do Hyper-Critical. Quando dentro de uma região do Hyper-Critical, o Agendador não observará nenhuma operação de bloqueio que ocorra durante a região. Isso significa que o Agendador não será reinserido para bloquear chamadas de função, bloquear tentativas de aquisição de bloqueio, falhas de página, suspensões de thread, chamadas de procedimento assíncrono de kernel (APCs) e assim por diante, para um thread UMS.

```cpp
virtual int EnterHyperCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região do Hyper-Critical. As regiões do Hyper-Critical são reentrante.

### <a name="remarks"></a>Comentários

O Agendador deve ser bastante cuidadoso sobre os métodos que ele chama e quais bloqueios ele adquire em tais regiões. Se o código nesses blocos de região em um bloqueio for mantido por algo que o Agendador é responsável por agendar, o deadlock poderá acontecer.

## <a name="exitcriticalregion"></a>Método IUMSThreadProxy:: ExitCriticalRegion

Chamado para sair de uma região crítica.

```cpp
virtual int ExitCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região crítica. Regiões críticas são reentrante.

## <a name="exithypercriticalregion"></a>Método IUMSThreadProxy:: ExitHyperCriticalRegion

Chamado para sair de uma região do Hyper-Critical.

```cpp
virtual int ExitHyperCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região do Hyper-Critical. As regiões do Hyper-Critical são reentrante.

## <a name="getcriticalregiontype"></a>Método IUMSThreadProxy:: GetCriticalRegionType

Retorna o tipo de região crítica em que o proxy de thread está. Como as regiões do Hyper-Critical são um superconjunto de regiões críticas, se o código tiver inserido uma região crítica e, em seguida, uma região do Hyper-Critical, `InsideHyperCriticalRegion` será retornado.

```cpp
virtual CriticalRegionType GetCriticalRegionType() const = 0;
```

### <a name="return-value"></a>Valor retornado

O tipo de região crítica em que o proxy de thread está.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)
