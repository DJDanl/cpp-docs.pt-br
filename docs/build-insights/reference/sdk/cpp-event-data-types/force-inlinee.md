---
title: Classe ForceInlinee
description: A C++ referência da classe build do SDK do insights ForceInlinee.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ForceInlinee
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7d3cce13601a0b3edbcd2b57664b2d0d94a7d3df
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333331"
---
# <a name="forceinlinee-class"></a>Classe ForceInlinee

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `ForceInlinee` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [FORCE_INLINEE](../event-table.md#force-inlinee) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a classe `ForceInlinee` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[ForceInlinee](#force-inlinee)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Tamanho](#size) da
de [nome](#name)

## <a name="force-inlinee"></a>ForceInlinee

```cpp
ForceInlinee(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [FORCE_INLINEE](../event-table.md#force-inlinee) .

## <a name="name"></a> Name

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome da função forçada e embutida, codificada em UTF-8.

## <a name="size"></a>Tamanho

```cpp
const unsigned short& Size() const;
```

### <a name="return-value"></a>Valor retornado

O tamanho da função de linha embutida forçada, como uma contagem de instruções intermediárias.

::: moniker-end
