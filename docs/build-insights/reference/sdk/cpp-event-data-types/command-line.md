---
title: Classe CommandLine
description: A C++ referência de classe de linha de comando do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CommandLine
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: ff16646920fe77f7f3b4cb8a194a38984c3e6c32
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333506"
---
# <a name="commandline-class"></a>Classe CommandLine

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `CommandLine` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [COMMAND_LINE](../event-table.md#command-line) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a classe `CommandLine` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[CommandLine](#command-line)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Valor](#value)

## <a name="command-line"></a>CommandLine

```cpp
CommandLine(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [COMMAND_LINE](../event-table.md#command-line) .

## <a name="value"></a>Valor

```cpp
const wchar_t Value() const;
```

### <a name="return-value"></a>Valor retornado

Uma cadeia de caracteres que contém uma linha de comando. O valor inclui argumentos que foram obtidos de um arquivo de resposta e de variáveis de ambiente, como CL, \_CL\_, link e \_LINK\_.

::: moniker-end
