---
title: Classe de atividade
description: A referência da classe de atividade do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Activity
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ce7e4083411f1654064ca4628d10a767c7be1b7f
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923401"
---
# <a name="activity-class"></a>Classe de atividade

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `Activity` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a qualquer evento de atividade. Consulte a [tabela de eventos](../event-table.md) para ver todos os eventos que podem ser correspondidos pela `Activity` classe.

## <a name="syntax"></a>Sintaxe

```cpp
class Activity : public Event
{
public:
    Activity(const RawEvent& event);

    const long long& StartTimestamp() const;
    const long long& StopTimestamp() const;
    const long long& ExclusiveDurationTicks() const;
    const long long& CPUTicks() const;
    const long long& ExclusiveCPUTicks() const;
    const long long& WallClockTimeResponsibilityTicks() const;
    const long long& ExclusiveWallClockTimeResponsibilityTicks() const;

    std::chrono::nanoseconds Duration() const;
    std::chrono::nanoseconds ExclusiveDuration() const;
    std::chrono::nanoseconds CPUTime() const ;
    std::chrono::nanoseconds ExclusiveCPUTime() const;
    std::chrono::nanoseconds WallClockTimeResponsibility() const;
    std::chrono::nanoseconds ExclusiveWallClockTimeResponsibility() const;
};
```

## <a name="remarks"></a>Comentários

