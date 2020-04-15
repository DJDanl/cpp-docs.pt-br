---
title: Classe LinkerPass
description: A referência da classe C++ Build Insights SDK LinkerPass.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- LinkerPass
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 2b0c5a02958560faeff30500543b6e6d4921ac52
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324610"
---
# <a name="linkerpass-class"></a>Classe LinkerPass

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `LinkerPass` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para corresponder a um evento [PASS1](../event-table.md#pass1) ou [PASS2.](../event-table.md#pass2)

## <a name="syntax"></a>Sintaxe

```cpp
class LinkerPass : public Activity
{
public:
    LinkerPass(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `LinkerPass` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[LinkerPass](#linker-pass)

## <a name="linkerpass"></a><a name="linker-pass"></a>LinkerPass

```cpp
LinkerPass(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [PASS1](../event-table.md#pass1) ou [PASS2.](../event-table.md#pass2)

::: moniker-end
