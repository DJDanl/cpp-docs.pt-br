---
title: Classe CommandLine
description: A referência da classe C++ Build Insights SDK CommandLine.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CommandLine
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: b35d688acf06579cc27f2fee053ef58032e204e0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325055"
---
# <a name="commandline-class"></a>Classe CommandLine

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `CommandLine` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [COMMAND_LINE.](../event-table.md#command-line)

## <a name="syntax"></a>Sintaxe

```cpp
class CommandLine : public SimpleEvent
{
public:
    CommandLine(const RawEvent& event);

    const wchar_t* Value() const;
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `CommandLine` sua classe base [SimpleEvent,](simple-event.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Commandline](#command-line)

### <a name="functions"></a>Funções

[Valor](#value)

## <a name="commandline"></a><a name="command-line"></a>Commandline

```cpp
CommandLine(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [COMMAND_LINE.](../event-table.md#command-line)

## <a name="value"></a><a name="value"></a> Valor

```cpp
const wchar_t Value() const;
```

### <a name="return-value"></a>Valor retornado

Uma seqüência contendo uma linha de comando. O valor inclui argumentos obtidos a partir de um arquivo de \_\_resposta e \_de\_variáveis de ambiente como CL, CL, Link e LINK .

::: moniker-end
