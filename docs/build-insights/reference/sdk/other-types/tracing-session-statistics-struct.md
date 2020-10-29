---
title: Estrutura de TRACING_SESSION_STATISTICS
description: Saiba mais sobre a referência de estrutura do SDK do insights de compilação do C++ TRACING_SESSION_STATISTICS.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACING_SESSION_STATISTICS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 7135c49bdf95ef5ba39db090c95ad46d266d8f65
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919651"
---
# <a name="tracing_session_statistics-structure"></a>Estrutura de TRACING_SESSION_STATISTICS

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

A `TRACING_SESSION_STATISTICS` estrutura descreve as estatísticas em um rastreamento que foi coletado. Seus campos são definidos ao interromper uma sessão de rastreamento.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct TRACING_SESSION_STATISTICS_TAG
{
    unsigned long MSVCEventsLost;
    unsigned long MSVCBuffersLost;
    unsigned long SystemEventsLost;
    unsigned long SystemBuffersLost;

} TRACING_SESSION_STATISTICS;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `MSVCEventsLost` | O número de eventos MSVC que foram descartados. |
| `MSVCBuffersLost` | O número de buffers de eventos MSVC que foram descartados. |
| `SystemEventsLost` | O número de eventos do sistema que foram descartados. |
| `SystemBuffersLost` | O número de buffers de eventos do sistema que foram descartados. |

## <a name="remarks"></a>Comentários

Essa estrutura é populada ao chamar as seguintes funções:

- [StopTracingSession](../functions/stop-tracing-session.md)
- [StopTracingSessionA](../functions/stop-tracing-session-a.md)
- [StopTracingSessionW](../functions/stop-tracing-session-w.md)
- [StopAndAnalyzeTracingSession](../functions/stop-and-analyze-tracing-session.md)
- [StopAndAnalyzeTracingSessionA](../functions/stop-and-analyze-tracing-session-a.md)
- [StopAndAnalyzeTracingSessionW](../functions/stop-and-analyze-tracing-session-w.md)
- [StopAndRelogTracingSession](../functions/stop-and-relog-tracing-session.md)
- [StopAndRelogTracingSessionA](../functions/stop-and-relog-tracing-session-a.md)
- [StopAndRelogTracingSessionW](../functions/stop-and-relog-tracing-session-w.md)

::: moniker-end
