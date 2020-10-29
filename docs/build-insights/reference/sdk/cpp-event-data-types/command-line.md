---
title: Classe CommandLine
description: A referência de classe de linha de comando do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CommandLine
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 5214f2970329510088184dc3092db66607f4d67e
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923333"
---
# <a name="commandline-class"></a>Classe CommandLine

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `CommandLine` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [COMMAND_LINE](../event-table.md#command-line) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a `CommandLine` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[CommandLine](#command-line)

### <a name="functions"></a>Funções

[Valor](#value)

## <a name="commandline"></a><a name="command-line"></a> CommandLine

```cpp
CommandLine(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [COMMAND_LINE](../event-table.md#command-line) .

## <a name="value"></a><a name="value"></a> Valor

```cpp
const wchar_t Value() const;
```

### <a name="return-value"></a>Valor Retornado

Uma cadeia de caracteres que contém uma linha de comando. O valor inclui argumentos que foram obtidos de um arquivo de resposta e de variáveis de ambiente, como CL, \_ CL \_ , link e \_ link \_ .

::: moniker-end
