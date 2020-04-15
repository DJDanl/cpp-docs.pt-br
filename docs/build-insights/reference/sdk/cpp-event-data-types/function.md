---
title: Classe de função
description: A referência de classe C++ Build Insights SDK Function.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- Function
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 69acbe4d6630de37120aec89a24a9f33d447009e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324716"
---
# <a name="function-class"></a>Classe de função

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `Function` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para corresponder a um evento [FUNCTION.](../event-table.md#function)

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

Juntamente com os membros herdados de `Function` sua classe base [de atividade,](activity.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Função](#function)

### <a name="functions"></a>Funções

[Nome](#name)

## <a name="function"></a><a name="function"></a>Função

```cpp
Function(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [FUNCTION.](../event-table.md#function)

## <a name="name"></a><a name="name"></a>Nome

```cpp
const char* Name() const;
```

### <a name="return-value"></a>Valor retornado

O nome da função, codificado em UTF-8.

::: moniker-end
