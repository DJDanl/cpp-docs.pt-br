---
title: Classe de invocação
description: A referência da classe de invocação do SDK do Application insights do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Invocation
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: dfd463c7b9ca72dc14ad74b3759fdd1e3730d5a9
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923136"
---
# <a name="invocation-class"></a>Classe de invocação

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `Invocation` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [compilador](../event-table.md#compiler) ou [vinculador](../event-table.md#linker) .

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

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a `Invocation` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Invocação](#invocation)

### <a name="functions"></a>Funções

[ToolPath](#tool-path) 
 [ToolVersion](#tool-version) 
 [ToolVersionString](#tool-version-string) 
 [Tipo](#type) 
 de [WorkingDirectory](#working-directory)

## <a name="invocation"></a><a name="invocation"></a> Invocação

```cpp
Invocation(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um [compilador](../event-table.md#compiler) ou evento de [vinculador](../event-table.md#linker) .

## <a name="toolpath"></a><a name="tool-path"></a> ToolPath

```cpp
const wchar_t* ToolPath() const;
```

### <a name="return-value"></a>Valor Retornado

O caminho absoluto para a ferramenta que foi invocada.

## <a name="toolversion"></a><a name="tool-version"></a> ToolVersion

```cpp
const INVOCATION_VERSION_DATA& ToolVersion() const;
```

### <a name="return-value"></a>Valor Retornado

A versão da ferramenta que foi invocada, como uma referência de [INVOCATION_VERSION_DATA](../c-event-data-types/invocation-version-data-struct.md) .

## <a name="toolversionstring"></a><a name="tool-version-string"></a> ToolVersionString

```cpp
const char* ToolVersionString() const;
```

### <a name="return-value"></a>Valor Retornado

A versão da ferramenta que foi invocada, como uma cadeia de caracteres ANSI.

## <a name="type"></a>Tipo <a name="type"></a>

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor Retornado

Um código que indica a ferramenta que foi invocada.

## <a name="workingdirectory"></a><a name="working-directory"></a> WorkingDirectory

```cpp
const wchar_t* WorkingDirectory() const;
```

### <a name="return-value"></a>Valor Retornado

O caminho absoluto para o diretório no qual a ferramenta foi invocada.

::: moniker-end
