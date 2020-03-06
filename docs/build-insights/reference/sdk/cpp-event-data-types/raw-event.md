---
title: Classe RawEvent
description: A C++ referência da classe build do SDK do insights RawEvent.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RawEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 4088920d6070e14d64ccd046238c1c49b2556ea1
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333058"
---
# <a name="rawevent-class"></a>Classe RawEvent

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `RawEvent` é usada para representar um evento geral em um [EventStack](event-stack.md).

## <a name="syntax"></a>Sintaxe

```cpp
class RawEvent
{
public:
    RawEvent(const EVENT_DATA& event);

    const unsigned short&        EventId() const;
    const unsigned long long&    EventInstanceId() const;
    const long long&             TickFrequency() const;
    const long long&             StartTimestamp() const;
    const long long&             StopTimestamp() const;
    const long long&             ExclusiveDurationTicks() const;
    const long long&             CPUTicks() const;
    const long long&             ExclusiveCPUTicks() const;
    const long long&             WallClockTimeResponsibilityTicks() const;
    const long long&             ExclusiveWallClockTimeResponsibilityTicks() const;
    const void*                  Data() const;
    const unsigned long&         ProcessId() const;
    const unsigned long&         ThreadId() const;
    const unsigned short&        ProcessorIndex() const;
    const char*                  EventName() const;
    const wchar_t*               EventWideName() const;

    std::chrono::nanoseconds Duration() const;
    std::chrono::nanoseconds ExclusiveDuration() const;
    std::chrono::nanoseconds CPUTime() const ;
    std::chrono::nanoseconds ExclusiveCPUTime() const;
    std::chrono::nanoseconds WallClockTimeResponsibility() const;
    std::chrono::nanoseconds ExclusiveWallClockTimeResponsibility() const;
};
```

## <a name="remarks"></a>Comentários

