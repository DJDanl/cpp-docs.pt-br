---
title: Estrutura de TRACING_SESSION_OPTIONS
description: Saiba mais sobre a referência de estrutura do SDK do insights de compilação do C++ TRACING_SESSION_OPTIONS.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- TRACING_SESSION_OPTIONS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: f7c53abc14c4862ccb73f94acd2e325eb3d4a6fa
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742769"
---
# <a name="tracing_session_options-structure"></a>Estrutura de TRACING_SESSION_OPTIONS

::: moniker range="<=vs-2015"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=vs-2017"

A `TRACING_SESSION_OPTIONS` estrutura é usada ao inicializar uma estrutura de [ANALYSIS_DESCRIPTOR](analysis-descriptor-struct.md) ou [RELOG_DESCRIPTOR](relog-descriptor-struct.md) . Ele descreve quais eventos capturar durante a coleta de um rastreamento.

## <a name="syntax"></a>Sintaxe

```cpp
typedef struct TRACING_SESSION_OPTIONS_TAG
{
    unsigned long long SystemEventFlags;
    unsigned long long MsvcEventFlags;

} TRACING_SESSION_OPTIONS;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `SystemEventFlags` | Uma bitmask que descreve os eventos do sistema a serem capturados. Para obter mais informações, consulte [TRACING_SESSION_SYSTEM_EVENT_FLAGS](tracing-session-system-event-flags-constants.md). |
| `MsvcEventFlags` | Uma bitmask que descreve os eventos MSVC a serem capturados. Para obter mais informações, consulte [TRACING_SESSION_MSVC_EVENT_FLAGS](tracing-session-msvc-event-flags-constants.md). |

::: moniker-end
