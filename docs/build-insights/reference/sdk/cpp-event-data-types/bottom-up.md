---
title: Classe BottomUp
description: A referência da classe C++ Build Insights SDK BottomUp.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- BottomUp
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1cfe25aaa5736b9e2ba55a577e64958a6b9f113b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325210"
---
# <a name="bottomup-class"></a>Classe BottomUp

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `BottomUp` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [BOTTOM_UP.](../event-table.md#bottom-up)

## <a name="syntax"></a>Sintaxe

```cpp
class BottomUp : public Activity
{
public:
    BottomUp(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `BottomUp` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Bottomup](#bottom-up)

## <a name="bottomup"></a><a name="bottom-up"></a>Bottomup

```cpp
BottomUp(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [BOTTOM_UP.](../event-table.md#bottom-up)

::: moniker-end
