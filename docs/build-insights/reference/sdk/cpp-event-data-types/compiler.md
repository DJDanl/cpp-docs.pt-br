---
title: Classe compilador
description: A referência da classe C++ Build Insights SDK Compiler.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Compiler
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 9b0a2622c4bc0bc19d7222977fe24c060ee8709e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325024"
---
# <a name="compiler-class"></a>Classe compilador

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Compiler` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para corresponder a um evento [COMPILER.](../event-table.md#compiler)

## <a name="syntax"></a>Sintaxe

```cpp
class Compiler : public Invocation
{
public:
    Compiler(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `Compiler` sua classe base [de Invocação,](invocation.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Compilador](#compiler)

## <a name="compiler"></a><a name="compiler"></a>Compilador

```cpp
Compiler(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [COMPILER.](../event-table.md#compiler)

::: moniker-end
