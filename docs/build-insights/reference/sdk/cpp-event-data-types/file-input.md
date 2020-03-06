---
title: Classe de entrada de dados
description: A C++ referência da classe de entrada do SDK do Build insights.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- FileInput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: bea2cf72ca2a83a9cd630f8a9ccefb87dd4b7ff1
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333345"
---
# <a name="fileinput-class"></a>Classe de entrada de dados

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `FileInput` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [FILE_INPUT](../event-table.md#file-input) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a classe `FileInput` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Entrada de dados](#file-input)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Tipo](#type) de
de [caminho](#path)

## <a name="file-input"></a>Entrada de dados

```cpp
FileInput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [FILE_INPUT](../event-table.md#file-input) .

## <a name="path"></a> Path

```cpp
const wchar_t Path() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo de entrada.

## <a name="type"></a>Escreva

```cpp
Type Type() const;
```

### <a name="return-value"></a>Valor retornado

Um código que descreve o tipo de arquivo de entrada.

::: moniker-end
