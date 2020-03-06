---
title: Classe WholeProgramAnalysis
description: A C++ referência da classe build do SDK do insights WholeProgramAnalysis.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- WholeProgramAnalysis
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 6b8e41242acb9e902b250bab960b1c2042dd981a
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332932"
---
# <a name="wholeprogramanalysis-class"></a>Classe WholeProgramAnalysis

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `WholeProgramAnalysis` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [WHOLE_PROGRAM_ANALYSIS](../event-table.md#whole-program-analysis) .

## <a name="syntax"></a>Sintaxe

```cpp
class WholeProgramAnalysis : public Activity
{
public:
    WholeProgramAnalysis(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a classe `WholeProgramAnalysis` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[WholeProgramAnalysis](#whole-program-analysis)

## <a name="whole-program-analysis"></a>WholeProgramAnalysis

```cpp
WholeProgramAnalysis(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [WHOLE_PROGRAM_ANALYSIS](../event-table.md#whole-program-analysis) .

::: moniker-end