Várias funções de membro na classe `RawEvent` retornam uma contagem de tiques. C++As informações de compilação usam o contador de desempenho do Windows como uma fonte de tiques. Uma contagem em escala deve ser usada com uma frequência de escala para convertê-la em uma unidade de tempo como segundos. A função membro `TickFrequency` pode ser chamada para obter a frequência de tiques. Consulte a página [EVENT_DATA](../c-event-data-types/event-data-struct.md#tick-conversion-example) para obter um exemplo de como converter tiques em uma unidade de tempo.

Se você não quiser converter os tiques por conta própria, a classe `RawEvent` fornece funções de membro que retornam valores de tempo em nanossegundos. Use a biblioteca C++ de `chrono` padrão para converter nanossegundos em outras unidades de tempo.

## <a name="members"></a>Membros

### <a name="constructor"></a>Construtor

[RawEvent](#raw-event)

### <a name="functions"></a>{1&gt;Funções&lt;1}

\ [CPUTicks](#cpu-ticks)
\ [CPUTime](#cpu-time)
[Dados](#data)\
[Duração](#duration)\
[EventId](#event-id)
[EventInstanceId](#event-instance-id)
[EventName](#event-name)\
\ [EventWideName](#event-wide-name)
\ [ExclusiveCPUTicks](#exclusive-cpu-ticks)
\ [ExclusiveCPUTime](#exclusive-cpu-time)
\ [ExclusiveDuration](#exclusive-duration)
\ [ExclusiveDurationTicks](#exclusive-duration-ticks)
\ [ExclusiveWallClockTimeResponsibility](#exclusive-wall-clock-time-responsibility)
\ [ExclusiveWallClockTimeResponsibilityTicks](#exclusive-wall-clock-time-responsibility-ticks)
[ProcessId](#process-id)\
\ [ProcessorIndex](#processor-index)
\ [StartTimestamp](#start-timestamp)
\ [StopTimestamp](#stop-timestamp)
\ [ThreadID](#thread-id)
\ [TickFrequency](#tick-frequency)
\ [WallClockTimeResponsibility](#wall-clock-time-responsibility)
[WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks)

## <a name="raw-event"></a>RawEvent

```cpp
RawEvent(const EVENT_DATA& data);
```

### <a name="parameters"></a>Parâmetros

*event*\
Os dados do evento.

## <a name="cpu-ticks"></a>CPUTicks

```cpp
const long long& CPUTicks() const;
```

### <a name="return-value"></a>Valor retornado

O número de tiques de CPU que ocorreram durante esta atividade. Um tique de CPU é diferente de um tique regular. Os tiques de CPU são contados apenas quando a CPU está executando o código em uma atividade. As tiques de CPU não são contadas quando o thread associado à atividade está em suspensão.

## <a name="cpu-time"></a>CPUTime

```cpp
std::chrono::nanoseconds CPUTime()() const;
```

### <a name="return-value"></a>Valor retornado

O tempo durante o qual a CPU estava executando o código dentro desta atividade. Esse valor pode ser maior do que a duração da atividade se atividades filhas forem executadas em threads separados. O valor é retornado em nanossegundos.

## <a name="data"></a>Dado

```cpp
const void* Data() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para dados adicionais contidos neste evento. Para obter mais informações sobre como interpretar esse campo, consulte [EVENT_DATA](../c-event-data-types/event-data-struct.md).

## <a name="duration"></a>Permanência

```cpp
std::chrono::nanoseconds Duration() const;
```

### <a name="return-value"></a>Valor retornado

A duração da atividade em nanossegundos.

## <a name="event-id"></a>1008

```cpp
const unsigned short& EventId() const;
```

### <a name="return-value"></a>Valor retornado

Um número que identifica o tipo de evento. Para obter uma lista de identificadores de eventos, consulte [EVENT_ID](../c-event-data-types/event-id-enum.md).

## <a name="event-instance-id"></a>EventInstanceId

```cpp
const unsigned long long& EventInstanceId() const;
```

### <a name="return-value"></a>Valor retornado

Um número que identifica exclusivamente o evento dentro de um rastreamento. Esse valor não é alterado ao analisar ou refazer o log do mesmo rastreamento várias vezes. Use esse valor para identificar o mesmo evento em várias análises ou o novo registro em log passa pelo mesmo rastreamento.

## <a name="event-name"></a>EventName

```cpp
const char* EventName() const;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres ANSI que contém o nome do tipo de evento identificado pelo [EventID](#event-id).

## <a name="event-wide-name"></a>EventWideName

```cpp
const wchar_t* EventWideName() const;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres larga que contém o nome do tipo de evento identificado pelo [EventID](#event-id).

## <a name="exclusive-cpu-ticks"></a>ExclusiveCPUTicks

```cpp
const long long& ExclusiveCPUTicks() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [CPUTicks](#cpu-ticks), mas não incluindo os tiques de CPU que ocorreram em atividades filhas.

## <a name="exclusive-cpu-time"></a>ExclusiveCPUTime

```cpp
std::chrono::nanoseconds ExclusiveCPUTime() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [CPUTime](#cpu-time), exceto que o tempo de CPU das atividades filhas não está incluído.

## <a name="exclusive-duration"></a>ExclusiveDuration

```cpp
std::chrono::nanoseconds ExclusiveDuration() const;
```

### <a name="return-value"></a>Valor retornado

A duração da atividade em nanossegundos, não incluindo a quantidade de tempo gasto em atividades filhas.

## <a name="exclusive-duration-ticks"></a>ExclusiveDurationTicks

```cpp
const long long& ExclusiveDurationTicks() const;
```

### <a name="return-value"></a>Valor retornado

O número de tiques que ocorreram nessa atividade, excluindo o número de tiques que ocorreram em atividades filhas.

## <a name="exclusive-wall-clock-time-responsibility"></a>ExclusiveWallClockTimeResponsibility

```cpp
std::chrono::nanoseconds ExclusiveWallClockTimeResponsibility() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [WallClockTimeResponsibility](#wall-clock-time-responsibility), mas não incluindo a responsabilidade do tempo do relógio das atividades filhas.

## <a name="exclusive-wall-clock-time-responsibility-ticks"></a>ExclusiveWallClockTimeResponsibilityTicks

```cpp
const long long& ExclusiveWallClockTimeResponsibilityTicks() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks), mas não incluindo os tiques de responsabilidade de tempo do relógio de parede de atividades filhas.

## <a name="process-id"></a>ProcessId

```cpp
const unsigned long& ProcessId() const;
```

### <a name="return-value"></a>Valor retornado

O identificador do processo no qual o evento ocorreu.

## <a name="processor-index"></a>ProcessorIndex

```cpp
const unsigned short& ProcessorIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice de base zero para o processador lógico no qual o evento ocorreu.

## <a name="start-timestamp"></a>StartTimestamp

```cpp
const long long& StartTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de tique capturado no momento em que a atividade foi iniciada.

## <a name="stop-timestamp"></a>StopTimestamp

```cpp
const long long& StopTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de tique capturado no momento em que a atividade foi interrompida.

## <a name="thread-id"></a>ThreadId

```cpp
const unsigned long& ThreadId() const;
```

### <a name="return-value"></a>Valor retornado

O identificador para o thread no qual o evento ocorreu.

## <a name="tick-frequency"></a>TickFrequency

```cpp
const long long& TickFrequency() const;
```

### <a name="return-value"></a>Valor retornado

O número de tiques por segundo a serem usados ao avaliar uma duração medida em tiques para esse evento.

## <a name="wall-clock-time-responsibility"></a>WallClockTimeResponsibility

```cpp
std::chrono::nanoseconds WallClockTimeResponsibility() const;
```

### <a name="return-value"></a>Valor retornado

A responsabilidade do tempo do relógio desta atividade, em nanossegundos. Para obter mais informações sobre o que significa responsabilidade de tempo do relógio de parede, consulte [WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks).

## <a name="wall-clock-time-responsibility-ticks"></a>WallClockTimeResponsibilityTicks

```cpp
const long long& WallClockTimeResponsibilityTicks() const;
```

### <a name="return-value"></a>Valor retornado

Uma contagem em escala que representa a contribuição desta atividade para o tempo geral do relógio de parede. Um tique de responsabilidade de tempo do relógio de parede é diferente de um tique regular. Os tiques de responsabilidade do tempo do relógio do mural levam em conta o paralelismo entre as atividades. Duas atividades paralelas podem ter uma duração de 50 tiques e a mesma hora de início e de término. Nesse caso, ambos recebem uma responsabilidade de tempo do relógio de parede de 25 tiques.

::: moniker-end
