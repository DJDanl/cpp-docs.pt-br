---
title: Classe de um filerevocation
description: A referência de classe do SDK do Application insights do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- InvocationGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 1a8d4786a228ab25551ee36ce22637d44dc07307
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920626"
---
# <a name="invocationgroup-class"></a>Classe de um filerevocation

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `InvocationGroup` classe é usada com as funções [MatchEventStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para fazer a correspondência de grupos que contêm uma mistura de eventos de [compilador](../event-table.md#compiler) e [vinculador](../event-table.md#linker) .

## <a name="syntax"></a>Sintaxe

```cpp
class InvocationGroup : public EventGroup<Invocation>
{
public:
    InvocationGroup(std::deque<Invocation>&& group);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados da classe base do seu conjunto de [eventos \<Invocation\> ](event-group.md) , a `InvocationGroup` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[InvocationGroup](#invocation-group)

## <a name="invocationgroup"></a><a name="invocation-group"></a> De invocação

```cpp
InvocationGroup(std::deque<Invocation>&& group);
```

### <a name="parameters"></a>Parâmetros

*Group*\
Um grupo que contém uma mistura de eventos de [compilador](../event-table.md#compiler) e [vinculador](../event-table.md#linker) .

::: moniker-end
