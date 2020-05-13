---
title: Classe CompilerPass
description: A referência de classe C++ Build Insights SDK CompilerPass.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- CompilerPass
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 11af981b647d5183f88dad024d90c0ef4f8a28bc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325038"
---
# <a name="compilerpass-class"></a>Classe CompilerPass

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `CompilerPass` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um [evento de BACK_END_PASS](../event-table.md#back-end-pass) ou [FRONT_END_PASS.](../event-table.md#front-end-pass)

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

Juntamente com os membros herdados de `CompilerPass` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[CompilerPass](#compiler-pass)

### <a name="enums"></a>Enums

#### <a name="passcode"></a>Senha

|||
|-|-|
|FRONT_END|O passe da frente.|
|BACK_END|O passe de fundo.|

### <a name="functions"></a>Funções

[InputSourcePath](#input-source-path)\
[SaídaObjectPath](#output-object-path)\
[Senha](#pass-code)\

## <a name="compilerpass"></a><a name="compiler-pass"></a>CompilerPass

```cpp
CompilerPass(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um [evento BACK_END_PASS](../event-table.md#back-end-pass) ou [FRONT_END_PASS.](../event-table.md#front-end-pass)

## <a name="inputsourcepath"></a><a name="input-source-path"></a>InputSourcePath

```cpp
const wchar_t* InputSourcePath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo de origem de entrada processado por este passe de compilador.

## <a name="outputobjectpath"></a><a name="output-object-path"></a>SaídaObjectPath

```cpp
const wchar_t* OutputObjectPath() const;
```

### <a name="return-value"></a>Valor retornado

O caminho absoluto para o arquivo objeto de saída produzido por este passe de compilador.

## <a name="passcode"></a><a name="pass-code"></a>Senha

```cpp
PassCode PassCode() const;
```

### <a name="return-value"></a>Valor retornado

Um código indicando qual passe de compilador é representado por este objeto CompilerPass.

::: moniker-end
