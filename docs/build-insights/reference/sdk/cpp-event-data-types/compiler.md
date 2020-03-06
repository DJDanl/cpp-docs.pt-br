---
title: Classe do compilador
description: A C++ referência de classe do compilador do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Compiler
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: a63a0bad1ab6063d5986fec77b5135f500ded1ce
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333457"
---
# <a name="compiler-class"></a>Classe do compilador

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `Compiler` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento do [compilador](../event-table.md#compiler) .

## <a name="syntax"></a>Sintaxe

```cpp
class Compiler : public Invocation
{
public:
    Compiler(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [invocação](invocation.md) , a classe `Compiler` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Compiler](#compiler)

## <a name="compiler"></a>Compiler

```cpp
Compiler(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento do [compilador](../event-table.md#compiler) .

::: moniker-end
