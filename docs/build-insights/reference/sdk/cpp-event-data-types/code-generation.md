---
title: Classe CodeGeneration
description: A referência da classe C++ Build Insights SDK CodeGeneration.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CodeGeneration
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 27149d60cc6970843ef2ecccbaf25472f002e35f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325074"
---
# <a name="codegeneration-class"></a>Classe CodeGeneration

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `CodeGeneration` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [CODE_GENERATION.](../event-table.md#code-generation)

## <a name="syntax"></a>Sintaxe

```cpp
class CodeGeneration : public Activity
{
public:
    CodeGeneration(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `CodeGeneration` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Codegeneration](#code-generation)

## <a name="codegeneration"></a><a name="code-generation"></a>Codegeneration

```cpp
CodeGeneration(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [CODE_GENERATION.](../event-table.md#code-generation)

::: moniker-end
