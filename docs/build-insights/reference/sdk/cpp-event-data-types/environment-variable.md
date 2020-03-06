---
title: Classe EnvironmentVariable
description: A C++ referência da classe build do SDK do insights EnvironmentVariable.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- EnvironmentVariable
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 19e9278e76fb2116dac30a0e790fba86c6c56484
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333436"
---
# <a name="environmentvariable-class"></a>Classe EnvironmentVariable

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `EnvironmentVariable` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [ENVIRONMENT_VARIABLE](../event-table.md#environment-variable) .

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

Junto com os membros herdados de sua classe base [SimpleEvent](simple-event.md) , a classe `EnvironmentVariable` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[EnvironmentVariable](#environment-variable)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Nome](#name)
[Valor](#value)

## <a name="environment-variable"></a>EnvironmentVariable

```cpp
EnvironmentVariable(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento [ENVIRONMENT_VARIABLE](../event-table.md#environment-variable) .

## <a name="name"></a> Name

```cpp
const wchar_t Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome da variável de ambiente.

## <a name="value"></a>Valor

```cpp
const wchar_t Value() const;
```

### <a name="return-value"></a>Valor retornado

O valor da variável de ambiente.

::: moniker-end
