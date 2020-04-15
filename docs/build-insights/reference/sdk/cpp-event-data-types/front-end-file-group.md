---
title: Classe FrontEndFileGroup
description: A referência da classe C++ Build Insights SDK FrontEndFileGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FrontEndFileGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: d2eebb650e59e750e5ebde74914dca5f0ef4779d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324769"
---
# <a name="frontendfilegroup-class"></a>Classe FrontEndFileGroup

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `FrontEndFileGroup` classe é usada com as funções [MatchEventStackStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar grupos de [eventos FRONT_END_FILE.](../event-table.md#front-end-file)

## <a name="syntax"></a>Sintaxe

```cpp
class FrontEndFileGroup : public EventGroup<FrontEndFile>
{
public:
    FrontEndFileGroup(std::deque<FrontEndFile>&& group);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de sua classe `FrontEndFileGroup` base [EventGroup\<\> FrontEndFile,](event-group.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[FrontEndFileGroup](#front-end-file-group)

## <a name="frontendfilegroup"></a><a name="front-end-file-group"></a>FrontEndFileGroup

```cpp
FrontEndFileGroup(std::deque<FrontEndFile>&& group);
```

### <a name="parameters"></a>Parâmetros

*Grupo*\
Um grupo de [eventos FRONT_END_FILE.](../event-table.md#front-end-file)

::: moniker-end
