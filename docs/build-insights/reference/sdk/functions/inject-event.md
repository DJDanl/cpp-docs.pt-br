---
title: InjectEvent
description: A C++ referência da função INJECTEVENT do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- InjectEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7b53eb71cf7a2ae40d04dbc3f8b5829f2737aba4
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332841"
---
# <a name="injectevent"></a>InjectEvent

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A função `InjectEvent` é chamada em um relogger que implementa a interface [IRelogger](../other-types/irelogger-class.md) . Ele é usado para gravar um evento ETW (rastreamento de eventos para Windows) no arquivo de rastreamento de saída de uma sessão de reregistro em log.

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

\ *relogSession*
Um ponteiro para a sessão de reregistro em log. Uma sessão de reregistro em log é fornecida para reagentes que implementam a interface `IRelogger`. Para obter mais informações, consulte [IRelogger](../other-types/irelogger-class.md).

*provedorid*\
Um GUID do provedor ETW (rastreamento de eventos para Windows) sob o qual o evento ETW é registrado novamente.

\ *eventDescriptor*
O descritor de evento ETW para o evento ETW que é registrado novamente.

*processId*\
O identificador do processo (PID) do evento ETW que é registrado novamente.

\ *ThreadID*
O identificador de thread (TID) para o evento ETW que é registrado novamente.

\ *processorIndex*
O índice de processador para o evento ETW que é registrado novamente.

*carimbo de data/hora*\
O carimbo de data/hora do evento ETW que é registrado novamente.

\ de *dados*
Um ponteiro para os dados que devem ser incluídos no evento ETW reregistrado.

*byteCount*\
O tamanho dos dados, em bytes, apontados por *dados*.

## <a name="remarks"></a>Comentários

Para obter mais informações sobre conceitos de ETW, como *GUID de provedor* e *descritor de eventos*, consulte a documentação do [ETW](/windows/win32/etw/about-event-tracing). Para obter detalhes sobre como iniciar uma sessão de reregistro com C++ o SDK do Build insights, consulte [relog](relog.md).

::: moniker-end
