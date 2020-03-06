---
title: Classe de um filerevocation
description: A C++ referência da classe do kit de chamada do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- InvocationGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b9a2bbcd2b7649b9b5703adc08ed41b272e10276
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333233"
---
# <a name="invocationgroup-class"></a>Classe de um filerevocation

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `InvocationGroup` é usada com as funções [MatchEventStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para fazer a correspondência de grupos que contêm uma mistura de eventos de [compilador](../event-table.md#compiler) e [vinculador](../event-table.md#linker) .

## <a name="syntax"></a>Sintaxe

```cpp
class InvocationGroup : public EventGroup<Invocation>
{
public:
    InvocationGroup(std::deque<Invocation>&& group);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua [\>de evento\<invocação](event-group.md) de classe base, a classe `InvocationGroup` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[De invocação](#invocation-group)

## <a name="invocation-group"></a>De invocação

```cpp
InvocationGroup(std::deque<Invocation>&& group);
```

### <a name="parameters"></a>Parâmetros

\ de *grupo*
Um grupo que contém uma mistura de eventos de [compilador](../event-table.md#compiler) e [vinculador](../event-table.md#linker) .

::: moniker-end
