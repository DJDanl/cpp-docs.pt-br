---
title: Classe SimpleEvent
description: A referência da classe C++ Build Insights SDK SimpleEvent.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- SimpleEvent
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 414ff5c1af99acc612384c1ae39f6e12ab051275
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324361"
---
# <a name="simpleevent-class"></a>Classe SimpleEvent

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `SimpleEvent` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com qualquer evento simples. Consulte a tabela do [evento](../event-table.md) para ver todos `SimpleEvent` os eventos que podem ser combinados pela classe.

## <a name="syntax"></a>Sintaxe

```cpp
class SimpleEvent : public Event
{
public:
    SimpleEvent(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `SimpleEvent` sua classe base [de eventos,](event.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Evento simples](#simple-event)

## <a name="simpleevent"></a><a name="simple-event"></a>Evento simples

```cpp
SimpleEvent(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Qualquer evento simples.

::: moniker-end
