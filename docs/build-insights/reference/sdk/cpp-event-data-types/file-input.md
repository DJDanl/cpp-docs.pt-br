---
title: Classe de entrada de dados
description: A referência da classe de dados do SDK de compilação do C++ do insights.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FileInput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 6e12336c10347f00ea2663116f2f308658775e0d
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920678"
---
# <a name="fileinput-class"></a>Classe de entrada de dados

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `FileInput` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [FILE_INPUT](../event-table.md#file-input) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a `FileInput` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[FileInput](#file-input)

### <a name="functions"></a>Funções

[Caminho](#path) 
 do [Tipo](#type) de

## <a name="fileinput"></a><a name="file-input"></a> Entrada de dados

```cpp
FileInput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [FILE_INPUT](../event-table.md#file-input) .

## <a name="path"></a><a name="path"></a> Path

```cpp
const wchar_t Path() const;
```

### <a name="return-value"></a>Valor Retornado

O caminho absoluto para o arquivo de entrada.

## <a name="type"></a>Tipo <a name="type"></a>

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor Retornado

Um código que descreve o tipo de arquivo de entrada.

::: moniker-end
