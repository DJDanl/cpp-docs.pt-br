---
title: Classe de eventos
description: A referência da classe de evento C++ Build insights SDK.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Event
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7dd96ffa3518c58e1b18312bb4fe2c36df26bd67
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923294"
---
# <a name="event-class"></a>Classe de eventos

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `Event` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a qualquer evento.

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

[Dados](#data) 
 do [EventID](#event-id)\
[EventInstanceId](#event-instance-id)\
[EventName](#event-name)\
[EventWideName](#event-wide-name)\
[ProcessId](#process-id)\
[ProcessorIndex](#processor-index)\
[ThreadId](#thread-id)\
[TickFrequency](#tick-frequency)\
[Timestamp](#timestamp)

## <a name="event"></a><a name="entity"></a> Circunstância

```cpp
Event(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Qualquer evento.

## <a name="data"></a><a name="data"></a> Dado

```cpp
const void* Data() const;
```

### <a name="return-value"></a>Valor Retornado

Um ponteiro para dados adicionais contidos neste evento. Para obter mais informações sobre como interpretar esse campo, consulte [EVENT_DATA](../c-event-data-types/event-data-struct.md).

## <a name="eventid"></a><a name="event-id"></a> 1008

```cpp
const unsigned short& EventId() const;
```

### <a name="return-value"></a>Valor Retornado

Um número que identifica o tipo de evento. Para obter uma lista de identificadores de eventos, consulte [EVENT_ID](../c-event-data-types/event-id-enum.md).

## <a name="eventinstanceid"></a><a name="event-instance-id"></a> EventInstanceId

```cpp
const unsigned long long& EventInstanceId() const;
```

### <a name="return-value"></a>Valor Retornado

Um número que identifica exclusivamente o evento dentro de um rastreamento. Esse valor não é alterado ao analisar ou refazer o log do mesmo rastreamento várias vezes. Use esse valor para identificar o mesmo evento em várias análises ou o novo registro em log passa pelo mesmo rastreamento.

## <a name="eventname"></a><a name="event-name"></a> EventName

```cpp
const char* EventName() const;
```

### <a name="return-value"></a>Valor Retornado

Uma cadeia de caracteres ANSI que contém o nome do tipo de evento identificado pelo [EventID](#event-id).

## <a name="eventwidename"></a><a name="event-wide-name"></a> EventWideName

```cpp
const wchar_t* EventWideName() const;
```

### <a name="return-value"></a>Valor Retornado

Uma cadeia de caracteres larga que contém o nome do evento identificado pelo [EventID](#event-id).

## <a name="processid"></a><a name="process-id"></a> ProcessId

```cpp
const unsigned long& ProcessId() const;
```

### <a name="return-value"></a>Valor Retornado

O identificador do processo no qual o evento ocorreu.

## <a name="processorindex"></a><a name="processor-index"></a> ProcessorIndex

```cpp
const unsigned short& ProcessorIndex() const;
```

### <a name="return-value"></a>Valor Retornado

O índice de base zero para o processador lógico no qual o evento ocorreu.

## <a name="threadid"></a><a name="thread-id"></a> ThreadId

```cpp
const unsigned long& ThreadId() const;
```

### <a name="return-value"></a>Valor Retornado

O identificador para o thread no qual o evento ocorreu.

## <a name="tickfrequency"></a><a name="tick-frequency"></a> TickFrequency

```cpp
const long long& TickFrequency() const;
```

### <a name="return-value"></a>Valor Retornado

O número de tiques por segundo a serem usados ao avaliar uma duração medida em tiques para esse evento.

## <a name="timestamp"></a><a name="timestamp"></a> Estampa

```cpp
const long long& Timestamp() const;
```

### <a name="return-value"></a>Valor Retornado

Se o evento for uma atividade, essa função retornará um valor de tique capturado no momento em que a atividade foi iniciada. Para um evento simples, essa função retorna um valor de tique capturado no momento em que o evento ocorreu.

::: moniker-end
