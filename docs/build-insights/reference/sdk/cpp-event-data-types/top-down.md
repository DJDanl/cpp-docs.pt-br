---
title: Classe TopDown
description: A referência da classe C++ Build Insights SDK TopDown.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TopDown
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7c0c957fa17daaec34710debeda634192c63d1da
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324210"
---
# <a name="topdown-class"></a>Classe TopDown

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TopDown` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [TOP_DOWN.](../event-table.md#top-down)

## <a name="syntax"></a>Sintaxe

```cpp
class TopDown : public Activity
{
public:
    TopDown(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `TopDown` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Topdown](#top-down)

## <a name="topdown"></a><a name="top-down"></a>Topdown

```cpp
TopDown(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [TOP_DOWN.](../event-table.md#top-down)

::: moniker-end
