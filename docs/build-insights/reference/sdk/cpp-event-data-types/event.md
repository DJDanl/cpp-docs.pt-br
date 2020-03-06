---
title: Classe de eventos
description: A C++ referência da classe de evento Build insights SDK.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Event
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 205a4e0ca9dd9449933f38f02d4ceafd5df8ead2
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333394"
---
# <a name="event-class"></a>Classe de eventos

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `Event` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a qualquer evento.

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

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Event](#entity)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Dados](#data)
[EventID](#event-id)\
\ [EventInstanceId](#event-instance-id)
[Eventoname](#event-name)\
\ [EventWideName](#event-wide-name)
[ProcessId](#process-id)\
\ [ProcessorIndex](#processor-index)
\ [ThreadID](#thread-id)
\ [TickFrequency](#tick-frequency)
[Carimbo de data/hora](#timestamp)

## <a name="entity"></a>Circunstância

```cpp
Event(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Qualquer evento.

## <a name="data"></a>Dado

```cpp
const void* Data() const;
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para dados adicionais contidos neste evento. Para obter mais informações sobre como interpretar esse campo, consulte [EVENT_DATA](../c-event-data-types/event-data-struct.md).

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

Uma cadeia de caracteres larga que contém o nome do evento identificado pelo [EventID](#event-id).

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

## <a name="timestamp"></a>Estampa

```cpp
const long long& Timestamp() const;
```

### <a name="return-value"></a>Valor retornado

Se o evento for uma atividade, essa função retornará um valor de tique capturado no momento em que a atividade foi iniciada. Para um evento simples, essa função retorna um valor de tique capturado no momento em que o evento ocorreu.

::: moniker-end
