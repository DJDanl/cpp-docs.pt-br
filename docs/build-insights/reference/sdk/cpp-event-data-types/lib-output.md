---
title: Classe LibOutput
description: A referência de classe do SDK do LibOutput de compilação do C++.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- LibOutput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7cb759403a3e9b922ffa861b3938bcb874adac32
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92920613"
---
# <a name="liboutput-class"></a>Classe LibOutput

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `LibOutput` classe é usada com as funções [MatchEvent](../functions/match-event.md), [MatchEventInMemberFunction](../functions/match-event-in-member-function.md), [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction](../functions/match-event-stack-in-member-function.md) . Use-o para corresponder a um evento [LIB_OUTPUT](../event-table.md#lib-output) .

## <a name="syntax"></a>Sintaxe

```cpp
class LibOutput : public FileOutput
{
public:
    LibOutput(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Junto com os membros herdados de sua classe base [fileoutput](file-output.md) , a `LibOutput` classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[LibOutput](#lib-output)

## <a name="liboutput"></a><a name="lib-output"></a> LibOutput

```cpp
LibOutput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*circunstância*\
Um evento [LIB_OUTPUT](../event-table.md#lib-output) .

::: moniker-end
