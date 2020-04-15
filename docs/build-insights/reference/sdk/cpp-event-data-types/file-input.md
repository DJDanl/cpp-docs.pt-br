---
title: Classe FileInput
description: A referência da classe C++ Build Insights SDK FileInput.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FileInput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 642236d3e67465ed38508cb24c8cd698ae880065
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324790"
---
# <a name="fileinput-class"></a>Classe FileInput

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `FileInput` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [FILE_INPUT.](../event-table.md#file-input)

## <a name="syntax"></a>Sintaxe

```cpp
class FileInput : public SimpleEvent
{
public:
    enum class Type
    {
        OTHER               = FILE_TYPE_CODE_OTHER,
        OBJ                 = FILE_TYPE_CODE_OBJ,
        EXECUTABLE_IMAGE    = FILE_TYPE_CODE_EXECUTABLE_IMAGE,
        LIB                 = FILE_TYPE_CODE_LIB,
        IMP_LIB             = FILE_TYPE_CODE_IMP_LIB,
        EXP                 = FILE_TYPE_CODE_EXP
    };

    FileInput(const RawEvent& event);

    const wchar_t* Path() const;
    Type           Type() const;
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `FileInput` sua classe base [SimpleEvent,](simple-event.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Entrada de arquivos](#file-input)

### <a name="functions"></a>Funções

[Path](#path)
[Tipo](#type) de caminho

## <a name="fileinput"></a><a name="file-input"></a>Entrada de arquivos

```cpp
FileInput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [FILE_INPUT.](../event-table.md#file-input)

## <a name="path"></a><a name="path"></a>Caminho

```cpp
const wchar_t Path() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo de entrada.

## <a name="type"></a>Tipo <a name="type"></a>

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor retornado

Um código que descreve o tipo de arquivo de entrada.

::: moniker-end
