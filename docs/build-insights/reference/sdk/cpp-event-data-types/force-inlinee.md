---
title: Classe ForceInlinee
description: A referência de classe C++ Build Insights SDK ForceInlinee.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ForceInlinee
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: c6a1af0384197a0a3b6062ad9ef30537c348190d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324776"
---
# <a name="forceinlinee-class"></a>Classe ForceInlinee

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `ForceInlinee` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [FORCE_INLINEE.](../event-table.md#force-inlinee)

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

Juntamente com os membros herdados de `ForceInlinee` sua classe base [SimpleEvent,](simple-event.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[ForceInlinee](#force-inlinee)

### <a name="functions"></a>Funções

[Tamanho do nome](#name)
[Size](#size)

## <a name="forceinlinee"></a><a name="force-inlinee"></a>ForceInlinee

```cpp
ForceInlinee(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [FORCE_INLINEE.](../event-table.md#force-inlinee)

## <a name="name"></a><a name="name"></a>Nome

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome da função forrada, codificada em UTF-8.

## <a name="size"></a><a name="size"></a> Tamanho

```cpp
const unsigned short& Size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho da função forrada, como uma contagem intermediária de instruções.

::: moniker-end
