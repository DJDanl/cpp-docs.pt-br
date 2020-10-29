---
title: Classe do vinculador
description: A referência da classe do vinculador do SDK do insights do C++ Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Linker
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: cf5544d725c12db8962d888944d4a281387207fa
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923090"
---
# <a name="linker-class"></a>Classe do vinculador

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `Linker` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [vinculador](../event-table.md#linker) .

## <a name="syntax"></a>Sintaxe

```cpp
class Linker : public Invocation
{
public:
    Linker(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [invocação](invocation.md) , a `Linker` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Vinculador](#linker)

## <a name="linker"></a><a name="linker"></a> Vinculador

```cpp
Linker(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento de [vinculador](../event-table.md#linker) .

::: moniker-end
