---
title: Aula de invocação
description: A referência da classe C++ Build Insights SDK Invocation.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Invocation
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: fcb087d46ea445251b0108f811545a44c26f421e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324638"
---
# <a name="invocation-class"></a>Aula de invocação

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Invocation` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [COMPILER](../event-table.md#compiler) ou [LINKER.](../event-table.md#linker)

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

Juntamente com os membros herdados de `Invocation` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Invocação](#invocation)

### <a name="functions"></a>Funções

[ToolPath](#tool-path)
[ToolVersion ToolVersionTypeType](#tool-version)
[ToolVersionString](#tool-version-string)
[Type](#type)
[WorkingDirectory](#working-directory)

## <a name="invocation"></a><a name="invocation"></a>Invocação

```cpp
Invocation(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um [evento COMPILER](../event-table.md#compiler) ou [LINKER.](../event-table.md#linker)

## <a name="toolpath"></a><a name="tool-path"></a>Toolpath

```cpp
const wchar_t* ToolPath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para a ferramenta que foi invocada.

## <a name="toolversion"></a><a name="tool-version"></a>Versão de ferramentas

```cpp
const INVOCATION_VERSION_DATA& ToolVersion() const;
```

### <a name="return-value"></a>Valor retornado

A versão da ferramenta que foi invocada, como uma [referência INVOCATION_VERSION_DATA.](../c-event-data-types/invocation-version-data-struct.md)

## <a name="toolversionstring"></a><a name="tool-version-string"></a>ToolVersionString

```cpp
const char* ToolVersionString() const;
```

### <a name="return-value"></a>Valor retornado

A versão da ferramenta que foi invocada, como uma seqüência ANSI.

## <a name="type"></a>Tipo <a name="type"></a>

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor retornado

Um código indicando a ferramenta que foi invocada.

## <a name="workingdirectory"></a><a name="working-directory"></a>Workingdirectory

```cpp
const wchar_t* WorkingDirectory() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o diretório em que a ferramenta foi invocada.

::: moniker-end
