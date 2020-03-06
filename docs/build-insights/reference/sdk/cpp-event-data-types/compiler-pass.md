---
title: Classe CompilerPass
description: A C++ referência da classe build do SDK do insights CompilerPass.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CompilerPass
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3c2fa1c2c4be8aaf5bec77b383f93a4b033ca8e3
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333471"
---
# <a name="compilerpass-class"></a>Classe CompilerPass

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `CompilerPass` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [BACK_END_PASS](../event-table.md#back-end-pass) ou [FRONT_END_PASS](../event-table.md#front-end-pass) .

## <a name="syntax"></a>Sintaxe

```cpp
class CompilerPass : public Activity
{
public:
    enum class PassCode
    {
        FRONT_END,
        BACK_END
    };

    CompilerPass(const RawEvent& event);

    PassCode       PassCode() const;
    const wchar_t* InputSourcePath() const;
    const wchar_t* OutputObjectPath() const;
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a classe `CompilerPass` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[CompilerPass](#compiler-pass)

### <a name="enums"></a>Enums

#### <a name="passcode"></a>Bluetooth

|||
|-|-|
|FRONT_END|A passagem de front-end.|
|BACK_END|A passagem de back-end.|

### <a name="functions"></a>{1&gt;Funções&lt;1}

\ [InputSourcePath](#input-source-path)
\ [OutputObjectPath](#output-object-path)
\ de [senha](#pass-code)

## <a name="compiler-pass"></a>CompilerPass

```cpp
CompilerPass(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [BACK_END_PASS](../event-table.md#back-end-pass) ou [FRONT_END_PASS](../event-table.md#front-end-pass) .

## <a name="input-source-path"></a>InputSourcePath

```cpp
const wchar_t* InputSourcePath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo de origem de entrada processado por esta passagem do compilador.

## <a name="output-object-path"></a>OutputObjectPath

```cpp
const wchar_t* OutputObjectPath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo de objeto de saída produzido por esse compilador passa.

## <a name="pass-code"></a>Bluetooth

```cpp
PassCode PassCode() const;
```

### <a name="return-value"></a>Valor retornado

Um código que indica qual passagem do compilador é representada por esse objeto CompilerPass.

::: moniker-end
