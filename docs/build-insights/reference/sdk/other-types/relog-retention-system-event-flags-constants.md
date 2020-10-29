---
title: RELOG_RETENTION_SYSTEM_EVENT_FLAGS constantes
description: O SDK de informações de compilação do C++ RELOG_RETENTION_SYSTEM_EVENT_FLAGS referência de constantes.
ms.date: 02/12/2020
helpviewer_keywords:
- C++ Build Insights
- C++ Build Insights SDK
- RELOG_RETENTION_SYSTEM_EVENT_FLAGS
- throughput analysis
- build time analysis
- vcperf.exe
ms.openlocfilehash: e0144835568dab12c8593fe8fbfa820f6cde7647
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919718"
---
# <a name="relog_retention_system_event_flags-constants"></a>RELOG_RETENTION_SYSTEM_EVENT_FLAGS constantes

::: moniker range="<=msvc-140"

O SDK do insights de compilação do C++ é compatível com o Visual Studio 2017 e superior. Para ver a documentação dessas versões, defina o controle do seletor de **versão** do Visual Studio para este artigo como visual Studio 2017 ou visual Studio 2019. Ele é encontrado na parte superior do Sumário nesta página.

::: moniker-end
::: moniker range=">=msvc-150"

As `RELOG_RETENTION_SYSTEM_EVENT_FLAGS` constantes são usadas para descrever quais eventos do sistema devem ser mantidos em um rastreamento reregistrado. Use-os para inicializar o campo da estrutura de [RELOG_DESCRIPTOR](relog-descriptor-struct.md) `SystemEventsRetentionFlags` .

## <a name="syntax"></a>Sintaxe

```cpp
static const unsigned long long
    RELOG_RETENTION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES = 0x1ULL;

static const unsigned long long
    RELOG_RETENTION_SYSTEM_EVENT_FLAGS_ALL         = 0xFFFFFFFFFFFFFFFFULL;
```

## <a name="members"></a>Membros

| Nome | Descrição |
|--|--|
| `RELOG_RETENTION_SYSTEM_EVENT_FLAGS_CPU_SAMPLES` | Mantenha os eventos do sistema de exemplo da CPU em um rastreamento reregistrado. |
| `RELOG_RETENTION_SYSTEM_EVENT_FLAGS_ALL` | Manter todos os eventos do sistema em um rastreamento reregistrado. |

## <a name="remarks"></a>Comentários

::: moniker-end
