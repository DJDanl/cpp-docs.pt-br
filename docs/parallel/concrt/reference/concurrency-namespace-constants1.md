---
title: constantes de namespace de simultaneidade | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- concrt/concurrency::AgentEventGuid
- concrt/concurrency::COOPERATIVE_TIMEOUT_INFINITE
- concrt/concurrency::COOPERATIVE_WAIT_TIMEOUT
- concrt/concurrency::ConcRTEventGuid
- concrt/concurrency::ConcRT_ProviderGuid
- concrt/concurrency::INHERIT_THREAD_PRIORITY
- concrt/concurrency::LockEventGuid
- concrt/concurrency::PPLParallelForEventGuid
- concrt/concurrency::PPLParallelForeachEventGuid
- concrt/concurrency::ResourceManagerEventGuid
- concrt/concurrency::ScheduleGroupEventGuid
- concrt/concurrency::VirtualProcessorEventGuid
dev_langs:
- C++
ms.assetid: 6f81fc4c-b10c-479e-8717-9c292360d5a0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 09971915b5adc8d083e2ca5007297b87eb55a329
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439517"
---
# <a name="concurrency-namespace-constants"></a>constantes de namespace de simultaneidade

||||
|-|-|-|
|[AgentEventGuid](#agenteventguid)|[CONCRT_RM_VERSION_1](#concrt_rm_version_1)|[COOPERATIVE_TIMEOUT_INFINITE](#cooperative_timeout_infinite)|
|[COOPERATIVE_WAIT_TIMEOUT](#cooperative_wait_timeout)|[ChoreEventGuid](#choreeventguid)|[ConcRTEventGuid](#concrteventguid)|
|[ConcRT_ProviderGuid](#concrt_providerguid)|[ContextEventGuid](#contexteventguid)|[INHERIT_THREAD_PRIORITY](#inherit_thread_priority)|
|[LockEventGuid](#lockeventguid)|[MaxExecutionResources](#maxexecutionresources)|[PPLParallelForEventGuid](#pplparallelforeventguid)|
|[PPLParallelForeachEventGuid](#pplparallelforeacheventguid)|[PPLParallelInvokeEventGuid](#pplparallelinvokeeventguid)|[ResourceManagerEventGuid](#resourcemanagereventguid)|
|[ScheduleGroupEventGuid](#schedulegroupeventguid)|[SchedulerEventGuid](#schedulereventguid)|[VirtualProcessorEventGuid](#virtualprocessoreventguid)|

##  <a name="agenteventguid"></a>  AgentEventGuid

Uma categoria de GUID ({B9B5B78C-0713-4898-A21A-C67949DCED07}) que descreve eventos ETW são acionados pela biblioteca de agentes no tempo de execução de simultaneidade.

```
const __declspec(selectany) GUID AgentEventGuid = {0xb9b5b78c, 0x713, 0x4898, { 0xa2, 0x1a, 0xc6, 0x79, 0x49, 0xdc, 0xed, 0x7 } };
```

##  <a name="choreeventguid"></a>  ChoreEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a tarefas ou tarefas.

```
const __declspec(selectany) GUID ChoreEventGuid =
    { 0x7E854EC7, 0xCDC4, 0x405a, { 0xB5, 0xB2, 0xAA, 0xF7, 0xC9, 0xE7, 0xD4, 0x0C } };
```

### <a name="remarks"></a>Comentários

Esta categoria de eventos não é disparada no momento pelo tempo de execução de simultaneidade.

##  <a name="concrt_providerguid"></a>  ConcRT_ProviderGuid

O GUID para o tempo de execução de simultaneidade do provedor ETW.

```
const __declspec(selectany) GUID ConcRT_ProviderGuid =
    { 0xF7B697A3, 0x4DB5, 0x4d3b, { 0xBE, 0x71, 0xC4, 0xD2, 0x84, 0xE6, 0x59, 0x2F } };
```

##  <a name="concrt_rm_version_1"></a>  CONCRT_RM_VERSION_1

Indica que há suporte da interface do Gerenciador de recursos definido no Visual Studio 2010.

```
const unsigned int CONCRT_RM_VERSION_1 = 0x00010000;
```

##  <a name="concrteventguid"></a>  ConcRTEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que não são descritas mais especificamente por outra categoria.

```
const __declspec(selectany) GUID ConcRTEventGuid =
    { 0x72B14A7D, 0x704C, 0x423e, { 0x92, 0xF8, 0x7E, 0x6D, 0x64, 0xBC, 0xB9, 0x2A } };
```

### <a name="remarks"></a>Comentários

Esta categoria de eventos não é disparada no momento pelo tempo de execução de simultaneidade.

##  <a name="cooperative_timeout_infinite"></a>  COOPERATIVE_TIMEOUT_INFINITE

Valor que indica que uma espera nunca deve atingir o tempo limite.

```
const unsigned int COOPERATIVE_TIMEOUT_INFINITE = (unsigned int)-1;
```

##  <a name="cooperative_wait_timeout"></a>  COOPERATIVE_WAIT_TIMEOUT

Valor que indica que uma espera atingiu o tempo limite.

```
const size_t COOPERATIVE_WAIT_TIMEOUT = SIZE_MAX;
```

##  <a name="contexteventguid"></a>  ContextEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionadas aos contextos.

```
const __declspec(selectany) GUID ContextEventGuid =
    { 0x5727A00F, 0x50BE, 0x4519, { 0x82, 0x56, 0xF7, 0x69, 0x98, 0x71, 0xFE, 0xCB } };
```

##  <a name="inherit_thread_priority"></a>  INHERIT_THREAD_PRIORITY

Valor especial para a chave de política `ContextPriority` indicando que a prioridade do thread de todos os contextos em que o Agendador deve ser o mesmo que um thread que criou o Agendador.

```
const unsigned int INHERIT_THREAD_PRIORITY = 0x0000F000;
```

##  <a name="lockeventguid"></a>  LockEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a bloqueios.

```
const __declspec(selectany) GUID LockEventGuid =
    { 0x79A60DC6, 0x5FC8, 0x4952, { 0xA4, 0x1C, 0x11, 0x63, 0xAE, 0xEC, 0x5E, 0xB8 } };
```

### <a name="remarks"></a>Comentários

Esta categoria de eventos não é disparada no momento pelo tempo de execução de simultaneidade.

##  <a name="maxexecutionresources"></a>  MaxExecutionResources

Valor especial para as chaves de política `MinConcurrency` e `MaxConcurrency`. O padrão é o número de threads de hardware na máquina na ausência de outras restrições.

```
const unsigned int MaxExecutionResources = 0xFFFFFFFF;
```

##  <a name="pplparallelforeventguid"></a>  PPLParallelForEventGuid

Uma categoria que descreve os eventos ETW de GUID acionado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_for` função.

```
const __declspec(selectany) GUID PPLParallelForEventGuid =
    { 0x31c8da6b, 0x6165, 0x4042, { 0x8b, 0x92, 0x94, 0x9e, 0x31, 0x5f, 0x4d, 0x84 } };
```

##  <a name="pplparallelforeacheventguid"></a>  PPLParallelForeachEventGuid

Uma categoria que descreve os eventos ETW de GUID acionado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_for_each` função.

```
const __declspec(selectany) GUID PPLParallelForeachEventGuid =
    { 0x5cb7d785, 0x9d66, 0x465d, { 0xba, 0xe1, 0x46, 0x11, 0x6, 0x1b, 0x54, 0x34 } };
```

##  <a name="pplparallelinvokeeventguid"></a>  PPLParallelInvokeEventGuid

Uma categoria que descreve os eventos ETW de GUID acionado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao uso do `parallel_invoke` função.

```
const __declspec(selectany) GUID PPLParallelInvokeEventGuid =
    { 0xd1b5b133, 0xec3d, 0x49f4, { 0x98, 0xa3, 0x46, 0x4d, 0x1a, 0x9e, 0x46, 0x82 } };
```

##  <a name="resourcemanagereventguid"></a>  ResourceManagerEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionadas ao Gerenciador de recursos.

```
const __declspec(selectany) GUID ResourceManagerEventGuid =
    { 0x2718D25B, 0x5BF5, 0x4479, { 0x8E, 0x88, 0xBA, 0xBC, 0x64, 0xBD, 0xBF, 0xCA } };
```

### <a name="remarks"></a>Comentários

Esta categoria de eventos não é disparada no momento pelo tempo de execução de simultaneidade.

##  <a name="schedulegroupeventguid"></a>  ScheduleGroupEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a grupos de agendas.

```
const __declspec(selectany) GUID ScheduleGroupEventGuid =
    { 0xE8A3BF1F, 0xA86B, 0x4390, { 0x9C, 0x60, 0x53, 0x90, 0xB9, 0x69, 0xD2, 0x2C } };
```

### <a name="remarks"></a>Comentários

Esta categoria de eventos não é disparada no momento pelo tempo de execução de simultaneidade.

##  <a name="schedulereventguid"></a>  SchedulerEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionadas à atividade do Agendador.

```
const __declspec(selectany) GUID SchedulerEventGuid =
    { 0xE2091F8A, 0x1E0A, 0x4731, { 0x84, 0xA2, 0x0D, 0xD5, 0x7C, 0x8A, 0x52, 0x61 } };
```

##  <a name="virtualprocessoreventguid"></a>  VirtualProcessorEventGuid

Uma categoria que descreve os eventos ETW de GUID disparado pelo tempo de execução de simultaneidade que estão diretamente relacionados a processadores virtuais.

```
const __declspec(selectany) GUID VirtualProcessorEventGuid =
    { 0x2f27805f, 0x1676, 0x4ecc, { 0x96, 0xfa, 0x7e, 0xb0, 0x9d, 0x44, 0x30, 0x2f } };
```

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
