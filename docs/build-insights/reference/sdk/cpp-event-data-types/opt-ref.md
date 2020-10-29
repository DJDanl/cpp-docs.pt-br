---
title: Classe OptRef
description: A referência de classe do SDK do OptRef de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- OptRef
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 72d3867456ecc2bb643239ddb0186668e43f69ef
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920509"
---
# <a name="optref-class"></a>Classe OptRef

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `OptRef` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [OPT_REF](../event-table.md#opt-ref) .

## <a name="syntax"></a>Sintaxe

```cpp
class OptRef : public Activity
{
public:
    OptRef(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a `OptRef` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[OptRef](#opt-ref)

## <a name="optref"></a><a name="opt-ref"></a> OptRef

```cpp
OptRef(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [OPT_REF](../event-table.md#opt-ref) .

::: moniker-end
