---
title: Classe ObjOutput
description: A referência da classe C++ Build Insights SDK ObjOutput.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ObjOutput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 194253e8995401114e2529b868b36c9823510a4f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324500"
---
# <a name="objoutput-class"></a>Classe ObjOutput

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `ObjOutput` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [OBJ_OUTPUT.](../event-table.md#obj-output)

## <a name="syntax"></a>Sintaxe

```cpp
class ObjOutput : public FileOutput
{
public:
    ObjOutput(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `ObjOutput` sua classe base [FileOutput,](file-output.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[ObjOutput](#obj-output)

## <a name="objoutput"></a><a name="obj-output"></a>ObjOutput

```cpp
ObjOutput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [OBJ_OUTPUT.](../event-table.md#obj-output)

::: moniker-end
