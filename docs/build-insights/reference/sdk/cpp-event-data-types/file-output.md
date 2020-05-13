---
title: Classe FileOutput
description: A referência da classe C++ Build Insights SDK FileOutput.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FileOutput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 37823da8a4aaac0ce4094583b8aee8ac1eb04aaa
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324814"
---
# <a name="fileoutput-class"></a>Classe FileOutput

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `FileOutput` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um [evento EXECUTABLE_IMAGE_OUTPUT](../event-table.md#executable-image-output), [EXP_OUTPUT](../event-table.md#exp-output), [IMP_LIB_OUTPUT](../event-table.md#imp-lib-output), [LIB_OUTPUT](../event-table.md#lib-output)ou [OBJ_OUTPUT.](../event-table.md#obj-output)

## <a name="syntax"></a>Sintaxe

```cpp
class FileOutput : public SimpleEvent
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

    FileOutput(const RawEvent& event);

    const wchar_t* Path() const;
    Type           Type() const;
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `FileOutput` sua classe base [SimpleEvent,](simple-event.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Saída de arquivos](#file-output)

### <a name="functions"></a>Funções

[Path](#path)
[Tipo](#type) de caminho

## <a name="fileoutput"></a><a name="file-output"></a>Saída de arquivos

```cpp
FileOutput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
[EXECUTABLE_IMAGE_OUTPUT](../event-table.md#executable-image-output), [EXP_OUTPUT](../event-table.md#exp-output), [IMP_LIB_OUTPUT,](../event-table.md#imp-lib-output) [LIB_OUTPUT](../event-table.md#lib-output)ou [OBJ_OUTPUT.](../event-table.md#obj-output)

## <a name="path"></a><a name="path"></a>Caminho

```cpp
const wchar_t Path() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo de saída.

## <a name="type"></a>Tipo <a name="type"></a>

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor retornado

Um código que descreve o tipo de arquivo de saída.

::: moniker-end
