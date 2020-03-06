---
title: Classe de invocação
description: A C++ referência da classe de invocação do SDK do Build insights.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Invocation
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 0c4698300a3eeaf77210ad74f84b0c0cd219b457
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333226"
---
# <a name="invocation-class"></a>Classe de invocação

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `Invocation` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [compilador](../event-table.md#compiler) ou [vinculador](../event-table.md#linker) .

## <a name="syntax"></a>Sintaxe

```cpp
class Invocation : public Activity
{
    const INVOCATION_DATA* data_;

public:
    enum class Type
    {
        CL      = MSVC_TOOL_CODE_CL,
        LINK    = MSVC_TOOL_CODE_LINK
    };

    Invocation(const RawEvent& event);

    Type             Type() const;
    const char*      ToolVersionString() const;
    const wchar_t*   WorkingDirectory() const;
    const wchar_t*   ToolPath() const;

    const INVOCATION_VERSION_DATA& ToolVersion() const;
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a classe `Invocation` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Invocação](#invocation)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[ToolPath](#tool-path)
[ToolVersion](#tool-version)
[ToolVersionString](#tool-version-string)
[tipo](#type)
[WorkingDirectory](#working-directory)

## <a name="invocation"></a>Invocação

```cpp
Invocation(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um [compilador](../event-table.md#compiler) ou evento de [vinculador](../event-table.md#linker) .

## <a name="tool-path"></a>ToolPath

```cpp
const wchar_t* ToolPath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para a ferramenta que foi invocada.

## <a name="tool-version"></a>ToolVersion

```cpp
const INVOCATION_VERSION_DATA& ToolVersion() const;
```

### <a name="return-value"></a>Valor retornado

A versão da ferramenta que foi invocada, como uma referência de [INVOCATION_VERSION_DATA](../c-event-data-types/invocation-version-data-struct.md) .

## <a name="tool-version-string"></a>ToolVersionString

```cpp
const char* ToolVersionString() const;
```

### <a name="return-value"></a>Valor retornado

A versão da ferramenta que foi invocada, como uma cadeia de caracteres ANSI.

## <a name="type"></a>Escreva

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor retornado

Um código que indica a ferramenta que foi invocada.

## <a name="working-directory"></a>WorkingDirectory

```cpp
const wchar_t* WorkingDirectory() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o diretório no qual a ferramenta foi invocada.

::: moniker-end
