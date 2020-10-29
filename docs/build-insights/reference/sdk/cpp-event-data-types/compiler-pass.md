---
title: Classe CompilerPass
description: A referência de classe do SDK do CompilerPass de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CompilerPass
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: bfbfdc28870a13a9cdb19d0ec050ea2e69fe1208
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920808"
---
# <a name="compilerpass-class"></a>Classe CompilerPass

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `CompilerPass` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [BACK_END_PASS](../event-table.md#back-end-pass) ou [FRONT_END_PASS](../event-table.md#front-end-pass) .

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

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a `CompilerPass` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[CompilerPass](#compiler-pass)

### <a name="enums"></a>Enumerações

#### <a name="passcode"></a>Bluetooth

|Valor|Descrição|
|-|-|
|FRONT_END|A passagem de front-end.|
|BACK_END|A passagem de back-end.|

### <a name="functions"></a>Funções

[InputSourcePath](#input-source-path)\
[OutputObjectPath](#output-object-path)\
[Bluetooth](#pass-code)\

## <a name="compilerpass"></a><a name="compiler-pass"></a> CompilerPass

```cpp
CompilerPass(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [BACK_END_PASS](../event-table.md#back-end-pass) ou [FRONT_END_PASS](../event-table.md#front-end-pass) .

## <a name="inputsourcepath"></a><a name="input-source-path"></a> InputSourcePath

```cpp
const wchar_t* InputSourcePath() const;
```

### <a name="return-value"></a>Valor Retornado

O caminho absoluto para o arquivo de origem de entrada processado por esta passagem do compilador.

## <a name="outputobjectpath"></a><a name="output-object-path"></a> OutputObjectPath

```cpp
const wchar_t* OutputObjectPath() const;
```

### <a name="return-value"></a>Valor Retornado

O caminho absoluto para o arquivo de objeto de saída produzido por esse compilador passa.

## <a name="passcode"></a><a name="pass-code"></a> Bluetooth

```cpp
PassCode PassCode() const;
```

### <a name="return-value"></a>Valor Retornado

Um código que indica qual passagem do compilador é representada por esse objeto CompilerPass.

::: moniker-end
