---
title: Classe Thread
description: A C++ referência da classe de thread do SDK do insights de compilação.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Thread
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a74eb130bd3f8be949fef0c19d545f61a72f3934
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332960"
---
# <a name="thread-class"></a>Classe Thread

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `Thread` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [thread](../event-table.md#thread) .

## <a name="syntax"></a>Sintaxe

```cpp
class Thread : public Activity
{
public:
    Thread(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a classe `Thread` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Thread](#thread)

## <a name="thread"></a>Processo

```cpp
Thread(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento de [thread](../event-table.md#thread) .

::: moniker-end
