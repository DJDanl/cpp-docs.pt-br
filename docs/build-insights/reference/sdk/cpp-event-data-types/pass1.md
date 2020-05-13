---
title: Classe Pass1
description: A referência da classe C++ Build Insights SDK Pass1.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Pass1
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 039c2cc92b8461009c235baa7e49484eb2a4f49f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324416"
---
# <a name="pass1-class"></a>Classe Pass1

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Pass1` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para corresponder a um evento [PASS1.](../event-table.md#pass1)

## <a name="syntax"></a>Sintaxe

```cpp
class Pass1 : public LinkerPass
{
public:
    Pass1(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de sua `Pass1` classe base [LinkerPass,](linker-pass.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Passe1](#pass1)

## <a name="pass1"></a><a name="pass1"></a>Passe1

```cpp
Pass1(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [PASS1.](../event-table.md#pass1)

::: moniker-end
