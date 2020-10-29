---
title: Classe EnvironmentVariable
description: A referência de classe do SDK do EnvironmentVariable de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EnvironmentVariable
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: f707ab744aaf6097975ba9e189815df3c9f32266
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920757"
---
# <a name="environmentvariable-class"></a>Classe EnvironmentVariable

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `EnvironmentVariable` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [ENVIRONMENT_VARIABLE](../event-table.md#environment-variable) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a `EnvironmentVariable` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[EnvironmentVariable](#environment-variable)

### <a name="functions"></a>Funções

[Nome](#name) 
 do [Valor](#value) do

## <a name="environmentvariable"></a><a name="environment-variable"></a> EnvironmentVariable

```cpp
EnvironmentVariable(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [ENVIRONMENT_VARIABLE](../event-table.md#environment-variable) .

## <a name="name"></a><a name="name"></a> Nomes

```cpp
const wchar_t Name() const;
```

### <a name="return-value"></a>Valor Retornado

O nome da variável de ambiente.

## <a name="value"></a><a name="value"></a> Valor

```cpp
const wchar_t Value() const;
```

### <a name="return-value"></a>Valor Retornado

O valor da variável de ambiente.

::: moniker-end
