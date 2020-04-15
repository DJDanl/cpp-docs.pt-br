---
title: InjectEvent
description: A referência da função C++ Build Insights SDK InjectEvent.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- InjectEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c82aad5923eff60e5c72ceccaa39aa136f942665
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324047"
---
# <a name="injectevent"></a>InjectEvent

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `InjectEvent` função é chamada dentro de um relogger implementando a interface [IRelogger.](../other-types/irelogger-class.md) Ele é usado para escrever um evento de rastreamento de eventos para Windows (ETW) no arquivo de rastreamento de saída de uma sessão de relogging.

## <a name="syntax"></a>Sintaxe

```cpp
void InjectEvent(
    const void* relogSession,
    LPCGUID providerId,
    PCEVENT_DESCRIPTOR eventDescriptor,
    unsigned long processId,
    unsigned long threadId,
    unsigned short processorIndex,
    long long timestamp,
    unsigned char* data,
    unsigned long byteCount);
```

### <a name="parameters"></a>Parâmetros

*sessão de relog*\
Um ponteiro para a sessão de relogamento. Uma sessão de relogamento é fornecida para `IRelogger` relocantes que implementam a interface. Para obter mais informações, consulte [IRelogger](../other-types/irelogger-class.md).

*Providerid*\
Um provedor de Rastreamento de Eventos para Windows (ETW) GUID sob o qual o evento ETW é relocado.

*Eventdescriptor*\
O descritor de eventos ETW para o evento ETW que está relocado.

*Processid*\
O identificador de processo (PID) para o evento ETW que está relocado.

*Threadid*\
O identificador de rosca (TID) para o evento ETW que está relocado.

*Índice do processador*\
O índice do processador para o evento ETW que está relocado.

*Timestamp*\
O carimbo de data e hora para o evento ETW que está relocado.

*Dados*\
Um ponteiro para os dados que devem ser incluídos no evento ETW relocado.

*Bytecount*\
O tamanho dos dados, em bytes, apontados por *dados.*

## <a name="remarks"></a>Comentários

Para obter mais informações sobre conceitos de ETW, como *o provedor GUID* e o *descritor de eventos,* consulte a documentação do [ETW](/windows/win32/etw/about-event-tracing). Para obter detalhes sobre como iniciar uma sessão de relogamento com o C++ Build Insights SDK, consulte [Relog](relog.md).

::: moniker-end
