---
title: Classe DeGrupo de Invocação
description: A referência da classe C++ Build Insights SDK InvocationGroup.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- InvocationGroup
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ff5a73d5304a21c314c0fc5ce442e0ffc23b28fd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324687"
---
# <a name="invocationgroup-class"></a>Classe DeGrupo de Invocação

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `InvocationGroup` classe é usada com as funções [MatchEventStackStack](../functions/match-event-stack.md) e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar grupos que contenham uma mistura de eventos [COMPILER](../event-table.md#compiler) e [LINKER.](../event-table.md#linker)

## <a name="syntax"></a>Sintaxe

```cpp
class InvocationGroup : public EventGroup<Invocation>
{
public:
    InvocationGroup(std::deque<Invocation>&& group);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de sua `InvocationGroup` classe base de [invocação\<\> eventGroup,](event-group.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Grupo de Invocação](#invocation-group)

## <a name="invocationgroup"></a><a name="invocation-group"></a>Grupo de Invocação

```cpp
InvocationGroup(std::deque<Invocation>&& group);
```

### <a name="parameters"></a>Parâmetros

*Grupo*\
Um grupo contendo uma mistura de eventos [COMPILER](../event-table.md#compiler) e [LINKER.](../event-table.md#linker)

::: moniker-end
