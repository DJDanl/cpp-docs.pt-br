---
title: Estrutura de TRACING_SESSION_STATISTICS
description: A C++ referência da estrutura de TRACING_SESSION_OPTIONS do SDK do insights do Build.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACING_SESSION_STATISTICS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 9aa7c0a861d80fd3ebff85eb7ecb17dd05ae869e
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2020
ms.locfileid: "78332197"
---
# <a name="tracing_session_statistics-structure"></a>Estrutura de TRACING_SESSION_STATISTICS

::: moniker range="<=vs-2015"

O C++ SDK de informações de compilação é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de versão do Visual Studio para este artigo como Visual Studio 2017 ou Visual Studio 2019.

::: moniker-end
::: moniker range=">=vs-2017"

A estrutura de `TRACING_SESSION_STATISTICS` descreve as estatísticas em um rastreamento que foi coletado. Seus campos são definidos ao interromper uma sessão de rastreamento.

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

|  |  |
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
