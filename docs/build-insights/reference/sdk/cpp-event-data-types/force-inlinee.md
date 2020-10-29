---
title: Classe ForceInlinee
description: A referência de classe do SDK do ForceInlinee de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ForceInlinee
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 53fff7b6cfd37ba3e3211dd072c1ce3386d00fda
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920665"
---
# <a name="forceinlinee-class"></a>Classe ForceInlinee

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `ForceInlinee` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [FORCE_INLINEE](../event-table.md#force-inlinee) .

## <a name="syntax"></a>Sintaxe

```cpp
class ForceInlinee : public SimpleEvent
{
public:
    ForceInlinee(const RawEvent& event);

    const char*             Name() const;
    const unsigned short&   Size() const;
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a `ForceInlinee` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[ForceInlinee](#force-inlinee)

### <a name="functions"></a>Funções

[Nome](#name) 
 do [Tamanho](#size)

## <a name="forceinlinee"></a><a name="force-inlinee"></a> ForceInlinee

```cpp
ForceInlinee(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [FORCE_INLINEE](../event-table.md#force-inlinee) .

## <a name="name"></a><a name="name"></a> Nomes

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor Retornado

O nome da função forçada e embutida, codificada em UTF-8.

## <a name="size"></a><a name="size"></a> Tamanho

```cpp
const unsigned short& Size() const;
```

### <a name="return-value"></a>Valor Retornado

O tamanho da função de linha embutida forçada, como uma contagem de instruções intermediárias.

::: moniker-end
