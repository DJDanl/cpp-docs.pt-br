---
title: Classe Pass2
description: A referência da classe C++ Build Insights SDK Pass2.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Pass2
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 89b775c60b1d136c33dbaf2c4e39f247be7bb0bc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324409"
---
# <a name="pass2-class"></a>Classe Pass2

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Pass2` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para corresponder a um evento [PASS2.](../event-table.md#pass2)

## <a name="syntax"></a>Sintaxe

```cpp
class Pass2 : public LinkerPass
{
public:
    Pass2(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de sua `Pass2` classe base [LinkerPass,](linker-pass.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Passe2](#pass2)

## <a name="pass2"></a><a name="pass2"></a>Passe2

```cpp
Pass2(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [PASS2.](../event-table.md#pass2)

::: moniker-end
