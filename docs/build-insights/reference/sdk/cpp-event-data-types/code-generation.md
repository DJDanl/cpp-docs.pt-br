---
title: Classe CodeGeneration
description: A referência de classe do SDK do CodeGeneration de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CodeGeneration
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e9d9ba3667a96c0a4fa4fe6dc76087536ef2202e
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920821"
---
# <a name="codegeneration-class"></a>Classe CodeGeneration

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `CodeGeneration` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [CODE_GENERATION](../event-table.md#code-generation) .

## <a name="syntax"></a>Sintaxe

```cpp
class CodeGeneration : public Activity
{
public:
    CodeGeneration(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a `CodeGeneration` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[CodeGeneration](#code-generation)

## <a name="codegeneration"></a><a name="code-generation"></a> CodeGeneration

```cpp
CodeGeneration(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [CODE_GENERATION](../event-table.md#code-generation) .

::: moniker-end