Várias funções de membro na `Activity` classe retornam uma contagem de tiques. As informações de Build do C++ usam o contador de desempenho do Windows como uma fonte de tiques. Uma contagem em escala deve ser usada com uma frequência de escala para convertê-la em uma unidade de tempo, como segundos. A `TickFrequency` função de membro, disponível na classe base de [evento](event.md) , pode ser chamada para obter a frequência de tiques. A página [EVENT_DATA](../c-event-data-types/event-data-struct.md#tick-conversion-example) mostra um exemplo de conversão de tiques em uma unidade de tempo.

Se você não quiser converter tiques em unidades de tempo por conta própria, a `Activity` classe fornecerá funções de membro que retornam valores de tempo em nanossegundos. Use a biblioteca C++ padrão `chrono` para convertê-las em outras unidades de tempo.

## <a name="members"></a>Membros

Junto com seus membros herdados da classe base de [evento](event.md) , a `Activity` classe contém os seguintes membros:

### <a name="constructor"></a>Construtor

[Atividade](#activity)

### <a name="functions"></a>Funções

[CPUTicks](#cpu-ticks)\
[CPUTime](#cpu-time)\
[Permanência](#duration)\
[ExclusiveCPUTicks](#exclusive-cpu-ticks)\
[ExclusiveCPUTime](#exclusive-cpu-time)\
[ExclusiveDuration](#exclusive-duration)\
[ExclusiveDurationTicks](#exclusive-duration-ticks)\
[ExclusiveWallClockTimeResponsibility](#exclusive-wall-clock-time-responsibility)\
[ExclusiveWallClockTimeResponsibilityTicks](#exclusive-wall-clock-time-responsibility-ticks)\
[StartTimestamp](#start-timestamp)\
[StopTimestamp](#stop-timestamp)\
[WallClockTimeResponsibility](#wall-clock-time-responsibility)\
[WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks)

## <a name="activity"></a><a name="activity"></a> Atividade

```cpp
Activity(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Qualquer evento de atividade.

## <a name="cputicks"></a><a name="cpu-ticks"></a> CPUTicks

```cpp
const long long& CPUTicks() const;
```

### <a name="return-value"></a>Valor Retornado

O número de tiques de CPU que ocorreram durante esta atividade. Um tique de CPU é diferente de um tique regular. Os tiques de CPU são contados apenas quando a CPU está executando o código em uma atividade. As tiques de CPU não são contadas quando o thread associado à atividade está em suspensão.

## <a name="cputime"></a><a name="cpu-time"></a> CPUTime

```cpp
std::chrono::nanoseconds CPUTime()() const;
```

### <a name="return-value"></a>Valor Retornado

O tempo durante o qual a CPU estava executando o código dentro desta atividade. Esse valor pode ser maior do que a duração da atividade se atividades filhas forem executadas em threads separados. O valor é retornado em nanossegundos.

## <a name="duration"></a><a name="duration"></a> Permanência

```cpp
std::chrono::nanoseconds Duration() const;
```

### <a name="return-value"></a>Valor Retornado

A duração da atividade em nanossegundos.

## <a name="exclusivecputicks"></a><a name="exclusive-cpu-ticks"></a> ExclusiveCPUTicks

```cpp
const long long& ExclusiveCPUTicks() const;
```

### <a name="return-value"></a>Valor Retornado

O mesmo que [CPUTicks](#cpu-ticks), mas não incluindo os tiques de CPU que ocorreram em atividades filhas.

## <a name="exclusivecputime"></a><a name="exclusive-cpu-time"></a> ExclusiveCPUTime

```cpp
std::chrono::nanoseconds ExclusiveCPUTime() const;
```

### <a name="return-value"></a>Valor Retornado

O mesmo que [CPUTime](#cpu-time), exceto que o tempo de CPU das atividades filhas não está incluído.

## <a name="exclusiveduration"></a><a name="exclusive-duration"></a> ExclusiveDuration

```cpp
std::chrono::nanoseconds ExclusiveDuration() const;
```

### <a name="return-value"></a>Valor Retornado

A duração da atividade em nanossegundos, não incluindo a quantidade de tempo gasto em atividades filhas.

## <a name="exclusivedurationticks"></a><a name="exclusive-duration-ticks"></a> ExclusiveDurationTicks

```cpp
const long long& ExclusiveDurationTicks() const;
```

### <a name="return-value"></a>Valor Retornado

O número de tiques que ocorreram nessa atividade, excluindo o número de tiques que ocorreram em atividades filhas.

## <a name="exclusivewallclocktimeresponsibility"></a><a name="exclusive-wall-clock-time-responsibility"></a> ExclusiveWallClockTimeResponsibility

```cpp
std::chrono::nanoseconds ExclusiveWallClockTimeResponsibility() const;
```

### <a name="return-value"></a>Valor Retornado

O mesmo que [WallClockTimeResponsibility](#wall-clock-time-responsibility), mas não incluindo a responsabilidade do tempo do relógio das atividades filhas.

## <a name="exclusivewallclocktimeresponsibilityticks"></a><a name="exclusive-wall-clock-time-responsibility-ticks"></a> ExclusiveWallClockTimeResponsibilityTicks

```cpp
const long long& ExclusiveWallClockTimeResponsibilityTicks() const;
```

### <a name="return-value"></a>Valor Retornado

O mesmo que [WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks), mas não incluindo os tiques de responsabilidade de tempo do relógio de parede de atividades filhas.

## <a name="starttimestamp"></a><a name="start-timestamp"></a> StartTimestamp

```cpp
const long long& StartTimestamp() const;
```

### <a name="return-value"></a>Valor Retornado

Um valor de tique capturado no momento em que a atividade foi iniciada.

## <a name="stoptimestamp"></a><a name="stop-timestamp"></a> StopTimestamp

```cpp
const long long& StopTimestamp() const;
```

### <a name="return-value"></a>Valor Retornado

Um valor de tique capturado no momento em que a atividade foi interrompida.

## <a name="wallclocktimeresponsibility"></a><a name="wall-clock-time-responsibility"></a> WallClockTimeResponsibility

```cpp
std::chrono::nanoseconds WallClockTimeResponsibility() const;
```

### <a name="return-value"></a>Valor Retornado

A responsabilidade do tempo do relógio desta atividade, em nanossegundos. Para obter mais informações sobre o que significa responsabilidade de tempo do relógio de parede, consulte [WallClockTimeResponsibilityTicks](#wall-clock-time-responsibility-ticks).

## <a name="wallclocktimeresponsibilityticks"></a><a name="wall-clock-time-responsibility-ticks"></a> WallClockTimeResponsibilityTicks

```cpp
const long long& WallClockTimeResponsibilityTicks() const;
```

### <a name="return-value"></a>Valor Retornado

Uma contagem em escala que representa a contribuição desta atividade para o tempo geral do relógio de parede. Um tique de responsabilidade de tempo do relógio de parede é diferente de um tique regular. Os tiques de responsabilidade do tempo do relógio do mural levam em conta o paralelismo entre as atividades. Duas atividades paralelas podem ter uma duração de 50 tiques e a mesma hora de início e de término. Nesse caso, ambos recebem uma responsabilidade de tempo do relógio de parede de 25 tiques.

::: moniker-end
