---
title: Classe de função
description: A C++ referência da classe de função do SDK do insights de compilação.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Function
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 3ff66119007ed7172fed7e824287ab8617c70973
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78333254"
---
# <a name="function-class"></a>Classe de função

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A classe `Function` é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [função](../event-table.md#function) .

## <a name="syntax"></a>Sintaxe

```cpp
class Function : public Activity
{
public:
    Function(const RawEvent& event);

    const char* Name() const;
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a classe `Function` contém os seguintes membros:

### <a name="constructors"></a>{1&gt;Construtores&lt;1}

[Função](#function)

### <a name="functions"></a>{1&gt;Funções&lt;1}

[Nome](#name)

## <a name="function"></a>Funcionamento

```cpp
Function(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*event*\
Um evento de [função](../event-table.md#function) .

## <a name="name"></a> Name

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome da função, codificado em UTF-8.

::: moniker-end
