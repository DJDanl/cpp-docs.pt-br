---
title: ExecutávelClasseImageOutput
description: A referência da classe C++ Build Insights SDK ExecutableImageOutput.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- ExecutableImageOutput
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 834689a3605b729260f2d4c925396ee1af1bb705
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81324952"
---
# <a name="executableimageoutput-class"></a>ExecutávelClasseImageOutput

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `ExecutableImageOutput` classe é usada com as funções [MatchEvent,](../functions/match-event.md) [MatchEventInMemberFunction,](../functions/match-event-in-member-function.md) [MatchEventStack](../functions/match-event-stack.md)e [MatchEventStackInMemberFunction.](../functions/match-event-stack-in-member-function.md) Use-o para combinar com um evento [EXECUTABLE_IMAGE_OUTPUT.](../event-table.md#executable-image-output)

## <a name="syntax"></a>Sintaxe

```cpp
class ExecutableImageOutput : public FileOutput
{
public:
    ExecutableImageOutput(const RawEvent& event);
};
```

## <a name="members"></a>Membros

Juntamente com os membros herdados de `ExecutableImageOutput` sua classe base [FileOutput,](file-output.md) a classe contém os seguintes membros:

### <a name="constructors"></a>Construtores

[ExecutávelImageOutput](#executable-image-output)

## <a name="executableimageoutput"></a><a name="executable-image-output"></a>ExecutávelImageOutput

```cpp
ExecutableImageOutput(const RawEvent& event);
```

### <a name="parameters"></a>Parâmetros

*Evento*\
Um evento [EXECUTABLE_IMAGE_OUTPUT.](../event-table.md#executable-image-output)

::: moniker-end
