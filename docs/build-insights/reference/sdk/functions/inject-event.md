---
title: InjectEvent
description: A referência da função InjectEvent do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- InjectEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b4d85f17a6d553d9dffa727824e6d4de94518645
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92922845"
---
# <a name="injectevent"></a>InjectEvent

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `InjectEvent` função é chamada em um relogger que implementa a interface [IRelogger](../other-types/irelogger-class.md) . Ele é usado para gravar um evento ETW (rastreamento de eventos para Windows) no arquivo de rastreamento de saída de uma sessão de reregistro em log.

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

*relogSession*\
Um ponteiro para a sessão de reregistro em log. Uma sessão de reregistro em log é fornecida para reagentes que implementam a `IRelogger` interface. Para obter mais informações, consulte [IRelogger](../other-types/irelogger-class.md).

*providerId*\
Um GUID do provedor ETW (rastreamento de eventos para Windows) sob o qual o evento ETW é registrado novamente.

*eventDescriptor*\
O descritor de evento ETW para o evento ETW que é registrado novamente.

*processId*\
O identificador do processo (PID) do evento ETW que é registrado novamente.

*threadId*\
O identificador de thread (TID) para o evento ETW que é registrado novamente.

*processorIndex*\
O índice de processador para o evento ETW que é registrado novamente.

*estampa*\
O carimbo de data/hora do evento ETW que é registrado novamente.

*dado*\
Um ponteiro para os dados que devem ser incluídos no evento ETW reregistrado.

*byteCount*\
O tamanho dos dados, em bytes, apontados por *dados* .

## <a name="remarks"></a>Comentários

Para obter mais informações sobre conceitos de ETW, como *GUID de provedor* e *descritor de eventos* , consulte a documentação do [ETW](/windows/win32/etw/about-event-tracing). Para obter detalhes sobre como iniciar uma sessão de reregistro com o SDK de compilação do C++, consulte [relog](relog.md).

::: moniker-end
