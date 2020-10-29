---
title: Classe de função
description: A referência da classe de função do SDK do insights de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Function
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 874477b9ca31095bfcf4ba3c7a6fd220dc073415
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920639"
---
# <a name="function-class"></a>Classe de função

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `Function` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento de [função](../event-table.md#function) .

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

Junto com os membros herdados de sua classe base de [atividade](activity.md) , a `Function` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Função](#function)

### <a name="functions"></a>Funções

[Nome](#name)

## <a name="function"></a><a name="function"></a> Funcionamento

```cpp
Function(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento de [função](../event-table.md#function) .

## <a name="name"></a><a name="name"></a> Nomes

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor Retornado

O nome da função, codificado em UTF-8.

::: moniker-end
