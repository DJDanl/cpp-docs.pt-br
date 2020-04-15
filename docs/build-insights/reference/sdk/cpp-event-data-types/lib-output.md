---
title: Classe LibOutput
description: A referência da classe C++ Build Insights SDK LibOutput.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- LibOutput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: fda7b471759a9c49937214bb2176473226668776
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324632"
---
# <a name="liboutput-class"></a>Classe LibOutput

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `LibOutput` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [LIB_OUTPUT.](../event-table.md#lib-output)

## <a name="syntax"></a>Sintaxe

```cpp
class LibOutput : public FileOutput
{
public:
    LibOutput(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `LibOutput` sua classe base [FileOutput,](file-output.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[LibOutput](#lib-output)

## <a name="liboutput"></a><a name="lib-output"></a>LibOutput

```cpp
LibOutput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [LIB_OUTPUT.](../event-table.md#lib-output)

::: moniker-end
