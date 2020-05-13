---
title: Classe ImpLibOutput
description: A referência da classe C++ Build Insights SDK ImpLibOutput.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ImpLibOutput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 98905dfe75484e98e14a0fa575e75fe3ab284559
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324707"
---
# <a name="impliboutput-class"></a>Classe ImpLibOutput

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `ImpLibOutput` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [IMP_LIB_OUTPUT.](../event-table.md#imp-lib-output)

## <a name="syntax"></a>Sintaxe

```cpp
class ImpLibOutput : public FileOutput
{
public:
    ImpLibOutput(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `ImpLibOutput` sua classe base [FileOutput,](file-output.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[Saída implib](#imp-lib-output)

## <a name="impliboutput"></a><a name="imp-lib-output"></a>Saída implib

```cpp
ImpLibOutput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [IMP_LIB_OUTPUT.](../event-table.md#imp-lib-output)

::: moniker-end
