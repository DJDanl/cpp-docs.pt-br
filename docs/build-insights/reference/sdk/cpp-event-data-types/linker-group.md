---
title: Classe LinkerGroup
description: A C++ referência da classe build do SDK do insights LinkerGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- LinkerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 95b0dcc3a771ec07ee60185a79a5ddbc29434b5d
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333205"
---
# <a name="linkergroup-class"></a>Classe LinkerGroup

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `LinkerGroup` é usada com as funções [MatchEventStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para fazer a correspondência de grupos de eventos [vinculadores](../event-table.md#linker) .

## <a name="syntax"></a>Sintaxe

```cpp
class LinkerGroup : public EventGroup<Linker>
{
public:
    LinkerGroup(std::deque<Linker>&& group);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de seu [\<vinculador\>](event-group.md) classe base, a classe `LinkerGroup` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[LinkerGroup](#linker-group)

## <a name="linker-group"></a>LinkerGroup

```cpp
LinkerGroup(std::deque<Linker>&& group);
```

### <a name="parameters"></a>Parâmetros

\ de *grupo*
Um grupo de eventos do [vinculador](../event-table.md#linker) .

::: moniker-end
