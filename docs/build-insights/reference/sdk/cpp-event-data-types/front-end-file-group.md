---
title: Classe FrontEndFileGroup
description: A C++ referência da classe build do SDK do insights FrontEndFileGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FrontEndFileGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 343a5a0d798d6c719088bd49668e70b10fba6d1a
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333324"
---
# <a name="frontendfilegroup-class"></a>Classe FrontEndFileGroup

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `FrontEndFileGroup` é usada com as funções [MatchEventStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para fazer a correspondência de grupos de eventos de [FRONT_END_FILE](../event-table.md#front-end-file) .

## <a name="syntax"></a>Sintaxe

```cpp
class FrontEndFileGroup : public EventGroup<FrontEndFile>
{
public:
    FrontEndFileGroup(std::deque<FrontEndFile>&& group);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de seu\<de eventos do seu\>de dados de [front-EndFile](event-group.md) , a classe `FrontEndFileGroup` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[FrontEndFileGroup](#front-end-file-group)

## <a name="front-end-file-group"></a>FrontEndFileGroup

```cpp
FrontEndFileGroup(std::deque<FrontEndFile>&& group);
```

### <a name="parameters"></a>Parâmetros

\ de *grupo*
Um grupo de eventos de [FRONT_END_FILE](../event-table.md#front-end-file) .

::: moniker-end
