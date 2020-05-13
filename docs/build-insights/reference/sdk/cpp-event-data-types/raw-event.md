---
title: Classe RawEvent
description: A referência da classe C++ Build Insights SDK RawEvent.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RawEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 83629457ac3a0d1f991f6b084af2f3400612b2ac
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324379"
---
# <a name="rawevent-class"></a>Classe RawEvent

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `RawEvent` classe é usada para representar um evento geral em um [EventStack](event-stack.md).

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

Várias funções `RawEvent` de membros na classe retornam uma contagem de carrapatos. O C++ Build Insights usa o contador de desempenho do Windows como fonte de tiques. Uma contagem de carrapatos deve ser usada com uma freqüência de carrapato para convertê-la em uma unidade de tempo como segundos. A `TickFrequency` função do membro pode ser chamada para obter a freqüência do carrapato. Consulte a página [EVENT_DATA](../c-event-data-types/event-data-struct.md#tick-conversion-example) para obter um exemplo de como converter carrapatos em uma unidade de tempo.

Se você não quiser converter carrapatos `RawEvent` você mesmo, a classe fornece funções de membro que retornam valores de tempo em nanossegundos. Use a biblioteca `chrono` C++ padrão para converter nanossegundos em outras unidades de tempo.

## <a name="members"></a>Membros

### <a name="constructor"></a>Construtor

[RawEvent](#raw-event)

### <a name="functions"></a>Funções

[CPUTicks](#cpu-ticks)\
[CPUTime](#cpu-time)\
[Dados](#data)\
[Duração](#duration)\
[EventId](#event-id)
[EventID EventID](#event-instance-id)
[EventName](#event-name)\
[EventWideName](#event-wide-name)\
[ExclusivoCPUTicks](#exclusive-cpu-ticks)\
[EXCLUSIVOCPUTime](#exclusive-cpu-time)\
[Duração exclusiva](#exclusive-duration)\
[ExclusiveDurationTicks](#exclusive-duration-ticks)\
[Responsabilidade exclusiva do wallclock](#exclusive-wall-clock-time-responsibility)\
[ExclusivoWallClockTimeResponsibilityTicks](#exclusive-wall-clock-time-responsibility-ticks)\
[Processid](#process-id)\
[Índice do processador](#processor-index)\
[StartTimestamp](#start-timestamp)\
[StopTimestamp](#stop-timestamp)\
[Threadid](#thread-id)\
[Tickfrequency](#tick-frequency)\
[WallClockResponsabilidade](#wall-clock-time-responsibility)\
[WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks)

## <a name="rawevent"></a><a name="raw-event"></a>RawEvent

```cpp
RawEvent(const EVENT_DATA& data);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Os dados do evento.

## <a name="cputicks"></a><a name="cpu-ticks"></a>CPUTicks

```cpp
const long long& CPUTicks() const;
```

### <a name="return-value"></a>Valor retornado

O número de carrapatos da CPU que ocorreram durante esta atividade. Um carrapato da CPU é diferente de um carrapato normal. Os carrapatos da CPU só são contados quando a CPU está executando o código em uma atividade. Os carrapatos da CPU não são contados quando o segmento associado à atividade está dormindo.

## <a name="cputime"></a><a name="cpu-time"></a>CPUTime

```cpp
std::chrono::nanoseconds CPUTime()() const;
```

### <a name="return-value"></a>Valor retornado

A quantidade de tempo que a CPU estava executando código dentro desta atividade. Esse valor pode ser maior do que a duração da atividade se as atividades da criança forem executadas em segmentos separados. O valor é devolvido em nanossegundos.

## <a name="data"></a><a name="data"></a>Dados

```cpp
const void* Data() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para dados extras contidos neste evento. Para obter mais informações sobre como interpretar este campo, consulte [EVENT_DATA](../c-event-data-types/event-data-struct.md).

## <a name="duration"></a><a name="duration"></a>Duração

```cpp
std::chrono::nanoseconds Duration() const;
```

### <a name="return-value"></a>Valor retornado

A duração da atividade em nanossegundos.

## <a name="eventid"></a><a name="event-id"></a>Eventid

```cpp
const unsigned short& EventId() const;
```

### <a name="return-value"></a>Valor retornado

Um número que identifica o tipo de evento. Para obter uma lista de identificadores de eventos, consulte [EVENT_ID](../c-event-data-types/event-id-enum.md).

## <a name="eventinstanceid"></a><a name="event-instance-id"></a>EventInstanceId

```cpp
const unsigned long long& EventInstanceId() const;
```

### <a name="return-value"></a>Valor retornado

Um número que identifica exclusivamente o evento dentro de um traço. Esse valor não muda ao analisar ou relogar o mesmo traço várias vezes. Use esse valor para identificar o mesmo evento em análise múltipla ou relogamento passa sobre o mesmo traço.

## <a name="eventname"></a><a name="event-name"></a>Eventname

```cpp
const char* EventName() const;
```

### <a name="return-value"></a>Valor retornado

Uma seqüência ANSI contendo o nome do tipo de evento identificado por [EventId](#event-id).

## <a name="eventwidename"></a><a name="event-wide-name"></a>EventWideName

```cpp
const wchar_t* EventWideName() const;
```

### <a name="return-value"></a>Valor retornado

Uma seqüência larga contendo o nome do tipo de evento identificado por [EventId](#event-id).

## <a name="exclusivecputicks"></a><a name="exclusive-cpu-ticks"></a>ExclusivoCPUTicks

```cpp
const long long& ExclusiveCPUTicks() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [CPUTicks,](#cpu-ticks)mas sem incluir os carrapatos da CPU que ocorreram em atividades infantis.

## <a name="exclusivecputime"></a><a name="exclusive-cpu-time"></a>EXCLUSIVOCPUTime

```cpp
std::chrono::nanoseconds ExclusiveCPUTime() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [CPUTime,](#cpu-time)exceto que o tempo da CPU das atividades infantis não está incluído.

## <a name="exclusiveduration"></a><a name="exclusive-duration"></a>Duração exclusiva

```cpp
std::chrono::nanoseconds ExclusiveDuration() const;
```

### <a name="return-value"></a>Valor retornado

A duração da atividade em nanossegundos, sem incluir o tempo gasto nas atividades infantis.

## <a name="exclusivedurationticks"></a><a name="exclusive-duration-ticks"></a>ExclusiveDurationTicks

```cpp
const long long& ExclusiveDurationTicks() const;
```

### <a name="return-value"></a>Valor retornado

O número de carrapatos ocorridos nesta atividade, excluindo o número de carrapatos ocorridos nas atividades infantis.

## <a name="exclusivewallclocktimeresponsibility"></a><a name="exclusive-wall-clock-time-responsibility"></a>Responsabilidade exclusiva do wallclock

```cpp
std::chrono::nanoseconds ExclusiveWallClockTimeResponsibility() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [WallClockTimeResponsibility,](#wall-clock-time-responsibility)mas não incluindo a responsabilidade do tempo de parede das atividades infantis.

## <a name="exclusivewallclocktimeresponsibilityticks"></a><a name="exclusive-wall-clock-time-responsibility-ticks"></a>ExclusivoWallClockTimeResponsibilityTicks

```cpp
const long long& ExclusiveWallClockTimeResponsibilityTicks() const;
```

### <a name="return-value"></a>Valor retornado

O mesmo que [WallClockTimeResponsibilityTicks,](#wall-clock-time-responsibility-ticks)mas não incluindo os carrapatos de responsabilidade do relógio de parede das atividades infantis.

## <a name="processid"></a><a name="process-id"></a>Processid

```cpp
const unsigned long& ProcessId() const;
```

### <a name="return-value"></a>Valor retornado

O identificador para o processo em que o evento ocorreu.

## <a name="processorindex"></a><a name="processor-index"></a>Índice do processador

```cpp
const unsigned short& ProcessorIndex() const;
```

### <a name="return-value"></a>Valor retornado

O índice baseado em zero para o processador lógico no qual o evento ocorreu.

## <a name="starttimestamp"></a><a name="start-timestamp"></a>StartTimestamp

```cpp
const long long& StartTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de tique-taque capturado no momento em que a atividade começou.

## <a name="stoptimestamp"></a><a name="stop-timestamp"></a>StopTimestamp

```cpp
const long long& StopTimestamp() const;
```

### <a name="return-value"></a>Valor retornado

Um valor de tique-taque capturado no momento em que a atividade parou.

## <a name="threadid"></a><a name="thread-id"></a>Threadid

```cpp
const unsigned long& ThreadId() const;
```

### <a name="return-value"></a>Valor retornado

O identificador para o segmento em que o evento ocorreu.

## <a name="tickfrequency"></a><a name="tick-frequency"></a>Tickfrequency

```cpp
const long long& TickFrequency() const;
```

### <a name="return-value"></a>Valor retornado

O número de carrapatos por segundo a ser usado ao avaliar uma duração medida em carrapatos para este evento.

## <a name="wallclocktimeresponsibility"></a><a name="wall-clock-time-responsibility"></a>WallClockResponsabilidade

```cpp
std::chrono::nanoseconds WallClockTimeResponsibility() const;
```

### <a name="return-value"></a>Valor retornado

A responsabilidade do relógio de parede desta atividade, em nanossegundos. Para obter mais informações sobre o que significa responsabilidade de tempo de relógio de parede, consulte [WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks).

## <a name="wallclocktimeresponsibilityticks"></a><a name="wall-clock-time-responsibility-ticks"></a>WallClockTimeResponsibilityTicks

```cpp
const long long& WallClockTimeResponsibilityTicks() const;
```

### <a name="return-value"></a>Valor retornado

Uma contagem de carrapatos que representa a contribuição desta atividade para o tempo geral do relógio de parede. Um carrapato de responsabilidade de relógio de parede é diferente de um carrapato normal. Os carrapatos de responsabilidade do relógio de parede levam em conta o paralelismo entre as atividades. Duas atividades paralelas podem ter uma duração de 50 carrapatos e o mesmo tempo de início e parada. Neste caso, ambos recebem uma responsabilidade de 25 carrapatos.

::: moniker-end
