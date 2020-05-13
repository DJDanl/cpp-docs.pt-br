---
title: Classe de eventos
description: A referência da classe C++ Build Insights SDK Event.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Event
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 25d58f642a1c314e48ddff62553394bcc65e4717
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324958"
---
# <a name="event-class"></a>Classe de eventos

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Event` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com qualquer evento.

## <a name="syntax"></a>Sintaxe

```cpp
class Event
{
public:
    Event(const RawEvent& event);

    const unsigned short&        EventId() const;
    const unsigned long long&    EventInstanceId() const;
    const long long&             TickFrequency() const;
    const long long&             Timestamp() const;
    const unsigned long&         ProcessId() const;
    const unsigned long&         ThreadId() const;
    const unsigned short&        ProcessorIndex() const;
    const char*                  EventName() const;
    const wchar_t*               EventWideName() const;
};
```

## <a name="members"></a>Membros

### <a name="constructors"></a>Construtores

[Evento](#entity)

### <a name="functions"></a>Funções

[Data](#data)
[EventId](#event-id)\
[EventInstanceId](#event-instance-id)\
[Eventname](#event-name)\
[EventWideName](#event-wide-name)\
[Processid](#process-id)\
[Índice do processador](#processor-index)\
[Threadid](#thread-id)\
[Tickfrequency](#tick-frequency)\
[Timestamp](#timestamp)

## <a name="event"></a><a name="entity"></a>Evento

```cpp
Event(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Qualquer evento.

## <a name="data"></a><a name="data"></a>Dados

```cpp
const void* Data() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para dados extras contidos neste evento. Para obter mais informações sobre como interpretar este campo, consulte [EVENT_DATA](../c-event-data-types/event-data-struct.md).

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

Uma corda larga contendo o nome do evento identificado por [EventId](#event-id).

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

## <a name="timestamp"></a><a name="timestamp"></a>Timestamp

```cpp
const long long& Timestamp() const;
```

### <a name="return-value"></a>Valor retornado

Se o evento for uma atividade, essa função retorna um valor de tique-taque capturado no momento em que a atividade começou. Para um evento simples, esta função retorna um valor de tique-taque capturado no momento em que o evento ocorreu.

::: moniker-end
