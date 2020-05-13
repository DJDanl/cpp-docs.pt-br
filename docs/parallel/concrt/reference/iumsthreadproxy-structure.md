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
ms.openlocfilehash: 2e748b1da02394e1f70afd8b92947e1291957c62
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81368076"
---
# <a name="iumsthreadproxy-structure"></a>Estrutura IUMSThreadProxy

Uma abstração para um fio de execução. Se você quiser que o seu agendador seja concedido threads de agendamento (UMS) `SchedulerKind` `UmsThreadDefault`no modo `IUMSScheduler` de usuário, defina o valor para o elemento de diretiva do agendador e implemente a interface. Os threads UMS só são suportados em sistemas operacionais de 64 bits com a versão Windows 7 ou superior.

## <a name="syntax"></a>Sintaxe

```cpp
struct IUMSThreadProxy : public IThreadProxy;
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[IUMSThreadproxy::EntercriticalRegion](#entercriticalregion)|Chamado para entrar em uma região crítica. Quando dentro de uma região crítica, o agendador não observará operações de bloqueio assíncronas que acontecem durante a região. Isso significa que o agendador não será reinserido por falhas de página, suspensões de rosca, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um segmento UMS.|
|[IUMSThreadproxy::EnterHyperCriticalRegion](#enterhypercriticalregion)|Chamado para entrar em uma região hipercrítica. Quando dentro de uma região hipercrítica, o agendador não observará nenhuma operação de bloqueio que aconteça durante a região. Isso significa que o agendador não será reinserido para bloquear chamadas de função, bloquear tentativas de aquisição que bloqueiam, falhas de página, suspensões de rosca, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um segmento UMS.|
|[IUMSThreadproxy::ExitcriticalRegion](#exitcriticalregion)|Chamado para sair de uma região crítica.|
|[IUMSThreadproxy::ExitHyperCriticalRegion](#exithypercriticalregion)|Chamado para sair de uma região hipercrítica.|
|[IUMSThreadproxy::getcriticalRegionType](#getcriticalregiontype)|Retorna que tipo de região crítica o proxy de segmento está dentro. Como as regiões hipercríticas são um superconjunto de regiões críticas, se o `InsideHyperCriticalRegion` código entrou em uma região crítica e, em seguida, uma região hipercrítica, será devolvida.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Ithreadproxy](ithreadproxy-structure.md)

`IUMSThreadProxy`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** concrtrm.h

**Namespace:** concurrency

## <a name="iumsthreadproxyentercriticalregion-method"></a><a name="entercriticalregion"></a>IUMSThreadproxy::Método EntercriticalRegion

Chamado para entrar em uma região crítica. Quando dentro de uma região crítica, o agendador não observará operações de bloqueio assíncronas que acontecem durante a região. Isso significa que o agendador não será reinserido por falhas de página, suspensões de rosca, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um segmento UMS.

```cpp
virtual int EnterCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região crítica. Regiões críticas são reentrantes.

## <a name="iumsthreadproxyenterhypercriticalregion-method"></a><a name="enterhypercriticalregion"></a>IUMSThreadproxy::Método enterHyperCriticalRegion

Chamado para entrar em uma região hipercrítica. Quando dentro de uma região hipercrítica, o agendador não observará nenhuma operação de bloqueio que aconteça durante a região. Isso significa que o agendador não será reinserido para bloquear chamadas de função, bloquear tentativas de aquisição que bloqueiam, falhas de página, suspensões de rosca, chamadas de procedimento assíncrono do kernel (APCs) e assim por diante, para um segmento UMS.

```cpp
virtual int EnterHyperCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região hipercrítica. Regiões hipercríticas são reentrantes.

### <a name="remarks"></a>Comentários

O agendador deve ser extraordinariamente cuidadoso sobre quais métodos ele chama e quais bloqueios ele adquire nessas regiões. Se o código em tal região bloqueia um bloqueio que é mantido por algo que o agendador é responsável pelo agendamento, o impasse pode ocorrer.

## <a name="iumsthreadproxyexitcriticalregion-method"></a><a name="exitcriticalregion"></a>IUMSThreadProxy::ExitCriticalRegion Method

Chamado para sair de uma região crítica.

```cpp
virtual int ExitCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região crítica. Regiões críticas são reentrantes.

## <a name="iumsthreadproxyexithypercriticalregion-method"></a><a name="exithypercriticalregion"></a>IUMSThreadProxy::ExitHyperCriticalRegion Method

Chamado para sair de uma região hipercrítica.

```cpp
virtual int ExitHyperCriticalRegion() = 0;
```

### <a name="return-value"></a>Valor retornado

A nova profundidade da região hipercrítica. Regiões hipercríticas são reentrantes.

## <a name="iumsthreadproxygetcriticalregiontype-method"></a><a name="getcriticalregiontype"></a>IUMSThreadProxy::GetCriticalRegionType Method

Retorna que tipo de região crítica o proxy de segmento está dentro. Como as regiões hipercríticas são um superconjunto de regiões críticas, se o `InsideHyperCriticalRegion` código entrou em uma região crítica e, em seguida, uma região hipercrítica, será devolvida.

```cpp
virtual CriticalRegionType GetCriticalRegionType() const = 0;
```

### <a name="return-value"></a>Valor retornado

O tipo de região crítica que o proxy thread está dentro.

## <a name="see-also"></a>Confira também

[namespace de concorrência](concurrency-namespace.md)<br/>
[Estrutura IUMSScheduler](iumsscheduler-structure.md)
