---
title: Classe fileoutput
description: A referência da classe de saída do SDK do Application insights do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FileOutput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 65e23715d8ac47a8653215e8bd3ee7a43bbe80a3
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923243"
---
# <a name="fileoutput-class"></a>Classe fileoutput

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `FileOutput` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [EXECUTABLE_IMAGE_OUTPUT](../event-table.md#executable-image-output), [EXP_OUTPUT](../event-table.md#exp-output), [IMP_LIB_OUTPUT](../event-table.md#imp-lib-output), [LIB_OUTPUT](../event-table.md#lib-output)ou [OBJ_OUTPUT](../event-table.md#obj-output) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a `FileOutput` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[FileOutput](#file-output)

### <a name="functions"></a>Funções

[Caminho](#path) 
 do [Tipo](#type) de

## <a name="fileoutput"></a><a name="file-output"></a> Saída de

```cpp
FileOutput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um [EXECUTABLE_IMAGE_OUTPUT](../event-table.md#executable-image-output), [EXP_OUTPUT](../event-table.md#exp-output), [IMP_LIB_OUTPUT](../event-table.md#imp-lib-output), [LIB_OUTPUT](../event-table.md#lib-output)ou [OBJ_OUTPUT](../event-table.md#obj-output) evento.

## <a name="path"></a><a name="path"></a> Path

```cpp
const wchar_t Path() const;
```

### <a name="return-value"></a>Valor Retornado

O caminho absoluto para o arquivo de saída.

## <a name="type"></a>Tipo <a name="type"></a>

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor Retornado

Um código que descreve o tipo de arquivo de saída.

::: moniker-end
