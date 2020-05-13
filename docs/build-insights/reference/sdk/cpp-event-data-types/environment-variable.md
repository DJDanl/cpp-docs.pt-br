---
title: Classe AmbienteVariável
description: A referência de classe C++ Build Insights SDK EnvironmentVariable.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EnvironmentVariable
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 963c52e0ea9e048448c6f2b3ac62d9938817467e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81325013"
---
# <a name="environmentvariable-class"></a>Classe AmbienteVariável

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `EnvironmentVariable` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [ENVIRONMENT_VARIABLE.](../event-table.md#environment-variable)

## <a name="syntax"></a>Sintaxe

```cpp
class EnvironmentVariable : public SimpleEvent
{
public:
    EnvironmentVariable(const RawEvent& event);

    const wchar_t* Name() const;
    const wchar_t* Value() const;
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `EnvironmentVariable` sua classe base [SimpleEvent,](simple-event.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[EnvironmentVariable](#environment-variable)

### <a name="functions"></a>Funções

[Name](#name)
[Valor](#value) do nome

## <a name="environmentvariable"></a><a name="environment-variable"></a>AmbienteVariável

```cpp
EnvironmentVariable(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [ENVIRONMENT_VARIABLE.](../event-table.md#environment-variable)

## <a name="name"></a><a name="name"></a>Nome

```cpp
const wchar_t Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome da variável ambiente.

## <a name="value"></a><a name="value"></a> Valor

```cpp
const wchar_t Value() const;
```

### <a name="return-value"></a>Valor retornado

O valor da variável ambiente.

::: moniker-end
