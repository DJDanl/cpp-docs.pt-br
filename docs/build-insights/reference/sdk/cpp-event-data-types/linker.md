---
title: Classe do vinculador
description: A C++ referência da classe do vinculador do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Linker
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: bb8948d7772046e18d5db5002deed48d0dd88375
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333184"
---
# <a name="linker-class"></a>Classe do vinculador

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `Linker` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [vinculador](../event-table.md#linker) .

## <a name="syntax"></a>Sintaxe

```cpp
class Linker : public Invocation
{
public:
    Linker(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [invocação](invocation.md) , a classe `Linker` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Vinculador](#linker)

## <a name="linker"></a>Vinculador

```cpp
Linker(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento de [vinculador](../event-table.md#linker) .

::: moniker-end
