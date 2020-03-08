---
title: Classe CodeGeneration
description: A C++ referência da classe build do SDK do insights CodeGeneration.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CodeGeneration
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1bc56794a197b9ae7bf116757581fb5a49699462
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333478"
---
# <a name="codegeneration-class"></a>Classe CodeGeneration

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `CodeGeneration` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [CODE_GENERATION](../event-table.md#code-generation) .

## <a name="syntax"></a>Sintaxe

```cpp
class CodeGeneration : public Activity
{
public:
    CodeGeneration(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a classe `CodeGeneration` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[CodeGeneration](#code-generation)

## <a name="code-generation"></a>CodeGeneration

```cpp
CodeGeneration(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [CODE_GENERATION](../event-table.md#code-generation) .

::: moniker-end