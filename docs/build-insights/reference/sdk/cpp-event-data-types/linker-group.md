---
title: Classe LinkerGroup
description: A referência de classe do SDK do LinkerGroup de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- LinkerGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 8a818cf7524405d4e2f29a1987e93b77371607cc
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923113"
---
# <a name="linkergroup-class"></a>Classe LinkerGroup

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `LinkerGroup` classe é usada com as funções [MatchEventStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para fazer a correspondência de grupos de eventos [vinculadores](../event-table.md#linker) .

## <a name="syntax"></a>Sintaxe

```cpp
class LinkerGroup : public EventGroup<Linker>
{
public:
    LinkerGroup(std::deque<Linker>&& group);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados da classe base do seu conjunto de [eventos \<Linker\> ](event-group.md) , a `LinkerGroup` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[LinkerGroup](#linker-group)

## <a name="linkergroup"></a><a name="linker-group"></a> LinkerGroup

```cpp
LinkerGroup(std::deque<Linker>&& group);
```

### <a name="parameters"></a>Parâmetros

*Group*\
Um grupo de eventos do [vinculador](../event-table.md#linker) .

::: moniker-end
