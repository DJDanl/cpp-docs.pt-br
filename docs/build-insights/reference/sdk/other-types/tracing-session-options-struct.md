---
title: estrutura TRACING_SESSION_OPTIONS
description: O C++ Build Insights SDK TRACING_SESSION_OPTIONS referência de estrutura.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACING_SESSION_OPTIONS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: 5aeb6299aea8dc0661b9469ee524e7aa4d010aca
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81323434"
---
# <a name="tracing_session_options-structure"></a>estrutura TRACING_SESSION_OPTIONS

::: moniker range="<=vs-2015"

O C++ Build Insights SDK é compatível com o Visual Studio 2017 e acima. Para ver a documentação dessas versões, defina o controle do seletor Visual Studio **Version** para este artigo para visual studio 2017 ou Visual Studio 2019. É encontrado no topo da tabela de conteúdo nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TRACING_SESSION_OPTIONS` estrutura é utilizada na inicialização de uma [estrutura ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR.](relog-descriptor-struct.md) Descreve quais eventos capturar durante a coleta de um vestígio.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct TRACING_SESSION_OPTIONS_TAG
{
    unsigned long long SystemEventFlags;
    unsigned long long MsvcEventFlags;

} TRACING_SESSION_OPTIONS;
```

## <a name="members"></a>Membros

|  |  |
|--|--|
| `SystemEventFlags` | Uma máscara descrevendo os eventos do sistema para capturar. Para obter mais informações, consulte [TRACING_SESSION_SYSTEM_EVENT_FLAGS](tracing-session-system-event-flags-constants.md). |
| `MsvcEventFlags` | Uma máscara de bit descrevendo os eventos do MSVC para capturar. Para obter mais informações, consulte [TRACING_SESSION_MSVC_EVENT_FLAGS](tracing-session-msvc-event-flags-constants.md). |

::: moniker-end
