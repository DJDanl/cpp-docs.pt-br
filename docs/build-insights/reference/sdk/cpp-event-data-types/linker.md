---
title: Classe Linker
description: A referência da classe C++ Build Insights SDK Linker.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Linker
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e5d4c0c3841377fc2e029c23d5cbbd076c8029cc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324598"
---
# <a name="linker-class"></a>Classe Linker

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Linker` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para corresponder a um evento [LINKER.](../event-table.md#linker)

## <a name="syntax"></a>Sintaxe

```cpp
class Linker : public Invocation
{
public:
    Linker(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `Linker` sua classe base [de Invocação,](invocation.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Vinculador](#linker)

## <a name="linker"></a><a name="linker"></a>Vinculador

```cpp
Linker(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [LINKER.](../event-table.md#linker)

::: moniker-end
